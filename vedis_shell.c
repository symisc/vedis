/*
 * Compile this file together with the vedis engine source code to generate
 * the desired executable. For example: 
 *  gcc -W -Wall -O6 vedis_shell.c vedis.c -o vedis_shell
 */
/*
 * The Vedis shell is a simple standalone program which let you execute
 * built-in Vedis commands from your command line interface (CLI).
 *
 * Introduction to the Command Execution Interfaces (CEI):
 *
 * Structured data storage is presented to clients via the command execution interface.
 * Basically, you execute one or more commands ala Redis (i.e. SET key value; HSET ds key value, GET key)
 * via [vedis_exec()] and you extract the execution result (The return value of the command) via 
 * [vedis_exec_result()]. You could also register foreign commands via [vedis_register_commmand()].
 * You may also be tempted by installing a command consumer callback in case you
 * want to invoke multiple commands (pipelined request) in a single [vedis_exec()] call rather
 * than calling [vedis_exec_result()] which return only the execution result of the last executed
 * command.
 *
 * For an introduction to the Vedis C/C++ interface, please refer to:
 *        http://vedis.symisc.net/api_intro.html
 * For the full C/C++ API reference guide, please refer to:
 *        http://vedis.symisc.net/c_api.html
 * Vedis in 5 Minutes or Less:
 *        http://vedis.symisc.net/intro.html
 * Built-in Vedis Commands:
 *        http://vedis.symisc.net/commands.html
 */
/* $SymiscID: vedis_shell.c v1.0.4 Linux 2013-09-15 02:22 stable <devel@symisc.net> $ */

/* Make sure you have the latest release of the Vedis engine
 * from:
 *  http://vedis.symisc.net/downloads.html
 */
#include <stdio.h>
#include <stdlib.h>
/* Make sure this header file is available.*/
#include "vedis.h"

/* 
 * Display an error message and exit.
 */
static void Fatal(const char *zMsg)
{
	puts(zMsg);
	/* Shutdown the library */
	vedis_lib_shutdown();
	/* Exit immediately */
	exit(0);
}
/*
 * Banner.
 */
static const char zBanner[] = {
	"============================================================\n"
	" Simple Vedis Shell                                         \n"
	"                                    http://vedis.symisc.net/\n"
	" Enter one or more Vedis commands.                          \n"
	"                                                            \n"
	" Type 'CMD_LIST' for a list of built-in Vedis commands.     \n"
	"                                                            \n"
	" Enter a blank line to exit the shell                       \n"
	"============================================================\n"
};
/*
 * atexit() callback. Shutdown the Vedis library.
 */
void vedis_exit(void)
{
	vedis_lib_shutdown();
}
#include <ctype.h>
/*
 * Return true only if we are dealing with a blank line.
 */
int isBlank(const char *zIn,unsigned int nByte)
{
	const char *zEnd = &zIn[nByte];
	while( zIn < zEnd && (isspace(zIn[0])) ){
		/* Advance the cursor */
		zIn++;
	}
	return (zIn[0] == 0 || zIn >= zEnd) ? 1 : 0;
}
/* Forward declaration */
struct array_rend
{
	int is_first;
	int cnt;
};
static int array_render(vedis_value *pEntry,void *pUserdata);
/*
 * Command result consumer callback. Each time a command is executed
 * the engine will invoke this callback in order to consume the
 * execution result (i.e. return value) of the last executed command.
 *
 * This callback is registered later via vedis_config() using VEDIS_CONFIG_OUTPUT_CONSUMER
 * as a configuration option. 
 */
static int command_result_render(vedis_value *pResult,void *pUnused /* userdata */)
{
	const char *zResult = 0;
	if( vedis_value_is_null(pResult) ){
		zResult = "<null>";
	}else if( vedis_value_is_array(pResult) ){
		struct array_rend sRend = { 1 , 0 };
		/* Command return an array, render it */
		vedis_array_walk(pResult,array_render,&sRend);
	}else{
		/* Explicitly cast the result to a null terminated string */
		zResult = vedis_value_to_string(pResult,0);
	}
	if( zResult ){
		puts(zResult);
	}
	return VEDIS_OK;
}
/* Vedis shell */
int main(int argc,char **argv)
{
	char zBuf[4096],*zPtr; /* Read buffer */
	vedis *pStore;         /* Vedis handle */
	int rc;

	/* Create our datastore */
	rc = vedis_open(&pStore,argc > 1 ? argv[1] /* An on-disk data store */ : ":mem:" /* An in-memory data store*/);
	if( rc != VEDIS_OK ){
		/* Seriously? */
		Fatal("Vedis is running out of memory");
	}

	/* Register the result (command return value) consumer callback */
	vedis_config(pStore,VEDIS_CONFIG_OUTPUT_CONSUMER,command_result_render,0 /* userdata */);
	
	/* Register the atexit() callback */
	atexit(vedis_exit);
	
	/* Start the shell */
	puts(zBanner);
	
	for(;;){
		
		fputs("vedis>",stdout);
		zPtr = fgets(zBuf,sizeof(zBuf),stdin);
		if( !zPtr || isBlank(zBuf,sizeof(zBuf)) ){
			/* Blank line - exit */
			puts("Exiting...comitting the transaction");
			break;
		}

		/* Exectute the command */
		rc = vedis_exec(pStore,zBuf,-1);
		if( rc != VEDIS_OK ){
			/* Error during execution. Extract the error log */
			const char *zErr;
			int nLen;
			vedis_config(pStore,VEDIS_CONFIG_ERR_LOG,&zErr,&nLen);
			if( nLen > 0 ){
				puts(zErr);
			}
			if( rc != VEDIS_UNKNOWN /* Unknown command */){
				/* Exit immediately */
				break;
			}
		}
		
	}/* for(;;) */

	/* Auto-commit and close the vedis handle */
	vedis_close(pStore);
	return 0;
}
/*
 * Array walker callback: Output array fields.
 *
 * This function is passed to the array_walk() interface which is
 * invoked for each array entry.
 */
static int array_render(vedis_value *pEntry,void *pUserdata)
{
	struct array_rend *pRend = (struct array_rend *)pUserdata;
	const char *zValue;
	int nByte;
	if( vedis_value_is_null(pEntry) ){
		zValue = "<null>";
		nByte = (int)sizeof("<null>") - 1;
	}else{
		/* Extract entry contents */
		zValue = vedis_value_to_string(pEntry,&nByte);
	}
	printf("%d) %.*s\n",++pRend->cnt,nByte,zValue);
	return VEDIS_OK;
}

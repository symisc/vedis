/*
 * Compile this file together with the Vedis datastore engine source code
 * to generate the executable. For example: 
 *  gcc -W -Wall -O6 vedis_intro.c vedis.c -o vedis_intro
*/
/*
 * This simple program is a quick introduction on how to embed and start
 * experimenting with Vedis without having to do a lot of tedious
 * reading and configuration.
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
/* $SymiscID: vedis_intro.c v1.0 Win7 2013-09-12 02:05 stable <chm@symisc.net> $ */
/* 
 * Make sure you have the latest release of Vedis from:
 *  http://vedis.symisc.net/downloads.html
 */
#include <stdio.h>  /* puts() */
#include <stdlib.h> /* exit() */
/* Make sure this header file is available.*/
#include "vedis.h"
/*
 * Banner.
 */
static const char zBanner[] = {
	"============================================================\n"
	"Vedis Command Execution Intro                               \n"
	"                                    http://vedis.symisc.net/\n"
	"============================================================\n"
};
/*
 * Extract the datastore error log and exit.
 */
static void Fatal(vedis *pStore,const char *zMsg)
{
	if( pStore ){
		const char *zErr;
		int iLen = 0; /* Stupid cc warning */

		/* Extract the datastore error log */
		vedis_config(pStore,VEDIS_CONFIG_ERR_LOG,&zErr,&iLen);
		if( iLen > 0 ){
			/* Output the error log */
			puts(zErr); /* Always null terminated */
		}
	}else{
		if( zMsg ){
			puts(zMsg);
		}
	}
	/* Manually shutdown the library */
	vedis_lib_shutdown();
	/* Exit immediately */
	exit(0);
}

int main(int argc,char *argv[])
{
	vedis *pStore;            /* Vedis handle */
	vedis_value *pResult;     /* Return value of the last executed command */
	int rc;

	puts(zBanner);

	/* Create our datastore */
	rc = vedis_open(&pStore,argc > 1 ? argv[1] /* On-disk DB */ : ":mem:" /* In-mem DB */);
	if( rc != VEDIS_OK ){
		Fatal(0,"Out of memory");
	}
	
	/* Execute the simplest command */
	rc = vedis_exec(pStore,"SET test 'Hello World'",-1);
	if( rc != VEDIS_OK ){
		/* Seriously? */
		Fatal(pStore,0);
	}

	/* Another simple command (Multiple set) */
	rc = vedis_exec(pStore,"MSET username james age 27 mail dude@example.com",-1);
	if( rc != VEDIS_OK ){
		Fatal(pStore,0);
	}

	/* A configuration hashtable */
	rc = vedis_exec(pStore,"HSET config path '/usr/local/etc'",-1);
	if( rc != VEDIS_OK ){
		Fatal(pStore,0);
	}
	
	/* A quite complex command (Multiple hash set) using foreign data */
	rc = vedis_exec_fmt(pStore,
		"HMSET config pid %d user %s os %s scm %s",
		1024 /* pid */,
		"dean", /* user */ 
		"FreeBSD", /* OS */
		"Git" /* SCM */
		);
	if( rc != VEDIS_OK ){
		Fatal(pStore,0);
	}

	puts("Insertion..OK");
	
	/* Fetch some data */
	
	vedis_exec(pStore,"GET test",-1);
	/* Extract the return value of the last executed command (i.e. GET test) " */
	rc = vedis_exec_result(pStore,&pResult);
	if( rc != VEDIS_OK ){
		/* Seriously? */
		Fatal(pStore,0);
	}else{
		const char *zResponse;
		/* Cast the vedis object to a string */
		zResponse = vedis_value_to_string(pResult,0);
		/* Output */
		printf(" test ==> %s\n",zResponse); /* test ==> 'Hello world' */
	}

	vedis_exec(pStore,"GET mail",-1);
	/* 'GET mail' return value */
	rc = vedis_exec_result(pStore,&pResult);
	if( rc != VEDIS_OK ){
		Fatal(pStore,0);
	}else{
		const char *zResponse;
		/* Cast the vedis object to a string */
		zResponse = vedis_value_to_string(pResult,0);
		/* Output */
		printf(" mail ==> %s\n",zResponse); /* Should be 'dude@example.com' */
	}

	/* 
	 * A command which return multiple value in array.
	 */
	vedis_exec(pStore,"MGET username age",-1); /* james 27*/
	
	vedis_exec_result(pStore,&pResult);
	
	if( vedis_value_is_array(pResult) ){
		/* Iterate over the elements of the returned array */
		vedis_value *pEntry;
		puts("Array entries:");
		while((pEntry = vedis_array_next_elem(pResult)) != 0 ){
			const char *zEntry;
			/* Cast to string and output */
			zEntry = vedis_value_to_string(pEntry,0);
			/* Output */
			printf("\t%s\n",zEntry);
		}
	}
	
	/* Extract hashtable data (i.e. pid field) */
	 vedis_exec(pStore,"HGET config pid",-1); /* 1024 */
	
	vedis_exec_result(pStore,&pResult);
	{
		int pid;
		/* Cast to integer */
		pid = vedis_value_to_int(pResult);
		/* Output */
		printf("pid ==> %d\n",pid); /* Should be 1024 */
	}

	/* All hashtable data */
	vedis_exec(pStore,"HVALS config",-1); /* All 'config' values */
	
	vedis_exec_result(pStore,&pResult);
	
	if( vedis_value_is_array(pResult) ){
		/* Iterate over the elements of the returned array */
		vedis_value *pEntry;
		puts("Array entries:");
		while((pEntry = vedis_array_next_elem(pResult)) != 0 ){
			const char *zEntry;
			/* Cast to string and output */
			zEntry = vedis_value_to_string(pEntry,0);
			/* Output */
			printf("\t%s\n",zEntry);
		}
	}
	puts("All done!");

	/* Auto-commit the transaction and close our datastore */
	vedis_close(pStore);
	return 0;
}

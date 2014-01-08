/*
 * Compile this file together with the Vedis datastore engine source code
 * to generate the executable. For example: 
 *  gcc -W -Wall -O6 vedis_huge_insert.c vedis.c -o vedis_huge 
*/
/*
 * This simple program is a quick introduction on how to embed and start
 * experimenting with Vedis without having to do a lot of tedious
 * reading and configuration.
 *
 * This program stores over 100000 random records (Dummy data of length 32 + random key of length 14)
 * in the given datastore. The random keys are obtained using the powerful
 * [vedis_util_random_string()] interface.
 * Feel free to raise this number to 1 million or whatever value you want
 * and do your own benchmark.
 * Note that if you generate 1 million records, you'll end up with a 560 MB datastore
 * file with garbage data.
 * Only Key/Value store interfaces (vedis_kv_store()) are used in this example.
 *
 * Typical usage of this program:
 *
 *  ./vedis_huge test.db
 *
 * To start an in-memory datastore, invoke the program without arguments as follows:
 *
 *  ./vedis_huge 
 *
 * For an introduction to the Vedis C/C++ interface, please refer to:
 *        http://vedis.symisc.net/api_intro.html
 * For the full C/C++ API reference guide, please refer to:
 *        http://vedis.symisc.net/c_api.html
 * Vedis in 5 Minutes or Less:
 *        http://vedis.symisc.net/intro.html
 * Built-in Vedis commands:
 *        http://vedis.symisc.net/commands.html
 */
/* $SymiscID: vedis_huge_insert.c v1.0 Solaris 2013-09-17 21:17 stable <chm@symisc.net> $ */
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
	"Vedis Huge Random Insertions                                \n"
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
			/* Output the DB error log */
			puts(zErr); /* Always null termniated */
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
/* Forward declaration: Data consumer callback */
static int DataConsumerCallback(const void *pData,unsigned int nDatalen,void *pUserData /* Unused */);
/*
 * Maximum records to be inserted in our datastore.
 */
#define MAX_RECORDS 100000

int main(int argc,char *argv[])
{
	vedis *pStore;                /* Database handle */
	char zKey[14];               /* Random generated key */
	char zData[32];              /* Dummy data */
	int i,rc;

	puts(zBanner);

	/* Open our datastore */
	rc = vedis_open(&pStore,argc > 1 ? argv[1] /* On-disk DB */ : ":mem:" /* In-mem DB */);
	if( rc != VEDIS_OK ){
		Fatal(0,"Out of memory");
	}
	
	printf("Starting insertions of %d random records...\n",MAX_RECORDS);
	
	/* Start the random insertions */
	for( i = 0 ; i < MAX_RECORDS; ++i ){
		
		/* Genearte the random key first */
		vedis_util_random_string(pStore,zKey,sizeof(zKey));

		/* Perform the insertion */
		rc = vedis_kv_store(pStore,zKey,sizeof(zKey),zData,sizeof(zData));
		if( rc != VEDIS_OK ){
			/* Something goes wrong */
			break;
		}

		if( i == 79125 ){
			/* Insert a sentinel record */

			/* time(&tt); pTm = localtime(&tt); ... */
			vedis_kv_store_fmt(pStore,"sentinel",-1,"I'm a sentinel record inserted on %d:%d:%d\n",14,15,18); /* Dummy time */
		}
	}
	
	/* If we are OK, then manually commit the transaction */
	if( rc == VEDIS_OK ){
		/* 
		 * In fact, a call to vedis_commit() is not necessary since Vedis
		 * will automatically commit the transaction during a call to vedis_close().
		 */
		rc = vedis_commit(pStore);
		if( rc != VEDIS_OK ){
			/* Rollback the transaction */
			rc = vedis_rollback(pStore);
		}
	}
	
	if( rc != VEDIS_OK ){
		/* Something goes wrong, extract the datastore error log and exit */
		Fatal(pStore,0);
	}
	puts("Done...Fetching the 'sentinel' record: ");

	/* Fetch the sentinel */
	rc = vedis_kv_fetch_callback(pStore,"sentinel",-1,DataConsumerCallback,0);
	if( rc != VEDIS_OK ){
		/* Can't happen */
		Fatal(0,"Sentinel record not found");
	}

	/* All done, close our datastore */
	vedis_close(pStore);
	return 0;
}

#ifdef __WINNT__
#include <Windows.h>
#else
/* Assume UNIX */
#include <unistd.h>
#endif
/*
 * The following define is used by the UNIX build process and have
 * no particular meaning on windows.
 */
#ifndef STDOUT_FILENO
#define STDOUT_FILENO	1
#endif
/*
 * Data consumer callback [vedis_kv_fetch_callback(), vedis_kv_cursor_key_callback(), etc.).
 * 
 * Rather than allocating a static or dynamic buffer (Inefficient scenario for large data).
 * The caller simply need to supply a consumer callback which is responsible of consuming
 * the record data perhaps redirecting it (i.e. Record data) to its standard output (STDOUT),
 * disk file, connected peer and so forth.
 * Depending on how large the extracted data, the callback may be invoked more than once.
 */
static int DataConsumerCallback(const void *pData,unsigned int nDatalen,void *pUserData /* Unused */)
{
#ifdef __WINNT__
	BOOL rc;
	rc = WriteFile(GetStdHandle(STD_OUTPUT_HANDLE),pData,(DWORD)nDatalen,0,0);
	if( !rc ){
		/* Abort processing */
		return VEDIS_ABORT;
	}
#else
	ssize_t nWr;
	nWr = write(STDOUT_FILENO,pData,nDatalen);
	if( nWr < 0 ){
		/* Abort processing */
		return VEDIS_ABORT;
	}
#endif /* __WINT__ */
	/* All done, data was redirected to STDOUT */
	return VEDIS_OK;
}

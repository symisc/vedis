/*
 * Symisc Vedis: A Highly Efficient Embeddable Data Store Engine.
 * Copyright (C) 2013, Symisc Systems http://vedis.symisc.net/
 * Version 1.2.6
 * For information on licensing, redistribution of this file, and for a DISCLAIMER OF ALL WARRANTIES
 * please contact Symisc Systems via:
 *       legal@symisc.net
 *       licensing@symisc.net
 *       contact@symisc.net
 * or visit:
 *      http://vedis.symisc.net/
 */
/*
 * Copyright (C) 2013 Symisc Systems, S.U.A.R.L [M.I.A.G Mrad Chems Eddine <chm@symisc.net>].
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Redistributions in any form must be accompanied by information on
 *    how to obtain complete source code for the Vedis engine and any 
 *    accompanying software that uses the Vedis engine software.
 *    The source code must either be included in the distribution
 *    or be available for no more than the cost of distribution plus
 *    a nominal fee, and must be freely redistributable under reasonable
 *    conditions. For an executable file, complete source code means
 *    the source code for all modules it contains.It does not include
 *    source code for modules or files that typically accompany the major
 *    components of the operating system on which the executable file runs.
 *
 * THIS SOFTWARE IS PROVIDED BY SYMISC SYSTEMS ``AS IS'' AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, OR
 * NON-INFRINGEMENT, ARE DISCLAIMED.  IN NO EVENT SHALL SYMISC SYSTEMS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
 * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/*
 * $SymiscID: vedis.c v1.2.6 Unix|Win32/64 2013-09-15 23:42:22 stable <chm@symisc.net> $ 
 */
/* This file is an amalgamation of many separate C source files from vedis version 1.2.6
 * By combining all the individual C code files into this single large file, the entire code
 * can be compiled as a single translation unit. This allows many compilers to do optimization's
 * that would not be possible if the files were compiled separately. Performance improvements
 * are commonly seen when vedis is compiled as a single translation unit.
 *
 * This file is all you need to compile vedis. To use vedis in other programs, you need
 * this file and the "vedis.h" header file that defines the programming interface to the 
 * vedis engine.(If you do not have the "vedis.h" header file at hand, you will find
 * a copy embedded within the text of this file.Search for "Header file: <vedis.h>" to find
 * the start of the embedded vedis.h header file.) Additional code files may be needed if
 * you want a wrapper to interface vedis with your choice of programming language.
 * To get the official documentation, please visit http://vedis.symisc.net/
 */
 /*
  * Make the sure the following directive is defined in the amalgamation build.
  */
 #ifndef VEDIS_AMALGAMATION
 #define VEDIS_AMALGAMATION
 #endif /* VEDIS_AMALGAMATION */
/*
 * Embedded header file for vedis: <vedis.h>
 */
/*
 * ----------------------------------------------------------
 * File: vedis.h
 * MD5: 935b32c31005cfdaa53305ce2d582dbf
 * ----------------------------------------------------------
 */
/* This file was automatically generated.  Do not edit (Except for compile time directives)! */ 
#ifndef  _VEDIS_H_
#define  _VEDIS_H_
/*
 * Symisc Vedis: A Highly Efficient Embeddable Data Store Engine.
 * Copyright (C) 2013, Symisc Systems http://vedis.symisc.net/
 * Version 1.2.6
 * For information on licensing, redistribution of this file, and for a DISCLAIMER OF ALL WARRANTIES
 * please contact Symisc Systems via:
 *       legal@symisc.net
 *       licensing@symisc.net
 *       contact@symisc.net
 * or visit:
 *      http://vedis.symisc.net/
 */
/*
 * Copyright (C) 2013 Symisc Systems, S.U.A.R.L [M.I.A.G Mrad Chems Eddine <chm@symisc.net>].
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Redistributions in any form must be accompanied by information on
 *    how to obtain complete source code for the Vedis engine and any 
 *    accompanying software that uses the Vedis engine software.
 *    The source code must either be included in the distribution
 *    or be available for no more than the cost of distribution plus
 *    a nominal fee, and must be freely redistributable under reasonable
 *    conditions. For an executable file, complete source code means
 *    the source code for all modules it contains.It does not include
 *    source code for modules or files that typically accompany the major
 *    components of the operating system on which the executable file runs.
 *
 * THIS SOFTWARE IS PROVIDED BY SYMISC SYSTEMS ``AS IS'' AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, OR
 * NON-INFRINGEMENT, ARE DISCLAIMED.  IN NO EVENT SHALL SYMISC SYSTEMS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
 * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/* Make sure we can call this stuff from C++ */
#ifdef __cplusplus
extern "C" { 
#endif
 /* $SymiscID: vedis.h v1.2 Unix 2013-09-16 00:38 stable <chm@symisc.net> $ */
#include <stdarg.h> /* needed for the definition of va_list */
/*
 * Compile time engine version, signature, identification in the symisc source tree
 * and copyright notice.
 * Each macro have an equivalent C interface associated with it that provide the same
 * information but are associated with the library instead of the header file.
 * Refer to [vedis_lib_version()], [vedis_lib_signature()], [vedis_lib_ident()] and
 * [vedis_lib_copyright()] for more information.
 */
/*
 * The VEDIS_VERSION C preprocessor macroevaluates to a string literal
 * that is the vedis version in the format "X.Y.Z" where X is the major
 * version number and Y is the minor version number and Z is the release
 * number.
 */
#define VEDIS_VERSION "1.2.6"
/*
 * The VEDIS_VERSION_NUMBER C preprocessor macro resolves to an integer
 * with the value (X*1000000 + Y*1000 + Z) where X, Y, and Z are the same
 * numbers used in [VEDIS_VERSION].
 */
#define VEDIS_VERSION_NUMBER 1002006
/*
 * The VEDIS_SIG C preprocessor macro evaluates to a string
 * literal which is the public signature of the vedis engine.
 */
#define VEDIS_SIG "vedis/1.2.6"
/*
 * Vedis identification in the Symisc source tree:
 * Each particular check-in of a particular software released
 * by symisc systems have an unique identifier associated with it.
 * This macro hold the one associated with vedis.
 */
#define VEDIS_IDENT "vedis:e361b2f3d4a71ac17e9f2ac1876232a13467dea1"
/*
 * Copyright notice.
 * If you have any questions about the licensing situation, please
 * visit http://vedis.symisc.net/licensing.html
 * or contact Symisc Systems via:
 *   legal@symisc.net
 *   licensing@symisc.net
 *   contact@symisc.net
 */
#define VEDIS_COPYRIGHT "Copyright (C) Symisc Systems, S.U.A.R.L [Mrad Chems Eddine <chm@symisc.net>] 2013, http://vedis.symisc.net/"
/* Forward declaration to public objects */
typedef struct vedis_io_methods vedis_io_methods;
typedef struct vedis_kv_methods vedis_kv_methods;
typedef struct vedis_kv_engine vedis_kv_engine;
typedef struct vedis_context vedis_context;
typedef struct vedis_value vedis_value;
typedef struct vedis_vfs vedis_vfs;
typedef struct vedis vedis;
/*
 * ------------------------------
 * Compile time directives
 * ------------------------------
 * For most purposes, Vedis can be built just fine using the default compilation options.
 * However, if required, the compile-time options documented below can be used to omit Vedis
 * features (resulting in a smaller compiled library size) or to change the default values
 * of some parameters.
 * Every effort has been made to ensure that the various combinations of compilation options
 * work harmoniously and produce a working library.
 *
 * VEDIS_ENABLE_THREADS
 *  This option controls whether or not code is included in Vedis to enable it to operate
 *  safely in a multithreaded environment. The default is not. All mutexing code is omitted
 *  and it is unsafe to use Vedis in a multithreaded program. When compiled with the
 *  VEDIS_ENABLE_THREADS directive enabled, Vedis can be used in a multithreaded program
 *  and it is safe to share the same virtual machine and engine handle between two or more threads.
 *  The value of VEDIS_ENABLE_THREADS can be determined at run-time using the vedis_lib_is_threadsafe()
 *  interface.
 *  When Vedis has been compiled with threading support then the threading mode can be altered
 * at run-time using the vedis_lib_config() interface together with one of these verbs:
 *    VEDIS_LIB_CONFIG_THREAD_LEVEL_SINGLE
 *    VEDIS_LIB_CONFIG_THREAD_LEVEL_MULTI
 *  Platforms others than Windows and UNIX systems must install their own mutex subsystem via 
 *  vedis_lib_config() with a configuration verb set to VEDIS_LIB_CONFIG_USER_MUTEX.
 *  Otherwise the library is not threadsafe.
 *  Note that you must link Vedis with the POSIX threads library under UNIX systems (i.e: -lpthread).
 *
 */
/* Symisc public definitions */
#if !defined(SYMISC_STANDARD_DEFS)
#define SYMISC_STANDARD_DEFS
#if defined (_WIN32) || defined (WIN32) || defined(__MINGW32__) || defined (_MSC_VER) || defined (_WIN32_WCE)
/* Windows Systems */
#if !defined(__WINNT__)
#define __WINNT__
#endif 
/*
 * Determine if we are dealing with WindowsCE - which has a much
 * reduced API.
 */
#if defined(_WIN32_WCE)
#ifndef __WIN_CE__
#define __WIN_CE__
#endif /* __WIN_CE__ */
#endif /* _WIN32_WCE */
#else
/*
 * By default we will assume that we are compiling on a UNIX systems.
 * Otherwise the OS_OTHER directive must be defined.
 */
#if !defined(OS_OTHER)
#if !defined(__UNIXES__)
#define __UNIXES__
#endif /* __UNIXES__ */
#else
#endif /* OS_OTHER */
#endif /* __WINNT__/__UNIXES__ */
#if defined(_MSC_VER) || defined(__BORLANDC__)
typedef signed __int64     sxi64; /* 64 bits(8 bytes) signed int64 */
typedef unsigned __int64   sxu64; /* 64 bits(8 bytes) unsigned int64 */
#else
typedef signed long long int   sxi64; /* 64 bits(8 bytes) signed int64 */
typedef unsigned long long int sxu64; /* 64 bits(8 bytes) unsigned int64 */
#endif /* _MSC_VER */
/* Signature of the consumer routine */
typedef int (*ProcConsumer)(const void *, unsigned int, void *);
/* Forward reference */
typedef struct SyMutexMethods SyMutexMethods;
typedef struct SyMemMethods SyMemMethods;
typedef struct SyString SyString;
typedef struct syiovec syiovec;
typedef struct SyMutex SyMutex;
typedef struct Sytm Sytm;
/* Scatter and gather array. */
struct syiovec
{
#if defined (__WINNT__)
	/* Same fields type and offset as WSABUF structure defined one winsock2 header */
	unsigned long nLen;
	char *pBase;
#else
	void *pBase;
	unsigned long nLen;
#endif
};
struct SyString
{
	const char *zString;  /* Raw string (may not be null terminated) */
	unsigned int nByte;   /* Raw string length */
};
/* Time structure. */
struct Sytm
{
  int tm_sec;     /* seconds (0 - 60) */
  int tm_min;     /* minutes (0 - 59) */
  int tm_hour;    /* hours (0 - 23) */
  int tm_mday;    /* day of month (1 - 31) */
  int tm_mon;     /* month of year (0 - 11) */
  int tm_year;    /* year + 1900 */
  int tm_wday;    /* day of week (Sunday = 0) */
  int tm_yday;    /* day of year (0 - 365) */
  int tm_isdst;   /* is summer time in effect? */
  char *tm_zone;  /* abbreviation of timezone name */
  long tm_gmtoff; /* offset from UTC in seconds */
};
/* Convert a tm structure (struct tm *) found in <time.h> to a Sytm structure */
#define STRUCT_TM_TO_SYTM(pTM, pSYTM) \
	(pSYTM)->tm_hour = (pTM)->tm_hour;\
	(pSYTM)->tm_min	 = (pTM)->tm_min;\
	(pSYTM)->tm_sec	 = (pTM)->tm_sec;\
	(pSYTM)->tm_mon	 = (pTM)->tm_mon;\
	(pSYTM)->tm_mday = (pTM)->tm_mday;\
	(pSYTM)->tm_year = (pTM)->tm_year + 1900;\
	(pSYTM)->tm_yday = (pTM)->tm_yday;\
	(pSYTM)->tm_wday = (pTM)->tm_wday;\
	(pSYTM)->tm_isdst = (pTM)->tm_isdst;\
	(pSYTM)->tm_gmtoff = 0;\
	(pSYTM)->tm_zone = 0;

/* Convert a SYSTEMTIME structure (LPSYSTEMTIME: Windows Systems only ) to a Sytm structure */
#define SYSTEMTIME_TO_SYTM(pSYSTIME, pSYTM) \
	 (pSYTM)->tm_hour = (pSYSTIME)->wHour;\
	 (pSYTM)->tm_min  = (pSYSTIME)->wMinute;\
	 (pSYTM)->tm_sec  = (pSYSTIME)->wSecond;\
	 (pSYTM)->tm_mon  = (pSYSTIME)->wMonth - 1;\
	 (pSYTM)->tm_mday = (pSYSTIME)->wDay;\
	 (pSYTM)->tm_year = (pSYSTIME)->wYear;\
	 (pSYTM)->tm_yday = 0;\
	 (pSYTM)->tm_wday = (pSYSTIME)->wDayOfWeek;\
	 (pSYTM)->tm_gmtoff = 0;\
	 (pSYTM)->tm_isdst = -1;\
	 (pSYTM)->tm_zone = 0;

/* Dynamic memory allocation methods. */
struct SyMemMethods 
{
	void * (*xAlloc)(unsigned int);          /* [Required:] Allocate a memory chunk */
	void * (*xRealloc)(void *, unsigned int); /* [Required:] Re-allocate a memory chunk */
	void   (*xFree)(void *);                 /* [Required:] Release a memory chunk */
	unsigned int  (*xChunkSize)(void *);     /* [Optional:] Return chunk size */
	int    (*xInit)(void *);                 /* [Optional:] Initialization callback */
	void   (*xRelease)(void *);              /* [Optional:] Release callback */
	void  *pUserData;                        /* [Optional:] First argument to xInit() and xRelease() */
};
/* Out of memory callback signature. */
typedef int (*ProcMemError)(void *);
/* Mutex methods. */
struct SyMutexMethods 
{
	int (*xGlobalInit)(void);		/* [Optional:] Global mutex initialization */
	void  (*xGlobalRelease)(void);	/* [Optional:] Global Release callback () */
	SyMutex * (*xNew)(int);	        /* [Required:] Request a new mutex */
	void  (*xRelease)(SyMutex *);	/* [Optional:] Release a mutex  */
	void  (*xEnter)(SyMutex *);	    /* [Required:] Enter mutex */
	int (*xTryEnter)(SyMutex *);    /* [Optional:] Try to enter a mutex */
	void  (*xLeave)(SyMutex *);	    /* [Required:] Leave a locked mutex */
};
#if defined (_MSC_VER) || defined (__MINGW32__) ||  defined (__GNUC__) && defined (__declspec)
#define SX_APIIMPORT	__declspec(dllimport)
#define SX_APIEXPORT	__declspec(dllexport)
#else
#define	SX_APIIMPORT
#define	SX_APIEXPORT
#endif
/* Standard return values from Symisc public interfaces */
#define SXRET_OK       0      /* Not an error */	
#define SXERR_MEM      (-1)   /* Out of memory */
#define SXERR_IO       (-2)   /* IO error */
#define SXERR_EMPTY    (-3)   /* Empty field */
#define SXERR_LOCKED   (-4)   /* Locked operation */
#define SXERR_ORANGE   (-5)   /* Out of range value */
#define SXERR_NOTFOUND (-6)   /* Item not found */
#define SXERR_LIMIT    (-7)   /* Limit reached */
#define SXERR_MORE     (-8)   /* Need more input */
#define SXERR_INVALID  (-9)   /* Invalid parameter */
#define SXERR_ABORT    (-10)  /* User callback request an operation abort */
#define SXERR_EXISTS   (-11)  /* Item exists */
#define SXERR_SYNTAX   (-12)  /* Syntax error */
#define SXERR_UNKNOWN  (-13)  /* Unknown error */
#define SXERR_BUSY     (-14)  /* Busy operation */
#define SXERR_OVERFLOW (-15)  /* Stack or buffer overflow */
#define SXERR_WILLBLOCK (-16) /* Operation will block */
#define SXERR_NOTIMPLEMENTED  (-17) /* Operation not implemented */
#define SXERR_EOF      (-18) /* End of input */
#define SXERR_PERM     (-19) /* Permission error */
#define SXERR_NOOP     (-20) /* No-op */	
#define SXERR_FORMAT   (-21) /* Invalid format */
#define SXERR_NEXT     (-22) /* Not an error */
#define SXERR_OS       (-23) /* System call return an error */
#define SXERR_CORRUPT  (-24) /* Corrupted pointer */
#define SXERR_CONTINUE (-25) /* Not an error: Operation in progress */
#define SXERR_NOMATCH  (-26) /* No match */
#define SXERR_RESET    (-27) /* Operation reset */
#define SXERR_DONE     (-28) /* Not an error */
#define SXERR_SHORT    (-29) /* Buffer too short */
#define SXERR_PATH     (-30) /* Path error */
#define SXERR_TIMEOUT  (-31) /* Timeout */
#define SXERR_BIG      (-32) /* Too big for processing */
#define SXERR_RETRY    (-33) /* Retry your call */
#define SXERR_IGNORE   (-63) /* Ignore */
#endif /* SYMISC_PUBLIC_DEFS */
/* 
 * Marker for exported interfaces. 
 */
#define VEDIS_APIEXPORT SX_APIEXPORT
/* Standard Vedis return values */
#define VEDIS_OK      SXRET_OK      /* Successful result */
/* Beginning of error codes */
#define VEDIS_NOMEM    SXERR_MEM     /* Out of memory */
#define VEDIS_ABORT    SXERR_ABORT   /* Another thread have released this instance */
#define VEDIS_IOERR    SXERR_IO      /* IO error */
#define VEDIS_CORRUPT  SXERR_CORRUPT /* Corrupt pointer */
#define VEDIS_LOCKED   SXERR_LOCKED  /* Forbidden Operation */ 
#define VEDIS_BUSY	 SXERR_BUSY    /* The database file is locked */
#define VEDIS_DONE	 SXERR_DONE    /* Operation done */
#define VEDIS_PERM     SXERR_PERM    /* Permission error */
#define VEDIS_NOTIMPLEMENTED SXERR_NOTIMPLEMENTED /* Method not implemented by the underlying Key/Value storage engine */
#define VEDIS_NOTFOUND SXERR_NOTFOUND /* No such record */
#define VEDIS_NOOP     SXERR_NOOP     /* No such method */
#define VEDIS_INVALID  SXERR_INVALID  /* Invalid parameter */
#define VEDIS_EOF      SXERR_EOF      /* End Of Input */
#define VEDIS_UNKNOWN  SXERR_UNKNOWN  /* Unknown configuration option */
#define VEDIS_LIMIT    SXERR_LIMIT    /* Database limit reached */
#define VEDIS_EXISTS   SXERR_EXISTS   /* Record exists */
#define VEDIS_EMPTY    SXERR_EMPTY    /* Empty record */
#define VEDIS_FULL        (-73)       /* Full database (unlikely) */
#define VEDIS_CANTOPEN    (-74)       /* Unable to open the database file */
#define VEDIS_READ_ONLY   (-75)       /* Read only Key/Value storage engine */
#define VEDIS_LOCKERR     (-76)       /* Locking protocol error */
/* end-of-error-codes */
/*
 * If compiling for a processor that lacks floating point
 * support, substitute integer for floating-point.
 */
#ifdef VEDIS_OMIT_FLOATING_POINT
typedef sxi64 vedis_real;
#else
typedef double vedis_real;
#endif
typedef sxi64 vedis_int64;
/*
 * Vedis Configuration Commands.
 *
 * The following set of constants are the available configuration verbs that can
 * be used by the host-application to configure a Vedis datastore handle.
 * These constants must be passed as the second argument to [vedis_config()].
 *
 * Each options require a variable number of arguments.
 * The [vedis_config()] interface will return VEDIS_OK on success, any other
 * return value indicates failure.
 * For a full discussion on the configuration verbs and their expected 
 * parameters, please refer to this page:
 *      http://vedis.symisc.net/c_api/vedis_config.html
 */
#define VEDIS_CONFIG_ERR_LOG             1  /* TWO ARGUMENTS: const char **pzBuf, int *pLen */
#define VEDIS_CONFIG_MAX_PAGE_CACHE      2  /* ONE ARGUMENT: int nMaxPage */
#define VEDIS_CONFIG_KV_ENGINE           4  /* ONE ARGUMENT: const char *zKvName */
#define VEDIS_CONFIG_DISABLE_AUTO_COMMIT 5  /* NO ARGUMENTS */
#define VEDIS_CONFIG_GET_KV_NAME         6  /* ONE ARGUMENT: const char **pzPtr */
#define VEDIS_CONFIG_DUP_EXEC_VALUE      7  /* ONE ARGUMENT: vedis_value **ppOut */
#define VEDIS_CONFIG_RELEASE_DUP_VALUE   8  /* ONE ARGUMENT: vedis_value *pIn */
#define VEDIS_CONFIG_OUTPUT_CONSUMER     9  /* TWO ARGUMENTS: int (*xConsumer)(vedis_value *pOut,void *pUserdata), void *pUserdata */
/*
 * Storage engine configuration commands.
 *
 * The following set of constants are the available configuration verbs that can
 * be used by the host-application to configure the underlying storage engine (i.e Hash, B+tree, R+tree).
 * These constants must be passed as the first argument to [vedis_kv_config()].
 * Each options require a variable number of arguments.
 * The [vedis_kv_config()] interface will return VEDIS_OK on success, any other return
 * value indicates failure.
 * For a full discussion on the configuration verbs and their expected parameters, please
 * refer to this page:
 *      http://vedis.symisc.net/c_api/vedis_kv_config.html
 */
#define VEDIS_KV_CONFIG_HASH_FUNC  1 /* ONE ARGUMENT: unsigned int (*xHash)(const void *,unsigned int) */
#define VEDIS_KV_CONFIG_CMP_FUNC   2 /* ONE ARGUMENT: int (*xCmp)(const void *,const void *,unsigned int) */
/*
 * Global Library Configuration Commands.
 *
 * The following set of constants are the available configuration verbs that can
 * be used by the host-application to configure the whole library.
 * These constants must be passed as the first argument to [vedis_lib_config()].
 *
 * Each options require a variable number of arguments.
 * The [vedis_lib_config()] interface will return VEDIS_OK on success, any other return
 * value indicates failure.
 * Notes:
 * The default configuration is recommended for most applications and so the call to
 * [vedis_lib_config()] is usually not necessary. It is provided to support rare 
 * applications with unusual needs. 
 * The [vedis_lib_config()] interface is not threadsafe. The application must insure that
 * no other [vedis_*()] interfaces are invoked by other threads while [vedis_lib_config()]
 * is running. Furthermore, [vedis_lib_config()] may only be invoked prior to library
 * initialization using [vedis_lib_init()] or [vedis_init()] or after shutdown
 * by [vedis_lib_shutdown()]. If [vedis_lib_config()] is called after [vedis_lib_init()]
 * or [vedis_init()] and before [vedis_lib_shutdown()] then it will return VEDIS_LOCKED.
 * For a full discussion on the configuration verbs and their expected parameters, please
 * refer to this page:
 *      http://vedis.symisc.net/c_api/vedis_lib.html
 */
#define VEDIS_LIB_CONFIG_USER_MALLOC            1 /* ONE ARGUMENT: const SyMemMethods *pMemMethods */ 
#define VEDIS_LIB_CONFIG_MEM_ERR_CALLBACK       2 /* TWO ARGUMENTS: int (*xMemError)(void *), void *pUserData */
#define VEDIS_LIB_CONFIG_USER_MUTEX             3 /* ONE ARGUMENT: const SyMutexMethods *pMutexMethods */ 
#define VEDIS_LIB_CONFIG_THREAD_LEVEL_SINGLE    4 /* NO ARGUMENTS */ 
#define VEDIS_LIB_CONFIG_THREAD_LEVEL_MULTI     5 /* NO ARGUMENTS */ 
#define VEDIS_LIB_CONFIG_VFS                    6 /* ONE ARGUMENT: const vedis_vfs *pVfs */
#define VEDIS_LIB_CONFIG_STORAGE_ENGINE         7 /* ONE ARGUMENT: vedis_kv_methods *pStorage */
#define VEDIS_LIB_CONFIG_PAGE_SIZE              8 /* ONE ARGUMENT: int iPageSize */
/*
 * Synchronization Type Flags
 *
 * When Vedis invokes the xSync() method of an [vedis_io_methods] object it uses
 * a combination of these integer values as the second argument.
 *
 * When the VEDIS_SYNC_DATAONLY flag is used, it means that the sync operation only
 * needs to flush data to mass storage.  Inode information need not be flushed.
 * If the lower four bits of the flag equal VEDIS_SYNC_NORMAL, that means to use normal
 * fsync() semantics. If the lower four bits equal VEDIS_SYNC_FULL, that means to use
 * Mac OS X style fullsync instead of fsync().
 */
#define VEDIS_SYNC_NORMAL        0x00002
#define VEDIS_SYNC_FULL          0x00003
#define VEDIS_SYNC_DATAONLY      0x00010
/*
 * File Locking Levels
 *
 * Vedis uses one of these integer values as the second
 * argument to calls it makes to the xLock() and xUnlock() methods
 * of an [vedis_io_methods] object.
 */
#define VEDIS_LOCK_NONE          0
#define VEDIS_LOCK_SHARED        1
#define VEDIS_LOCK_RESERVED      2
#define VEDIS_LOCK_PENDING       3
#define VEDIS_LOCK_EXCLUSIVE     4
/*
 * CAPIREF: OS Interface: Open File Handle
 *
 * An [vedis_file] object represents an open file in the [vedis_vfs] OS interface
 * layer.
 * Individual OS interface implementations will want to subclass this object by appending
 * additional fields for their own use. The pMethods entry is a pointer to an
 * [vedis_io_methods] object that defines methods for performing
 * I/O operations on the open file.
*/
typedef struct vedis_file vedis_file;
struct vedis_file {
  const vedis_io_methods *pMethods;  /* Methods for an open file. MUST BE FIRST */
};
/*
 * CAPIREF: OS Interface: File Methods Object
 *
 * Every file opened by the [vedis_vfs] xOpen method populates an
 * [vedis_file] object (or, more commonly, a subclass of the
 * [vedis_file] object) with a pointer to an instance of this object.
 * This object defines the methods used to perform various operations
 * against the open file represented by the [vedis_file] object.
 *
 * If the xOpen method sets the vedis_file.pMethods element 
 * to a non-NULL pointer, then the vedis_io_methods.xClose method
 * may be invoked even if the xOpen reported that it failed.  The
 * only way to prevent a call to xClose following a failed xOpen
 * is for the xOpen to set the vedis_file.pMethods element to NULL.
 *
 * The flags argument to xSync may be one of [VEDIS_SYNC_NORMAL] or
 * [VEDIS_SYNC_FULL]. The first choice is the normal fsync().
 * The second choice is a Mac OS X style fullsync. The [VEDIS_SYNC_DATAONLY]
 * flag may be ORed in to indicate that only the data of the file
 * and not its inode needs to be synced.
 *
 * The integer values to xLock() and xUnlock() are one of
 *
 * VEDIS_LOCK_NONE
 * VEDIS_LOCK_SHARED
 * VEDIS_LOCK_RESERVED
 * VEDIS_LOCK_PENDING
 * VEDIS_LOCK_EXCLUSIVE
 * 
 * xLock() increases the lock. xUnlock() decreases the lock.
 * The xCheckReservedLock() method checks whether any database connection,
 * either in this process or in some other process, is holding a RESERVED,
 * PENDING, or EXCLUSIVE lock on the file. It returns true if such a lock exists
 * and false otherwise.
 * 
 * The xSectorSize() method returns the sector size of the device that underlies
 * the file. The sector size is the minimum write that can be performed without
 * disturbing other bytes in the file.
 */
struct vedis_io_methods {
  int iVersion;                 /* Structure version number (currently 1) */
  int (*xClose)(vedis_file*);
  int (*xRead)(vedis_file*, void*, vedis_int64 iAmt, vedis_int64 iOfst);
  int (*xWrite)(vedis_file*, const void*, vedis_int64 iAmt, vedis_int64 iOfst);
  int (*xTruncate)(vedis_file*, vedis_int64 size);
  int (*xSync)(vedis_file*, int flags);
  int (*xFileSize)(vedis_file*, vedis_int64 *pSize);
  int (*xLock)(vedis_file*, int);
  int (*xUnlock)(vedis_file*, int);
  int (*xCheckReservedLock)(vedis_file*, int *pResOut);
  int (*xSectorSize)(vedis_file*);
};
/*
 * CAPIREF: OS Interface Object
 *
 * An instance of the vedis_vfs object defines the interface between
 * the Vedis core and the underlying operating system.  The "vfs"
 * in the name of the object stands for "Virtual File System".
 *
 * Only a single vfs can be registered within the Vedis core.
 * Vfs registration is done using the [vedis_lib_config()] interface
 * with a configuration verb set to VEDIS_LIB_CONFIG_VFS.
 * Note that Windows and UNIX (Linux, FreeBSD, Solaris, Mac OS X, etc.) users
 * does not have to worry about registering and installing a vfs since Vedis
 * come with a built-in vfs for these platforms that implements most the methods
 * defined below.
 *
 * Clients running on exotic systems (ie: Other than Windows and UNIX systems)
 * must register their own vfs in order to be able to use the Vedis library.
 *
 * The value of the iVersion field is initially 1 but may be larger in
 * future versions of Vedis. 
 *
 * The szOsFile field is the size of the subclassed [vedis_file] structure
 * used by this VFS. mxPathname is the maximum length of a pathname in this VFS.
 * 
 * At least szOsFile bytes of memory are allocated by Vedis to hold the [vedis_file]
 * structure passed as the third argument to xOpen. The xOpen method does not have to
 * allocate the structure; it should just fill it in. Note that the xOpen method must
 * set the vedis_file.pMethods to either a valid [vedis_io_methods] object or to NULL.
 * xOpen must do this even if the open fails. Vedis expects that the vedis_file.pMethods
 * element will be valid after xOpen returns regardless of the success or failure of the
 * xOpen call.
 */
struct vedis_vfs {
  const char *zName;       /* Name of this virtual file system [i.e: Windows, UNIX, etc.] */
  int iVersion;            /* Structure version number (currently 1) */
  int szOsFile;            /* Size of subclassed vedis_file */
  int mxPathname;          /* Maximum file pathname length */
  int (*xOpen)(vedis_vfs*, const char *zName, vedis_file*,unsigned int flags);
  int (*xDelete)(vedis_vfs*, const char *zName, int syncDir);
  int (*xAccess)(vedis_vfs*, const char *zName, int flags, int *pResOut);
  int (*xFullPathname)(vedis_vfs*, const char *zName,int buf_len,char *zBuf);
  int (*xTmpDir)(vedis_vfs*,char *zBuf,int buf_len);
  int (*xSleep)(vedis_vfs*, int microseconds);
  int (*xCurrentTime)(vedis_vfs*,Sytm *pOut);
  int (*xGetLastError)(vedis_vfs*, int, char *);
  int (*xMmap)(const char *, void **, vedis_int64 *);  
  void (*xUnmap)(void *,vedis_int64);
};
/*
 * Flags for the xAccess VFS method
 *
 * These integer constants can be used as the third parameter to
 * the xAccess method of an [vedis_vfs] object.  They determine
 * what kind of permissions the xAccess method is looking for.
 * With VEDIS_ACCESS_EXISTS, the xAccess method
 * simply checks whether the file exists.
 * With VEDIS_ACCESS_READWRITE, the xAccess method
 * checks whether the named directory is both readable and writable
 * (in other words, if files can be added, removed, and renamed within
 * the directory).
 * The VEDIS_ACCESS_READWRITE constant is currently used only by the
 * [temp_store_directory pragma], though this could change in a future
 * release of Vedis.
 * With VEDIS_ACCESS_READ, the xAccess method
 * checks whether the file is readable.  The VEDIS_ACCESS_READ constant is
 * currently unused, though it might be used in a future release of
 * Vedis.
 */
#define VEDIS_ACCESS_EXISTS    0
#define VEDIS_ACCESS_READWRITE 1   
#define VEDIS_ACCESS_READ      2 
/*
 * The type used to represent a page number.  The first page in a file
 * is called page 1.  0 is used to represent "not a page".
 * A page number is an unsigned 64-bit integer.
 */
typedef sxu64 pgno;
/*
 * A database disk page is represented by an instance
 * of the follwoing structure.
 */
typedef struct vedis_page vedis_page;
struct vedis_page
{
  unsigned char *zData;       /* Content of this page */
  void *pUserData;            /* Extra content */
  pgno pgno;                  /* Page number for this page */
};
/*
 * Vedis handle to the underlying Key/Value Storage Engine (See below).
 */
typedef void * vedis_kv_handle;
/*
 * Vedis pager IO methods.
 *
 * An instance of the following structure define the exported methods of the Vedis pager
 * to the underlying Key/Value storage engine.
 */
typedef struct vedis_kv_io vedis_kv_io;
struct vedis_kv_io
{
	vedis_kv_handle  pHandle;     /* Vedis handle passed as the first parameter to the
									 * method defined below.
									 */
	vedis_kv_methods *pMethods;   /* Underlying storage engine */
	/* Pager methods */
	int (*xGet)(vedis_kv_handle,pgno,vedis_page **);
	int (*xLookup)(vedis_kv_handle,pgno,vedis_page **);
	int (*xNew)(vedis_kv_handle,vedis_page **);
	int (*xWrite)(vedis_page *);
	int (*xDontWrite)(vedis_page *);
	int (*xDontJournal)(vedis_page *);
	int (*xDontMkHot)(vedis_page *);
	int (*xPageRef)(vedis_page *);
	int (*xPageUnref)(vedis_page *);
	int (*xPageSize)(vedis_kv_handle);
	int (*xReadOnly)(vedis_kv_handle);
	unsigned char * (*xTmpPage)(vedis_kv_handle);
	void (*xSetUnpin)(vedis_kv_handle,void (*xPageUnpin)(void *)); 
	void (*xSetReload)(vedis_kv_handle,void (*xPageReload)(void *));
	void (*xErr)(vedis_kv_handle,const char *);
};
/*
 * Key/Value Cursor Object.
 *
 * An instance of a subclass of the following object defines a cursor
 * used to scan through a key-value storage engine.
 */
typedef struct vedis_kv_cursor vedis_kv_cursor;
struct vedis_kv_cursor
{
  vedis_kv_engine *pStore; /* Must be first */
  /* Subclasses will typically add additional fields */
};
/*
 * Possible seek positions.
 */
#define VEDIS_CURSOR_MATCH_EXACT  1
#define VEDIS_CURSOR_MATCH_LE     2
#define VEDIS_CURSOR_MATCH_GE     3
/*
 * Key/Value Storage Engine.
 *
 * A Key-Value storage engine is defined by an instance of the following
 * object.
 * Vedis works with run-time interchangeable storage engines (i.e. Hash, B+Tree, R+Tree, LSM, etc.).
 * The storage engine works with key/value pairs where both the key
 * and the value are byte arrays of arbitrary length and with no restrictions on content.
 * Vedis come with two built-in KV storage engine: A Virtual Linear Hash (VLH) storage
 * engine is used for persistent on-disk databases with O(1) lookup time and an in-memory
 * hash-table or Red-black tree storage engine is used for in-memory databases.
 * Future versions of Vedis might add other built-in storage engines (i.e. LSM). 
 * Registration of a Key/Value storage engine at run-time is done via [vedis_lib_config()]
 * with a configuration verb set to VEDIS_LIB_CONFIG_STORAGE_ENGINE.
 */
struct vedis_kv_engine
{
  const vedis_kv_io *pIo; /* IO methods: MUST be first */
   /* Subclasses will typically add additional fields */
};
/*
 * Key/Value Storage Engine Virtual Method Table.
 *
 * Key/Value storage engine methods is defined by an instance of the following
 * object.
 * Registration of a Key/Value storage engine at run-time is done via [vedis_lib_config()]
 * with a configuration verb set to VEDIS_LIB_CONFIG_STORAGE_ENGINE.
 */
struct vedis_kv_methods
{
  const char *zName; /* Storage engine name [i.e. Hash, B+tree, LSM, R-tree, Mem, etc.]*/
  int szKv;          /* 'vedis_kv_engine' subclass size */
  int szCursor;      /* 'vedis_kv_cursor' subclass size */
  int iVersion;      /* Structure version, currently 1 */
  /* Storage engine methods */
  int (*xInit)(vedis_kv_engine *,int iPageSize);
  void (*xRelease)(vedis_kv_engine *);
  int (*xConfig)(vedis_kv_engine *,int op,va_list ap);
  int (*xOpen)(vedis_kv_engine *,pgno);
  int (*xReplace)(
	  vedis_kv_engine *,
	  const void *pKey,int nKeyLen,
	  const void *pData,vedis_int64 nDataLen
	  ); 
    int (*xAppend)(
	  vedis_kv_engine *,
	  const void *pKey,int nKeyLen,
	  const void *pData,vedis_int64 nDataLen
	  );
  void (*xCursorInit)(vedis_kv_cursor *);
  int (*xSeek)(vedis_kv_cursor *,const void *pKey,int nByte,int iPos); /* Mandatory */
  int (*xFirst)(vedis_kv_cursor *);
  int (*xLast)(vedis_kv_cursor *);
  int (*xValid)(vedis_kv_cursor *);
  int (*xNext)(vedis_kv_cursor *);
  int (*xPrev)(vedis_kv_cursor *);
  int (*xDelete)(vedis_kv_cursor *);
  int (*xKeyLength)(vedis_kv_cursor *,int *);
  int (*xKey)(vedis_kv_cursor *,int (*xConsumer)(const void *,unsigned int,void *),void *pUserData);
  int (*xDataLength)(vedis_kv_cursor *,vedis_int64 *);
  int (*xData)(vedis_kv_cursor *,int (*xConsumer)(const void *,unsigned int,void *),void *pUserData);
  void (*xReset)(vedis_kv_cursor *);
  void (*xCursorRelease)(vedis_kv_cursor *);
};
/*
 * Vedis journal file suffix.
 */
#ifndef VEDIS_JOURNAL_FILE_SUFFIX
#define VEDIS_JOURNAL_FILE_SUFFIX "_vedis_journal"
#endif
/*
 * Call Context - Error Message Serverity Level.
 *
 * The following constans are the allowed severity level that can
 * passed as the second argument to the [vedis_context_throw_error()] or
 * [vedis_context_throw_error_format()] interfaces.
 * Refer to the official documentation for additional information.
 */
#define VEDIS_CTX_ERR       1 /* Call context error such as unexpected number of arguments, invalid types and so on. */
#define VEDIS_CTX_WARNING   2 /* Call context Warning */
#define VEDIS_CTX_NOTICE    3 /* Call context Notice */
/* 
 * C-API-REF: Please refer to the official documentation for interfaces
 * purpose and expected parameters. 
 */
/* Vedis Datastore Handle */
VEDIS_APIEXPORT int vedis_open(vedis **ppStore,const char *zStorage);
VEDIS_APIEXPORT int vedis_config(vedis *pStore,int iOp,...);
VEDIS_APIEXPORT int vedis_close(vedis *pStore);

/* Command Execution Interfaces */
VEDIS_APIEXPORT int vedis_exec(vedis *pStore,const char *zCmd,int nLen);
VEDIS_APIEXPORT int vedis_exec_fmt(vedis *pStore,const char *zFmt,...);
VEDIS_APIEXPORT int vedis_exec_result(vedis *pStore,vedis_value **ppOut);

/* Foreign Command Registar */
VEDIS_APIEXPORT int vedis_register_command(vedis *pStore,const char *zName,int (*xCmd)(vedis_context *,int,vedis_value **),void *pUserdata);
VEDIS_APIEXPORT int vedis_delete_command(vedis *pStore,const char *zName);

/* Raw Data Store/Fetch (http://vedis.org) */
VEDIS_APIEXPORT int vedis_kv_store(vedis *pStore,const void *pKey,int nKeyLen,const void *pData,vedis_int64 nDataLen);
VEDIS_APIEXPORT int vedis_kv_append(vedis *pStore,const void *pKey,int nKeyLen,const void *pData,vedis_int64 nDataLen);
VEDIS_APIEXPORT int vedis_kv_store_fmt(vedis *pStore,const void *pKey,int nKeyLen,const char *zFormat,...);
VEDIS_APIEXPORT int vedis_kv_append_fmt(vedis *pStore,const void *pKey,int nKeyLen,const char *zFormat,...);
VEDIS_APIEXPORT int vedis_kv_fetch(vedis *pStore,const void *pKey,int nKeyLen,void *pBuf,vedis_int64 /* in|out */*pBufLen);
VEDIS_APIEXPORT int vedis_kv_fetch_callback(vedis *pStore,const void *pKey,
	                    int nKeyLen,int (*xConsumer)(const void *,unsigned int,void *),void *pUserData);
VEDIS_APIEXPORT int vedis_kv_config(vedis *pStore,int iOp,...);
VEDIS_APIEXPORT int vedis_kv_delete(vedis *pStore,const void *pKey,int nKeyLen);

/* Manual Transaction Manager */
VEDIS_APIEXPORT int vedis_begin(vedis *pStore);
VEDIS_APIEXPORT int vedis_commit(vedis *pStore);
VEDIS_APIEXPORT int vedis_rollback(vedis *pStore);

/* Utility interfaces */
VEDIS_APIEXPORT int vedis_util_random_string(vedis *pStore,char *zBuf,unsigned int buf_size);
VEDIS_APIEXPORT unsigned int vedis_util_random_num(vedis *pStore);

/* Call Context Key/Value Store Interfaces */
VEDIS_APIEXPORT int vedis_context_kv_store(vedis_context *pCtx,const void *pKey,int nKeyLen,const void *pData,vedis_int64 nDataLen);
VEDIS_APIEXPORT int vedis_context_kv_append(vedis_context *pCtx,const void *pKey,int nKeyLen,const void *pData,vedis_int64 nDataLen);
VEDIS_APIEXPORT int vedis_context_kv_store_fmt(vedis_context *pCtx,const void *pKey,int nKeyLen,const char *zFormat,...);
VEDIS_APIEXPORT int vedis_context_kv_append_fmt(vedis_context *pCtx,const void *pKey,int nKeyLen,const char *zFormat,...);
VEDIS_APIEXPORT int vedis_context_kv_fetch(vedis_context *pCtx,const void *pKey,int nKeyLen,void *pBuf,vedis_int64 /* in|out */*pBufLen);
VEDIS_APIEXPORT int vedis_context_kv_fetch_callback(vedis_context *pCtx,const void *pKey,
	                    int nKeyLen,int (*xConsumer)(const void *,unsigned int,void *),void *pUserData);
VEDIS_APIEXPORT int vedis_context_kv_delete(vedis_context *pCtx,const void *pKey,int nKeyLen);

/* Command Execution Context Interfaces */
VEDIS_APIEXPORT int vedis_context_throw_error(vedis_context *pCtx, int iErr, const char *zErr);
VEDIS_APIEXPORT int vedis_context_throw_error_format(vedis_context *pCtx, int iErr, const char *zFormat, ...);
VEDIS_APIEXPORT unsigned int vedis_context_random_num(vedis_context *pCtx);
VEDIS_APIEXPORT int vedis_context_random_string(vedis_context *pCtx, char *zBuf, int nBuflen);
VEDIS_APIEXPORT void * vedis_context_user_data(vedis_context *pCtx);
VEDIS_APIEXPORT int    vedis_context_push_aux_data(vedis_context *pCtx, void *pUserData);
VEDIS_APIEXPORT void * vedis_context_peek_aux_data(vedis_context *pCtx);
VEDIS_APIEXPORT void * vedis_context_pop_aux_data(vedis_context *pCtx);

/* Setting The Return Value Of A Vedis Command */
VEDIS_APIEXPORT int vedis_result_int(vedis_context *pCtx, int iValue);
VEDIS_APIEXPORT int vedis_result_int64(vedis_context *pCtx, vedis_int64 iValue);
VEDIS_APIEXPORT int vedis_result_bool(vedis_context *pCtx, int iBool);
VEDIS_APIEXPORT int vedis_result_double(vedis_context *pCtx, double Value);
VEDIS_APIEXPORT int vedis_result_null(vedis_context *pCtx);
VEDIS_APIEXPORT int vedis_result_string(vedis_context *pCtx, const char *zString, int nLen);
VEDIS_APIEXPORT int vedis_result_string_format(vedis_context *pCtx, const char *zFormat, ...);
VEDIS_APIEXPORT int vedis_result_value(vedis_context *pCtx, vedis_value *pValue);

/* Extracting Vedis Commands Parameter/Return Values */
VEDIS_APIEXPORT int vedis_value_to_int(vedis_value *pValue);
VEDIS_APIEXPORT int vedis_value_to_bool(vedis_value *pValue);
VEDIS_APIEXPORT vedis_int64 vedis_value_to_int64(vedis_value *pValue);
VEDIS_APIEXPORT double vedis_value_to_double(vedis_value *pValue);
VEDIS_APIEXPORT const char * vedis_value_to_string(vedis_value *pValue, int *pLen);

/* Dynamically Typed Value Object Query Interfaces */
VEDIS_APIEXPORT int vedis_value_is_int(vedis_value *pVal);
VEDIS_APIEXPORT int vedis_value_is_float(vedis_value *pVal);
VEDIS_APIEXPORT int vedis_value_is_bool(vedis_value *pVal);
VEDIS_APIEXPORT int vedis_value_is_string(vedis_value *pVal);
VEDIS_APIEXPORT int vedis_value_is_null(vedis_value *pVal);
VEDIS_APIEXPORT int vedis_value_is_numeric(vedis_value *pVal);
VEDIS_APIEXPORT int vedis_value_is_scalar(vedis_value *pVal);
VEDIS_APIEXPORT int vedis_value_is_array(vedis_value *pVal);

/* Populating dynamically Typed Objects  */
VEDIS_APIEXPORT int vedis_value_int(vedis_value *pVal, int iValue);
VEDIS_APIEXPORT int vedis_value_int64(vedis_value *pVal, vedis_int64 iValue);
VEDIS_APIEXPORT int vedis_value_bool(vedis_value *pVal, int iBool);
VEDIS_APIEXPORT int vedis_value_null(vedis_value *pVal);
VEDIS_APIEXPORT int vedis_value_double(vedis_value *pVal, double Value);
VEDIS_APIEXPORT int vedis_value_string(vedis_value *pVal, const char *zString, int nLen);
VEDIS_APIEXPORT int vedis_value_string_format(vedis_value *pVal, const char *zFormat, ...);
VEDIS_APIEXPORT int vedis_value_reset_string_cursor(vedis_value *pVal);
VEDIS_APIEXPORT int vedis_value_release(vedis_value *pVal);

/* On-demand Object Value Allocation */
VEDIS_APIEXPORT vedis_value * vedis_context_new_scalar(vedis_context *pCtx);
VEDIS_APIEXPORT vedis_value * vedis_context_new_array(vedis_context *pCtx);
VEDIS_APIEXPORT void vedis_context_release_value(vedis_context *pCtx, vedis_value *pValue);

/* Working with Vedis Arrays */
VEDIS_APIEXPORT vedis_value * vedis_array_fetch(vedis_value *pArray,unsigned int index);
VEDIS_APIEXPORT int vedis_array_walk(vedis_value *pArray, int (*xWalk)(vedis_value *, void *), void *pUserData);
VEDIS_APIEXPORT int vedis_array_insert(vedis_value *pArray,vedis_value *pValue);
VEDIS_APIEXPORT unsigned int vedis_array_count(vedis_value *pArray);
VEDIS_APIEXPORT int vedis_array_reset(vedis_value *pArray);
VEDIS_APIEXPORT vedis_value * vedis_array_next_elem(vedis_value *pArray);

/* Global Library Management Interfaces */
VEDIS_APIEXPORT int vedis_lib_init(void);
VEDIS_APIEXPORT int vedis_lib_config(int nConfigOp, ...);
VEDIS_APIEXPORT int vedis_lib_shutdown(void);
VEDIS_APIEXPORT int vedis_lib_is_threadsafe(void);
VEDIS_APIEXPORT const char * vedis_lib_version(void);
VEDIS_APIEXPORT const char * vedis_lib_signature(void);
VEDIS_APIEXPORT const char * vedis_lib_ident(void);
VEDIS_APIEXPORT const char * vedis_lib_copyright(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* _VEDIS_H_ */
/*
 * ----------------------------------------------------------
 * File: vedisInt.h
 * MD5: 9cc0cabef3741742fc403ac1a3dc0e0a
 * ----------------------------------------------------------
 */
/*
 * Symisc Vedis: A Highly Efficient Embeddable Data Store Engine.
 * Copyright (C) 2013, Symisc Systems http://vedis.symisc.net/
 * Version 1.2.6
 * For information on licensing, redistribution of this file, and for a DISCLAIMER OF ALL WARRANTIES
 * please contact Symisc Systems via:
 *       legal@symisc.net
 *       licensing@symisc.net
 *       contact@symisc.net
 * or visit:
 *      http://vedis.symisc.net/
 */
 /* $SymiscID: vedisInt.h v2.1 FreeBSD 2013-09-15 01:49 devel <chm@symisc.net> $ */
#ifndef __VEDISINT_H__
#define __VEDISINT_H__
/* Internal interface definitions for Vedis. */
#ifdef VEDIS_AMALGAMATION
#ifndef VEDIS_PRIVATE
/* Marker for routines not intended for external use */
#define VEDIS_PRIVATE static
#endif /* VEDIS_PRIVATE */
#else
#define VEDIS_PRIVATE
#include "vedis.h"
#endif 
#ifndef VEDIS_PI
/* Value of PI */
#define VEDIS_PI 3.1415926535898
#endif
/*
 * Constants for the largest and smallest possible 64-bit signed integers.
 * These macros are designed to work correctly on both 32-bit and 64-bit
 * compilers.
 */
#ifndef LARGEST_INT64
#define LARGEST_INT64  (0xffffffff|(((sxi64)0x7fffffff)<<32))
#endif
#ifndef SMALLEST_INT64
#define SMALLEST_INT64 (((sxi64)-1) - LARGEST_INT64)
#endif

/* Symisc Standard types */
#if !defined(SYMISC_STD_TYPES)
#define SYMISC_STD_TYPES
#ifdef __WINNT__
/* Disable nuisance warnings on Borland compilers */
#if defined(__BORLANDC__)
#pragma warn -rch /* unreachable code */
#pragma warn -ccc /* Condition is always true or false */
#pragma warn -aus /* Assigned value is never used */
#pragma warn -csu /* Comparing signed and unsigned */
#pragma warn -spa /* Suspicious pointer arithmetic */
#endif
#endif
typedef signed char        sxi8; /* signed char */
typedef unsigned char      sxu8; /* unsigned char */
typedef signed short int   sxi16; /* 16 bits(2 bytes) signed integer */
typedef unsigned short int sxu16; /* 16 bits(2 bytes) unsigned integer */
typedef int                sxi32; /* 32 bits(4 bytes) integer */
typedef unsigned int       sxu32; /* 32 bits(4 bytes) unsigned integer */
typedef long               sxptr;
typedef unsigned long      sxuptr;
typedef long               sxlong;
typedef unsigned long      sxulong;
typedef sxi32              sxofft;
typedef sxi64              sxofft64;
typedef long double	       sxlongreal;
typedef double             sxreal;
#define SXI8_HIGH       0x7F
#define SXU8_HIGH       0xFF
#define SXI16_HIGH      0x7FFF
#define SXU16_HIGH      0xFFFF
#define SXI32_HIGH      0x7FFFFFFF
#define SXU32_HIGH      0xFFFFFFFF
#define SXI64_HIGH      0x7FFFFFFFFFFFFFFF
#define SXU64_HIGH      0xFFFFFFFFFFFFFFFF 
#if !defined(TRUE)
#define TRUE 1
#endif
#if !defined(FALSE)
#define FALSE 0
#endif
/*
 * The following macros are used to cast pointers to integers and
 * integers to pointers.
 */
#if defined(__PTRDIFF_TYPE__)  
# define SX_INT_TO_PTR(X)  ((void*)(__PTRDIFF_TYPE__)(X))
# define SX_PTR_TO_INT(X)  ((int)(__PTRDIFF_TYPE__)(X))
#elif !defined(__GNUC__)    
# define SX_INT_TO_PTR(X)  ((void*)&((char*)0)[X])
# define SX_PTR_TO_INT(X)  ((int)(((char*)X)-(char*)0))
#else                       
# define SX_INT_TO_PTR(X)  ((void*)(X))
# define SX_PTR_TO_INT(X)  ((int)(X))
#endif
#define SXMIN(a, b)  ((a < b) ? (a) : (b))
#define SXMAX(a, b)  ((a < b) ? (b) : (a))
#endif /* SYMISC_STD_TYPES */
/* Symisc Run-time API private definitions */
#if !defined(SYMISC_PRIVATE_DEFS)
#define SYMISC_PRIVATE_DEFS

typedef sxi32 (*ProcRawStrCmp)(const SyString *, const SyString *);
#define SyStringData(RAW)	((RAW)->zString)
#define SyStringLength(RAW)	((RAW)->nByte)
#define SyStringInitFromBuf(RAW, ZBUF, NLEN){\
	(RAW)->zString 	= (const char *)ZBUF;\
	(RAW)->nByte	= (sxu32)(NLEN);\
}
#define SyStringUpdatePtr(RAW, NBYTES){\
	if( NBYTES > (RAW)->nByte ){\
		(RAW)->nByte = 0;\
	}else{\
		(RAW)->zString += NBYTES;\
		(RAW)->nByte -= NBYTES;\
	}\
}
#define SyStringDupPtr(RAW1, RAW2)\
	(RAW1)->zString = (RAW2)->zString;\
	(RAW1)->nByte = (RAW2)->nByte;

#define SyStringTrimLeadingChar(RAW, CHAR)\
	while((RAW)->nByte > 0 && (RAW)->zString[0] == CHAR ){\
			(RAW)->zString++;\
			(RAW)->nByte--;\
	}
#define SyStringTrimTrailingChar(RAW, CHAR)\
	while((RAW)->nByte > 0 && (RAW)->zString[(RAW)->nByte - 1] == CHAR){\
		(RAW)->nByte--;\
	}
#define SyStringCmp(RAW1, RAW2, xCMP)\
	(((RAW1)->nByte == (RAW2)->nByte) ? xCMP((RAW1)->zString, (RAW2)->zString, (RAW2)->nByte) : (sxi32)((RAW1)->nByte - (RAW2)->nByte))

#define SyStringCmp2(RAW1, RAW2, xCMP)\
	(((RAW1)->nByte >= (RAW2)->nByte) ? xCMP((RAW1)->zString, (RAW2)->zString, (RAW2)->nByte) : (sxi32)((RAW2)->nByte - (RAW1)->nByte))

#define SyStringCharCmp(RAW, CHAR) \
	(((RAW)->nByte == sizeof(char)) ? ((RAW)->zString[0] == CHAR ? 0 : CHAR - (RAW)->zString[0]) : ((RAW)->zString[0] == CHAR ? 0 : (RAW)->nByte - sizeof(char)))

#define SX_ADDR(PTR)    ((sxptr)PTR)
#define SX_ARRAYSIZE(X) (sizeof(X)/sizeof(X[0]))
#define SXUNUSED(P)	(P = 0)
#define	SX_EMPTY(PTR)   (PTR == 0)
#define SX_EMPTY_STR(STR) (STR == 0 || STR[0] == 0 )
typedef struct SyMemBackend SyMemBackend;
typedef struct SyBlob SyBlob;
typedef struct SySet SySet;
/* Standard function signatures */
typedef sxi32 (*ProcCmp)(const void *, const void *, sxu32);
typedef sxi32 (*ProcPatternMatch)(const char *, sxu32, const char *, sxu32, sxu32 *);
typedef sxi32 (*ProcSearch)(const void *, sxu32, const void *, sxu32, ProcCmp, sxu32 *);
typedef sxu32 (*ProcHash)(const void *, sxu32);
typedef sxi32 (*ProcHashSum)(const void *, sxu32, unsigned char *, sxu32);
typedef sxi32 (*ProcSort)(void *, sxu32, sxu32, ProcCmp);
#define MACRO_LIST_PUSH(Head, Item)\
	Item->pNext = Head;\
	Head = Item; 
#define MACRO_LD_PUSH(Head, Item)\
	if( Head == 0 ){\
		Head = Item;\
	}else{\
		Item->pNext = Head;\
		Head->pPrev = Item;\
		Head = Item;\
	}
#define MACRO_LD_REMOVE(Head, Item)\
	if( Head == Item ){\
		Head = Head->pNext;\
	}\
	if( Item->pPrev ){ Item->pPrev->pNext = Item->pNext;}\
	if( Item->pNext ){ Item->pNext->pPrev = Item->pPrev;}
/*
 * A generic dynamic set.
 */
struct SySet
{
	SyMemBackend *pAllocator; /* Memory backend */
	void *pBase;              /* Base pointer */	
	sxu32 nUsed;              /* Total number of used slots  */
	sxu32 nSize;              /* Total number of available slots */
	sxu32 eSize;              /* Size of a single slot */
	sxu32 nCursor;	          /* Loop cursor */	
	void *pUserData;          /* User private data associated with this container */
};
#define SySetBasePtr(S)           ((S)->pBase)
#define SySetBasePtrJump(S, OFFT)  (&((char *)(S)->pBase)[OFFT*(S)->eSize])
#define SySetUsed(S)              ((S)->nUsed)
#define SySetSize(S)              ((S)->nSize)
#define SySetElemSize(S)          ((S)->eSize) 
#define SySetCursor(S)            ((S)->nCursor)
#define SySetGetAllocator(S)      ((S)->pAllocator)
#define SySetSetUserData(S, DATA)  ((S)->pUserData = DATA)
#define SySetGetUserData(S)       ((S)->pUserData)
/*
 * A variable length containers for generic data.
 */
struct SyBlob
{
	SyMemBackend *pAllocator; /* Memory backend */
	void   *pBlob;	          /* Base pointer */
	sxu32  nByte;	          /* Total number of used bytes */
	sxu32  mByte;	          /* Total number of available bytes */
	sxu32  nFlags;	          /* Blob internal flags, see below */
};
#define SXBLOB_LOCKED	0x01	/* Blob is locked [i.e: Cannot auto grow] */
#define SXBLOB_STATIC	0x02	/* Not allocated from heap   */
#define SXBLOB_RDONLY   0x04    /* Read-Only data */

#define SyBlobFreeSpace(BLOB)	 ((BLOB)->mByte - (BLOB)->nByte)
#define SyBlobLength(BLOB)	     ((BLOB)->nByte)
#define SyBlobData(BLOB)	     ((BLOB)->pBlob)
#define SyBlobCurData(BLOB)	     ((void*)(&((char*)(BLOB)->pBlob)[(BLOB)->nByte]))
#define SyBlobDataAt(BLOB, OFFT)	 ((void *)(&((char *)(BLOB)->pBlob)[OFFT]))
#define SyBlobGetAllocator(BLOB) ((BLOB)->pAllocator)

#define SXMEM_POOL_INCR			3
#define SXMEM_POOL_NBUCKETS		12
#define SXMEM_BACKEND_MAGIC	0xBAC3E67D
#define SXMEM_BACKEND_CORRUPT(BACKEND)	(BACKEND == 0 || BACKEND->nMagic != SXMEM_BACKEND_MAGIC)

#define SXMEM_BACKEND_RETRY	3
/* A memory backend subsystem is defined by an instance of the following structures */
typedef union SyMemHeader SyMemHeader;
typedef struct SyMemBlock SyMemBlock;
struct SyMemBlock
{
	SyMemBlock *pNext, *pPrev; /* Chain of allocated memory blocks */
#ifdef UNTRUST
	sxu32 nGuard;             /* magic number associated with each valid block, so we
							   * can detect misuse.
							   */
#endif
};
/*
 * Header associated with each valid memory pool block.
 */
union SyMemHeader
{
	SyMemHeader *pNext; /* Next chunk of size 1 << (nBucket + SXMEM_POOL_INCR) in the list */
	sxu32 nBucket;      /* Bucket index in aPool[] */
};
struct SyMemBackend
{
	const SyMutexMethods *pMutexMethods; /* Mutex methods */
	const SyMemMethods *pMethods;  /* Memory allocation methods */
	SyMemBlock *pBlocks;           /* List of valid memory blocks */
	sxu32 nBlock;                  /* Total number of memory blocks allocated so far */
	ProcMemError xMemError;        /* Out-of memory callback */
	void *pUserData;               /* First arg to xMemError() */
	SyMutex *pMutex;               /* Per instance mutex */
	sxu32 nMagic;                  /* Sanity check against misuse */
	SyMemHeader *apPool[SXMEM_POOL_NBUCKETS+SXMEM_POOL_INCR]; /* Pool of memory chunks */
};
/* Mutex types */
#define SXMUTEX_TYPE_FAST	1
#define SXMUTEX_TYPE_RECURSIVE	2
#define SXMUTEX_TYPE_STATIC_1	3
#define SXMUTEX_TYPE_STATIC_2	4
#define SXMUTEX_TYPE_STATIC_3	5
#define SXMUTEX_TYPE_STATIC_4	6
#define SXMUTEX_TYPE_STATIC_5	7
#define SXMUTEX_TYPE_STATIC_6	8

#define SyMutexGlobalInit(METHOD){\
	if( (METHOD)->xGlobalInit ){\
	(METHOD)->xGlobalInit();\
	}\
}
#define SyMutexGlobalRelease(METHOD){\
	if( (METHOD)->xGlobalRelease ){\
	(METHOD)->xGlobalRelease();\
	}\
}
#define SyMutexNew(METHOD, TYPE)			(METHOD)->xNew(TYPE)
#define SyMutexRelease(METHOD, MUTEX){\
	if( MUTEX && (METHOD)->xRelease ){\
		(METHOD)->xRelease(MUTEX);\
	}\
}
#define SyMutexEnter(METHOD, MUTEX){\
	if( MUTEX ){\
	(METHOD)->xEnter(MUTEX);\
	}\
}
#define SyMutexTryEnter(METHOD, MUTEX){\
	if( MUTEX && (METHOD)->xTryEnter ){\
	(METHOD)->xTryEnter(MUTEX);\
	}\
}
#define SyMutexLeave(METHOD, MUTEX){\
	if( MUTEX ){\
	(METHOD)->xLeave(MUTEX);\
	}\
}
/* Comparison, byte swap, byte copy macros */
#define SX_MACRO_FAST_CMP(X1, X2, SIZE, RC){\
	register unsigned char *r1 = (unsigned char *)X1;\
	register unsigned char *r2 = (unsigned char *)X2;\
	register sxu32 LEN = SIZE;\
	for(;;){\
	  if( !LEN ){ break; }if( r1[0] != r2[0] ){ break; } r1++; r2++; LEN--;\
	  if( !LEN ){ break; }if( r1[0] != r2[0] ){ break; } r1++; r2++; LEN--;\
	  if( !LEN ){ break; }if( r1[0] != r2[0] ){ break; } r1++; r2++; LEN--;\
	  if( !LEN ){ break; }if( r1[0] != r2[0] ){ break; } r1++; r2++; LEN--;\
	}\
	RC = !LEN ? 0 : r1[0] - r2[0];\
}
#define	SX_MACRO_FAST_MEMCPY(SRC, DST, SIZ){\
	register unsigned char *xSrc = (unsigned char *)SRC;\
	register unsigned char *xDst = (unsigned char *)DST;\
	register sxu32 xLen = SIZ;\
	for(;;){\
	    if( !xLen ){ break; }xDst[0] = xSrc[0]; xDst++; xSrc++; --xLen;\
		if( !xLen ){ break; }xDst[0] = xSrc[0]; xDst++; xSrc++; --xLen;\
		if( !xLen ){ break; }xDst[0] = xSrc[0]; xDst++; xSrc++; --xLen;\
		if( !xLen ){ break; }xDst[0] = xSrc[0]; xDst++; xSrc++; --xLen;\
	}\
}
#define SX_MACRO_BYTE_SWAP(X, Y, Z){\
	register unsigned char *s = (unsigned char *)X;\
	register unsigned char *d = (unsigned char *)Y;\
	sxu32	ZLong = Z;  \
	sxi32 c; \
	for(;;){\
	  if(!ZLong){ break; } c = s[0] ; s[0] = d[0]; d[0] = (unsigned char)c; s++; d++; --ZLong;\
	  if(!ZLong){ break; } c = s[0] ; s[0] = d[0]; d[0] = (unsigned char)c; s++; d++; --ZLong;\
	  if(!ZLong){ break; } c = s[0] ; s[0] = d[0]; d[0] = (unsigned char)c; s++; d++; --ZLong;\
	  if(!ZLong){ break; } c = s[0] ; s[0] = d[0]; d[0] = (unsigned char)c; s++; d++; --ZLong;\
	}\
}
#define SX_MSEC_PER_SEC	(1000)			/* Millisec per seconds */
#define SX_USEC_PER_SEC	(1000000)		/* Microsec per seconds */
#define SX_NSEC_PER_SEC	(1000000000)	/* Nanosec per seconds */
#endif /* SYMISC_PRIVATE_DEFS */
/* Symisc Run-time API auxiliary definitions */
#if !defined(SYMISC_PRIVATE_AUX_DEFS)
#define SYMISC_PRIVATE_AUX_DEFS

typedef struct SyHashEntry_Pr SyHashEntry_Pr;
typedef struct SyHashEntry SyHashEntry;
typedef struct SyHash SyHash;
/*
 * Each public hashtable entry is represented by an instance
 * of the following structure.
 */
struct SyHashEntry
{
	const void *pKey; /* Hash key */
	sxu32 nKeyLen;    /* Key length */
	void *pUserData;  /* User private data */
};
#define SyHashEntryGetUserData(ENTRY) ((ENTRY)->pUserData)
#define SyHashEntryGetKey(ENTRY)      ((ENTRY)->pKey)
/* Each active hashtable is identified by an instance of the following structure */
struct SyHash
{
	SyMemBackend *pAllocator;         /* Memory backend */
	ProcHash xHash;                   /* Hash function */
	ProcCmp xCmp;                     /* Comparison function */
	SyHashEntry_Pr *pList, *pCurrent;  /* Linked list of hash entries user for linear traversal */
	sxu32 nEntry;                     /* Total number of entries */
	SyHashEntry_Pr **apBucket;        /* Hash buckets */
	sxu32 nBucketSize;                /* Current bucket size */
};
#define SXHASH_BUCKET_SIZE 16 /* Initial bucket size: must be a power of two */
#define SXHASH_FILL_FACTOR 3
/* Hash access macro */
#define SyHashFunc(HASH)		((HASH)->xHash)
#define SyHashCmpFunc(HASH)		((HASH)->xCmp)
#define SyHashTotalEntry(HASH)	((HASH)->nEntry)
#define SyHashGetPool(HASH)		((HASH)->pAllocator)
/*
 * An instance of the following structure define a single context
 * for an Pseudo Random Number Generator.
 *
 * Nothing in this file or anywhere else in the library does any kind of
 * encryption.  The RC4 algorithm is being used as a PRNG (pseudo-random
 * number generator) not as an encryption device.
 * This implementation is taken from the SQLite3 source tree.
 */
typedef struct SyPRNGCtx SyPRNGCtx;
struct SyPRNGCtx
{
    sxu8 i, j;				/* State variables */
    unsigned char s[256];   /* State variables */
	sxu16 nMagic;			/* Sanity check */
 };
typedef sxi32 (*ProcRandomSeed)(void *, unsigned int, void *);
/* High resolution timer.*/
typedef struct sytime sytime;
struct sytime
{
	long tm_sec;	/* seconds */
	long tm_usec;	/* microseconds */
};
/* Forward declaration */
typedef struct SyStream SyStream;
typedef struct SyToken  SyToken;
typedef struct SyLex    SyLex;
/*
 * Tokenizer callback signature.
 */
typedef sxi32 (*ProcTokenizer)(SyStream *, SyToken *, void *, void *);
/*
 * Each token in the input is represented by an instance
 * of the following structure.
 */
struct SyToken
{
	SyString sData;  /* Token text and length */
	sxu32 nType;     /* Token type */
	sxu32 nLine;     /* Token line number */
	void *pUserData; /* User private data associated with this token */
};
/*
 * During tokenization, information about the state of the input
 * stream is held in an instance of the following structure.
 */
struct SyStream
{
	const unsigned char *zInput; /* Complete text of the input */
	const unsigned char *zText; /* Current input we are processing */	
	const unsigned char *zEnd; /* End of input marker */
	sxu32  nLine; /* Total number of processed lines */
	sxu32  nIgn; /* Total number of ignored tokens */
	SySet *pSet; /* Token containers */
};
/*
 * Each lexer is represented by an instance of the following structure.
 */
struct SyLex
{
	SyStream sStream;         /* Input stream */
	ProcTokenizer xTokenizer; /* Tokenizer callback */
	void * pUserData;         /* Third argument to xTokenizer() */
	SySet *pTokenSet;         /* Token set */
};
#define SyLexTotalToken(LEX)    SySetTotalEntry(&(LEX)->aTokenSet)
#define SyLexTotalLines(LEX)    ((LEX)->sStream.nLine)
#define SyLexTotalIgnored(LEX)  ((LEX)->sStream.nIgn)
#define XLEX_IN_LEN(STREAM)     (sxu32)(STREAM->zEnd - STREAM->zText)
#endif /* SYMISC_PRIVATE_AUX_DEFS */
/*
** Notes on UTF-8 (According to SQLite3 authors):
**
**   Byte-0    Byte-1    Byte-2    Byte-3    Value
**  0xxxxxxx                                 00000000 00000000 0xxxxxxx
**  110yyyyy  10xxxxxx                       00000000 00000yyy yyxxxxxx
**  1110zzzz  10yyyyyy  10xxxxxx             00000000 zzzzyyyy yyxxxxxx
**  11110uuu  10uuzzzz  10yyyyyy  10xxxxxx   000uuuuu zzzzyyyy yyxxxxxx
**
*/
/*
** Assuming zIn points to the first byte of a UTF-8 character, 
** advance zIn to point to the first byte of the next UTF-8 character.
*/
#define SX_JMP_UTF8(zIn, zEnd)\
	while(zIn < zEnd && (((unsigned char)zIn[0] & 0xc0) == 0x80) ){ zIn++; }
#define SX_WRITE_UTF8(zOut, c) {                       \
  if( c<0x00080 ){                                     \
    *zOut++ = (sxu8)(c&0xFF);                          \
  }else if( c<0x00800 ){                               \
    *zOut++ = 0xC0 + (sxu8)((c>>6)&0x1F);              \
    *zOut++ = 0x80 + (sxu8)(c & 0x3F);                 \
  }else if( c<0x10000 ){                               \
    *zOut++ = 0xE0 + (sxu8)((c>>12)&0x0F);             \
    *zOut++ = 0x80 + (sxu8)((c>>6) & 0x3F);            \
    *zOut++ = 0x80 + (sxu8)(c & 0x3F);                 \
  }else{                                               \
    *zOut++ = 0xF0 + (sxu8)((c>>18) & 0x07);           \
    *zOut++ = 0x80 + (sxu8)((c>>12) & 0x3F);           \
    *zOut++ = 0x80 + (sxu8)((c>>6) & 0x3F);            \
    *zOut++ = 0x80 + (sxu8)(c & 0x3F);                 \
  }                                                    \
}
/* Rely on the standard ctype */
#include <ctype.h>
#define SyToUpper(c) toupper(c) 
#define SyToLower(c) tolower(c) 
#define SyisUpper(c) isupper(c)
#define SyisLower(c) islower(c)
#define SyisSpace(c) isspace(c)
#define SyisBlank(c) isspace(c)
#define SyisAlpha(c) isalpha(c)
#define SyisDigit(c) isdigit(c)
#define SyisHex(c)	 isxdigit(c)
#define SyisPrint(c) isprint(c)
#define SyisPunct(c) ispunct(c)
#define SyisSpec(c)	 iscntrl(c)
#define SyisCtrl(c)	 iscntrl(c)
#define SyisAscii(c) isascii(c)
#define SyisAlphaNum(c) isalnum(c)
#define SyisGraph(c)     isgraph(c)
#define SyDigToHex(c)    "0123456789ABCDEF"[c & 0x0F] 		
#define SyDigToInt(c)     ((c < 0xc0 && SyisDigit(c))? (c - '0') : 0 )
#define SyCharToUpper(c)  ((c < 0xc0 && SyisLower(c))? SyToUpper(c) : c)
#define SyCharToLower(c)  ((c < 0xc0 && SyisUpper(c))? SyToLower(c) : c)
/* Remove white space/NUL byte from a raw string */
#define SyStringLeftTrim(RAW)\
	while((RAW)->nByte > 0 && (unsigned char)(RAW)->zString[0] < 0xc0 && SyisSpace((RAW)->zString[0])){\
		(RAW)->nByte--;\
		(RAW)->zString++;\
	}
#define SyStringLeftTrimSafe(RAW)\
	while((RAW)->nByte > 0 && (unsigned char)(RAW)->zString[0] < 0xc0 && ((RAW)->zString[0] == 0 || SyisSpace((RAW)->zString[0]))){\
		(RAW)->nByte--;\
		(RAW)->zString++;\
	}
#define SyStringRightTrim(RAW)\
	while((RAW)->nByte > 0 && (unsigned char)(RAW)->zString[(RAW)->nByte - 1] < 0xc0  && SyisSpace((RAW)->zString[(RAW)->nByte - 1])){\
		(RAW)->nByte--;\
	}
#define SyStringRightTrimSafe(RAW)\
	while((RAW)->nByte > 0 && (unsigned char)(RAW)->zString[(RAW)->nByte - 1] < 0xc0  && \
	(( RAW)->zString[(RAW)->nByte - 1] == 0 || SyisSpace((RAW)->zString[(RAW)->nByte - 1]))){\
		(RAW)->nByte--;\
	}

#define SyStringFullTrim(RAW)\
	while((RAW)->nByte > 0 && (unsigned char)(RAW)->zString[0] < 0xc0  && SyisSpace((RAW)->zString[0])){\
		(RAW)->nByte--;\
		(RAW)->zString++;\
	}\
	while((RAW)->nByte > 0 && (unsigned char)(RAW)->zString[(RAW)->nByte - 1] < 0xc0  && SyisSpace((RAW)->zString[(RAW)->nByte - 1])){\
		(RAW)->nByte--;\
	}
#define SyStringFullTrimSafe(RAW)\
	while((RAW)->nByte > 0 && (unsigned char)(RAW)->zString[0] < 0xc0  && \
          ( (RAW)->zString[0] == 0 || SyisSpace((RAW)->zString[0]))){\
		(RAW)->nByte--;\
		(RAW)->zString++;\
	}\
	while((RAW)->nByte > 0 && (unsigned char)(RAW)->zString[(RAW)->nByte - 1] < 0xc0  && \
                   ( (RAW)->zString[(RAW)->nByte - 1] == 0 || SyisSpace((RAW)->zString[(RAW)->nByte - 1]))){\
		(RAW)->nByte--;\
	}

#ifndef VEDIS_DISABLE_HASH_FUNC
/* MD5 context */
typedef struct MD5Context MD5Context;
struct MD5Context {
 sxu32 buf[4];
 sxu32 bits[2];
 unsigned char in[64];
};
/* SHA1 context */
typedef struct SHA1Context SHA1Context;
struct SHA1Context {
  unsigned int state[5];
  unsigned int count[2];
  unsigned char buffer[64];
};
#endif /* VEDIS_DISABLE_HASH_FUNC */
/*
** The following values may be passed as the second argument to
** UnqliteOsLock(). The various locks exhibit the following semantics:
**
** SHARED:    Any number of processes may hold a SHARED lock simultaneously.
** RESERVED:  A single process may hold a RESERVED lock on a file at
**            any time. Other processes may hold and obtain new SHARED locks.
** PENDING:   A single process may hold a PENDING lock on a file at
**            any one time. Existing SHARED locks may persist, but no new
**            SHARED locks may be obtained by other processes.
** EXCLUSIVE: An EXCLUSIVE lock precludes all other locks.
**
** PENDING_LOCK may not be passed directly to UnqliteOsLock(). Instead, a
** process that requests an EXCLUSIVE lock may actually obtain a PENDING
** lock. This can be upgraded to an EXCLUSIVE lock by a subsequent call to
** UnqliteOsLock().
*/
#define NO_LOCK         0
#define SHARED_LOCK     1
#define RESERVED_LOCK   2
#define PENDING_LOCK    3
#define EXCLUSIVE_LOCK  4
/*
 * Vedis Locking Strategy (Same as SQLite3)
 *
 * The following #defines specify the range of bytes used for locking.
 * SHARED_SIZE is the number of bytes available in the pool from which
 * a random byte is selected for a shared lock.  The pool of bytes for
 * shared locks begins at SHARED_FIRST. 
 *
 * The same locking strategy and byte ranges are used for Unix and Windows.
 * This leaves open the possiblity of having clients on winNT, and
 * unix all talking to the same shared file and all locking correctly.
 * To do so would require that samba (or whatever
 * tool is being used for file sharing) implements locks correctly between
 * windows and unix.  I'm guessing that isn't likely to happen, but by
 * using the same locking range we are at least open to the possibility.
 *
 * Locking in windows is mandatory.  For this reason, we cannot store
 * actual data in the bytes used for locking.  The pager never allocates
 * the pages involved in locking therefore.  SHARED_SIZE is selected so
 * that all locks will fit on a single page even at the minimum page size.
 * PENDING_BYTE defines the beginning of the locks.  By default PENDING_BYTE
 * is set high so that we don't have to allocate an unused page except
 * for very large databases.  But one should test the page skipping logic 
 * by setting PENDING_BYTE low and running the entire regression suite.
 *
 * Changing the value of PENDING_BYTE results in a subtly incompatible
 * file format.  Depending on how it is changed, you might not notice
 * the incompatibility right away, even running a full regression test.
 * The default location of PENDING_BYTE is the first byte past the
 * 1GB boundary.
 */
#define PENDING_BYTE     (0x40000000)
#define RESERVED_BYTE    (PENDING_BYTE+1)
#define SHARED_FIRST     (PENDING_BYTE+2)
#define SHARED_SIZE      510
/*
 * The default size of a disk sector in bytes.
 */
#ifndef VEDIS_DEFAULT_SECTOR_SIZE
#define VEDIS_DEFAULT_SECTOR_SIZE 512
#endif
/* Forward declaration */
typedef struct vedis_hashmap_node vedis_hashmap_node;
typedef struct vedis_hashmap vedis_hashmap;
/* Forward declaration */
typedef struct vedis_table_entry vedis_table_entry;
typedef struct vedis_table vedis_table;
typedef struct Bitvec Bitvec;
/*
 * Each open database file is managed by a separate instance
 * of the "Pager" structure.
 */
typedef struct Pager Pager;
/*
 * Memory Objects.
 * Internally, the Vedis engine manipulates nearly all vedis values
 * [i.e: string, int, float, bool, null] as vedis_values structures.
 * Each vedis_values struct may cache multiple representations (string, integer etc.)
 * of the same value.
 */
struct vedis_value
{
	union{
		vedis_real rVal;      /* Real value */
		sxi64 iVal;       /* Integer value */
		void *pOther;     /* Other values (Hashmap etc.) */
	}x;
	sxi32 iFlags;       /* Control flags (see below) */
	SyBlob sBlob;       /* Blob values (Warning: Must be last field in this structure) */
};
/* Allowed value types.
 */
#define MEMOBJ_STRING    0x001  /* Memory value is a UTF-8/Binary stream */
#define MEMOBJ_INT       0x002  /* Memory value is an integer */
#define MEMOBJ_REAL      0x004  /* Memory value is a real number */
#define MEMOBJ_BOOL      0x008  /* Memory value is a boolean */
#define MEMOBJ_NULL      0x020  /* Memory value is NULL */
#define MEMOBJ_HASHMAP   0x040  /* Memory value is a hashmap  */
/* Mask of all known types */
#define MEMOBJ_ALL (MEMOBJ_STRING|MEMOBJ_INT|MEMOBJ_REAL|MEMOBJ_BOOL|MEMOBJ_NULL|MEMOBJ_HASHMAP) 
/*
 * The following macro clear the current vedis_value type and replace
 * it with the given one.
 */
#define MemObjSetType(OBJ, TYPE) ((OBJ)->iFlags = ((OBJ)->iFlags&~MEMOBJ_ALL)|TYPE)
#define MEMOBJ_SCALAR (MEMOBJ_STRING|MEMOBJ_INT|MEMOBJ_REAL|MEMOBJ_BOOL|MEMOBJ_NULL)
/* vedis cast method signature */
typedef sxi32 (*ProcMemObjCast)(vedis_value *);
/*
 * Auxiliary data associated with each foreign command is stored
 * in a stack of the following structure.
 * Note that automatic tracked chunks are also stored in an instance
 * of this structure.
 */
typedef struct vedis_aux_data vedis_aux_data;
struct vedis_aux_data
{
	void *pAuxData; /* Aux data */
};
/*
 * Each registered vedis command is represented by an instance of the following
 * structure.
 */
typedef int (*ProcVedisCmd)(vedis_context *,int,vedis_value **);
typedef struct vedis_cmd vedis_cmd;
struct vedis_cmd
{
	SyString sName;       /* Command name */
	sxu32 nHash;          /* Hash of the command name */
	ProcVedisCmd xCmd;    /* Command implementation */
	SySet aAux;           /* Stack of auxiliary data */
	void *pUserData;      /* Command private data */
	vedis_cmd *pNext,*pPrev; /* Pointer to other commands in the chaine */
	vedis_cmd *pNextCol,*pPrevCol; /* Collision chain */
};
/*
 * The 'context' argument for an installable commands. A pointer to an
 * instance of this structure is the first argument to the routines used
 * implement the vedis commands.
 */
struct vedis_context
{
	vedis *pVedis;       /* Vedis handle */
	vedis_cmd *pCmd;     /* Executed vedis command */
	SyBlob sWorker;      /* Working buffer */
	vedis_value *pRet;   /* Return value is stored here. */
	SySet sVar;          /* Container of dynamically allocated vedis_values
						  * [i.e: Garbage collection purposes.]
						  */
};
/*
 * Command output consumer callback.
 */
typedef int (*ProcCmdConsumer)(vedis_value *,void *);
/*
 * Each datastore connection is an instance of the following structure.
 */
struct vedis
{
	SyMemBackend sMem;               /* Memory allocator subsystem */
	SyBlob sErr;                     /* Error log */
	Pager *pPager;                   /* Storage backend */
	vedis_kv_cursor *pCursor;        /* General purpose database cursor */
	vedis_cmd **apCmd;               /* Table of vedis command */
	sxu32 nSize;                     /* Table size */
	sxu32 nCmd;                      /* Total number of installed vedis commands */
	vedis_cmd *pList;                /* List of vedis command */
	vedis_table **apTable;           /* Loaded vedis tables */
	sxu32 nTableSize;                /* apTable[] size */
	sxu32 nTable;                    /* apTable[] length */
	vedis_table *pTableList;         /* List of vedis tables loaded in memory */
#if defined(VEDIS_ENABLE_THREADS)
	const SyMutexMethods *pMethods;  /* Mutex methods */
	SyMutex *pMutex;                 /* Per-handle mutex */
#endif
	ProcCmdConsumer xResultConsumer; /* Result consumer callback */
	void *pUserData;                 /* Last argument to xResultConsumer() */
	vedis_value sResult;             /* Execution result of the last executed command */
	sxi32 iFlags;                    /* Control flags (See below)  */
	vedis *pNext,*pPrev;             /* List of active handles */
	sxu32 nMagic;                    /* Sanity check against misuse */
};
#define VEDIS_FL_DISABLE_AUTO_COMMIT   0x001 /* Disable auto-commit on close */
/*
 * Vedis Token
 * The following set of constants are the tokens recognized
 * by the lexer when processing input.
 * Important: Token values MUST BE A POWER OF TWO.
 */
#define VEDIS_TK_INTEGER   0x0000001  /* Integer */
#define VEDIS_TK_REAL      0x0000002  /* Real number */
#define VEDIS_TK_NUM       (VEDIS_TK_INTEGER|VEDIS_TK_REAL) /* Numeric token, either integer or real */
#define VEDIS_TK_STREAM    0x0000004 /* UTF-8/Binary stream */
#define VEDIS_TK_SEMI      0x0000008 /* ';' semi-colon */
/* 
 * Database signature to identify a valid database image.
 */
#define VEDIS_DB_SIG "SymiscVedis"
/*
 * Database magic number (4 bytes).
 */
#define VEDIS_DB_MAGIC   0xCA1DB634
/*
 * Maximum page size in bytes.
 */
#ifdef VEDIS_MAX_PAGE_SIZE
# undef VEDIS_MAX_PAGE_SIZE
#endif
#define VEDIS_MAX_PAGE_SIZE 65536 /* 65K */
/*
 * Minimum page size in bytes.
 */
#ifdef VEDIS_MIN_PAGE_SIZE
# undef VEDIS_MIN_PAGE_SIZE
#endif
#define VEDIS_MIN_PAGE_SIZE 512
/*
 * The default size of a database page.
 */
#ifndef VEDIS_DEFAULT_PAGE_SIZE
# undef VEDIS_DEFAULT_PAGE_SIZE
#endif
# define VEDIS_DEFAULT_PAGE_SIZE 4096 /* 4K */
/*
 * These bit values are intended for use in the 3rd parameter to the [vedis_open()] interface
 * and in the 4th parameter to the xOpen method of the [vedis_vfs] object.
 */
#define VEDIS_OPEN_READONLY         0x00000001  /* Read only mode. Ok for [vedis_open] */
#define VEDIS_OPEN_READWRITE        0x00000002  /* Ok for [vedis_open] */
#define VEDIS_OPEN_CREATE           0x00000004  /* Ok for [vedis_open] */
#define VEDIS_OPEN_EXCLUSIVE        0x00000008  /* VFS only */
#define VEDIS_OPEN_TEMP_DB          0x00000010  /* VFS only */
#define VEDIS_OPEN_NOMUTEX          0x00000020  /* Ok for [vedis_open] */
#define VEDIS_OPEN_OMIT_JOURNALING  0x00000040  /* Omit journaling for this database. Ok for [vedis_open] */
#define VEDIS_OPEN_IN_MEMORY        0x00000080  /* An in memory database. Ok for [vedis_open]*/
#define VEDIS_OPEN_MMAP             0x00000100  /* Obtain a memory view of the whole file. Ok for [vedis_open] */
/*
 * Each vedis table (i.e.: Hash, Set, List, etc.) is identified by an instance
 * of the following structure.
 */
struct vedis_table_entry
{
	vedis_table *pTable; /* Table that own this entry */
	sxi32 iType;           /* Node type */
	union{
		sxi64 iKey;        /* Int key */
		SyBlob sKey;       /* Blob key */
	}xKey;
	sxi32 iFlags;          /* Control flags */
	sxu32 nHash;           /* Key hash value */
	SyBlob sData;          /* Data */
	sxu32 nId;             /* Unique ID associated with this entry */
	vedis_table_entry *pNext,*pPrev; 
	vedis_table_entry *pNextCollide,*pPrevCollide;
};
/* Allowed node types */
#define VEDIS_TABLE_ENTRY_INT_NODE    1  /* Node with an int [i.e: 64-bit integer] key */
#define VEDIS_TABLE_ENTRY_BLOB_NODE  2  /* Node with a string/BLOB key */
/*
 * Supported Vedis Data Structures.
 */
#define VEDIS_TABLE_HASH 1
#define VEDIS_TABLE_SET  2
#define VEDIS_TABLE_LIST 3
/* hashmap.c */
VEDIS_PRIVATE sxu32 vedisHashmapCount(vedis_hashmap *pMap);
VEDIS_PRIVATE sxi32 vedisHashmapWalk(
	vedis_hashmap *pMap, /* Target hashmap */
	int (*xWalk)(vedis_value *, void *), /* Walker callback */
	void *pUserData /* Last argument to xWalk() */
	);
VEDIS_PRIVATE void vedisHashmapResetLoopCursor(vedis_hashmap *pMap);
VEDIS_PRIVATE vedis_value * vedisHashmapGetNextEntry(vedis_hashmap *pMap);
VEDIS_PRIVATE vedis_hashmap * vedisNewHashmap(
	vedis *pStore,             /* Engine that trigger the hashmap creation */
	sxu32 (*xIntHash)(sxi64), /* Hash function for int keys.NULL otherwise*/
	sxu32 (*xBlobHash)(const void *, sxu32) /* Hash function for BLOB keys.NULL otherwise */
	);
VEDIS_PRIVATE void vedisHashmapRef(vedis_hashmap *pMap);
VEDIS_PRIVATE void vedisHashmapUnref(vedis_hashmap *pMap);
VEDIS_PRIVATE vedis * vedisHashmapGetEngine(vedis_hashmap *pMap);
VEDIS_PRIVATE sxi32 vedisHashmapLookup(
	vedis_hashmap *pMap,        /* Target hashmap */
	vedis_value *pKey,          /* Lookup key */
	vedis_value **ppOut /* OUT: Target node on success */
	);
VEDIS_PRIVATE sxi32 vedisHashmapInsert(
	vedis_hashmap *pMap, /* Target hashmap */
	vedis_value *pKey,   /* Lookup key */
	vedis_value *pVal    /* Node value.NULL otherwise */
	);
/* zSet.c */
VEDIS_PRIVATE void vedisTableReset(vedis_table *pTable);
VEDIS_PRIVATE int VedisRemoveTableEntry(vedis_table *pTable,vedis_table_entry *pEntry);
VEDIS_PRIVATE vedis_table_entry * vedisTableFirstEntry(vedis_table *pTable);
VEDIS_PRIVATE vedis_table_entry * vedisTableLastEntry(vedis_table *pTable);
VEDIS_PRIVATE vedis_table_entry * vedisTableNextEntry(vedis_table *pTable);
VEDIS_PRIVATE sxu32 vedisTableLength(vedis_table *pTable);
VEDIS_PRIVATE vedis_table * vedisFetchTable(vedis *pDb,vedis_value *pName,int create_new,int iType);
VEDIS_PRIVATE vedis_table_entry * vedisTableGetRecordByIndex(vedis_table *pTable,sxu32 nIndex);
VEDIS_PRIVATE vedis_table_entry * vedisTableGetRecord(vedis_table *pTable,vedis_value *pKey);
VEDIS_PRIVATE int vedisTableInsertRecord(vedis_table *pTable,vedis_value *pKey,vedis_value *pData);
VEDIS_PRIVATE int vedisTableDeleteRecord(vedis_table *pTable,vedis_value *pKey);
VEDIS_PRIVATE  vedis_table * vedisTableChain(vedis_table *pEntry);
VEDIS_PRIVATE  SyString * vedisTableName(vedis_table *pEntry);
VEDIS_PRIVATE int vedisOnCommit(void *pUserData);
/* cmd.c */
VEDIS_PRIVATE int vedisRegisterBuiltinCommands(vedis *pVedis);
/* json.c */
VEDIS_PRIVATE int vedisJsonSerialize(vedis_value *pValue,SyBlob *pOut);
/* obj.c */
VEDIS_PRIVATE void vedisMemObjInit(vedis *pVedis,vedis_value *pObj);
VEDIS_PRIVATE sxi32 vedisMemObjInitFromString(vedis *pStore, vedis_value *pObj, const SyString *pVal);
VEDIS_PRIVATE sxi32 vedisMemObjInitFromInt(vedis *pStore, vedis_value *pObj, sxi64 iVal);
VEDIS_PRIVATE vedis_value * vedisNewObjectValue(vedis *pVedis,SyToken *pToken);
VEDIS_PRIVATE vedis_value * vedisNewObjectArrayValue(vedis *pVedis);
VEDIS_PRIVATE void vedisObjectValueDestroy(vedis *pVedis,vedis_value *pValue);
VEDIS_PRIVATE SyBlob * vedisObjectValueBlob(vedis_value *pValue);
VEDIS_PRIVATE sxi32 vedisMemObjRelease(vedis_value *pObj);
VEDIS_PRIVATE sxi32 vedisMemObjTryInteger(vedis_value *pObj);
VEDIS_PRIVATE sxi32 vedisMemObjIsNumeric(vedis_value *pObj);
VEDIS_PRIVATE sxi32 vedisMemObjToInteger(vedis_value *pObj);
VEDIS_PRIVATE sxi32 vedisMemObjToReal(vedis_value *pObj);
VEDIS_PRIVATE sxi32 vedisMemObjToBool(vedis_value *pObj);
VEDIS_PRIVATE sxi32 vedisMemObjToString(vedis_value *pObj);
VEDIS_PRIVATE sxi32 vedisMemObjToNull(vedis_value *pObj);
VEDIS_PRIVATE sxi32 vedisMemObjStore(vedis_value *pSrc, vedis_value *pDest);
/* parse.c */
VEDIS_PRIVATE int vedisProcessInput(vedis *pVedis,const char *zInput,sxu32 nByte);
VEDIS_PRIVATE SyBlob * VedisContextResultBuffer(vedis_context *pCtx);
VEDIS_PRIVATE SyBlob * VedisContextWorkingBuffer(vedis_context *pCtx);
/* api.c */
VEDIS_PRIVATE const SyMemBackend * vedisExportMemBackend(void);
VEDIS_PRIVATE int vedisKvFetchCallback(vedis *pStore,const void *pKey,int nKeyLen,int (*xConsumer)(const void *,unsigned int,void *),void *pUserData);
VEDIS_PRIVATE int vedisKvDelete(vedis *pStore,const void *pKey,int nKeyLen);
VEDIS_PRIVATE int vedisDataConsumer(
	const void *pOut,   /* Data to consume */
	unsigned int nLen,  /* Data length */
	void *pUserData     /* User private data */
	);
VEDIS_PRIVATE vedis_kv_methods * vedisFindKVStore(
	const char *zName, /* Storage engine name [i.e. Hash, B+tree, LSM, etc.] */
	sxu32 nByte        /* zName length */
	);
VEDIS_PRIVATE int vedisGetPageSize(void);
VEDIS_PRIVATE int vedisGenError(vedis *pDb,const char *zErr);
VEDIS_PRIVATE int vedisGenErrorFormat(vedis *pDb,const char *zFmt,...);
VEDIS_PRIVATE int vedisGenOutofMem(vedis *pDb);
VEDIS_PRIVATE vedis_cmd * vedisFetchCommand(vedis *pVedis,SyString *pName);
/* vfs.c [io_win.c, io_unix.c ] */
VEDIS_PRIVATE const vedis_vfs * vedisExportBuiltinVfs(void);
/* mem_kv.c */
VEDIS_PRIVATE const vedis_kv_methods * vedisExportMemKvStorage(void);
/* lhash_kv.c */
VEDIS_PRIVATE const vedis_kv_methods * vedisExportDiskKvStorage(void);
/* os.c */
VEDIS_PRIVATE int vedisOsRead(vedis_file *id, void *pBuf, vedis_int64 amt, vedis_int64 offset);
VEDIS_PRIVATE int vedisOsWrite(vedis_file *id, const void *pBuf, vedis_int64 amt, vedis_int64 offset);
VEDIS_PRIVATE int vedisOsTruncate(vedis_file *id, vedis_int64 size);
VEDIS_PRIVATE int vedisOsSync(vedis_file *id, int flags);
VEDIS_PRIVATE int vedisOsFileSize(vedis_file *id, vedis_int64 *pSize);
VEDIS_PRIVATE int vedisOsLock(vedis_file *id, int lockType);
VEDIS_PRIVATE int vedisOsUnlock(vedis_file *id, int lockType);
VEDIS_PRIVATE int vedisOsCheckReservedLock(vedis_file *id, int *pResOut);
VEDIS_PRIVATE int vedisOsSectorSize(vedis_file *id);
VEDIS_PRIVATE int vedisOsOpen(
  vedis_vfs *pVfs,
  SyMemBackend *pAlloc,
  const char *zPath, 
  vedis_file **ppOut, 
  unsigned int flags
);
VEDIS_PRIVATE int vedisOsCloseFree(SyMemBackend *pAlloc,vedis_file *pId);
VEDIS_PRIVATE int vedisOsDelete(vedis_vfs *pVfs, const char *zPath, int dirSync);
VEDIS_PRIVATE int vedisOsAccess(vedis_vfs *pVfs,const char *zPath,int flags,int *pResOut);
/* bitmap.c */
VEDIS_PRIVATE Bitvec *vedisBitvecCreate(SyMemBackend *pAlloc,pgno iSize);
VEDIS_PRIVATE int vedisBitvecTest(Bitvec *p,pgno i);
VEDIS_PRIVATE int vedisBitvecSet(Bitvec *p,pgno i);
VEDIS_PRIVATE void vedisBitvecDestroy(Bitvec *p);
/* pager.c */
VEDIS_PRIVATE int vedisInitCursor(vedis *pDb,vedis_kv_cursor **ppOut);
VEDIS_PRIVATE int vedisReleaseCursor(vedis *pDb,vedis_kv_cursor *pCur);
VEDIS_PRIVATE int vedisPagerisMemStore(vedis *pStore);
VEDIS_PRIVATE int vedisPagerSetCachesize(Pager *pPager,int mxPage);
VEDIS_PRIVATE int vedisPagerSetCommitCallback(Pager *pPager,int (*xCommit)(void *),void *pUserdata);
VEDIS_PRIVATE int vedisPagerClose(Pager *pPager);
VEDIS_PRIVATE int vedisPagerOpen(
  vedis_vfs *pVfs,       /* The virtual file system to use */
  vedis *pDb,            /* Database handle */
  const char *zFilename,   /* Name of the database file to open */
  unsigned int iFlags      /* flags controlling this file */
  );
VEDIS_PRIVATE int vedisPagerRegisterKvEngine(Pager *pPager,vedis_kv_methods *pMethods);
VEDIS_PRIVATE vedis_kv_engine * vedisPagerGetKvEngine(vedis *pDb);
VEDIS_PRIVATE int vedisPagerBegin(Pager *pPager);
VEDIS_PRIVATE int vedisPagerCommit(Pager *pPager);
VEDIS_PRIVATE int vedisPagerRollback(Pager *pPager,int bResetKvEngine);
VEDIS_PRIVATE void vedisPagerRandomString(Pager *pPager,char *zBuf,sxu32 nLen);
VEDIS_PRIVATE sxu32 vedisPagerRandomNum(Pager *pPager);
/* lib.c */
#ifdef VEDIS_ENABLE_HASH_CMD
VEDIS_PRIVATE sxi32 SyBinToHexConsumer(const void *pIn, sxu32 nLen, ProcConsumer xConsumer, void *pConsumerData);
VEDIS_PRIVATE sxu32 SyCrc32(const void *pSrc, sxu32 nLen);
VEDIS_PRIVATE void MD5Update(MD5Context *ctx, const unsigned char *buf, unsigned int len);
VEDIS_PRIVATE void MD5Final(unsigned char digest[16], MD5Context *ctx);
VEDIS_PRIVATE sxi32 MD5Init(MD5Context *pCtx);
VEDIS_PRIVATE sxi32 SyMD5Compute(const void *pIn, sxu32 nLen, unsigned char zDigest[16]);
VEDIS_PRIVATE void SHA1Init(SHA1Context *context);
VEDIS_PRIVATE void SHA1Update(SHA1Context *context, const unsigned char *data, unsigned int len);
VEDIS_PRIVATE void SHA1Final(SHA1Context *context, unsigned char digest[20]);
VEDIS_PRIVATE sxi32 SySha1Compute(const void *pIn, sxu32 nLen, unsigned char zDigest[20]);
#endif /* VEDIS_ENABLE_HASH_CMD */
VEDIS_PRIVATE sxi32 SyRandomness(SyPRNGCtx *pCtx, void *pBuf, sxu32 nLen);
VEDIS_PRIVATE sxi32 SyRandomnessInit(SyPRNGCtx *pCtx, ProcRandomSeed xSeed, void *pUserData);
#ifdef __UNIXES__
VEDIS_PRIVATE sxu32 SyBufferFormat(char *zBuf, sxu32 nLen, const char *zFormat, ...);
#endif /* __UNIXES__ */
VEDIS_PRIVATE sxu32 SyBlobFormatAp(SyBlob *pBlob, const char *zFormat, va_list ap);
VEDIS_PRIVATE sxu32 SyBlobFormat(SyBlob *pBlob, const char *zFormat, ...);
VEDIS_PRIVATE sxi32 SyLexRelease(SyLex *pLex);
VEDIS_PRIVATE sxi32 SyLexTokenizeInput(SyLex *pLex, const char *zInput, sxu32 nLen, void *pCtxData, ProcSort xSort, ProcCmp xCmp);
VEDIS_PRIVATE sxi32 SyLexInit(SyLex *pLex, SySet *pSet, ProcTokenizer xTokenizer, void *pUserData);
VEDIS_PRIVATE sxi32 SyBase64Decode(const char *zB64, sxu32 nLen, ProcConsumer xConsumer, void *pUserData);
VEDIS_PRIVATE sxi32 SyBase64Encode(const char *zSrc, sxu32 nLen, ProcConsumer xConsumer, void *pUserData);
VEDIS_PRIVATE sxu32 SyBinHash(const void *pSrc, sxu32 nLen);
VEDIS_PRIVATE sxi32 SyStrToReal(const char *zSrc, sxu32 nLen, void *pOutVal, const char **zRest);
VEDIS_PRIVATE sxi32 SyBinaryStrToInt64(const char *zSrc, sxu32 nLen, void *pOutVal, const char **zRest);
VEDIS_PRIVATE sxi32 SyOctalStrToInt64(const char *zSrc, sxu32 nLen, void *pOutVal, const char **zRest);
VEDIS_PRIVATE sxi32 SyHexStrToInt64(const char *zSrc, sxu32 nLen, void *pOutVal, const char **zRest);
VEDIS_PRIVATE sxi32 SyHexToint(sxi32 c);
VEDIS_PRIVATE sxi32 SyStrToInt64(const char *zSrc, sxu32 nLen, void *pOutVal, const char **zRest);
VEDIS_PRIVATE sxi32 SyStrIsNumeric(const char *zSrc, sxu32 nLen, sxu8 *pReal, const char **pzTail);
VEDIS_PRIVATE void *SySetPop(SySet *pSet);
VEDIS_PRIVATE void *SySetPeek(SySet *pSet);
VEDIS_PRIVATE sxi32 SySetRelease(SySet *pSet);
VEDIS_PRIVATE sxi32 SySetReset(SySet *pSet);
VEDIS_PRIVATE sxi32 SySetPut(SySet *pSet, const void *pItem);
VEDIS_PRIVATE sxi32 SySetInit(SySet *pSet, SyMemBackend *pAllocator, sxu32 ElemSize);
VEDIS_PRIVATE sxi32 SyBlobRelease(SyBlob *pBlob);
VEDIS_PRIVATE sxi32 SyBlobReset(SyBlob *pBlob);
VEDIS_PRIVATE sxi32 SyBlobDup(SyBlob *pSrc, SyBlob *pDest);
VEDIS_PRIVATE sxi32 SyBlobNullAppend(SyBlob *pBlob);
VEDIS_PRIVATE sxi32 SyBlobAppend(SyBlob *pBlob, const void *pData, sxu32 nSize);
VEDIS_PRIVATE sxi32 SyBlobInit(SyBlob *pBlob, SyMemBackend *pAllocator);
VEDIS_PRIVATE sxi32 SyBlobInitFromBuf(SyBlob *pBlob, void *pBuffer, sxu32 nSize);
VEDIS_PRIVATE void *SyMemBackendDup(SyMemBackend *pBackend, const void *pSrc, sxu32 nSize);
VEDIS_PRIVATE sxi32 SyMemBackendRelease(SyMemBackend *pBackend);
VEDIS_PRIVATE sxi32 SyMemBackendInitFromOthers(SyMemBackend *pBackend, const SyMemMethods *pMethods, ProcMemError xMemErr, void *pUserData);
VEDIS_PRIVATE sxi32 SyMemBackendInit(SyMemBackend *pBackend, ProcMemError xMemErr, void *pUserData);
VEDIS_PRIVATE sxi32 SyMemBackendInitFromParent(SyMemBackend *pBackend,const SyMemBackend *pParent);
#if 0
/* Not used in the current release of the VEDIS engine */
VEDIS_PRIVATE void *SyMemBackendPoolRealloc(SyMemBackend *pBackend, void *pOld, sxu32 nByte);
#endif
VEDIS_PRIVATE sxi32 SyMemBackendPoolFree(SyMemBackend *pBackend, void *pChunk);
VEDIS_PRIVATE void *SyMemBackendPoolAlloc(SyMemBackend *pBackend, sxu32 nByte);
VEDIS_PRIVATE sxi32 SyMemBackendFree(SyMemBackend *pBackend, void *pChunk);
VEDIS_PRIVATE void *SyMemBackendRealloc(SyMemBackend *pBackend, void *pOld, sxu32 nByte);
VEDIS_PRIVATE void *SyMemBackendAlloc(SyMemBackend *pBackend, sxu32 nByte);
VEDIS_PRIVATE sxu32 SyMemcpy(const void *pSrc, void *pDest, sxu32 nLen);
VEDIS_PRIVATE sxi32 SyMemcmp(const void *pB1, const void *pB2, sxu32 nSize);
VEDIS_PRIVATE void SyZero(void *pSrc, sxu32 nSize);
VEDIS_PRIVATE sxi32 SyStrnicmp(const char *zLeft, const char *zRight, sxu32 SLen);
VEDIS_PRIVATE sxu32 Systrcpy(char *zDest, sxu32 nDestLen, const char *zSrc, sxu32 nLen);
#if defined(__APPLE__)
VEDIS_PRIVATE sxi32 SyStrncmp(const char *zLeft, const char *zRight, sxu32 nLen);
#endif
VEDIS_PRIVATE sxu32 SyStrlen(const char *zSrc);
#if defined(VEDIS_ENABLE_THREADS)
VEDIS_PRIVATE const SyMutexMethods *SyMutexExportMethods(void);
VEDIS_PRIVATE sxi32 SyMemBackendMakeThreadSafe(SyMemBackend *pBackend, const SyMutexMethods *pMethods);
VEDIS_PRIVATE sxi32 SyMemBackendDisbaleMutexing(SyMemBackend *pBackend);
#endif
VEDIS_PRIVATE void SyBigEndianPack32(unsigned char *buf,sxu32 nb);
VEDIS_PRIVATE void SyBigEndianUnpack32(const unsigned char *buf,sxu32 *uNB);
VEDIS_PRIVATE void SyBigEndianPack16(unsigned char *buf,sxu16 nb);
VEDIS_PRIVATE void SyBigEndianUnpack16(const unsigned char *buf,sxu16 *uNB);
VEDIS_PRIVATE void SyBigEndianPack64(unsigned char *buf,sxu64 n64);
VEDIS_PRIVATE void SyBigEndianUnpack64(const unsigned char *buf,sxu64 *n64);
#if 0
VEDIS_PRIVATE sxi32 SyBlobAppendBig64(SyBlob *pBlob,sxu64 n64);
#endif
VEDIS_PRIVATE sxi32 SyBlobAppendBig32(SyBlob *pBlob,sxu32 n32);
VEDIS_PRIVATE sxi32 SyBlobAppendBig16(SyBlob *pBlob,sxu16 n16);
VEDIS_PRIVATE void SyTimeFormatToDos(Sytm *pFmt,sxu32 *pOut);
VEDIS_PRIVATE void SyDosTimeFormat(sxu32 nDosDate, Sytm *pOut);
#endif /* _VEDISINT_H_ */
/*
 * ----------------------------------------------------------
 * File: zset.c
 * MD5: 88b2fa4158316f4d34b59a22d03468d5
 * ----------------------------------------------------------
 */
/*
 * Symisc Vedis: A Highly Efficient Embeddable Data Store Engine.
 * Copyright (C) 2013, Symisc Systems http://vedis.symisc.net/
 * Version 1.2.6
 * For information on licensing, redistribution of this file, and for a DISCLAIMER OF ALL WARRANTIES
 * please contact Symisc Systems via:
 *       legal@symisc.net
 *       licensing@symisc.net
 *       contact@symisc.net
 * or visit:
 *      http://vedis.symisc.net/
 */
/* $SymiscID: obj.c v1.6 Linux 2013-07-10 03:52 stable <chm@symisc.net> $ */
#ifndef VEDIS_AMALGAMATION
#include "vedisInt.h"
#endif
/* Hash, Set, List in a single data structure which support persistance for the set
 * of the HSET, HGET, ZSET, etc. command family.
 * This was taken from the PH7 engine source tree, another project developed by
 * Symisc Systems,S.U.A.R.L. Visit http://ph7.symisc.net/ for additional
 * information.
 */
struct vedis_table
{
	vedis *pStore;  /* Store that own this instance */
	SyString sName; /* Table name */
	vedis_table_entry **apBucket;  /* Hash bucket */
	vedis_table_entry *pFirst;     /* First inserted entry */
	vedis_table_entry *pLast;      /* Last inserted entry */
	vedis_table_entry *pCur;       /* Current entry */
	sxu32 nEntry;                  /* Total entries */
	sxu32 nSize;                   /* apBucket[] length */
	sxu32 (*xIntHash)(sxi64);      /* Hash function for int_keys */
	sxu32 (*xBlobHash)(const void *, sxu32); /* Hash function for blob_keys */
	sxi32 iFlags;                 /* vedisTable control flags */
	sxi64 iNextIdx;               /* Next available automatically assigned index */
	sxi32 iTableType;          /* Table type [i.e. Hash, Set, ...] */
	sxu32 nLastID;             /* Last assigned ID */
	vedis_table *pNext,*pPrev; /* Link to other tables */
	vedis_table *pNextCol,*pPrevCol; /* Collision chain */
};
/* Table control flags */
#define VEDIS_TABLE_DISK_LOAD 0x001 /* Decoding table entries from diks */
/*
 * Default hash function for int [i.e; 64-bit integer] keys.
 */
static sxu32 VedisTableIntHash(sxi64 iKey)
{
	return (sxu32)(iKey ^ (iKey << 8) ^ (iKey >> 8));
}
/*
 * Default hash function for string/BLOB keys.
 */
static sxu32 VedisTableBinHash(const void *pSrc, sxu32 nLen)
{
	register unsigned char *zIn = (unsigned char *)pSrc;
	unsigned char *zEnd;
	sxu32 nH = 5381;
	zEnd = &zIn[nLen];
	for(;;){
		if( zIn >= zEnd ){ break; } nH = nH * 33 + zIn[0] ; zIn++;
		if( zIn >= zEnd ){ break; } nH = nH * 33 + zIn[0] ; zIn++;
		if( zIn >= zEnd ){ break; } nH = nH * 33 + zIn[0] ; zIn++;
		if( zIn >= zEnd ){ break; } nH = nH * 33 + zIn[0] ; zIn++;
	}	
	return nH;
}
/*
 * Allocate a new hashmap node with a 64-bit integer key.
 * If something goes wrong [i.e: out of memory], this function return NULL.
 * Otherwise a fresh [vedis_table_entry] instance is returned.
 */
static vedis_table_entry * vedisTableNewIntNode(vedis_table *pTable, sxi64 iKey, sxu32 nHash,vedis_value *pValue)
{
	vedis_table_entry *pNode;
	/* Allocate a new node */
	pNode = (vedis_table_entry *)SyMemBackendPoolAlloc(&pTable->pStore->sMem, sizeof(vedis_table_entry));
	if( pNode == 0 ){
		return 0;
	}
	/* Zero the stucture */
	SyZero(pNode, sizeof(vedis_table_entry));
	/* Fill in the structure */
	pNode->pTable  = &(*pTable);
	pNode->iType = VEDIS_TABLE_ENTRY_INT_NODE;
	pNode->nHash = nHash;
	pNode->xKey.iKey = iKey;
	SyBlobInit(&pNode->sData,&pTable->pStore->sMem);
	/* Duplicate the value */
	if( pValue ){
		const char *zData;
		int nByte;
		zData = vedis_value_to_string(pValue,&nByte);
		if( nByte > 0 ){
			SyBlobAppend(&pNode->sData,zData,(sxu32)nByte);
		}
	}
	return pNode;
}
/*
 * Allocate a new hashmap node with a BLOB key.
 * If something goes wrong [i.e: out of memory], this function return NULL.
 * Otherwise a fresh [vedis_table_entry] instance is returned.
 */
static vedis_table_entry * vedisTableNewBlobNode(vedis_table *pTable, const void *pKey, sxu32 nKeyLen, sxu32 nHash,vedis_value *pValue)
{
	vedis_table_entry *pNode;
	/* Allocate a new node */
	pNode = (vedis_table_entry *)SyMemBackendPoolAlloc(&pTable->pStore->sMem, sizeof(vedis_table_entry));
	if( pNode == 0 ){
		return 0;
	}
	/* Zero the stucture */
	SyZero(pNode, sizeof(vedis_table_entry));
	/* Fill in the structure */
	pNode->pTable  = &(*pTable);
	pNode->iType = VEDIS_TABLE_ENTRY_BLOB_NODE;
	pNode->nHash = nHash;
	SyBlobInit(&pNode->xKey.sKey, &pTable->pStore->sMem);
	SyBlobAppend(&pNode->xKey.sKey, pKey, nKeyLen);
	SyBlobInit(&pNode->sData,&pTable->pStore->sMem);
	/* Duplicate the value */
	if( pValue ){
		const char *zData;
		int nByte;
		zData = vedis_value_to_string(pValue,&nByte);
		if( nByte > 0 ){
			SyBlobAppend(&pNode->sData,zData,(sxu32)nByte);
		}
	}
	return pNode;
}
/* Forward declaration */
static int vedisTableEntrySerialize(vedis_table *pTable,vedis_table_entry *pEntry);
/*
 * link a hashmap node to the given bucket index (last argument to this function).
 */
static int vedisTableNodeLink(vedis_table *pTable, vedis_table_entry *pNode, sxu32 nBucketIdx)
{
	int rc = VEDIS_OK;
	/* Link */
	if( pTable->apBucket[nBucketIdx] != 0 ){
		pNode->pNextCollide = pTable->apBucket[nBucketIdx];
		pTable->apBucket[nBucketIdx]->pPrevCollide = pNode;
	}
	pTable->apBucket[nBucketIdx] = pNode;
	/* Link to the map list */
	if( pTable->pFirst == 0 ){
		pTable->pFirst = pTable->pLast = pNode;
		/* Point to the first inserted node */
		pTable->pCur = pNode;
	}else{
		MACRO_LD_PUSH(pTable->pLast, pNode);
	}
	pNode->nId = pTable->nLastID++;
	++pTable->nEntry;
	if( !vedisPagerisMemStore(pTable->pStore) && !(pTable->iFlags & VEDIS_TABLE_DISK_LOAD)){
		rc = vedisTableEntrySerialize(pTable,pNode);
	}
	return rc;
}
/*
 * Unlink a node from the hashmap.
 * If the node count reaches zero then release the whole hash-bucket.
 */
static void vedisTableUnlinkNode(vedis_table_entry *pNode)
{
	vedis_table *pTable = pNode->pTable;	
	/* Unlink from the corresponding bucket */
	if( pNode->pPrevCollide == 0 ){
		pTable->apBucket[pNode->nHash & (pTable->nSize - 1)] = pNode->pNextCollide;
	}else{
		pNode->pPrevCollide->pNextCollide = pNode->pNextCollide;
	}
	if( pNode->pNextCollide ){
		pNode->pNextCollide->pPrevCollide = pNode->pPrevCollide;
	}
	if( pTable->pFirst == pNode ){
		pTable->pFirst = pNode->pPrev;
	}
	if( pTable->pCur == pNode ){
		/* Advance the node cursor */
		pTable->pCur = pTable->pCur->pPrev; /* Reverse link */
	}
	/* Unlink from the map list */
	MACRO_LD_REMOVE(pTable->pLast, pNode);
	/* Release the value */
	if( pNode->iType == VEDIS_TABLE_ENTRY_BLOB_NODE ){
		SyBlobRelease(&pNode->xKey.sKey);
	}
	SyBlobRelease(&pNode->sData);
	SyMemBackendPoolFree(&pTable->pStore->sMem, pNode);
	pTable->nEntry--;
	if( pTable->nEntry < 1 ){
		/* Free the hash-bucket */
		SyMemBackendFree(&pTable->pStore->sMem, pTable->apBucket);
		pTable->apBucket = 0;
		pTable->nSize = 0;
		pTable->pFirst = pTable->pLast = pTable->pCur = 0;
	}
}
#define VEDIS_TABLE_FILL_FACTOR 3
/*
 * Grow the hash-table and rehash all entries.
 */
static sxi32 vedisTableGrowBucket(vedis_table *pTable)
{
	if( pTable->nEntry >= pTable->nSize * VEDIS_TABLE_FILL_FACTOR ){
		vedis_table_entry **apOld = pTable->apBucket;
		vedis_table_entry *pEntry, **apNew;
		sxu32 nNew = pTable->nSize << 1;
		sxu32 nBucket;
		sxu32 n;
		if( nNew < 1 ){
			nNew = 16;
		}
		/* Allocate a new bucket */
		apNew = (vedis_table_entry **)SyMemBackendAlloc(&pTable->pStore->sMem, nNew * sizeof(vedis_table_entry *));
		if( apNew == 0 ){
			if( pTable->nSize < 1 ){
				return SXERR_MEM; /* Fatal */
			}
			/* Not so fatal here, simply a performance hit */
			return SXRET_OK;
		}
		/* Zero the table */
		SyZero((void *)apNew, nNew * sizeof(vedis_table_entry *));
		/* Reflect the change */
		pTable->apBucket = apNew;
		pTable->nSize = nNew;
		if( apOld == 0 ){
			/* First allocated table [i.e: no entry], return immediately */
			return SXRET_OK;
		}
		/* Rehash old entries */
		pEntry = pTable->pFirst;
		n = 0;
		for( ;; ){
			if( n >= pTable->nEntry ){
				break;
			}
			/* Clear the old collision link */
			pEntry->pNextCollide = pEntry->pPrevCollide = 0;
			/* Link to the new bucket */
			nBucket = pEntry->nHash & (nNew - 1);
			if( pTable->apBucket[nBucket] != 0 ){
				pEntry->pNextCollide = pTable->apBucket[nBucket];
				pTable->apBucket[nBucket]->pPrevCollide = pEntry;
			}
			pTable->apBucket[nBucket] = pEntry;
			/* Point to the next entry */
			pEntry = pEntry->pPrev; /* Reverse link */
			n++;
		}
		/* Free the old table */
		SyMemBackendFree(&pTable->pStore->sMem, (void *)apOld);
	}
	return SXRET_OK;
}
/*
 * Insert a 64-bit integer key and it's associated value (if any) in the given
 * hashmap.
 */
static sxi32 vedisTableInsertIntKey(vedis_table *pTable,sxi64 iKey,vedis_value *pValue)
{
	vedis_table_entry *pNode;
	sxu32 nHash;
	sxi32 rc;
	/* Hash the key */
	nHash = pTable->xIntHash(iKey);
	/* Allocate a new int node */
	pNode = vedisTableNewIntNode(&(*pTable), iKey, nHash, pValue);
	if( pNode == 0 ){
		return SXERR_MEM;
	}
	/* Make sure the bucket is big enough to hold the new entry */
	rc = vedisTableGrowBucket(&(*pTable));
	if( rc == VEDIS_OK ){
		/* Perform the insertion */
		rc = vedisTableNodeLink(&(*pTable), pNode, nHash & (pTable->nSize - 1));
	}
	if( rc != SXRET_OK ){
		SyMemBackendPoolFree(&pTable->pStore->sMem, pNode);
		return rc;
	}
	return VEDIS_OK;
}
/*
 * Insert a BLOB key and it's associated value (if any) in the given
 * hashmap.
 */
static sxi32 vedisTableInsertBlobKey(vedis_table *pTable,const void *pKey,sxu32 nKeyLen,vedis_value *pValue)
{
	vedis_table_entry *pNode;
	sxu32 nHash;
	sxi32 rc;
	/* Hash the key */
	nHash = pTable->xBlobHash(pKey, nKeyLen);
	/* Allocate a new blob node */
	pNode = vedisTableNewBlobNode(&(*pTable), pKey, nKeyLen, nHash,pValue);
	if( pNode == 0 ){
		return SXERR_MEM;
	}
	/* Make sure the bucket is big enough to hold the new entry */
	rc = vedisTableGrowBucket(&(*pTable));
	if( rc == VEDIS_OK ){
		/* Perform the insertion */
		rc = vedisTableNodeLink(&(*pTable), pNode, nHash & (pTable->nSize - 1));
	}
	if( rc != SXRET_OK ){
		SyMemBackendPoolFree(&pTable->pStore->sMem, pNode);
		return rc;
	}
	/* All done */
	return VEDIS_OK;
}
/*
 * Check if a given 64-bit integer key exists in the given hashmap.
 * Write a pointer to the target node on success. Otherwise
 * SXERR_NOTFOUND is returned on failure.
 */
static sxi32 vedisTableLookupIntKey(
	vedis_table *pMap,         /* Target hashmap */
	sxi64 iKey,                /* lookup key */
	vedis_table_entry **ppNode  /* OUT: target node on success */
	)
{
	vedis_table_entry *pNode;
	sxu32 nHash;
	if( pMap->nEntry < 1 ){
		/* Don't bother hashing, there is no entry anyway */
		return SXERR_NOTFOUND;
	}
	/* Hash the key first */
	nHash = pMap->xIntHash(iKey);
	/* Point to the appropriate bucket */
	pNode = pMap->apBucket[nHash & (pMap->nSize - 1)];
	/* Perform the lookup */
	for(;;){
		if( pNode == 0 ){
			break;
		}
		if( pNode->iType == VEDIS_TABLE_ENTRY_INT_NODE
			&& pNode->nHash == nHash
			&& pNode->xKey.iKey == iKey ){
				/* Node found */
				if( ppNode ){
					*ppNode = pNode;
				}
				return SXRET_OK;
		}
		/* Follow the collision link */
		pNode = pNode->pNextCollide;
	}
	/* No such entry */
	return SXERR_NOTFOUND;
}
/*
 * Check if a given BLOB key exists in the given hashmap.
 * Write a pointer to the target node on success. Otherwise
 * SXERR_NOTFOUND is returned on failure.
 */
static sxi32 vedisTableLookupBlobKey(
	vedis_table *pMap,          /* Target hashmap */
	const void *pKey,           /* Lookup key */
	sxu32 nKeyLen,              /* Key length in bytes */
	vedis_table_entry **ppNode   /* OUT: target node on success */
	)
{
	vedis_table_entry *pNode;
	sxu32 nHash;
	if( pMap->nEntry < 1 ){
		/* Don't bother hashing, there is no entry anyway */
		return SXERR_NOTFOUND;
	}
	/* Hash the key first */
	nHash = pMap->xBlobHash(pKey, nKeyLen);
	/* Point to the appropriate bucket */
	pNode = pMap->apBucket[nHash & (pMap->nSize - 1)];
	/* Perform the lookup */
	for(;;){
		if( pNode == 0 ){
			break;
		}
		if( pNode->iType == VEDIS_TABLE_ENTRY_BLOB_NODE 
			&& pNode->nHash == nHash
			&& SyBlobLength(&pNode->xKey.sKey) == nKeyLen 
			&& SyMemcmp(SyBlobData(&pNode->xKey.sKey), pKey, nKeyLen) == 0 ){
				/* Node found */
				if( ppNode ){
					*ppNode = pNode;
				}
				return SXRET_OK;
		}
		/* Follow the collision link */
		pNode = pNode->pNextCollide;
	}
	/* No such entry */
	return SXERR_NOTFOUND;
}
/*
 * Check if a given key exists in the given hashmap.
 * Write a pointer to the target node on success.
 * Otherwise SXERR_NOTFOUND is returned on failure.
 */
static sxi32 vedisTableLookup(
	vedis_table *pMap,          /* Target hashmap */
	vedis_value *pKey,            /* Lookup key */
	vedis_table_entry **ppNode   /* OUT: target node on success */
	)
{
	vedis_table_entry *pNode = 0; /* cc -O6 warning */
	sxi32 rc;
	if( pKey->iFlags & (MEMOBJ_STRING|MEMOBJ_HASHMAP|MEMOBJ_REAL) ){
		if( (pKey->iFlags & MEMOBJ_STRING) == 0 ){
			/* Force a string cast */
			vedisMemObjToString(&(*pKey));
		}
		if( SyBlobLength(&pKey->sBlob) > 0 ){
			/* Perform a blob lookup */
			rc = vedisTableLookupBlobKey(&(*pMap), SyBlobData(&pKey->sBlob), SyBlobLength(&pKey->sBlob), &pNode);
			goto result;
		}
	}
	/* Perform an int lookup */
	if((pKey->iFlags & MEMOBJ_INT) == 0 ){
		/* Force an integer cast */
		vedisMemObjToInteger(pKey);
	}
	/* Perform an int lookup */
	rc = vedisTableLookupIntKey(&(*pMap), pKey->x.iVal, &pNode);
result:
	if( rc == SXRET_OK ){
		/* Node found */
		if( ppNode ){
			*ppNode = pNode;
		}
		return SXRET_OK;
	}
	/* No such entry */
	return SXERR_NOTFOUND;
}
/*
 * Insert a given key and it's associated value (if any) in the given
 * hashmap.
 * If a node with the given key already exists in the database
 * then this function overwrite the old value.
 */
static sxi32 vedisTableInsert(
	vedis_table *pMap, /* Target hashmap */
	vedis_value *pKey,   /* Lookup key  */
	vedis_value *pVal    /* Node value */
	)
{
	vedis_table_entry *pNode = 0;
	sxi32 rc = SXRET_OK;
	
	if( pKey && (pKey->iFlags & (MEMOBJ_STRING|MEMOBJ_HASHMAP)) ){
		if( (pKey->iFlags & MEMOBJ_STRING) == 0 ){
			/* Force a string cast */
			vedisMemObjToString(&(*pKey));
		}
		if( SyBlobLength(&pKey->sBlob) < 1  ){
			/* Automatic index assign */
			pKey = 0;
			goto IntKey;
		}
		if( SXRET_OK == vedisTableLookupBlobKey(&(*pMap), SyBlobData(&pKey->sBlob), 
			SyBlobLength(&pKey->sBlob), &pNode) ){
				/* Overwrite the old value */
				SyBlobReset(&pNode->sData);
				if( pVal ){
					const char *zVal;
					int nByte;
					/* Get a string representation */
					zVal = vedis_value_to_string(pVal,&nByte);
					if( nByte > 0 ){
						SyBlobAppend(&pNode->sData,zVal,(sxu32)nByte);
					}
				}
				if( !vedisPagerisMemStore(pMap->pStore) ){
					rc = vedisTableEntrySerialize(pMap,pNode);
				}
				return rc;
		}else{
			/* Perform a blob-key insertion */
			rc = vedisTableInsertBlobKey(&(*pMap),SyBlobData(&pKey->sBlob),SyBlobLength(&pKey->sBlob),&(*pVal));
			if( rc != VEDIS_OK ){
				return rc;
			}
		}
		return rc;
	}
IntKey:
	if( pKey ){
		if((pKey->iFlags & MEMOBJ_INT) == 0 ){
			/* Force an integer cast */
			vedisMemObjToInteger(pKey);
		}
		if( SXRET_OK == vedisTableLookupIntKey(&(*pMap), pKey->x.iVal, &pNode) ){
			/* Overwrite the old value */
			SyBlobReset(&pNode->sData);
				if( pVal ){
					const char *zVal;
					int nByte;
					/* Get a string representation */
					zVal = vedis_value_to_string(pVal,&nByte);
					if( nByte > 0 ){
						SyBlobAppend(&pNode->sData,zVal,(sxu32)nByte);
					}
				}
				rc = VEDIS_OK;
				if( !vedisPagerisMemStore(pMap->pStore) ){
					rc = vedisTableEntrySerialize(pMap,pNode);
				}
				return rc;
		}
		/* Perform a 64-bit-int-key insertion */
		rc = vedisTableInsertIntKey(&(*pMap), pKey->x.iVal, &(*pVal));
		if( rc == SXRET_OK ){
			if( pKey->x.iVal >= pMap->iNextIdx ){
				/* Increment the automatic index */ 
				pMap->iNextIdx = pKey->x.iVal + 1;
				/* Make sure the automatic index is not reserved */
				while( SXRET_OK == vedisTableLookupIntKey(&(*pMap), pMap->iNextIdx, 0) ){
					pMap->iNextIdx++;
				}
			}
		}
	}else{
		/* Assign an automatic index */
		rc = vedisTableInsertIntKey(&(*pMap),pMap->iNextIdx,&(*pVal));
		if( rc == SXRET_OK ){
			++pMap->iNextIdx;
		}
	}
	/* Insertion result */
	return rc;
}
/*
 * Exported interfaces used by the built-in Vedis commands.
 */
/*
 * Remove the given entry from the target table.
 */
VEDIS_PRIVATE int VedisRemoveTableEntry(vedis_table *pTable,vedis_table_entry *pEntry)
{
	int rc = VEDIS_OK;
	if( !vedisPagerisMemStore(pTable->pStore) ){
		SyBlob sWorker;
		/* Remove the entry from disk */
		SyBlobInit(&sWorker,&pTable->pStore->sMem);
		/* Build the key */
		SyBlobFormat(&sWorker,"vt%z%d%u",&pTable->sName,pTable->iTableType,pEntry->nId);
		/* Perform the deletion */
		rc = vedisKvDelete(pTable->pStore,SyBlobData(&sWorker),(int)SyBlobLength(&sWorker));
		/* Cleanup */
		SyBlobRelease(&sWorker);
	}
	vedisTableUnlinkNode(pEntry);
	return rc;
}
/*
 * Fetch a record from the given table.
 */
VEDIS_PRIVATE vedis_table_entry * vedisTableGetRecord(vedis_table *pTable,vedis_value *pKey)
{
	vedis_table_entry *pEntry;
	int rc;
	/* Fetch */
	rc = vedisTableLookup(pTable,pKey,&pEntry);
	return rc == VEDIS_OK ? pEntry : 0 /* No such entry */;
}
/*
 * Only lists.
 */
VEDIS_PRIVATE vedis_table_entry * vedisTableGetRecordByIndex(vedis_table *pTable,sxu32 nIndex)
{
	vedis_table_entry *pEntry = 0; /* cc warning */
	vedis_value sKey;
	int rc;
	vedisMemObjInitFromInt(pTable->pStore,&sKey,(sxi64)nIndex);
	/* Fetch */
	rc = vedisTableLookup(pTable,&sKey,&pEntry);
	vedisMemObjRelease(&sKey);
	return rc == VEDIS_OK ? pEntry : 0 /* No such entry */;
}
/*
 * Delete a record from the given table.
 */
VEDIS_PRIVATE int vedisTableDeleteRecord(vedis_table *pTable,vedis_value *pKey)
{
	vedis_table_entry *pEntry;
	int rc;
	/* Fetch */
	rc = vedisTableLookup(pTable,pKey,&pEntry);
	if( rc != VEDIS_OK ){
		return rc;
	}
	/* Perform the deletion */
	rc = VedisRemoveTableEntry(pTable,pEntry);
	return rc;
}
/*
 * Insert a record into the given table.
 */
VEDIS_PRIVATE int vedisTableInsertRecord(vedis_table *pTable,vedis_value *pKey,vedis_value *pData)
{
	int rc;
	rc = vedisTableInsert(pTable,pKey,pData);
	return rc;
}
/*
 * Return the total entries in a given table.
 */
VEDIS_PRIVATE sxu32 vedisTableLength(vedis_table *pTable)
{
	return pTable->nEntry;
}
/*
 * Point to the first entry in a given table.
 */
VEDIS_PRIVATE void vedisTableReset(vedis_table *pTable)
{
	/* Reset the loop cursor */
	pTable->pCur = pTable->pFirst;
}
/*
 * Return the entry pointed by the cursor in a given table.
 */
VEDIS_PRIVATE vedis_table_entry * vedisTableNextEntry(vedis_table *pTable)
{
	vedis_table_entry *pCur = pTable->pCur;
	if( pCur == 0 ){
		/* End of the list, return null */
		return 0;
	}
	/* Advance the node cursor */
	pTable->pCur = pCur->pPrev; /* Reverse link */
	/* Current Entry */
	return pCur;
}
/*
 * Return the last entry in a given table.
 */
VEDIS_PRIVATE vedis_table_entry * vedisTableLastEntry(vedis_table *pTable)
{
	return pTable->nEntry > 0 ? pTable->pLast : 0 /* Empty list*/;
}
/*
 * Return the first entry in a given table.
 */
VEDIS_PRIVATE vedis_table_entry * vedisTableFirstEntry(vedis_table *pTable)
{
	return pTable->nEntry > 0 ? pTable->pFirst : 0 /* Empty list*/;
}
/*
 * Install a freshly created table.
 */
static void vedisInstallTable(vedis *pStore,vedis_table *pTable,sxu32 nHash)
{
	sxu32 nBucket = nHash & (pStore->nTableSize - 1);
	/* Install in the corresponding bucket */
	pTable->pNextCol = pStore->apTable[nBucket];
	if( pStore->apTable[nBucket] ){
		pStore->apTable[nBucket]->pPrevCol = pTable;
	}
	pStore->apTable[nBucket] = pTable;
	/* Link the table */
	MACRO_LD_PUSH(pStore->pTableList,pTable);
	pStore->nTable++;
	if( (pStore->nTable >= pStore->nTableSize * 4) && pStore->nTable < 100000 ){
		/* Grow the hashtable */
		sxu32 nNewSize = pStore->nTableSize << 1;
		vedis_table *pEntry,**apNew;
		sxu32 n;
		apNew = (vedis_table **)SyMemBackendAlloc(&pStore->sMem, nNewSize * sizeof(vedis_table *));
		if( apNew ){
			sxu32 iBucket;
			/* Zero the new table */
			SyZero((void *)apNew, nNewSize * sizeof(vedis_table *));
			/* Rehash all entries */
			n = 0;
			pEntry = pStore->pTableList;
			for(;;){
				/* Loop one */
				if( n >= pStore->nTable ){
					break;
				}
				pEntry->pNextCol = pEntry->pPrevCol = 0;
				/* Install in the new bucket */
				iBucket = SyBinHash(SyStringData(&pEntry->sName),SyStringLength(&pEntry->sName)) & (nNewSize - 1);
				pEntry->pNextCol = apNew[iBucket];
				if( apNew[iBucket] ){
					apNew[iBucket]->pPrevCol = pEntry;
				}
				apNew[iBucket] = pEntry;
				/* Point to the next entry */
				pEntry = pEntry->pNext;
				n++;
			}
			/* Release the old table and reflect the change */
			SyMemBackendFree(&pStore->sMem,(void *)pStore->apTable);
			pStore->apTable = apNew;
			pStore->nTableSize  = nNewSize;
		}
	}
}
/*
 * Allocate a new table.
 */
static vedis_table * vedisNewTable(vedis *pStore,SyString *pName,int iType,sxu32 nHash)
{
	vedis_table *pTable;
	char *zPtr;
	/* Allocate a new instance */
	pTable = (vedis_table *)SyMemBackendAlloc(&pStore->sMem,sizeof(vedis_table)+pName->nByte);
	if( pTable == 0 ){
		return 0;
	}
	/* Zero the structure */
	SyZero(pTable,sizeof(vedis_table));
	/* Fill-in */
	pTable->iTableType = iType;
	pTable->pStore = pStore;
	pTable->xIntHash  = VedisTableIntHash;
	pTable->xBlobHash = VedisTableBinHash; 
	zPtr = (char *)&pTable[1];
	SyMemcpy(pName->zString,zPtr,pName->nByte);
	SyStringInitFromBuf(&pTable->sName,zPtr,pName->nByte);
	/* Install the table */
	vedisInstallTable(pStore,pTable,nHash);
	return pTable;
}
#define VEDIS_TABLE_MAGIC        0xCA10 /* Table magic number */
#define VEDIS_TABLE_ENTRY_MAGIC  0xEF32 /* Table entry magic number */
/*
 * Serialize a vedis table to disk.
 */
static int vedisTableSerialize(vedis_table *pTable)
{
	vedis *pStore = pTable->pStore;
	vedis_kv_methods *pMethods;
	vedis_kv_engine *pEngine;
	SyBlob sWorker;
	sxu32 nOfft;
	int rc;
	
	/* Start the serialization process */
	pEngine = vedisPagerGetKvEngine(pStore);
	pMethods = pEngine->pIo->pMethods;
	if( pMethods->xReplace ==  0 ){
		vedisGenErrorFormat(pStore,
			"Cannot serialize table '%z' due to a read-only KV storage engine '%s'",
			&pTable->sName,pMethods->zName
			);
		return VEDIS_READ_ONLY;
	}
	SyBlobInit(&sWorker,&pStore->sMem);
	/* Write the table header */
	SyBlobFormat(&sWorker,"vt%d%z",pTable->iTableType,&pTable->sName);
	nOfft = SyBlobLength(&sWorker);
	/* table header */
	SyBlobAppendBig16(&sWorker,VEDIS_TABLE_MAGIC); /* Magic number */
	SyBlobAppendBig32(&sWorker,pTable->nLastID);   /* Last assigned ID */
	SyBlobAppendBig32(&sWorker,pTable->nEntry);    /* Total number of records  */
	/* Write the header */
	rc = pMethods->xReplace(pEngine,SyBlobData(&sWorker),(int)nOfft,SyBlobDataAt(&sWorker,nOfft),SyBlobLength(&sWorker)-nOfft);
	if( rc != VEDIS_OK ){
		return rc;
	}
	/* All done, clean up and return */
	SyBlobRelease(&sWorker);
	return VEDIS_OK;
}
/*
 * Serialize a vedis table entry to Disk
 */
static int vedisTableEntrySerialize(vedis_table *pTable,vedis_table_entry *pEntry)
{
	vedis *pStore = pTable->pStore;
	vedis_kv_methods *pMethods;
	vedis_kv_engine *pEngine;
	SyBlob sWorker;
	sxu32 nByte = 0;
	sxu32 nOfft;
	
	/* Start the serialization process */
	pEngine = vedisPagerGetKvEngine(pStore);
	pMethods = pEngine->pIo->pMethods;
	if( pMethods->xReplace ==  0 ){
		vedisGenErrorFormat(pStore,
			"Cannot serialize table '%z' entry due to a read-only KV storage engine '%s'",
			&pTable->sName,pMethods->zName
			);
		return VEDIS_READ_ONLY;
	}
	SyBlobInit(&sWorker,&pStore->sMem);
	/* Prepare the key */
	SyBlobFormat(&sWorker,"vt%z%d%u",&pTable->sName,pTable->iTableType,pEntry->nId);
	nOfft = SyBlobLength(&sWorker);
	/* Prepare the payload */
	SyBlobAppendBig16(&sWorker,VEDIS_TABLE_ENTRY_MAGIC); /* Magic */
	SyBlobAppendBig32(&sWorker,pEntry->nId); /* Unique ID */
	SyBlobAppend(&sWorker,(const void *)&pEntry->iType,sizeof(char)); /* Key type */
	if( pEntry->iType == VEDIS_TABLE_ENTRY_BLOB_NODE ){
		nByte = SyBlobLength(&pEntry->xKey.sKey);
	}
	SyBlobAppendBig32(&sWorker,nByte);
	SyBlobAppendBig32(&sWorker,SyBlobLength(&pEntry->sData)); /* Data length */
	if( pEntry->iType == VEDIS_TABLE_ENTRY_BLOB_NODE ){
		SyBlobDup(&pEntry->xKey.sKey,&sWorker);
	}
	SyBlobDup(&pEntry->sData,&sWorker);
	/* Perform the write process */
	pMethods->xReplace(pEngine,SyBlobData(&sWorker),(int)nOfft,SyBlobDataAt(&sWorker,nOfft),SyBlobLength(&sWorker) - nOfft);	
	/* All done, clean up and return */
	SyBlobRelease(&sWorker);
	return VEDIS_OK;
}
/*
 * On commit callback.
 */
VEDIS_PRIVATE int vedisOnCommit(void *pUserData)
{
	vedis *pStore = (vedis *)pUserData;
	vedis_table *pTable;
	sxu32 n;
	int rc;
	/* Make sure we are dealing with an on-disk data store */
	if( vedisPagerisMemStore(pStore) ){
		return VEDIS_OK;
	}
	pTable = pStore->pTableList;
	for( n = 0 ; n < pStore->nTable ; ++n ){
		/* Serialize this table */
		rc = vedisTableSerialize(pTable);
		if( rc != VEDIS_OK ){
			return rc;
		}
		/* Point to the next entry */
		pTable = pTable->pNext;
	}
	return VEDIS_OK;
}
/*
 * Unserialize an on-disk table.
 */
static vedis_table * vedisTableUnserialize(
	vedis *pStore,SyString *pName,int iType,sxu32 nHash,
	const unsigned char *zBuf,sxu32 nByte,
	sxu32 *pEntry,sxu32 *pLastID
	)
{
	vedis_table *pNew;
	sxu16 iMagic;
	/* Sanity check */
	if( nByte != 2 /* Magic */ + 4 /* Last unique ID */ + 4 /* Total records */ ){
		/* Corrupt */
		return 0;
	}
	SyBigEndianUnpack16(zBuf,&iMagic);
	if( iMagic != VEDIS_TABLE_MAGIC ){
		return 0;
	}
	zBuf += 2; /* Magic */
	SyBigEndianUnpack32(zBuf,pLastID); /* Last Unique ID */
	zBuf += 4;
	SyBigEndianUnpack32(zBuf,pEntry); /* Total number of records */
	zBuf += 4;
	/* Allocate a new table */
	pNew = vedisNewTable(pStore,pName,iType,nHash);
	return pNew;
}
/*
 * Unserialize a table entry.
 */
static int vedisUnserializeEntry(vedis_table *pTable,const unsigned char *zPtr,sxu32 nByte)
{
	const unsigned char *zBuf = zPtr;
	vedis_value sKey,sData;
	sxu32 nData,nKey;
	SyString sEntry;
	sxu16 iMagic;
	sxu32 nId;
	int iType;
	
	if( nByte < 2 /* Magic */ + 4 /* Unique ID */+ 1 /* type */ + 4 /* key length */ + 4 /* data length */ ){
		return VEDIS_CORRUPT;
	}
	SyBigEndianUnpack16(zBuf,&iMagic); /* Magic */
	if( iMagic != VEDIS_TABLE_ENTRY_MAGIC ){
		return VEDIS_CORRUPT;
	}
	zBuf += 2; /* Magic */
	SyBigEndianUnpack32(zBuf,&nId);
	zBuf += 4; /* Unique ID */
	iType = (int)zBuf[0];
	if( iType != VEDIS_TABLE_ENTRY_BLOB_NODE && iType != VEDIS_TABLE_ENTRY_INT_NODE ){
		return VEDIS_CORRUPT;
	}
	zBuf++;
	SyBigEndianUnpack32(zBuf,&nKey); /* Key */
	zBuf += 4;
	SyBigEndianUnpack32(zBuf,&nData); /* Data */
	zBuf += 4;
	/* Sanity check */
	if(  (sxu32)(&zPtr[nByte] - zBuf) != nKey + nData ){
		return VEDIS_CORRUPT;
	}
	SyStringInitFromBuf(&sEntry,zBuf,nKey);
	vedisMemObjInitFromString(pTable->pStore,&sKey,&sEntry);
	zBuf += nKey;
	SyStringInitFromBuf(&sEntry,zBuf,nData);
	vedisMemObjInitFromString(pTable->pStore,&sData,&sEntry);
	/* Perform the insertion */
	if( VEDIS_OK == vedisTableInsert(pTable,nKey > 0 ? &sKey : 0,nData > 0 ? &sData : 0) ){
		/* Set the real ID */
		pTable->pLast->nId = nId;
		if( pTable->nLastID > 0 ){
			pTable->nLastID--;
		}
	}
	/* Clean up and return */
	vedisMemObjRelease(&sKey);
	vedisMemObjRelease(&sData);
	return VEDIS_OK;
}
/*
 * Fetch a table from disk and load its entries.
 */
static vedis_table * vedisTableLoadFromDisk(vedis *pStore,SyString *pName,int iType,sxu32 nHash)
{
	vedis_table *pTable;
	SyBlob sWorker;
	sxu32 nLastID;
	sxu32 nEntry;
	sxu32 nByte;
	sxu32 nOfft;
	sxu32 nId;
	sxu32 n;
	int rc;
	/* Make sure we are dealing with an on-disk data store */
	if( vedisPagerisMemStore(pStore) ){
		return 0;
	}
	/* Go fetch */
	SyBlobInit(&sWorker,&pStore->sMem);
	SyBlobFormat(&sWorker,"vt%d%z",iType,pName);
	nOfft = SyBlobLength(&sWorker);
	rc = vedisKvFetchCallback(pStore,SyBlobData(&sWorker),(int)nOfft,vedisDataConsumer,&sWorker);
	if( rc != VEDIS_OK ){
		goto fail;
	}
	nByte = SyBlobLength(&sWorker) - nOfft;
	/* Unserialize the table */
	nEntry = 0;
	pTable = vedisTableUnserialize(pStore,pName,iType,nHash,(const unsigned char *)SyBlobDataAt(&sWorker,nOfft),nByte,&nEntry,&nLastID);
	if( pTable == 0 ){
		/* No such table */
		goto fail;
	}
	pTable->iFlags |= VEDIS_TABLE_DISK_LOAD;
	pTable->nLastID = nLastID;
	/* Unserialize table entries */
	n = nId = 0;
	for( ;; ){
		if( n >= nEntry ){
			break;
		}
		SyBlobReset(&sWorker);
		/* Read the entry */
		SyBlobFormat(&sWorker,"vt%z%d%u",&pTable->sName,pTable->iTableType,nId++);
		nOfft = SyBlobLength(&sWorker);
		rc = vedisKvFetchCallback(pStore,SyBlobData(&sWorker),nOfft,vedisDataConsumer,&sWorker);
		if( rc == VEDIS_OK ){
			/* Decode the entry */
			vedisUnserializeEntry(pTable,(const unsigned char *)SyBlobDataAt(&sWorker,nOfft),SyBlobLength(&sWorker) - nOfft);
			n++;
		}else if( rc != VEDIS_NOTFOUND ){
			break;
		}
	}
	SyBlobRelease(&sWorker);
	/* Remove stale flags */
	pTable->iFlags &= ~VEDIS_TABLE_DISK_LOAD;
	/* All done */
	return pTable;
fail:
	SyBlobRelease(&sWorker);
	/* No such table */
	return 0;
}
/*
 * Fetch a table and load its entries.
 */
VEDIS_PRIVATE vedis_table * vedisFetchTable(vedis *pDb,vedis_value *pName,int create_new,int iType)
{
	vedis_table *pTable;
	const char *zName;
	SyString sName;
	sxu32 nHash;
	int nByte;
	/* Extract table name */
	zName = vedis_value_to_string(pName,&nByte);
	if( nByte < 1 ){
		/* Invalid table name */
		vedisGenError(pDb,"Invalid table name");
		return 0;
	}
	SyStringInitFromBuf(&sName,zName,nByte);
	/* Fetch table */
	nHash = SyBinHash(sName.zString,sName.nByte);
	pTable = pDb->apTable[nHash & (pDb->nTableSize - 1)];
	for(;;){
		if( pTable == 0 ){
			break;
		}
		if( pTable->iTableType == iType && SyStringCmp(&sName,&pTable->sName,SyMemcmp) == 0 ){
			/* Table found */
			return pTable;
		}
		/* Point to the next entry */
		pTable = pTable->pNext;
	}
	/* Try to load from disk */
	pTable = vedisTableLoadFromDisk(pDb,&sName,iType,nHash);
	if( pTable ){
		return pTable;
	}
	if( !create_new ){
		/* No such table */
		return 0;
	}
	/* fall through, create a new table */
	pTable = vedisNewTable(pDb,&sName,iType,nHash);
	if( !pTable ){
		vedisGenOutofMem(pDb);
		return 0;
	}
	return pTable;
}
/*
 * Return the name of the given table.
 */
VEDIS_PRIVATE  SyString * vedisTableName(vedis_table *pEntry)
{
	return &pEntry->sName;
}
/*
 * Return the next table on the chain.
 */
VEDIS_PRIVATE  vedis_table * vedisTableChain(vedis_table *pEntry)
{
	return pEntry->pNext;
}
/*
 * ----------------------------------------------------------
 * File: parse.c
 * MD5: 90f0b67cbdc5dc75d39c2ce4f9ba3edd
 * ----------------------------------------------------------
 */
/*
 * Symisc Vedis: A Highly Efficient Embeddable Data Store Engine.
 * Copyright (C) 2013, Symisc Systems http://vedis.symisc.net/
 * Version 1.2.6
 * For information on licensing, redistribution of this file, and for a DISCLAIMER OF ALL WARRANTIES
 * please contact Symisc Systems via:
 *       legal@symisc.net
 *       licensing@symisc.net
 *       contact@symisc.net
 * or visit:
 *      http://vedis.symisc.net/
 */
/* $SymiscID: parse.c v1.3 Win7 2013-07-08 05:42 stable <chm@symisc.net> $ */
#ifndef VEDIS_AMALGAMATION
#include "vedisInt.h"
#endif
/* Vedis command Lexer & parser */
/*
 * Tokenize a raw input.
 * Get a single low-level token from the input file. Update the stream pointer so that
 * it points to the first character beyond the extracted token.
 */
static sxi32 vedisTokenizeInput(SyStream *pStream,SyToken *pToken,void *pUserData,void *pCtxData)
{
	const unsigned char *zIn;
	SyString *pStr;
	sxi32 c;
	/* Ignore leading white spaces */
	while( pStream->zText < pStream->zEnd && pStream->zText[0] < 0xc0 && SyisSpace(pStream->zText[0]) ){
		/* Advance the stream cursor */
		if( pStream->zText[0] == '\n' ){
			/* Update line counter */
			pStream->nLine++;
		}
		pStream->zText++;
	}
	if( pStream->zText >= pStream->zEnd ){
		/* End of input reached */
		return SXERR_EOF;
	}
	/* Record token starting position and line */
	pToken->nLine = pStream->nLine;
	pToken->pUserData = 0;
	pStr = &pToken->sData;
	SyStringInitFromBuf(pStr, pStream->zText, 0);
	if( pStream->zText[0] == ';' ){
		pStream->zText++;
		/* A stream of semi-colons */
		while( pStream->zText < pStream->zEnd && pStream->zText[0] < 0xc0 && pStream->zText[0] == ';' ){
			pStream->zText++;
		}
		/* Mark the token */
		pToken->nType = VEDIS_TK_SEMI;
		/* Record token length */
		pStr->nByte = (sxu32)((const char *)pStream->zText-pStr->zString);
	}else if( SyisDigit(pStream->zText[0]) ){
		pStream->zText++;
		/* Decimal digit stream */
		while( pStream->zText < pStream->zEnd && pStream->zText[0] < 0xc0 && SyisDigit(pStream->zText[0]) ){
			pStream->zText++;
		}
		/* Mark the token as integer until we encounter a real number */
		pToken->nType = VEDIS_TK_INTEGER;
		if( pStream->zText < pStream->zEnd ){
			c = pStream->zText[0];
			if( c == '.' ){
				/* Real number */
				pStream->zText++;
				while( pStream->zText < pStream->zEnd && pStream->zText[0] < 0xc0 && SyisDigit(pStream->zText[0]) ){
					pStream->zText++;
				}
				if( pStream->zText < pStream->zEnd ){
					c = pStream->zText[0];
					if( c=='e' || c=='E' ){
						pStream->zText++;
						if( pStream->zText < pStream->zEnd ){
							c = pStream->zText[0];
							if( (c =='+' || c=='-') && &pStream->zText[1] < pStream->zEnd  &&
								pStream->zText[1] < 0xc0 && SyisDigit(pStream->zText[1]) ){
									pStream->zText++;
							}
							while( pStream->zText < pStream->zEnd && pStream->zText[0] < 0xc0 && SyisDigit(pStream->zText[0]) ){
								pStream->zText++;
							}
						}
					}
				}
				pToken->nType = VEDIS_TK_REAL;
			}else if( c=='e' || c=='E' ){
				SXUNUSED(pUserData); /* Prevent compiler warning */
				SXUNUSED(pCtxData);
				pStream->zText++;
				if( pStream->zText < pStream->zEnd ){
					c = pStream->zText[0];
					if( (c =='+' || c=='-') && &pStream->zText[1] < pStream->zEnd  &&
						pStream->zText[1] < 0xc0 && SyisDigit(pStream->zText[1]) ){
							pStream->zText++;
					}
					while( pStream->zText < pStream->zEnd && pStream->zText[0] < 0xc0 && SyisDigit(pStream->zText[0]) ){
						pStream->zText++;
					}
				}
				pToken->nType = VEDIS_TK_REAL;
			}else if( c == 'x' || c == 'X' ){
				/* Hex digit stream */
				pStream->zText++;
				while( pStream->zText < pStream->zEnd && pStream->zText[0] < 0xc0 && SyisHex(pStream->zText[0]) ){
					pStream->zText++;
				}
			}else if(c  == 'b' || c == 'B' ){
				/* Binary digit stream */
				pStream->zText++;
				while( pStream->zText < pStream->zEnd && (pStream->zText[0] == '0' || pStream->zText[0] == '1') ){
					pStream->zText++;
				}
			}
		}
		/* Record token length */
		pStr->nByte = (sxu32)((const char *)pStream->zText-pStr->zString);
	}else if( pStream->zText[0] == '"' || pStream->zText[0] == '\'' ){
		/* Quoted string */
		c = pStream->zText[0];
		pStream->zText++;
		pStr->zString++;
		while( pStream->zText < pStream->zEnd ){
			if( pStream->zText[0] == c  ){
				if( pStream->zText[-1] != '\\' ){
					break;
				}
			}
			if( pStream->zText[0] == '\n' ){
				pStream->nLine++;
			}
			pStream->zText++;
		}
		/* Record token length and type */
		pStr->nByte = (sxu32)((const char *)pStream->zText-pStr->zString);
		pToken->nType = VEDIS_TK_STREAM;
		/* Jump the trailing quote */
		pStream->zText++;
	}else{
		/* The following code fragment is taken verbatim from the xPP source tree.
		 * xPP is a modern embeddable macro processor with advanced features useful for
		 * application seeking for a production quality, ready to use macro processor.
		 * xPP is a widely used library developed and maintened by Symisc Systems.
		 * You can reach the xPP home page by following this link:
		 * http://symisc.net/
		 */
		/* Isolate UTF-8 or alphanumeric stream */
		if( pStream->zText[0] < 0xc0 ){
			pStream->zText++;
		}
		for(;;){
			zIn = pStream->zText;
			if( zIn[0] >= 0xc0 ){
				zIn++;
				/* UTF-8 stream */
				while( zIn < pStream->zEnd && ((zIn[0] & 0xc0) == 0x80) ){
					zIn++;
				}
			}
			/* Delimit the stream */
			while( zIn < pStream->zEnd && zIn[0] < 0xc0 && zIn[0] != ';' && !SyisSpace(zIn[0]) ){
				zIn++;
			}
			if( zIn == pStream->zText ){
				/* End of the stream */
				break;
			}
			/* Synchronize pointers */
			pStream->zText = zIn;
		}
		/* Record token length */
		pStr->nByte = (sxu32)((const char *)pStream->zText-pStr->zString);
		/* A simple identifier */
		pToken->nType = VEDIS_TK_STREAM;
	}
	/* Tell the upper-layer to save the extracted token for later processing */
	return SXRET_OK;
}
/*
 * Tokenize a raw input. 
 */
static sxi32 vedisTokenize(const char *zInput,sxu32 nLen,SySet *pOut)
{
	SyLex sLexer;
	sxi32 rc;
	/* Initialize the lexer */
	rc = SyLexInit(&sLexer, &(*pOut),vedisTokenizeInput,0);
	if( rc != SXRET_OK ){
		return rc;
	}
	/* Tokenize input */
	rc = SyLexTokenizeInput(&sLexer, zInput, nLen, 0, 0, 0);
	/* Release the lexer */
	SyLexRelease(&sLexer);
	/* Tokenization result */
	return rc;
}
/*
 * Vedis parser state is recorded in an instance of the following structure.
 */
typedef struct vedis_gen_state vedis_gen_state;
struct vedis_gen_state
{
	SyToken *pIn;  /* Token stream */
	SyToken *pEnd; /* End of the token stream */
	vedis *pVedis;    /* Vedis handle  */
};
static int vedisInitContext(vedis_context *pCtx,vedis *pVedis,vedis_cmd *pCmd)
{
	pCtx->pVedis = pVedis;
	pCtx->pCmd = pCmd;
	SyBlobInit(&pCtx->sWorker,&pVedis->sMem);
	SySetInit(&pCtx->sVar, &pVedis->sMem, sizeof(vedis_value *));
	pCtx->pRet = &pVedis->sResult;
	/* Invalidate any prior representation */
	vedisMemObjRelease(pCtx->pRet);
	return VEDIS_OK;
}
VEDIS_PRIVATE SyBlob * VedisContextResultBuffer(vedis_context *pCtx)
{
	return &pCtx->pRet->sBlob;
}
VEDIS_PRIVATE SyBlob * VedisContextWorkingBuffer(vedis_context *pCtx)
{
	return &pCtx->sWorker;
}
static void vedisReleaseContext(vedis_context *pCtx)
{
	sxu32 n;
	if( SySetUsed(&pCtx->sVar) > 0 ){
		/* Context alloacated values */
		vedis_value **apObj = (vedis_value **)SySetBasePtr(&pCtx->sVar);
		for( n = 0 ; n < SySetUsed(&pCtx->sVar) ; ++n ){
			if( apObj[n] == 0 ){
				/* Already released */
				continue;
			}
			vedisMemObjRelease(apObj[n]);
			SyMemBackendPoolFree(&pCtx->pVedis->sMem, apObj[n]);
		}
		SySetRelease(&pCtx->sVar);
	}
	SyBlobRelease(&pCtx->sWorker);
}
static void vedisObjContainerDestroy(SySet *aValues,vedis *pVedis)
{
	vedis_value **apValues = (vedis_value **)SySetBasePtr(aValues);
	sxu32 n;
	for( n = 0 ; n < SySetUsed(aValues) ; ++n ){
		vedis_value *pValue = apValues[n];
		/* Destroy the object */
		vedisObjectValueDestroy(pVedis,pValue);
	}
	SySetRelease(aValues);
}
static int vedisExec(vedis_gen_state *pGen)
{
	vedis_value *pValue;
	vedis_context sCtx;
	vedis_cmd *pCmd;
	vedis *pStore;
	SySet sValue;
	int rc;
	/* Get the target command */
	if( !(pGen->pIn->nType & VEDIS_TK_STREAM) ){
		vedisGenError(pGen->pVedis,"Invalid Vedis command");
		return SXERR_INVALID;
	}
	pStore = pGen->pVedis;
	/* Extract it */
	pCmd = vedisFetchCommand(pStore,&pGen->pIn->sData);
	if( pCmd == 0 ){
		vedisGenErrorFormat(pStore,"Unknown Vedis command: '%z'",&pGen->pIn->sData);
		return SXERR_UNKNOWN;
	}
	pGen->pIn++;
	/* Collect command arguments */
	SySetInit(&sValue,&pStore->sMem,sizeof(vedis_value *));
	while( pGen->pIn < pGen->pEnd && (pGen->pIn->nType != VEDIS_TK_SEMI /*';'*/) ){
		pValue = vedisNewObjectValue(pStore,pGen->pIn);
		if( pValue ){
			SySetPut(&sValue,(const void *)&pValue);
		}
		/* Point to the next token */
		pGen->pIn++;
	}
	/* Init the call context */
	vedisInitContext(&sCtx,pStore,pCmd);
	/* Invoke the command */
	rc = pCmd->xCmd(&sCtx,(int)SySetUsed(&sValue),(vedis_value **)SySetBasePtr(&sValue));
	if( rc == VEDIS_ABORT ){
		vedisGenErrorFormat(pGen->pVedis,"Vedis command '%z' request an operation abort",&pCmd->sName);
	}else{
		rc = VEDIS_OK;
	}
	/* Invoke any output consumer callback */
	if( pStore->xResultConsumer && rc == VEDIS_OK ){
		rc = pStore->xResultConsumer(sCtx.pRet,pStore->pUserData);
		if( rc != VEDIS_ABORT ){
			rc = VEDIS_OK;
		}
	}
	/* Cleanup */
	vedisReleaseContext(&sCtx);
	vedisObjContainerDestroy(&sValue,pGen->pVedis);
	return rc;
}

VEDIS_PRIVATE int vedisProcessInput(vedis *pVedis,const char *zInput,sxu32 nByte)
{
	SySet sToken;
	int rc;
	/* Prepare the tokenizer */
	SySetInit(&sToken,&pVedis->sMem,sizeof(SyToken));
	/* Tokenize the input */
	rc = vedisTokenize(zInput,nByte,&sToken);
	if( rc != VEDIS_OK ){
		goto fail;
	}
	rc = VEDIS_OK;
	if( SySetUsed(&sToken) > 0 ){
		vedis_gen_state sGen;
		/* Init the parser state */
		sGen.pIn = (SyToken *)SySetBasePtr(&sToken);
		sGen.pEnd = &sGen.pIn[SySetUsed(&sToken)];
		sGen.pVedis = pVedis;
		/* Process the pipelined commands */
		for(;;){
			while( sGen.pIn < sGen.pEnd && sGen.pIn->nType == VEDIS_TK_SEMI ){
				/* Discard leading and trailing semi-colons */
				sGen.pIn++;
			}
			if( sGen.pIn >= sGen.pEnd ){
				/* End of the vedis input */
				break;
			}
			/* Execute the command if available */
			rc = vedisExec(&sGen);
			if( rc != VEDIS_OK ){
				break;
			}
		}
	}
	/* Fall through */
fail:
	/* Cleanup */
	SySetRelease(&sToken);
	return rc;
}
/*
 * ----------------------------------------------------------
 * File: pager.c
 * MD5: b4db2677f77d8b4f49a90287106a7de1
 * ----------------------------------------------------------
 */
/*
 * Symisc Vedis: An Embeddable NoSQL (Post Modern) Database Engine.
 * Copyright (C) 2012-2013, Symisc Systems http://vedis.org/
 * Version 1.1.6
 * For information on licensing, redistribution of this file, and for a DISCLAIMER OF ALL WARRANTIES
 * please contact Symisc Systems via:
 *       legal@symisc.net
 *       licensing@symisc.net
 *       contact@symisc.net
 * or visit:
 *      http://vedis.org/licensing.html
 */
 /* $SymiscID: pager.c v1.1 Win7 2012-11-29 03:46 stable <chm@symisc.net> $ */
#ifndef VEDIS_AMALGAMATION
#include "vedisInt.h"
#endif
/*
** This file implements the pager and the transaction manager for UnQLite (Mostly inspired from the SQLite3 Source tree).
**
** The Pager.eState variable stores the current 'state' of a pager. A
** pager may be in any one of the seven states shown in the following
** state diagram.
**
**                            OPEN <------+------+
**                              |         |      |
**                              V         |      |
**               +---------> READER-------+      |
**               |              |                |
**               |              V                |
**               |<-------WRITER_LOCKED--------->| 
**               |              |                |  
**               |              V                |
**               |<------WRITER_CACHEMOD-------->|
**               |              |                |
**               |              V                |
**               |<-------WRITER_DBMOD---------->|
**               |              |                |
**               |              V                |
**               +<------WRITER_FINISHED-------->+
** 
**  OPEN:
**
**    The pager starts up in this state. Nothing is guaranteed in this
**    state - the file may or may not be locked and the database size is
**    unknown. The database may not be read or written.
**
**    * No read or write transaction is active.
**    * Any lock, or no lock at all, may be held on the database file.
**    * The dbSize and dbOrigSize variables may not be trusted.
**
**  READER:
**
**    In this state all the requirements for reading the database in 
**    rollback mode are met. Unless the pager is (or recently
**    was) in exclusive-locking mode, a user-level read transaction is 
**    open. The database size is known in this state.
** 
**    * A read transaction may be active (but a write-transaction cannot).
**    * A SHARED or greater lock is held on the database file.
**    * The dbSize variable may be trusted (even if a user-level read 
**      transaction is not active). The dbOrigSize variables
**      may not be trusted at this point.
**    * Even if a read-transaction is not open, it is guaranteed that 
**      there is no hot-journal in the file-system.
**
**  WRITER_LOCKED:
**
**    The pager moves to this state from READER when a write-transaction
**    is first opened on the database. In WRITER_LOCKED state, all locks 
**    required to start a write-transaction are held, but no actual 
**    modifications to the cache or database have taken place.
**
**    In rollback mode, a RESERVED or (if the transaction was opened with 
**    EXCLUSIVE flag) EXCLUSIVE lock is obtained on the database file when
**    moving to this state, but the journal file is not written to or opened 
**    to in this state. If the transaction is committed or rolled back while 
**    in WRITER_LOCKED state, all that is required is to unlock the database 
**    file.
**
**    * A write transaction is active.
**    * If the connection is open in rollback-mode, a RESERVED or greater 
**      lock is held on the database file.
**    * The dbSize and dbOrigSize variables are all valid.
**    * The contents of the pager cache have not been modified.
**    * The journal file may or may not be open.
**    * Nothing (not even the first header) has been written to the journal.
**
**  WRITER_CACHEMOD:
**
**    A pager moves from WRITER_LOCKED state to this state when a page is
**    first modified by the upper layer. In rollback mode the journal file
**    is opened (if it is not already open) and a header written to the
**    start of it. The database file on disk has not been modified.
**
**    * A write transaction is active.
**    * A RESERVED or greater lock is held on the database file.
**    * The journal file is open and the first header has been written 
**      to it, but the header has not been synced to disk.
**    * The contents of the page cache have been modified.
**
**  WRITER_DBMOD:
**
**    The pager transitions from WRITER_CACHEMOD into WRITER_DBMOD state
**    when it modifies the contents of the database file.
**
**    * A write transaction is active.
**    * An EXCLUSIVE or greater lock is held on the database file.
**    * The journal file is open and the first header has been written 
**      and synced to disk.
**    * The contents of the page cache have been modified (and possibly
**      written to disk).
**
**  WRITER_FINISHED:
**
**    A rollback-mode pager changes to WRITER_FINISHED state from WRITER_DBMOD
**    state after the entire transaction has been successfully written into the
**    database file. In this state the transaction may be committed simply
**    by finalizing the journal file. Once in WRITER_FINISHED state, it is 
**    not possible to modify the database further. At this point, the upper 
**    layer must either commit or rollback the transaction.
**
**    * A write transaction is active.
**    * An EXCLUSIVE or greater lock is held on the database file.
**    * All writing and syncing of journal and database data has finished.
**      If no error occured, all that remains is to finalize the journal to
**      commit the transaction. If an error did occur, the caller will need
**      to rollback the transaction. 
**  
**
*/
#define PAGER_OPEN                  0
#define PAGER_READER                1
#define PAGER_WRITER_LOCKED         2
#define PAGER_WRITER_CACHEMOD       3
#define PAGER_WRITER_DBMOD          4
#define PAGER_WRITER_FINISHED       5
/*
** Journal files begin with the following magic string.  The data
** was obtained from /dev/random.  It is used only as a sanity check.
**
** NOTE: These values must be different from the one used by SQLite3
** to avoid journal file collision.
**
*/
static const unsigned char aJournalMagic[] = {
  0xc1, 0xd2, 0xfa, 0x77, 0x2b, 0x18, 0x27, 0x2a,
};
/*
** The journal header size for this pager. This is usually the same 
** size as a single disk sector. See also setSectorSize().
*/
#define JOURNAL_HDR_SZ(pPager) (pPager->iSectorSize)
/*
 * Database page handle.
 * Each raw disk page is represented in memory by an instance
 * of the following structure.
 */
typedef struct Page Page;
struct Page {
  /* Must correspond to vedis_page */
  unsigned char *zData;           /* Content of this page */
  void *pUserData;                /* Extra content */
  pgno pgno;                      /* Page number for this page */
  /**********************************************************************
  ** Elements above are public.  All that follows is private to pcache.c
  ** and should not be accessed by other modules.
  */
  Pager *pPager;                 /* The pager this page is part of */
  int flags;                     /* Page flags defined below */
  int nRef;                      /* Number of users of this page */
  Page *pNext, *pPrev;    /* A list of all pages */
  Page *pDirtyNext;             /* Next element in list of dirty pages */
  Page *pDirtyPrev;             /* Previous element in list of dirty pages */
  Page *pNextCollide,*pPrevCollide; /* Collission chain */
  Page *pNextHot,*pPrevHot;    /* Hot dirty pages chain */
};
/* Bit values for Page.flags */
#define PAGE_DIRTY             0x002  /* Page has changed */
#define PAGE_NEED_SYNC         0x004  /* fsync the rollback journal before
                                       ** writing this page to the database */
#define PAGE_DONT_WRITE        0x008  /* Dont write page content to disk */
#define PAGE_NEED_READ         0x010  /* Content is unread */
#define PAGE_IN_JOURNAL        0x020  /* Page written to the journal */
#define PAGE_HOT_DIRTY         0x040  /* Hot dirty page */
#define PAGE_DONT_MAKE_HOT     0x080  /* Dont make this page Hot. In other words,
									   * do not link it to the hot dirty list.
									   */
/*
 * Each active database pager is represented by an instance of
 * the following structure.
 */
struct Pager
{
  SyMemBackend *pAllocator;      /* Memory backend */
  vedis *pDb;                  /* DB handle that own this instance */
  vedis_kv_engine *pEngine;    /* Underlying KV storage engine */
  char *zFilename;               /* Name of the database file */
  char *zJournal;                /* Name of the journal file */
  vedis_vfs *pVfs;             /* Underlying virtual file system */
  vedis_file *pfd,*pjfd;       /* File descriptors for database and journal */
  pgno dbSize;                   /* Number of pages in the file */
  pgno dbOrigSize;               /* dbSize before the current change */
  sxi64 dbByteSize;              /* Database size in bytes */
  void *pMmap;                   /* Read-only Memory view (mmap) of the whole file if requested (VEDIS_OPEN_MMAP). */
  sxu32 nRec;                    /* Number of pages written to the journal */
  SyPRNGCtx sPrng;               /* PRNG Context */
  sxu32 cksumInit;               /* Quasi-random value added to every checksum */
  sxu32 iOpenFlags;              /* Flag passed to vedis_open() after processing */
  sxi64 iJournalOfft;            /* Journal offset we are reading from */
  int (*xBusyHandler)(void *);   /* Busy handler */
  void *pBusyHandlerArg;         /* First arg to xBusyHandler() */
  void (*xPageUnpin)(void *);    /* Page Unpin callback */
  void (*xPageReload)(void *);   /* Page Reload callback */
  int (*xCommit)(void *);        /* On commit user callback */
  void *pCommitData;             /* First arg to xCommit() */
  Bitvec *pVec;                  /* Bitmap */
  Page *pHeader;                 /* Page one of the database (Unqlite header) */
  Sytm tmCreate;                 /* Database creation time */
  SyString sKv;                  /* Underlying Key/Value storage engine name */
  int iState;                    /* Pager state */
  int iLock;                     /* Lock state */
  sxi32 iFlags;                  /* Control flags (see below) */
  int is_mem;                    /* True for an in-memory database */
  int is_rdonly;                 /* True for a read-only database */
  int no_jrnl;                   /* TRUE to omit journaling */
  int iPageSize;                 /* Page size in bytes (default 4K) */
  int iSectorSize;               /* Size of a single sector on disk */
  unsigned char *zTmpPage;       /* Temporary page */
  Page *pFirstDirty;             /* First dirty pages */
  Page *pDirty;                  /* Transient list of dirty pages */
  Page *pAll;                    /* List of all pages */
  Page *pHotDirty;               /* List of hot dirty pages */
  Page *pFirstHot;               /* First hot dirty page */
  sxu32 nHot;                    /* Total number of hot dirty pages */
  Page **apHash;                 /* Page table */
  sxu32 nSize;                   /* apHash[] size: Must be a power of two  */
  sxu32 nPage;                   /* Total number of page loaded in memory */
  sxu32 nCacheMax;               /* Maximum page to cache*/
};
/* Control flags */
#define PAGER_CTRL_COMMIT_ERR   0x001 /* Commit error */
#define PAGER_CTRL_DIRTY_COMMIT 0x002 /* Dirty commit has been applied */ 
/*
** Read a 32-bit integer from the given file descriptor. 
** All values are stored on disk as big-endian.
*/
static int ReadInt32(vedis_file *pFd,sxu32 *pOut,sxi64 iOfft)
{
	unsigned char zBuf[4];
	int rc;
	rc = vedisOsRead(pFd,zBuf,sizeof(zBuf),iOfft);
	if( rc != VEDIS_OK ){
		return rc;
	}
	SyBigEndianUnpack32(zBuf,pOut);
	return VEDIS_OK;
}
/*
** Read a 64-bit integer from the given file descriptor. 
** All values are stored on disk as big-endian.
*/
static int ReadInt64(vedis_file *pFd,sxu64 *pOut,sxi64 iOfft)
{
	unsigned char zBuf[8];
	int rc;
	rc = vedisOsRead(pFd,zBuf,sizeof(zBuf),iOfft);
	if( rc != VEDIS_OK ){
		return rc;
	}
	SyBigEndianUnpack64(zBuf,pOut);
	return VEDIS_OK;
}
/*
** Write a 32-bit integer into the given file descriptor.
*/
static int WriteInt32(vedis_file *pFd,sxu32 iNum,sxi64 iOfft)
{
	unsigned char zBuf[4];
	int rc;
	SyBigEndianPack32(zBuf,iNum);
	rc = vedisOsWrite(pFd,zBuf,sizeof(zBuf),iOfft);
	return rc;
}
/*
** Write a 64-bit integer into the given file descriptor.
*/
static int WriteInt64(vedis_file *pFd,sxu64 iNum,sxi64 iOfft)
{
	unsigned char zBuf[8];
	int rc;
	SyBigEndianPack64(zBuf,iNum);
	rc = vedisOsWrite(pFd,zBuf,sizeof(zBuf),iOfft);
	return rc;
}
/*
** The maximum allowed sector size. 64KiB. If the xSectorsize() method 
** returns a value larger than this, then MAX_SECTOR_SIZE is used instead.
** This could conceivably cause corruption following a power failure on
** such a system. This is currently an undocumented limit.
*/
#define MAX_SECTOR_SIZE 0x10000
/*
** Get the size of a single sector on disk.
** The sector size will be used used  to determine the size
** and alignment of journal header and within created journal files.
**
** The default sector size is set to 512.
*/
static int GetSectorSize(vedis_file *pFd)
{
	int iSectorSize = VEDIS_DEFAULT_SECTOR_SIZE;
	if( pFd ){
		iSectorSize = vedisOsSectorSize(pFd);
		if( iSectorSize < 32 ){
			iSectorSize = 512;
		}
		if( iSectorSize > MAX_SECTOR_SIZE ){
			iSectorSize = MAX_SECTOR_SIZE;
		}
	}
	return iSectorSize;
}
/* Hash function for page number  */
#define PAGE_HASH(PNUM) (PNUM)
/*
 * Fetch a page from the cache.
 */
static Page * pager_fetch_page(Pager *pPager,pgno page_num)
{
	Page *pEntry;
	if( pPager->nPage < 1 ){
		/* Don't bother hashing */
		return 0;
	}
	/* Perform the lookup */
	pEntry = pPager->apHash[PAGE_HASH(page_num) & (pPager->nSize - 1)];
	for(;;){
		if( pEntry == 0 ){
			break;
		}
		if( pEntry->pgno == page_num ){
			return pEntry;
		}
		/* Point to the next entry in the colission chain */
		pEntry = pEntry->pNextCollide;
	}
	/* No such page */
	return 0;
}
/*
 * Allocate and initialize a new page.
 */
static Page * pager_alloc_page(Pager *pPager,pgno num_page)
{
	Page *pNew;
	
	pNew = (Page *)SyMemBackendPoolAlloc(pPager->pAllocator,sizeof(Page)+pPager->iPageSize);
	if( pNew == 0 ){
		return 0;
	}
	/* Zero the structure */
	SyZero(pNew,sizeof(Page)+pPager->iPageSize);
	/* Page data */
	pNew->zData = (unsigned char *)&pNew[1];
	/* Fill in the structure */
	pNew->pPager = pPager;
	pNew->nRef = 1;
	pNew->pgno = num_page;
	return pNew;
}
/*
 * Increment the reference count of a given page.
 */
static void page_ref(Page *pPage)
{
	pPage->nRef++;
}
/*
 * Release an in-memory page after its reference count reach zero.
 */
static int pager_release_page(Pager *pPager,Page *pPage)
{
	int rc = VEDIS_OK;
	if( !(pPage->flags & PAGE_DIRTY)){
		/* Invoke the unpin callback if available */
		if( pPager->xPageUnpin && pPage->pUserData ){
			pPager->xPageUnpin(pPage->pUserData);
		}
		pPage->pUserData = 0;
		SyMemBackendPoolFree(pPager->pAllocator,pPage);
	}else{
		/* Dirty page, it will be released later when a dirty commit
		 * or the final commit have been applied.
		 */
		rc = VEDIS_LOCKED;
	}
	return rc;
}
/* Forward declaration */
static int pager_unlink_page(Pager *pPager,Page *pPage);
/*
 * Decrement the reference count of a given page.
 */
static void page_unref(Page *pPage)
{
	pPage->nRef--;
	if( pPage->nRef < 1	){
		Pager *pPager = pPage->pPager;
		if( !(pPage->flags & PAGE_DIRTY)  ){
			pager_unlink_page(pPager,pPage);
			/* Release the page */
			pager_release_page(pPager,pPage);
		}else{
			if( pPage->flags & PAGE_DONT_MAKE_HOT ){
				/* Do not add this page to the hot dirty list */
				return;
			}
			if( !(pPage->flags & PAGE_HOT_DIRTY) ){
				/* Add to the hot dirty list */
				pPage->pPrevHot = 0;
				if( pPager->pFirstHot == 0 ){
					pPager->pFirstHot = pPager->pHotDirty = pPage;
				}else{
					pPage->pNextHot = pPager->pHotDirty;
					if( pPager->pHotDirty ){
						pPager->pHotDirty->pPrevHot = pPage;
					}
					pPager->pHotDirty = pPage;
				}
				pPager->nHot++;
				pPage->flags |= PAGE_HOT_DIRTY;
			}
		}
	}
}
/*
 * Link a freshly created page to the list of active page.
 */
static int pager_link_page(Pager *pPager,Page *pPage)
{
	sxu32 nBucket;
	/* Install in the corresponding bucket */
	nBucket = PAGE_HASH(pPage->pgno) & (pPager->nSize - 1);
	pPage->pNextCollide = pPager->apHash[nBucket];
	if( pPager->apHash[nBucket] ){
		pPager->apHash[nBucket]->pPrevCollide = pPage;
	}
	pPager->apHash[nBucket] = pPage;
	/* Link to the list of active pages */
	MACRO_LD_PUSH(pPager->pAll,pPage);
	pPager->nPage++;
	if( (pPager->nPage >= pPager->nSize * 4)  && pPager->nPage < 100000 ){
		/* Grow the hashtable */
		sxu32 nNewSize = pPager->nSize << 1;
		Page *pEntry,**apNew;
		sxu32 n;
		apNew = (Page **)SyMemBackendAlloc(pPager->pAllocator, nNewSize * sizeof(Page *));
		if( apNew ){
			sxu32 iBucket;
			/* Zero the new table */
			SyZero((void *)apNew, nNewSize * sizeof(Page *));
			/* Rehash all entries */
			n = 0;
			pEntry = pPager->pAll;
			for(;;){
				/* Loop one */
				if( n >= pPager->nPage ){
					break;
				}
				pEntry->pNextCollide = pEntry->pPrevCollide = 0;
				/* Install in the new bucket */
				iBucket = PAGE_HASH(pEntry->pgno) & (nNewSize - 1);
				pEntry->pNextCollide = apNew[iBucket];
				if( apNew[iBucket] ){
					apNew[iBucket]->pPrevCollide = pEntry;
				}
				apNew[iBucket] = pEntry;
				/* Point to the next entry */
				pEntry = pEntry->pNext;
				n++;
			}
			/* Release the old table and reflect the change */
			SyMemBackendFree(pPager->pAllocator,(void *)pPager->apHash);
			pPager->apHash = apNew;
			pPager->nSize  = nNewSize;
		}
	}
	return VEDIS_OK;
}
/*
 * Unlink a page from the list of active pages.
 */
static int pager_unlink_page(Pager *pPager,Page *pPage)
{
	if( pPage->pNextCollide ){
		pPage->pNextCollide->pPrevCollide = pPage->pPrevCollide;
	}
	if( pPage->pPrevCollide ){
		pPage->pPrevCollide->pNextCollide = pPage->pNextCollide;
	}else{
		sxu32 nBucket = PAGE_HASH(pPage->pgno) & (pPager->nSize - 1);
		pPager->apHash[nBucket] = pPage->pNextCollide;
	}
	MACRO_LD_REMOVE(pPager->pAll,pPage);
	pPager->nPage--;
	return VEDIS_OK;
}
/*
 * Update the content of a cached page.
 */
static int pager_fill_page(Pager *pPager,pgno iNum,void *pContents)
{
	Page *pPage;
	/* Fetch the page from the catch */
	pPage = pager_fetch_page(pPager,iNum);
	if( pPage == 0 ){
		return SXERR_NOTFOUND;
	}
	/* Reflect the change */
	SyMemcpy(pContents,pPage->zData,pPager->iPageSize);

	return VEDIS_OK;
}
/*
 * Read the content of a page from disk.
 */
static int pager_get_page_contents(Pager *pPager,Page *pPage,int noContent)
{
	int rc = VEDIS_OK;
	if( pPager->is_mem || noContent || pPage->pgno >= pPager->dbSize ){
		/* Do not bother reading, zero the page contents only */
		SyZero(pPage->zData,pPager->iPageSize);
		return VEDIS_OK;
	}
	if( (pPager->iOpenFlags & VEDIS_OPEN_MMAP) && (pPager->pMmap /* Paranoid edition */) ){
		unsigned char *zMap = (unsigned char *)pPager->pMmap;
		pPage->zData = &zMap[pPage->pgno * pPager->iPageSize];
	}else{
		/* Read content */
		rc = vedisOsRead(pPager->pfd,pPage->zData,pPager->iPageSize,pPage->pgno * pPager->iPageSize);
	}
	return rc;
}
/*
 * Add a page to the dirty list.
 */
static void pager_page_to_dirty_list(Pager *pPager,Page *pPage)
{
	if( pPage->flags & PAGE_DIRTY ){
		/* Already set */
		return;
	}
	/* Mark the page as dirty */
	pPage->flags |= PAGE_DIRTY|PAGE_NEED_SYNC|PAGE_IN_JOURNAL;
	/* Link to the list */
	pPage->pDirtyPrev = 0;
	pPage->pDirtyNext = pPager->pDirty;
	if( pPager->pDirty ){
		pPager->pDirty->pDirtyPrev = pPage;
	}
	pPager->pDirty = pPage;
	if( pPager->pFirstDirty == 0 ){
		pPager->pFirstDirty = pPage;
	}
}
/*
 * Merge sort.
 * The merge sort implementation is based on the one used by
 * the PH7 Embeddable PHP Engine (http://ph7.symisc.net/).
 */
/*
** Inputs:
**   a:       A sorted, null-terminated linked list.  (May be null).
**   b:       A sorted, null-terminated linked list.  (May be null).
**   cmp:     A pointer to the comparison function.
**
** Return Value:
**   A pointer to the head of a sorted list containing the elements
**   of both a and b.
**
** Side effects:
**   The "next", "prev" pointers for elements in the lists a and b are
**   changed.
*/
static Page * page_merge_dirty(Page *pA, Page *pB)
{
	Page result, *pTail;
    /* Prevent compiler warning */
	result.pDirtyNext = result.pDirtyPrev = 0;
	pTail = &result;
	while( pA && pB ){
		if( pA->pgno < pB->pgno ){
			pTail->pDirtyPrev = pA;
			pA->pDirtyNext = pTail;
			pTail = pA;
			pA = pA->pDirtyPrev;
		}else{
			pTail->pDirtyPrev = pB;
			pB->pDirtyNext = pTail;
			pTail = pB;
			pB = pB->pDirtyPrev;
		}
	}
	if( pA ){
		pTail->pDirtyPrev = pA;
		pA->pDirtyNext = pTail;
	}else if( pB ){
		pTail->pDirtyPrev = pB;
		pB->pDirtyNext = pTail;
	}else{
		pTail->pDirtyPrev = pTail->pDirtyNext = 0;
	}
	return result.pDirtyPrev;
}
/*
** Inputs:
**   Map:       Input hashmap
**   cmp:       A comparison function.
**
** Return Value:
**   Sorted hashmap.
**
** Side effects:
**   The "next" pointers for elements in list are changed.
*/
#define N_SORT_BUCKET  32
static Page * pager_get_dirty_pages(Pager *pPager)
{
	Page *a[N_SORT_BUCKET], *p, *pIn;
	sxu32 i;
	if( pPager->pFirstDirty == 0 ){
		/* Don't bother sorting, the list is already empty */
		return 0;
	}
	SyZero(a, sizeof(a));
	/* Point to the first inserted entry */
	pIn = pPager->pFirstDirty;
	while( pIn ){
		p = pIn;
		pIn = p->pDirtyPrev;
		p->pDirtyPrev = 0;
		for(i=0; i<N_SORT_BUCKET-1; i++){
			if( a[i]==0 ){
				a[i] = p;
				break;
			}else{
				p = page_merge_dirty(a[i], p);
				a[i] = 0;
			}
		}
		if( i==N_SORT_BUCKET-1 ){
			/* To get here, there need to be 2^(N_SORT_BUCKET) elements in he input list.
			 * But that is impossible.
			 */
			a[i] = page_merge_dirty(a[i], p);
		}
	}
	p = a[0];
	for(i=1; i<N_SORT_BUCKET; i++){
		p = page_merge_dirty(p,a[i]);
	}
	p->pDirtyNext = 0;
	return p;
}
/*
 * See block comment above.
 */
static Page * page_merge_hot(Page *pA, Page *pB)
{
	Page result, *pTail;
    /* Prevent compiler warning */
	result.pNextHot = result.pPrevHot = 0;
	pTail = &result;
	while( pA && pB ){
		if( pA->pgno < pB->pgno ){
			pTail->pPrevHot = pA;
			pA->pNextHot = pTail;
			pTail = pA;
			pA = pA->pPrevHot;
		}else{
			pTail->pPrevHot = pB;
			pB->pNextHot = pTail;
			pTail = pB;
			pB = pB->pPrevHot;
		}
	}
	if( pA ){
		pTail->pPrevHot = pA;
		pA->pNextHot = pTail;
	}else if( pB ){
		pTail->pPrevHot = pB;
		pB->pNextHot = pTail;
	}else{
		pTail->pPrevHot = pTail->pNextHot = 0;
	}
	return result.pPrevHot;
}
/*
** Inputs:
**   Map:       Input hashmap
**   cmp:       A comparison function.
**
** Return Value:
**   Sorted hashmap.
**
** Side effects:
**   The "next" pointers for elements in list are changed.
*/
#define N_SORT_BUCKET  32
static Page * pager_get_hot_pages(Pager *pPager)
{
	Page *a[N_SORT_BUCKET], *p, *pIn;
	sxu32 i;
	if( pPager->pFirstHot == 0 ){
		/* Don't bother sorting, the list is already empty */
		return 0;
	}
	SyZero(a, sizeof(a));
	/* Point to the first inserted entry */
	pIn = pPager->pFirstHot;
	while( pIn ){
		p = pIn;
		pIn = p->pPrevHot;
		p->pPrevHot = 0;
		for(i=0; i<N_SORT_BUCKET-1; i++){
			if( a[i]==0 ){
				a[i] = p;
				break;
			}else{
				p = page_merge_hot(a[i], p);
				a[i] = 0;
			}
		}
		if( i==N_SORT_BUCKET-1 ){
			/* To get here, there need to be 2^(N_SORT_BUCKET) elements in he input list.
			 * But that is impossible.
			 */
			a[i] = page_merge_hot(a[i], p);
		}
	}
	p = a[0];
	for(i=1; i<N_SORT_BUCKET; i++){
		p = page_merge_hot(p,a[i]);
	}
	p->pNextHot = 0;
	return p;
}
/*
** The format for the journal header is as follows:
** - 8 bytes: Magic identifying journal format.
** - 4 bytes: Number of records in journal.
** - 4 bytes: Random number used for page hash.
** - 8 bytes: Initial database page count.
** - 4 bytes: Sector size used by the process that wrote this journal.
** - 4 bytes: Database page size.
** 
** Followed by (JOURNAL_HDR_SZ - 28) bytes of unused space.
*/
/*
** Open the journal file and extract its header information.
**
** If the header is read successfully, *pNRec is set to the number of
** page records following this header and *pDbSize is set to the size of the
** database before the transaction began, in pages. Also, pPager->cksumInit
** is set to the value read from the journal header. VEDIS_OK is returned
** in this case.
**
** If the journal header file appears to be corrupted, VEDIS_DONE is
** returned and *pNRec and *PDbSize are undefined.  If JOURNAL_HDR_SZ bytes
** cannot be read from the journal file an error code is returned.
*/
static int pager_read_journal_header(
  Pager *pPager,               /* Pager object */
  sxu32 *pNRec,                /* OUT: Value read from the nRec field */
  pgno  *pDbSize               /* OUT: Value of original database size field */
)
{
	sxu32 iPageSize,iSectorSize;
	unsigned char zMagic[8];
	sxi64 iHdrOfft;
	sxi64 iSize;
	int rc;
	/* Offset to start reading from */
	iHdrOfft = 0;
	/* Get the size of the journal */
	rc = vedisOsFileSize(pPager->pjfd,&iSize);
	if( rc != VEDIS_OK ){
		return VEDIS_DONE;
	}
	/* If the journal file is too small, return VEDIS_DONE. */
	if( 32 /* Minimum sector size */> iSize ){
		return VEDIS_DONE;
	}
	/* Make sure we are dealing with a valid journal */
	rc = vedisOsRead(pPager->pjfd,zMagic,sizeof(zMagic),iHdrOfft);
	if( rc != VEDIS_OK ){
		return rc;
	}
	if( SyMemcmp(zMagic,aJournalMagic,sizeof(zMagic)) != 0 ){
		return VEDIS_DONE;
	}
	iHdrOfft += sizeof(zMagic);
	 /* Read the first three 32-bit fields of the journal header: The nRec
      ** field, the checksum-initializer and the database size at the start
      ** of the transaction. Return an error code if anything goes wrong.
      */
	rc = ReadInt32(pPager->pjfd,pNRec,iHdrOfft);
	if( rc != VEDIS_OK ){
		return rc;
	}
	iHdrOfft += 4;
	rc = ReadInt32(pPager->pjfd,&pPager->cksumInit,iHdrOfft);
	if( rc != VEDIS_OK ){
		return rc;
	}
	iHdrOfft += 4;
	rc = ReadInt64(pPager->pjfd,pDbSize,iHdrOfft);
	if( rc != VEDIS_OK ){
		return rc;
	}
	iHdrOfft += 8;
	/* Read the page-size and sector-size journal header fields. */
	rc = ReadInt32(pPager->pjfd,&iSectorSize,iHdrOfft);
	if( rc != VEDIS_OK ){
		return rc;
	}
	iHdrOfft += 4;
	rc = ReadInt32(pPager->pjfd,&iPageSize,iHdrOfft);
	if( rc != VEDIS_OK ){
		return rc;
	}
	/* Check that the values read from the page-size and sector-size fields
    ** are within range. To be 'in range', both values need to be a power
    ** of two greater than or equal to 512 or 32, and not greater than their 
    ** respective compile time maximum limits.
    */
    if( iPageSize < VEDIS_MIN_PAGE_SIZE || iSectorSize<32
     || iPageSize > VEDIS_MAX_PAGE_SIZE || iSectorSize>MAX_SECTOR_SIZE
     || ((iPageSize-1)&iPageSize)!=0    || ((iSectorSize-1)&iSectorSize)!=0 
    ){
      /* If the either the page-size or sector-size in the journal-header is 
      ** invalid, then the process that wrote the journal-header must have 
      ** crashed before the header was synced. In this case stop reading 
      ** the journal file here.
      */
      return VEDIS_DONE;
    }
    /* Update the assumed sector-size to match the value used by 
    ** the process that created this journal. If this journal was
    ** created by a process other than this one, then this routine
    ** is being called from within pager_playback(). The local value
    ** of Pager.sectorSize is restored at the end of that routine.
    */
    pPager->iSectorSize = iSectorSize;
	pPager->iPageSize = iPageSize;
	/* Ready to rollback */
	pPager->iJournalOfft = JOURNAL_HDR_SZ(pPager);
	/* All done */
	return VEDIS_OK;
}
/*
 * Write the journal header in the given memory buffer.
 * The given buffer is big enough to hold the whole header.
 */
static int pager_write_journal_header(Pager *pPager,unsigned char *zBuf)
{
	unsigned char *zPtr = zBuf;
	/* 8 bytes magic number */
	SyMemcpy(aJournalMagic,zPtr,sizeof(aJournalMagic));
	zPtr += sizeof(aJournalMagic);
	/* 4 bytes: Number of records in journal. */
	SyBigEndianPack32(zPtr,0);
	zPtr += 4;
	/* 4 bytes: Random number used to compute page checksum. */
	SyBigEndianPack32(zPtr,pPager->cksumInit);
	zPtr += 4;
	/* 8 bytes: Initial database page count. */
	SyBigEndianPack64(zPtr,pPager->dbOrigSize);
	zPtr += 8;
	/* 4 bytes: Sector size used by the process that wrote this journal. */
	SyBigEndianPack32(zPtr,(sxu32)pPager->iSectorSize);
	zPtr += 4;
	/* 4 bytes: Database page size. */
	SyBigEndianPack32(zPtr,(sxu32)pPager->iPageSize);
	return VEDIS_OK;
}
/*
** Parameter aData must point to a buffer of pPager->pageSize bytes
** of data. Compute and return a checksum based ont the contents of the 
** page of data and the current value of pPager->cksumInit.
**
** This is not a real checksum. It is really just the sum of the 
** random initial value (pPager->cksumInit) and every 200th byte
** of the page data, starting with byte offset (pPager->pageSize%200).
** Each byte is interpreted as an 8-bit unsigned integer.
**
** Changing the formula used to compute this checksum results in an
** incompatible journal file format.
**
** If journal corruption occurs due to a power failure, the most likely 
** scenario is that one end or the other of the record will be changed. 
** It is much less likely that the two ends of the journal record will be
** correct and the middle be corrupt.  Thus, this "checksum" scheme,
** though fast and simple, catches the mostly likely kind of corruption.
*/
static sxu32 pager_cksum(Pager *pPager,const unsigned char *zData)
{
  sxu32 cksum = pPager->cksumInit;         /* Checksum value to return */
  int i = pPager->iPageSize-200;          /* Loop counter */
  while( i>0 ){
    cksum += zData[i];
    i -= 200;
  }
  return cksum;
}
/*
** Read a single page from the journal file opened on file descriptor
** jfd. Playback this one page. Update the offset to read from.
*/
static int pager_play_back_one_page(Pager *pPager,sxi64 *pOfft,unsigned char *zTmp)
{
	unsigned char *zData = zTmp;
	sxi64 iOfft; /* Offset to read from */
	pgno iNum;   /* Pager number */
	sxu32 ckSum; /* Sanity check */
	int rc;
	/* Offset to start reading from */
	iOfft = *pOfft;
	/* Database page number */
	rc = ReadInt64(pPager->pjfd,&iNum,iOfft);
	if( rc != VEDIS_OK ){ return rc; }
	iOfft += 8;
	/* Page data */
	rc = vedisOsRead(pPager->pjfd,zData,pPager->iPageSize,iOfft);
	if( rc != VEDIS_OK ){ return rc; }
	iOfft += pPager->iPageSize;
	/* Page cksum */
	rc = ReadInt32(pPager->pjfd,&ckSum,iOfft);
	if( rc != VEDIS_OK ){ return rc; }
	iOfft += 4;
	/* Synchronize pointers */
	*pOfft = iOfft;
	/* Make sure we are dealing with a valid page */
	if( ckSum != pager_cksum(pPager,zData) ){
		/* Ignore that page */
		return SXERR_IGNORE;
	}
	if( iNum >= pPager->dbSize ){
		/* Ignore that page */
		return VEDIS_OK;
	}
	/* playback */
	rc = vedisOsWrite(pPager->pfd,zData,pPager->iPageSize,iNum * pPager->iPageSize);
	if( rc == VEDIS_OK ){
		/* Flush the cache */
		pager_fill_page(pPager,iNum,zData);
	}
	return rc;
}
/*
** Playback the journal and thus restore the database file to
** the state it was in before we started making changes.  
**
** The journal file format is as follows: 
**
**  (1)  8 byte prefix.  A copy of aJournalMagic[].
**  (2)  4 byte big-endian integer which is the number of valid page records
**       in the journal. 
**  (3)  4 byte big-endian integer which is the initial value for the 
**       sanity checksum.
**  (4)  8 byte integer which is the number of pages to truncate the
**       database to during a rollback.
**  (5)  4 byte big-endian integer which is the sector size.  The header
**       is this many bytes in size.
**  (6)  4 byte big-endian integer which is the page size.
**  (7)  zero padding out to the next sector size.
**  (8)  Zero or more pages instances, each as follows:
**        +  4 byte page number.
**        +  pPager->pageSize bytes of data.
**        +  4 byte checksum
**
** When we speak of the journal header, we mean the first 7 items above.
** Each entry in the journal is an instance of the 8th item.
**
** Call the value from the second bullet "nRec".  nRec is the number of
** valid page entries in the journal.  In most cases, you can compute the
** value of nRec from the size of the journal file.  But if a power
** failure occurred while the journal was being written, it could be the
** case that the size of the journal file had already been increased but
** the extra entries had not yet made it safely to disk.  In such a case,
** the value of nRec computed from the file size would be too large.  For
** that reason, we always use the nRec value in the header.
**
** If the file opened as the journal file is not a well-formed
** journal file then all pages up to the first corrupted page are rolled
** back (or no pages if the journal header is corrupted). The journal file
** is then deleted and SQLITE_OK returned, just as if no corruption had
** been encountered.
**
** If an I/O or malloc() error occurs, the journal-file is not deleted
** and an error code is returned.
**
*/
static int pager_playback(Pager *pPager)
{
	unsigned char *zTmp = 0; /* cc warning */
	sxu32 n,nRec;
	sxi64 iOfft;
	int rc;
	/* Read the journal header*/
	rc = pager_read_journal_header(pPager,&nRec,&pPager->dbSize);
	if( rc != VEDIS_OK ){
		if( rc == VEDIS_DONE ){
			goto end_playback;
		}
		vedisGenErrorFormat(pPager->pDb,"IO error while reading journal file '%s' header",pPager->zJournal);
		return rc;
	}
	/* Truncate the database back to its original size */
	rc = vedisOsTruncate(pPager->pfd,pPager->iPageSize * pPager->dbSize);
	if( rc != VEDIS_OK ){
		vedisGenError(pPager->pDb,"IO error while truncating database file");
		return rc;
	}
	/* Allocate a temporary page */
	zTmp = (unsigned char *)SyMemBackendAlloc(pPager->pAllocator,(sxu32)pPager->iPageSize);
	if( zTmp == 0 ){
		vedisGenOutofMem(pPager->pDb);
		return VEDIS_NOMEM;
	}
	SyZero((void *)zTmp,(sxu32)pPager->iPageSize);
	/* Copy original pages out of the journal and back into the 
    ** database file and/or page cache.
    */
	iOfft = pPager->iJournalOfft;
	for( n = 0 ; n < nRec ; ++n ){
		rc = pager_play_back_one_page(pPager,&iOfft,zTmp);
		if( rc != VEDIS_OK ){
			if( rc != SXERR_IGNORE ){
				vedisGenError(pPager->pDb,"Page playback error");
				goto end_playback;
			}
		}
	}
end_playback:
	/* Release the temp page */
	SyMemBackendFree(pPager->pAllocator,(void *)zTmp);
	if( rc == VEDIS_OK ){
		/* Sync the database file */
		vedisOsSync(pPager->pfd,VEDIS_SYNC_FULL);
	}
	if( rc == VEDIS_DONE ){
		rc = VEDIS_OK;
	}
	/* Return to the caller */
	return rc;
}
/*
** Unlock the database file to level eLock, which must be either NO_LOCK
** or SHARED_LOCK. Regardless of whether or not the call to xUnlock()
** succeeds, set the Pager.iLock variable to match the (attempted) new lock.
**
** Except, if Pager.iLock is set to NO_LOCK when this function is
** called, do not modify it. See the comment above the #define of 
** NO_LOCK for an explanation of this.
*/
static int pager_unlock_db(Pager *pPager, int eLock)
{
  int rc = VEDIS_OK;
  if( pPager->iLock != NO_LOCK ){
    rc = vedisOsUnlock(pPager->pfd,eLock);
    pPager->iLock = eLock;
  }
  return rc;
}
/*
** Lock the database file to level eLock, which must be either SHARED_LOCK,
** RESERVED_LOCK or EXCLUSIVE_LOCK. If the caller is successful, set the
** Pager.eLock variable to the new locking state. 
**
** Except, if Pager.eLock is set to NO_LOCK when this function is 
** called, do not modify it unless the new locking state is EXCLUSIVE_LOCK. 
** See the comment above the #define of NO_LOCK for an explanation 
** of this.
*/
static int pager_lock_db(Pager *pPager, int eLock){
  int rc = VEDIS_OK;
  if( pPager->iLock < eLock || pPager->iLock == NO_LOCK ){
    rc = vedisOsLock(pPager->pfd, eLock);
    if( rc==VEDIS_OK ){
      pPager->iLock = eLock;
    }else{
		vedisGenError(pPager->pDb,
			rc == VEDIS_BUSY ? "Another process or thread hold the requested lock" : "Error while requesting database lock"
			);
	}
  }
  return rc;
}
/*
** Try to obtain a lock of type locktype on the database file. If
** a similar or greater lock is already held, this function is a no-op
** (returning VEDIS_OK immediately).
**
** Otherwise, attempt to obtain the lock using vedisOsLock(). Invoke 
** the busy callback if the lock is currently not available. Repeat 
** until the busy callback returns false or until the attempt to 
** obtain the lock succeeds.
**
** Return VEDIS_OK on success and an error code if we cannot obtain
** the lock. If the lock is obtained successfully, set the Pager.state 
** variable to locktype before returning.
*/
static int pager_wait_on_lock(Pager *pPager, int locktype){
  int rc;                              /* Return code */
  do {
    rc = pager_lock_db(pPager,locktype);
  }while( rc==VEDIS_BUSY && pPager->xBusyHandler && pPager->xBusyHandler(pPager->pBusyHandlerArg) );
  return rc;
}
/*
** This function is called after transitioning from PAGER_OPEN to
** PAGER_SHARED state. It tests if there is a hot journal present in
** the file-system for the given pager. A hot journal is one that 
** needs to be played back. According to this function, a hot-journal
** file exists if the following criteria are met:
**
**   * The journal file exists in the file system, and
**   * No process holds a RESERVED or greater lock on the database file, and
**   * The database file itself is greater than 0 bytes in size, and
**   * The first byte of the journal file exists and is not 0x00.
**
** If the current size of the database file is 0 but a journal file
** exists, that is probably an old journal left over from a prior
** database with the same name. In this case the journal file is
** just deleted using OsDelete, *pExists is set to 0 and VEDIS_OK
** is returned.
**
** If a hot-journal file is found to exist, *pExists is set to 1 and 
** VEDIS_OK returned. If no hot-journal file is present, *pExists is
** set to 0 and VEDIS_OK returned. If an IO error occurs while trying
** to determine whether or not a hot-journal file exists, the IO error
** code is returned and the value of *pExists is undefined.
*/
static int pager_has_hot_journal(Pager *pPager, int *pExists)
{
  vedis_vfs *pVfs = pPager->pVfs;
  int rc = VEDIS_OK;           /* Return code */
  int exists = 1;               /* True if a journal file is present */

  *pExists = 0;
  rc = vedisOsAccess(pVfs, pPager->zJournal, VEDIS_ACCESS_EXISTS, &exists);
  if( rc==VEDIS_OK && exists ){
    int locked = 0;             /* True if some process holds a RESERVED lock */

    /* Race condition here:  Another process might have been holding the
    ** the RESERVED lock and have a journal open at the vedisOsAccess() 
    ** call above, but then delete the journal and drop the lock before
    ** we get to the following vedisOsCheckReservedLock() call.  If that
    ** is the case, this routine might think there is a hot journal when
    ** in fact there is none.  This results in a false-positive which will
    ** be dealt with by the playback routine.
    */
    rc = vedisOsCheckReservedLock(pPager->pfd, &locked);
    if( rc==VEDIS_OK && !locked ){
      sxi64 n = 0;                    /* Size of db file in bytes */
 
      /* Check the size of the database file. If it consists of 0 pages,
      ** then delete the journal file. See the header comment above for 
      ** the reasoning here.  Delete the obsolete journal file under
      ** a RESERVED lock to avoid race conditions.
      */
      rc = vedisOsFileSize(pPager->pfd,&n);
      if( rc==VEDIS_OK ){
        if( n < 1 ){
          if( pager_lock_db(pPager, RESERVED_LOCK)==VEDIS_OK ){
            vedisOsDelete(pVfs, pPager->zJournal, 0);
			pager_unlock_db(pPager, SHARED_LOCK);
          }
        }else{
          /* The journal file exists and no other connection has a reserved
          ** or greater lock on the database file. */
			*pExists = 1;
        }
      }
    }
  }
  return rc;
}
/*
 * Rollback a journal file. (See block-comment above).
 */
static int pager_journal_rollback(Pager *pPager,int check_hot)
{
	int rc;
	if( check_hot ){
		int iExists = 0; /* cc warning */
		/* Check if the journal file exists */
		rc = pager_has_hot_journal(pPager,&iExists);
		if( rc != VEDIS_OK  ){
			/* IO error */
			return rc;
		}
		if( !iExists ){
			/* Journal file does not exists */
			return VEDIS_OK;
		}
	}
	if( pPager->is_rdonly ){
		vedisGenErrorFormat(pPager->pDb,
			"Cannot rollback journal file '%s' due to a read-only database handle",pPager->zJournal);
		return VEDIS_READ_ONLY;
	}
	/* Get an EXCLUSIVE lock on the database file. At this point it is
      ** important that a RESERVED lock is not obtained on the way to the
      ** EXCLUSIVE lock. If it were, another process might open the
      ** database file, detect the RESERVED lock, and conclude that the
      ** database is safe to read while this process is still rolling the 
      ** hot-journal back.
      ** 
      ** Because the intermediate RESERVED lock is not requested, any
      ** other process attempting to access the database file will get to 
      ** this point in the code and fail to obtain its own EXCLUSIVE lock 
      ** on the database file.
      **
      ** Unless the pager is in locking_mode=exclusive mode, the lock is
      ** downgraded to SHARED_LOCK before this function returns.
      */
	/* Open the journal file */
	rc = vedisOsOpen(pPager->pVfs,pPager->pAllocator,pPager->zJournal,&pPager->pjfd,VEDIS_OPEN_READWRITE);
	if( rc != VEDIS_OK ){
		vedisGenErrorFormat(pPager->pDb,"IO error while opening journal file: '%s'",pPager->zJournal);
		goto fail;
	}
	rc = pager_lock_db(pPager,EXCLUSIVE_LOCK);
	if( rc != VEDIS_OK ){
		vedisGenError(pPager->pDb,"Cannot acquire an exclusive lock on the database while journal rollback");
		goto fail;
	}
	/* Sync the journal file */
	vedisOsSync(pPager->pjfd,VEDIS_SYNC_NORMAL);
	/* Finally rollback the database */
	rc = pager_playback(pPager);
	/* Switch back to shared lock */
	pager_unlock_db(pPager,SHARED_LOCK);
fail:
	/* Close the journal handle */
	vedisOsCloseFree(pPager->pAllocator,pPager->pjfd);
	pPager->pjfd = 0;
	if( rc == VEDIS_OK ){
		/* Delete the journal file */
		vedisOsDelete(pPager->pVfs,pPager->zJournal,TRUE);
	}
	return rc;
}
/*
 * Write the vedis header (First page). (Big-Endian)
 */
static int pager_write_db_header(Pager *pPager)
{
	unsigned char *zRaw = pPager->pHeader->zData;
	vedis_kv_engine *pEngine = pPager->pEngine;
	sxu32 nDos;
	sxu16 nLen;
	/* Database signature */
	SyMemcpy(VEDIS_DB_SIG,zRaw,sizeof(VEDIS_DB_SIG)-1);
	zRaw += sizeof(VEDIS_DB_SIG)-1;
	/* Database magic number */
	SyBigEndianPack32(zRaw,VEDIS_DB_MAGIC);
	zRaw += 4; /* 4 byte magic number */
	/* Database creation time */
	SyZero(&pPager->tmCreate,sizeof(Sytm));
	if( pPager->pVfs->xCurrentTime ){
		pPager->pVfs->xCurrentTime(pPager->pVfs,&pPager->tmCreate);
	}
	/* DOS time format (4 bytes) */
	SyTimeFormatToDos(&pPager->tmCreate,&nDos);
	SyBigEndianPack32(zRaw,nDos);
	zRaw += 4; /* 4 byte DOS time */
	/* Sector size */
	SyBigEndianPack32(zRaw,(sxu32)pPager->iSectorSize);
	zRaw += 4; /* 4 byte sector size */
	/* Page size */
	SyBigEndianPack32(zRaw,(sxu32)pPager->iPageSize);
	zRaw += 4; /* 4 byte page size */
	/* Key value storage engine */
	nLen = (sxu16)SyStrlen(pEngine->pIo->pMethods->zName);
	SyBigEndianPack16(zRaw,nLen); /* 2 byte storage engine name */
	zRaw += 2;
	SyMemcpy((const void *)pEngine->pIo->pMethods->zName,(void *)zRaw,nLen);
	zRaw += nLen;
	/* All rest are meta-data available to the host application */
	return VEDIS_OK;
}
/*
 * Read the vedis header (first page). (Big-Endian)
 */
static int pager_extract_header(Pager *pPager,const unsigned char *zRaw,sxu32 nByte)
{
	const unsigned char *zEnd = &zRaw[nByte];
	sxu32 nDos,iMagic;
	sxu16 nLen;
	char *zKv;
	/* Database signature */
	if( SyMemcmp(VEDIS_DB_SIG,zRaw,sizeof(VEDIS_DB_SIG)-1) != 0 ){
		/* Corrupt database */
		return VEDIS_CORRUPT;
	}
	zRaw += sizeof(VEDIS_DB_SIG)-1;
	/* Database magic number */
	SyBigEndianUnpack32(zRaw,&iMagic);
	zRaw += 4; /* 4 byte magic number */
	if( iMagic != VEDIS_DB_MAGIC ){
		/* Corrupt database */
		return VEDIS_CORRUPT;
	}
	/* Database creation time */
	SyBigEndianUnpack32(zRaw,&nDos);
	zRaw += 4; /* 4 byte DOS time format */
	SyDosTimeFormat(nDos,&pPager->tmCreate);
	/* Sector size */
	SyBigEndianUnpack32(zRaw,(sxu32 *)&pPager->iSectorSize);
	zRaw += 4; /* 4 byte sector size */
	/* Page size */
	SyBigEndianUnpack32(zRaw,(sxu32 *)&pPager->iPageSize);
	zRaw += 4; /* 4 byte page size */
	/* Check that the values read from the page-size and sector-size fields
    ** are within range. To be 'in range', both values need to be a power
    ** of two greater than or equal to 512 or 32, and not greater than their 
    ** respective compile time maximum limits.
    */
    if( pPager->iPageSize<VEDIS_MIN_PAGE_SIZE || pPager->iSectorSize<32
     || pPager->iPageSize>VEDIS_MAX_PAGE_SIZE || pPager->iSectorSize>MAX_SECTOR_SIZE
     || ((pPager->iPageSize<-1)&pPager->iPageSize)!=0    || ((pPager->iSectorSize-1)&pPager->iSectorSize)!=0 
    ){
      return VEDIS_CORRUPT;
	}
	/* Key value storage engine */
	SyBigEndianUnpack16(zRaw,&nLen); /* 2 byte storage engine length */
	zRaw += 2;
	if( nLen > (sxu16)(zEnd - zRaw) ){
		nLen = (sxu16)(zEnd - zRaw);
	}
	zKv = (char *)SyMemBackendDup(pPager->pAllocator,(const char *)zRaw,nLen);
	if( zKv == 0 ){
		return VEDIS_NOMEM;
	}
	SyStringInitFromBuf(&pPager->sKv,zKv,nLen);
	return VEDIS_OK;
}
/*
 * Read the database header.
 */
static int pager_read_db_header(Pager *pPager)
{
	unsigned char zRaw[VEDIS_MIN_PAGE_SIZE]; /* Minimum page size */
	sxi64 n = 0;              /* Size of db file in bytes */
	int rc;
	/* Get the file size first */
	rc = vedisOsFileSize(pPager->pfd,&n);
	if( rc != VEDIS_OK ){
		return rc;
	}
	pPager->dbByteSize = n;
	if( n > 0 ){
		vedis_kv_methods *pMethods;
		SyString *pKv;
		pgno nPage;
		if( n < VEDIS_MIN_PAGE_SIZE ){
			/* A valid vedis database must be at least 512 bytes long */
			vedisGenError(pPager->pDb,"Malformed database image");
			return VEDIS_CORRUPT;
		}
		/* Read the database header */
		rc = vedisOsRead(pPager->pfd,zRaw,sizeof(zRaw),0);
		if( rc != VEDIS_OK ){
			vedisGenError(pPager->pDb,"IO error while reading database header");
			return rc;
		}
		/* Extract the header */
		rc = pager_extract_header(pPager,zRaw,sizeof(zRaw));
		if( rc != VEDIS_OK ){
			vedisGenError(pPager->pDb,rc == VEDIS_NOMEM ? "Unqlite is running out of memory" : "Malformed database image");
			return rc;
		}
		/* Update pager state  */
		nPage = (pgno)(n / pPager->iPageSize);
		if( nPage==0 && n>0 ){
			nPage = 1;
		}
		pPager->dbSize = nPage;
		/* Laod the target Key/Value storage engine */
		pKv = &pPager->sKv;
		pMethods = vedisFindKVStore(pKv->zString,pKv->nByte);
		if( pMethods == 0 ){
			vedisGenErrorFormat(pPager->pDb,"No such Key/Value storage engine '%z'",pKv);
			return VEDIS_NOTIMPLEMENTED;
		}
		/* Install the new KV storage engine */
		rc = vedisPagerRegisterKvEngine(pPager,pMethods);
		if( rc != VEDIS_OK ){
			return rc;
		}
	}else{
		/* Set a default page and sector size */
		pPager->iSectorSize = GetSectorSize(pPager->pfd);
		pPager->iPageSize = vedisGetPageSize();
		SyStringInitFromBuf(&pPager->sKv,pPager->pEngine->pIo->pMethods->zName,SyStrlen(pPager->pEngine->pIo->pMethods->zName));
		pPager->dbSize = 0;
	}
	/* Allocate a temporary page size */
	pPager->zTmpPage = (unsigned char *)SyMemBackendAlloc(pPager->pAllocator,(sxu32)pPager->iPageSize);
	if( pPager->zTmpPage == 0 ){
		vedisGenOutofMem(pPager->pDb);
		return VEDIS_NOMEM;
	}
	SyZero(pPager->zTmpPage,(sxu32)pPager->iPageSize);
	return VEDIS_OK;
}
/*
 * Write the database header.
 */
static int pager_create_header(Pager *pPager)
{
	Page *pHeader;
	int rc;
	/* Allocate a new page */
	pHeader = pager_alloc_page(pPager,0);
	if( pHeader == 0 ){
		return VEDIS_NOMEM;
	}
	pPager->pHeader = pHeader;
	/* Link the page */
	pager_link_page(pPager,pHeader);
	/* Add to the dirty list */
	pager_page_to_dirty_list(pPager,pHeader);
	/* Write the database header */
	rc = pager_write_db_header(pPager);
	return rc;
}
/*
** This function is called to obtain a shared lock on the database file.
** It is illegal to call vedisPagerAcquire() until after this function
** has been successfully called. If a shared-lock is already held when
** this function is called, it is a no-op.
**
** The following operations are also performed by this function.
**
**   1) If the pager is currently in PAGER_OPEN state (no lock held
**      on the database file), then an attempt is made to obtain a
**      SHARED lock on the database file. Immediately after obtaining
**      the SHARED lock, the file-system is checked for a hot-journal,
**      which is played back if present. 
**
** If everything is successful, VEDIS_OK is returned. If an IO error 
** occurs while locking the database, checking for a hot-journal file or 
** rolling back a journal file, the IO error code is returned.
*/
static int pager_shared_lock(Pager *pPager)
{
	int rc = VEDIS_OK;
	if( pPager->iState == PAGER_OPEN ){
		vedis_kv_methods *pMethods;
		/* Open the target database */
		rc = vedisOsOpen(pPager->pVfs,pPager->pAllocator,pPager->zFilename,&pPager->pfd,pPager->iOpenFlags);
		if( rc != VEDIS_OK ){
			vedisGenErrorFormat(pPager->pDb,
				"IO error while opening the target database file: %s",pPager->zFilename
				);
			return rc;
		}
		/* Try to obtain a shared lock */
		rc = pager_wait_on_lock(pPager,SHARED_LOCK);
		if( rc == VEDIS_OK ){
			if( pPager->iLock <= SHARED_LOCK ){
				/* Rollback any hot journal */
				rc = pager_journal_rollback(pPager,1);
				if( rc != VEDIS_OK ){
					return rc;
				}
			}
			/* Read the database header */
			rc = pager_read_db_header(pPager);
			if( rc != VEDIS_OK ){
				return rc;
			}
			if(pPager->dbSize > 0 ){
				if( pPager->iOpenFlags & VEDIS_OPEN_MMAP ){
					const vedis_vfs *pVfs = vedisExportBuiltinVfs();
					/* Obtain a read-only memory view of the whole file */
					if( pVfs && pVfs->xMmap ){
						int vr;
						vr = pVfs->xMmap(pPager->zFilename,&pPager->pMmap,&pPager->dbByteSize);
						if( vr != VEDIS_OK ){
							/* Generate a warning */
							vedisGenError(pPager->pDb,"Cannot obtain a read-only memory view of the target database");
							pPager->iOpenFlags &= ~VEDIS_OPEN_MMAP;
						}
					}else{
						/* Generate a warning */
						vedisGenError(pPager->pDb,"Cannot obtain a read-only memory view of the target database");
						pPager->iOpenFlags &= ~VEDIS_OPEN_MMAP;
					}
				}
			}
			/* Update the pager state */
			pPager->iState = PAGER_READER;
			/* Invoke the xOpen methods if available */
			pMethods = pPager->pEngine->pIo->pMethods;
			if( pMethods->xOpen ){
				rc = pMethods->xOpen(pPager->pEngine,pPager->dbSize);
				if( rc != VEDIS_OK ){
					vedisGenErrorFormat(pPager->pDb,
						"xOpen() method of the underlying KV engine '%z' failed",
						&pPager->sKv
						);
					pager_unlock_db(pPager,NO_LOCK);
					pPager->iState = PAGER_OPEN;
					return rc;
				}
			}
		}else if( rc == VEDIS_BUSY ){
			vedisGenError(pPager->pDb,"Another process or thread have a reserved or exclusive lock on this database");
		}		
	}
	return rc;
}
/*
** Begin a write-transaction on the specified pager object. If a 
** write-transaction has already been opened, this function is a no-op.
*/
VEDIS_PRIVATE int vedisPagerBegin(Pager *pPager)
{
	int rc;
	/* Obtain a shared lock on the database first */
	rc = pager_shared_lock(pPager);
	if( rc != VEDIS_OK ){
		return rc;
	}
	if( pPager->iState >= PAGER_WRITER_LOCKED ){
		return VEDIS_OK;
	}
	if( pPager->is_rdonly ){
		vedisGenError(pPager->pDb,"Read-only database");
		/* Read only database */
		return VEDIS_READ_ONLY;
	}
	/* Obtain a reserved lock on the database */
	rc = pager_wait_on_lock(pPager,RESERVED_LOCK);
	if( rc == VEDIS_OK ){
		/* Create the bitvec */
		pPager->pVec = vedisBitvecCreate(pPager->pAllocator,pPager->dbSize);
		if( pPager->pVec == 0 ){
			vedisGenOutofMem(pPager->pDb);
			rc = VEDIS_NOMEM;
			goto fail;
		}
		/* Change to the WRITER_LOCK state */
		pPager->iState = PAGER_WRITER_LOCKED;
		pPager->dbOrigSize = pPager->dbSize;
		pPager->iJournalOfft = 0;
		pPager->nRec = 0;
		if( pPager->dbSize < 1 ){
			/* Write the  database header */
			rc = pager_create_header(pPager);
			if( rc != VEDIS_OK ){
				goto fail;
			}
			pPager->dbSize = 1;
		}
	}else if( rc == VEDIS_BUSY ){
		vedisGenError(pPager->pDb,"Another process or thread have a reserved lock on this database");
	}
	return rc;
fail:
	/* Downgrade to shared lock */
	pager_unlock_db(pPager,SHARED_LOCK);
	return rc;
}
/*
** This function is called at the start of every write transaction.
** There must already be a RESERVED or EXCLUSIVE lock on the database 
** file when this routine is called.
**
*/
static int vedisOpenJournal(Pager *pPager)
{
	unsigned char *zHeader;
	int rc = VEDIS_OK;
	if( pPager->is_mem || pPager->no_jrnl ){
		/* Journaling is omitted for this database */
		goto finish;
	}
	if( pPager->iState >= PAGER_WRITER_CACHEMOD ){
		/* Already opened */
		return VEDIS_OK;
	}
	/* Delete any previously journal with the same name */
	vedisOsDelete(pPager->pVfs,pPager->zJournal,1);
	/* Open the journal file */
	rc = vedisOsOpen(pPager->pVfs,pPager->pAllocator,pPager->zJournal,
		&pPager->pjfd,VEDIS_OPEN_CREATE|VEDIS_OPEN_READWRITE);
	if( rc != VEDIS_OK ){
		vedisGenErrorFormat(pPager->pDb,"IO error while opening journal file: %s",pPager->zJournal);
		return rc;
	}
	/* Write the journal header */
	zHeader = (unsigned char *)SyMemBackendAlloc(pPager->pAllocator,(sxu32)pPager->iSectorSize);
	if( zHeader == 0 ){
		rc = VEDIS_NOMEM;
		goto fail;
	}
	pager_write_journal_header(pPager,zHeader);
	/* Perform the disk write */
	rc = vedisOsWrite(pPager->pjfd,zHeader,pPager->iSectorSize,0);
	/* Offset to start writing from */
	pPager->iJournalOfft = pPager->iSectorSize;
	/* All done, journal will be synced later */
	SyMemBackendFree(pPager->pAllocator,zHeader);
finish:
	if( rc == VEDIS_OK ){
		pPager->iState = PAGER_WRITER_CACHEMOD;
		return VEDIS_OK;
	}
fail:
	/* Unlink the journal file if something goes wrong */
	vedisOsCloseFree(pPager->pAllocator,pPager->pjfd);
	vedisOsDelete(pPager->pVfs,pPager->zJournal,0);
	pPager->pjfd = 0;
	return rc;
}
/*
** Sync the journal. In other words, make sure all the pages that have
** been written to the journal have actually reached the surface of the
** disk and can be restored in the event of a hot-journal rollback.
*
* This routine try also to obtain an exlusive lock on the database.
*/
static int vedisFinalizeJournal(Pager *pPager,int *pRetry,int close_jrnl)
{
	int rc;
	*pRetry = 0;
	/* Grab the exclusive lock first */
	rc = pager_lock_db(pPager,EXCLUSIVE_LOCK);
	if( rc != VEDIS_OK ){
		/* Retry the excusive lock process */
		*pRetry = 1;
		rc = VEDIS_OK;
	}
	if( pPager->no_jrnl ){
		/* Journaling is omitted, return immediately */
		return VEDIS_OK;
	}
	/* Write the total number of database records */
	rc = WriteInt32(pPager->pjfd,pPager->nRec,8 /* sizeof(aJournalRec) */);
	if( rc != VEDIS_OK ){
		if( pPager->nRec > 0 ){
			return rc;
		}else{
			/* Not so fatal */
			rc = VEDIS_OK;
		}
	}
	/* Sync the journal and close it */
	rc = vedisOsSync(pPager->pjfd,VEDIS_SYNC_NORMAL);
	if( close_jrnl ){
		/* close the journal file */
		if( VEDIS_OK != vedisOsCloseFree(pPager->pAllocator,pPager->pjfd) ){
			if( rc != VEDIS_OK /* vedisOsSync */ ){
				return rc;
			}
		}
		pPager->pjfd = 0;
	}
	if( (*pRetry) == 1 ){
		if( pager_lock_db(pPager,EXCLUSIVE_LOCK) == VEDIS_OK ){
			/* Got exclusive lock */
			*pRetry = 0;
		}
	}
	return VEDIS_OK;
}
/*
 * Mark a single data page as writeable. The page is written into the 
 * main journal as required.
 */
static int page_write(Pager *pPager,Page *pPage)
{
	int rc;
	if( !pPager->is_mem && !pPager->no_jrnl ){
		/* Write the page to the transaction journal */
		if( pPage->pgno < pPager->dbOrigSize && !vedisBitvecTest(pPager->pVec,pPage->pgno) ){
			sxu32 cksum;
			if( pPager->nRec == SXU32_HIGH ){
				/* Journal Limit reached */
				vedisGenError(pPager->pDb,"Journal record limit reached, commit your changes");
				return VEDIS_LIMIT;
			}
			/* Write the page number */
			rc = WriteInt64(pPager->pjfd,pPage->pgno,pPager->iJournalOfft);
			if( rc != VEDIS_OK ){ return rc; }
			/* Write the raw page */
			/** CODEC */
			rc = vedisOsWrite(pPager->pjfd,pPage->zData,pPager->iPageSize,pPager->iJournalOfft + 8);
			if( rc != VEDIS_OK ){ return rc; }
			/* Compute the checksum */
			cksum = pager_cksum(pPager,pPage->zData);
			rc = WriteInt32(pPager->pjfd,cksum,pPager->iJournalOfft + 8 + pPager->iPageSize);
			if( rc != VEDIS_OK ){ return rc; }
			/* Update the journal offset */
			pPager->iJournalOfft += 8 /* page num */ + pPager->iPageSize + 4 /* cksum */;
			pPager->nRec++;
			/* Mark as journalled  */
			vedisBitvecSet(pPager->pVec,pPage->pgno);
		}
	}
	/* Add the page to the dirty list */
	pager_page_to_dirty_list(pPager,pPage);
	/* Update the database size and return. */
	if( (1 + pPage->pgno) > pPager->dbSize ){
		pPager->dbSize = 1 + pPage->pgno;
		if( pPager->dbSize == SXU64_HIGH ){
			vedisGenError(pPager->pDb,"Database maximum page limit (64-bit) reached");
			return VEDIS_LIMIT;
		}
	}	
	return VEDIS_OK;
}
/*
** The argument is the first in a linked list of dirty pages connected
** by the PgHdr.pDirty pointer. This function writes each one of the
** in-memory pages in the list to the database file. The argument may
** be NULL, representing an empty list. In this case this function is
** a no-op.
**
** The pager must hold at least a RESERVED lock when this function
** is called. Before writing anything to the database file, this lock
** is upgraded to an EXCLUSIVE lock. If the lock cannot be obtained,
** VEDIS_BUSY is returned and no data is written to the database file.
*/
static int pager_write_dirty_pages(Pager *pPager,Page *pDirty)
{
	int rc = VEDIS_OK;
	Page *pNext;
	for(;;){
		if( pDirty == 0 ){
			break;
		}
		/* Point to the next dirty page */
		pNext = pDirty->pDirtyPrev; /* Not a bug: Reverse link */
		if( (pDirty->flags & PAGE_DONT_WRITE) == 0 ){
			rc = vedisOsWrite(pPager->pfd,pDirty->zData,pPager->iPageSize,pDirty->pgno * pPager->iPageSize);
			if( rc != VEDIS_OK ){
				/* A rollback should be done */
				break;
			}
		}
		/* Remove stale flags */
		pDirty->flags &= ~(PAGE_DIRTY|PAGE_DONT_WRITE|PAGE_NEED_SYNC|PAGE_IN_JOURNAL|PAGE_HOT_DIRTY);
		if( pDirty->nRef < 1 ){
			/* Unlink the page now it is unused */
			pager_unlink_page(pPager,pDirty);
			/* Release the page */
			pager_release_page(pPager,pDirty);
		}
		/* Point to the next page */
		pDirty = pNext;
	}
	pPager->pDirty = pPager->pFirstDirty = 0;
	pPager->pHotDirty = pPager->pFirstHot = 0;
	pPager->nHot = 0;
	return rc;
}
/*
** The argument is the first in a linked list of hot dirty pages connected
** by the PgHdr.pHotDirty pointer. This function writes each one of the
** in-memory pages in the list to the database file. The argument may
** be NULL, representing an empty list. In this case this function is
** a no-op.
**
** The pager must hold at least a RESERVED lock when this function
** is called. Before writing anything to the database file, this lock
** is upgraded to an EXCLUSIVE lock. If the lock cannot be obtained,
** VEDIS_BUSY is returned and no data is written to the database file.
*/
static int pager_write_hot_dirty_pages(Pager *pPager,Page *pDirty)
{
	int rc = VEDIS_OK;
	Page *pNext;
	for(;;){
		if( pDirty == 0 ){
			break;
		}
		/* Point to the next page */
		pNext = pDirty->pPrevHot; /* Not a bug: Reverse link */
		if( (pDirty->flags & PAGE_DONT_WRITE) == 0 ){
			rc = vedisOsWrite(pPager->pfd,pDirty->zData,pPager->iPageSize,pDirty->pgno * pPager->iPageSize);
			if( rc != VEDIS_OK ){
				break;
			}
		}
		/* Remove stale flags */
		pDirty->flags &= ~(PAGE_DIRTY|PAGE_DONT_WRITE|PAGE_NEED_SYNC|PAGE_IN_JOURNAL|PAGE_HOT_DIRTY);
		/* Unlink from the list of dirty pages */
		if( pDirty->pDirtyPrev ){
			pDirty->pDirtyPrev->pDirtyNext = pDirty->pDirtyNext;
		}else{
			pPager->pDirty = pDirty->pDirtyNext;
		}
		if( pDirty->pDirtyNext ){
			pDirty->pDirtyNext->pDirtyPrev = pDirty->pDirtyPrev;
		}else{
			pPager->pFirstDirty = pDirty->pDirtyPrev;
		}
		/* Discard */
		pager_unlink_page(pPager,pDirty);
		/* Release the page */
		pager_release_page(pPager,pDirty);
		/* Next hot page */
		pDirty = pNext;
	}
	return rc;
}
/*
 * Commit a transaction: Phase one.
 */
static int pager_commit_phase1(Pager *pPager)
{
	int get_excl = 0;
	Page *pDirty;
	int rc;
	/* If no database changes have been made, return early. */
	if( pPager->iState < PAGER_WRITER_CACHEMOD ){
		return VEDIS_OK;
	}
	if( pPager->is_rdonly ){
		/* Read-Only DB */
		vedisGenError(pPager->pDb,"Read-Only database");
		return VEDIS_READ_ONLY;
	}
	/* Invoke any user commit callback */
	if( pPager->xCommit ){
		rc = pPager->xCommit(pPager->pCommitData);
		if( rc == VEDIS_ABORT ){
			vedisGenError(pPager->pDb,"User ommit callback request an operation abort");
			return VEDIS_ABORT;
		}
		/* Fall through */
		rc = VEDIS_OK;
	}
	if( pPager->is_mem ){
		/* An in-memory database */
		return VEDIS_OK;
	}
	/* Finalize the journal file */
	rc = vedisFinalizeJournal(pPager,&get_excl,1);
	if( rc != VEDIS_OK ){
		return rc;
	}
	/* Get the dirty pages */
	pDirty = pager_get_dirty_pages(pPager);
	if( get_excl ){
		/* Wait one last time for the exclusive lock */
		rc = pager_wait_on_lock(pPager,EXCLUSIVE_LOCK);
		if( rc != VEDIS_OK ){
			vedisGenError(pPager->pDb,"Cannot obtain an Exclusive lock on the target database");
			return rc;
		}
	}
	if( pPager->iFlags & PAGER_CTRL_DIRTY_COMMIT ){
		/* Synce the database first if a dirty commit have been applied */
		vedisOsSync(pPager->pfd,VEDIS_SYNC_NORMAL);
	}
	/* Write the dirty pages */
	rc = pager_write_dirty_pages(pPager,pDirty);
	if( rc != VEDIS_OK ){
		/* Rollback your DB */
		pPager->iFlags |= PAGER_CTRL_COMMIT_ERR;
		pPager->pFirstDirty = pDirty;
		vedisGenError(pPager->pDb,"IO error while writing dirty pages, rollback your database");
		return rc;
	}
	/* If the file on disk is not the same size as the database image,
     * then use vedisOsTruncate to grow or shrink the file here.
     */
	if( pPager->dbSize != pPager->dbOrigSize ){
		vedisOsTruncate(pPager->pfd,pPager->iPageSize * pPager->dbSize);
	}
	/* Sync the database file */
	vedisOsSync(pPager->pfd,VEDIS_SYNC_FULL);
	/* Remove stale flags */
	pPager->iJournalOfft = 0;
	pPager->nRec = 0;
	return VEDIS_OK;
}
/*
 * Commit a transaction: Phase two.
 */
static int pager_commit_phase2(Pager *pPager)
{
	if( !pPager->is_mem ){
		if( pPager->iState == PAGER_OPEN ){
			return VEDIS_OK;
		}
		if( pPager->iState != PAGER_READER ){
			if( !pPager->no_jrnl ){
				/* Finally, unlink the journal file */
				vedisOsDelete(pPager->pVfs,pPager->zJournal,1);
			}
			/* Downgrade to shraed lock */
			pager_unlock_db(pPager,SHARED_LOCK);
			pPager->iState = PAGER_READER;
			if( pPager->pVec ){
				vedisBitvecDestroy(pPager->pVec);
				pPager->pVec = 0;
			}
		}
	}
	return VEDIS_OK;
}
/*
 * Perform a dirty commit.
 */
static int pager_dirty_commit(Pager *pPager)
{
	int get_excl = 0;
	Page *pHot;
	int rc;
	/* Finalize the journal file without closing it */
	rc = vedisFinalizeJournal(pPager,&get_excl,0);
	if( rc != VEDIS_OK ){
		/* It's not a fatal error if something goes wrong here since
		 * its not the final commit.
		 */
		return VEDIS_OK;
	}
	/* Point to the list of hot pages */
	pHot = pager_get_hot_pages(pPager);
	if( pHot == 0 ){
		return VEDIS_OK;
	}
	if( get_excl ){
		/* Wait one last time for the exclusive lock */
		rc = pager_wait_on_lock(pPager,EXCLUSIVE_LOCK);
		if( rc != VEDIS_OK ){
			/* Not so fatal, will try another time */
			return VEDIS_OK;
		}
	}
	/* Tell that a dirty commit happen */
	pPager->iFlags |= PAGER_CTRL_DIRTY_COMMIT;
	/* Write the hot pages now */
	rc = pager_write_hot_dirty_pages(pPager,pHot);
	if( rc != VEDIS_OK ){
		pPager->iFlags |= PAGER_CTRL_COMMIT_ERR;
		vedisGenError(pPager->pDb,"IO error while writing hot dirty pages, rollback your database");
		return rc;
	}
	pPager->pFirstHot = pPager->pHotDirty = 0;
	pPager->nHot = 0;
	/* No need to sync the database file here, since the journal is already
	 * open here and this is not the final commit.
	 */
	return VEDIS_OK;
}
/*
** Commit a transaction and sync the database file for the pager pPager.
**
** This routine ensures that:
**
**   * the journal is synced,
**   * all dirty pages are written to the database file, 
**   * the database file is truncated (if required), and
**   * the database file synced.
**   * the journal file is deleted.
*/
VEDIS_PRIVATE int vedisPagerCommit(Pager *pPager)
{
	int rc;
	/* Commit: Phase One */
	rc = pager_commit_phase1(pPager);
	if( rc != VEDIS_OK ){
		goto fail;
	}
	/* Commit: Phase Two */
	rc = pager_commit_phase2(pPager);
	if( rc != VEDIS_OK ){
		goto fail;
	}
	/* Remove stale flags */
	pPager->iFlags &= ~PAGER_CTRL_COMMIT_ERR;
	/* All done */
	return VEDIS_OK;
fail:
	/* Disable the auto-commit flag */
	pPager->pDb->iFlags |= VEDIS_FL_DISABLE_AUTO_COMMIT;
	return rc;
}
/*
 * Reset the pager to its initial state. This is caused by
 * a rollback operation.
 */
static int pager_reset_state(Pager *pPager,int bResetKvEngine)
{
	vedis_kv_engine *pEngine = pPager->pEngine;
	Page *pNext,*pPtr = pPager->pAll;
	const vedis_kv_io *pIo;
	int rc;
	/* Remove stale flags */
	pPager->iFlags &= ~(PAGER_CTRL_COMMIT_ERR|PAGER_CTRL_DIRTY_COMMIT);
	pPager->iJournalOfft = 0;
	pPager->nRec = 0;
	/* Database original size */
	pPager->dbSize = pPager->dbOrigSize;
	/* Discard all in-memory pages */
	for(;;){
		if( pPtr == 0 ){
			break;
		}
		pNext = pPtr->pNext; /* Reverse link */
		/* Remove stale flags */
		pPtr->flags &= ~(PAGE_DIRTY|PAGE_DONT_WRITE|PAGE_NEED_SYNC|PAGE_IN_JOURNAL|PAGE_HOT_DIRTY);
		/* Release the page */
		pager_release_page(pPager,pPtr);
		/* Point to the next page */
		pPtr = pNext;
	}
	pPager->pAll = 0;
	pPager->nPage = 0;
	pPager->pDirty = pPager->pFirstDirty = 0;
	pPager->pHotDirty = pPager->pFirstHot = 0;
	pPager->nHot = 0;
	if( pPager->apHash ){
		/* Zero the table */
		SyZero((void *)pPager->apHash,sizeof(Page *) * pPager->nSize);
	}
	if( pPager->pVec ){
		vedisBitvecDestroy(pPager->pVec);
		pPager->pVec = 0;
	}
	/* Switch back to shared lock */
	pager_unlock_db(pPager,SHARED_LOCK);
	pPager->iState = PAGER_READER;
	if( bResetKvEngine ){
		/* Reset the underlying KV engine */
		pIo = pEngine->pIo;
		if( pIo->pMethods->xRelease ){
			/* Call the release callback */
			pIo->pMethods->xRelease(pEngine);
		}
		/* Zero the structure */
		SyZero(pEngine,(sxu32)pIo->pMethods->szKv);
		/* Fill in */
		pEngine->pIo = pIo;
		if( pIo->pMethods->xInit ){
			/* Call the init method */
			rc = pIo->pMethods->xInit(pEngine,pPager->iPageSize);
			if( rc != VEDIS_OK ){
				return rc;
			}
		}
		if( pIo->pMethods->xOpen ){
			/* Call the xOpen method */
			rc = pIo->pMethods->xOpen(pEngine,pPager->dbSize);
			if( rc != VEDIS_OK ){
				return rc;
			}
		}
	}
	/* All done */
	return VEDIS_OK;
}
/*
** If a write transaction is open, then all changes made within the 
** transaction are reverted and the current write-transaction is closed.
** The pager falls back to PAGER_READER state if successful.
**
** Otherwise, in rollback mode, this function performs two functions:
**
**   1) It rolls back the journal file, restoring all database file and 
**      in-memory cache pages to the state they were in when the transaction
**      was opened, and
**
**   2) It finalizes the journal file, so that it is not used for hot
**      rollback at any point in the future (i.e. deletion).
**
** Finalization of the journal file (task 2) is only performed if the 
** rollback is successful.
**
*/
VEDIS_PRIVATE int vedisPagerRollback(Pager *pPager,int bResetKvEngine)
{
	int rc = VEDIS_OK;
	if( pPager->iState < PAGER_WRITER_LOCKED ){
		/* A write transaction must be opened */
		return VEDIS_OK;
	}
	if( pPager->is_mem ){
		/* As of this release 1.1.6: Transactions are not supported for in-memory databases */
		return VEDIS_OK;
	}
	if( pPager->is_rdonly ){
		/* Read-Only DB */
		vedisGenError(pPager->pDb,"Read-Only database");
		return VEDIS_READ_ONLY;
	}
	if( pPager->iState >= PAGER_WRITER_CACHEMOD ){
		if( !pPager->no_jrnl ){
			/* Close any outstanding joural file */
			if( pPager->pjfd ){
				/* Sync the journal file */
				vedisOsSync(pPager->pjfd,VEDIS_SYNC_NORMAL);
			}
			vedisOsCloseFree(pPager->pAllocator,pPager->pjfd);
			pPager->pjfd = 0;
			if( pPager->iFlags & (PAGER_CTRL_COMMIT_ERR|PAGER_CTRL_DIRTY_COMMIT) ){
				/* Perform the rollback */
				rc = pager_journal_rollback(pPager,0);
				if( rc != VEDIS_OK ){
					/* Set the auto-commit flag */
					pPager->pDb->iFlags |= VEDIS_FL_DISABLE_AUTO_COMMIT;
					return rc;
				}
			}
		}
		/* Unlink the journal file */
		vedisOsDelete(pPager->pVfs,pPager->zJournal,1);
		/* Reset the pager state */
		rc = pager_reset_state(pPager,bResetKvEngine);
		if( rc != VEDIS_OK ){
			/* Mostly an unlikely scenario */
			pPager->pDb->iFlags |= VEDIS_FL_DISABLE_AUTO_COMMIT; /* Set the auto-commit flag */
			vedisGenError(pPager->pDb,"Error while reseting pager to its initial state");
			return rc;
		}
	}else{
		/* Downgrade to shared lock */
		pager_unlock_db(pPager,SHARED_LOCK);
		pPager->iState = PAGER_READER;
	}
	return VEDIS_OK;
}
/*
 *  Mark a data page as non writeable.
 */
static int vedisPagerDontWrite(vedis_page *pMyPage)
{
	Page *pPage = (Page *)pMyPage;
	if( pPage->pgno > 0 /* Page 0 is always writeable */ ){
		pPage->flags |= PAGE_DONT_WRITE;
	}
	return VEDIS_OK;
}
/*
** Mark a data page as writeable. This routine must be called before 
** making changes to a page. The caller must check the return value 
** of this function and be careful not to change any page data unless 
** this routine returns VEDIS_OK.
*/
static int vedisPageWrite(vedis_page *pMyPage)
{
	Page *pPage = (Page *)pMyPage;
	Pager *pPager = pPage->pPager;
	int rc;
	/* Begin the write transaction */
	rc = vedisPagerBegin(pPager);
	if( rc != VEDIS_OK ){
		return rc;
	}
	if( pPager->iState == PAGER_WRITER_LOCKED ){
		/* The journal file needs to be opened. Higher level routines have already
		 ** obtained the necessary locks to begin the write-transaction, but the
		 ** rollback journal might not yet be open. Open it now if this is the case.
		 */
		rc = vedisOpenJournal(pPager);
		if( rc != VEDIS_OK ){
			return rc;
		}
	}
	if( pPager->nHot > 127 ){
		/* Write hot dirty pages */
		rc = pager_dirty_commit(pPager);
		if( rc != VEDIS_OK ){
			/* A rollback must be done */
			vedisGenError(pPager->pDb,"Please perform a rollback");
			return rc;
		}
	}
	/* Write the page to the journal file */
	rc = page_write(pPager,pPage);
	return rc;
}
/*
** Acquire a reference to page number pgno in pager pPager (a page
** reference has type vedis_page*). If the requested reference is 
** successfully obtained, it is copied to *ppPage and VEDIS_OK returned.
**
** If the requested page is already in the cache, it is returned. 
** Otherwise, a new page object is allocated and populated with data
** read from the database file.
*/
static int vedisPagerAcquire(
  Pager *pPager,      /* The pager open on the database file */
  pgno pgno,          /* Page number to fetch */
  vedis_page **ppPage,    /* OUT: Acquired page */
  int fetchOnly,      /* Cache lookup only */
  int noContent       /* Do not bother reading content from disk if true */
)
{
	Page *pPage;
	int rc;
	/* Acquire a shared lock (if not yet done) on the database and rollback any hot-journal if present */
	rc = pager_shared_lock(pPager);
	if( rc != VEDIS_OK ){
		return rc;
	}
	/* Fetch the page from the cache */
	pPage = pager_fetch_page(pPager,pgno);
	if( fetchOnly ){
		if( ppPage ){
			*ppPage = (vedis_page *)pPage;
		}
		return pPage ? VEDIS_OK : VEDIS_NOTFOUND;
	}
	if( pPage == 0 ){
		/* Allocate a new page */
		pPage = pager_alloc_page(pPager,pgno);
		if( pPage == 0 ){
			vedisGenOutofMem(pPager->pDb);
			return VEDIS_NOMEM;
		}
		/* Read page contents */
		rc = pager_get_page_contents(pPager,pPage,noContent);
		if( rc != VEDIS_OK ){
			SyMemBackendPoolFree(pPager->pAllocator,pPage);
			return rc;
		}
		/* Link the page */
		pager_link_page(pPager,pPage);
	}else{
		if( ppPage ){
			page_ref(pPage);
		}
	}
	/* All done, page is loaded in memeory */
	if( ppPage ){
		*ppPage = (vedis_page *)pPage;
	}
	return VEDIS_OK;
}
/*
 * Return true if we are dealing with an in-memory database.
 */
static int vedisInMemory(const char *zFilename)
{
	sxu32 n;
	if( SX_EMPTY_STR(zFilename) ){
		/* NULL or the empty string means an in-memory database */
		return TRUE;
	}
	n = SyStrlen(zFilename);
	if( n == sizeof(":mem:") - 1 && 
		SyStrnicmp(zFilename,":mem:",sizeof(":mem:") - 1) == 0 ){
			return TRUE;
	}
	if( n == sizeof(":memory:") - 1 && 
		SyStrnicmp(zFilename,":memory:",sizeof(":memory:") - 1) == 0 ){
			return TRUE;
	}
	return FALSE;
}
/*
 * Allocate a new KV cursor.
 */
VEDIS_PRIVATE int vedisInitCursor(vedis *pDb,vedis_kv_cursor **ppOut)
{
	vedis_kv_methods *pMethods;
	vedis_kv_cursor *pCur;
	sxu32 nByte;
	/* Storage engine methods */
	pMethods = pDb->pPager->pEngine->pIo->pMethods;
	if( pMethods->szCursor < 1 ){
		/* Implementation does not supprt cursors */
		vedisGenErrorFormat(pDb,"Storage engine '%s' does not support cursors",pMethods->zName);
		return VEDIS_NOTIMPLEMENTED;
	}
	nByte = pMethods->szCursor;
	if( nByte < sizeof(vedis_kv_cursor) ){
		nByte += sizeof(vedis_kv_cursor);
	}
	pCur = (vedis_kv_cursor *)SyMemBackendPoolAlloc(&pDb->sMem,nByte);
	if( pCur == 0 ){
		vedisGenOutofMem(pDb);
		return VEDIS_NOMEM;
	}
	/* Zero the structure */
	SyZero(pCur,nByte);
	/* Save the cursor */
	pCur->pStore = pDb->pPager->pEngine;
	/* Invoke the initialization callback if any */
	if( pMethods->xCursorInit ){
		pMethods->xCursorInit(pCur);
	}
	/* All done */
	*ppOut = pCur;
	return VEDIS_OK;
}
/*
 * Release a cursor.
 */
VEDIS_PRIVATE int vedisReleaseCursor(vedis *pDb,vedis_kv_cursor *pCur)
{
	vedis_kv_methods *pMethods;
	/* Storage engine methods */
	pMethods = pDb->pPager->pEngine->pIo->pMethods;
	/* Invoke the release callback if available */
	if( pMethods->xCursorRelease ){
		pMethods->xCursorRelease(pCur);
	}
	/* Finally, free the whole instance */
	SyMemBackendPoolFree(&pDb->sMem,pCur);
	return VEDIS_OK;
}
/*
 * Release the underlying KV storage engine and invoke
 * its associated callbacks if available.
 */
static void pager_release_kv_engine(Pager *pPager)
{
	vedis_kv_engine *pEngine = pPager->pEngine;
	vedis *pStorage = pPager->pDb;
	if( pStorage->pCursor ){
		/* Release the associated cursor */
		vedisReleaseCursor(pPager->pDb,pStorage->pCursor);
		pStorage->pCursor = 0;
	}
	if( pEngine->pIo->pMethods->xRelease ){
		pEngine->pIo->pMethods->xRelease(pEngine);
	}
	/* Release the whole instance */
	SyMemBackendFree(&pPager->pDb->sMem,(void *)pEngine->pIo);
	SyMemBackendFree(&pPager->pDb->sMem,(void *)pEngine);
	pPager->pEngine = 0;
}
/* Forward declaration */
static int pager_kv_io_init(Pager *pPager,vedis_kv_methods *pMethods,vedis_kv_io *pIo);
/*
 * Allocate, initialize and register a new KV storage engine
 * within this database instance.
 */
VEDIS_PRIVATE int vedisPagerRegisterKvEngine(Pager *pPager,vedis_kv_methods *pMethods)
{
	vedis *pStorage = pPager->pDb;
	vedis *pDb = pPager->pDb;
	vedis_kv_engine *pEngine;
	vedis_kv_io *pIo;
	sxu32 nByte;
	int rc;
	if( pPager->pEngine ){
		if( pMethods == pPager->pEngine->pIo->pMethods ){
			/* Ticket 1432: Same implementation */
			return VEDIS_OK;
		}
		/* Release the old KV engine */
		pager_release_kv_engine(pPager);
	}
	/* Allocate a new KV engine instance */
	nByte = (sxu32)pMethods->szKv;
	pEngine = (vedis_kv_engine *)SyMemBackendAlloc(&pDb->sMem,nByte);
	if( pEngine == 0 ){
		vedisGenOutofMem(pDb);
		return VEDIS_NOMEM;
	}
	pIo = (vedis_kv_io *)SyMemBackendAlloc(&pDb->sMem,sizeof(vedis_kv_io));
	if( pIo == 0 ){
		SyMemBackendFree(&pDb->sMem,pEngine);
		vedisGenOutofMem(pDb);
		return VEDIS_NOMEM;
	}
	/* Zero the structure */
	SyZero(pIo,sizeof(vedis_io_methods));
	SyZero(pEngine,nByte);
	/* Populate the IO structure */
	pager_kv_io_init(pPager,pMethods,pIo);
	pEngine->pIo = pIo;
	/* Invoke the init callback if avaialble */
	if( pMethods->xInit ){
		rc = pMethods->xInit(pEngine,vedisGetPageSize());
		if( rc != VEDIS_OK ){
			vedisGenErrorFormat(pDb,
				"xInit() method of the underlying KV engine '%z' failed",&pPager->sKv);
			goto fail;
		}
		pEngine->pIo = pIo;
	}
	pPager->pEngine = pEngine;
	/* Allocate a new cursor */
	rc = vedisInitCursor(pDb,&pStorage->pCursor);
	if( rc != VEDIS_OK ){
		goto fail;
	}
	return VEDIS_OK;
fail:
	SyMemBackendFree(&pDb->sMem,pEngine);
	SyMemBackendFree(&pDb->sMem,pIo);
	return rc;
}
/*
 * Return the underlying KV storage engine instance.
 */
VEDIS_PRIVATE vedis_kv_engine * vedisPagerGetKvEngine(vedis *pDb)
{
	return pDb->pPager->pEngine;
}
/*
* Allocate and initialize a new Pager object. The pager should
* eventually be freed by passing it to vedisPagerClose().
*
* The zFilename argument is the path to the database file to open.
* If zFilename is NULL or ":memory:" then all information is held
* in cache. It is never written to disk.  This can be used to implement
* an in-memory database.
*/
VEDIS_PRIVATE int vedisPagerOpen(
  vedis_vfs *pVfs,       /* The virtual file system to use */
  vedis *pDb,            /* Database handle */
  const char *zFilename,   /* Name of the database file to open */
  unsigned int iFlags      /* flags controlling this file */
  )
{
	vedis_kv_methods *pMethods = 0;
	int is_mem,rd_only,no_jrnl;
	Pager *pPager;
	sxu32 nByte;
	sxu32 nLen;
	int rc;

	/* Select the appropriate KV storage subsytem  */
	if( (iFlags & VEDIS_OPEN_IN_MEMORY) || vedisInMemory(zFilename) ){
		/* An in-memory database, record that  */
		pMethods = vedisFindKVStore("mem",sizeof("mem") - 1); /* Always available */
		iFlags |= VEDIS_OPEN_IN_MEMORY;
	}else{
		/* Install the default key value storage subsystem [i.e. Linear Hash] */
		pMethods = vedisFindKVStore("hash",sizeof("hash")-1);
		if( pMethods == 0 ){
			/* Use the b+tree storage backend if the linear hash storage is not available */
			pMethods = vedisFindKVStore("btree",sizeof("btree")-1);
		}
	}
	if( pMethods == 0 ){
		/* Can't happen */
		vedisGenError(pDb,"Cannot install a default Key/Value storage engine");
		return VEDIS_NOTIMPLEMENTED;
	}
	is_mem = (iFlags & VEDIS_OPEN_IN_MEMORY) != 0;
	rd_only = (iFlags & VEDIS_OPEN_READONLY) != 0;
	no_jrnl = (iFlags & VEDIS_OPEN_OMIT_JOURNALING) != 0;
	rc = VEDIS_OK;
	if( is_mem ){
		/* Omit journaling for in-memory database */
		no_jrnl = 1;
	}
	/* Total number of bytes to allocate */
	nByte = sizeof(Pager);
	nLen = 0;
	if( !is_mem ){
		nLen = SyStrlen(zFilename);
		nByte += pVfs->mxPathname + nLen + sizeof(char) /* null termniator */;
	}
	/* Allocate */
	pPager = (Pager *)SyMemBackendAlloc(&pDb->sMem,nByte);
	if( pPager == 0 ){
		return VEDIS_NOMEM;
	}
	/* Zero the structure */
	SyZero(pPager,nByte);
	/* Fill-in the structure */
	pPager->pAllocator = &pDb->sMem;
	pPager->pDb = pDb;
	pDb->pPager = pPager;
	/* Allocate page table */
	pPager->nSize = 128; /* Must be a power of two */
	nByte = pPager->nSize * sizeof(Page *);
	pPager->apHash = (Page **)SyMemBackendAlloc(pPager->pAllocator,nByte);
	if( pPager->apHash == 0 ){
		rc = VEDIS_NOMEM;
		goto fail;
	}
	SyZero(pPager->apHash,nByte);
	pPager->is_mem = is_mem;
	pPager->no_jrnl = no_jrnl;
	pPager->is_rdonly = rd_only;
	pPager->iOpenFlags = iFlags;
	pPager->pVfs = pVfs;
	SyRandomnessInit(&pPager->sPrng,0,0);
	SyRandomness(&pPager->sPrng,(void *)&pPager->cksumInit,sizeof(sxu32));
	/* Unlimited cache size */
	pPager->nCacheMax = SXU32_HIGH;
	/* Copy filename and journal name */
	if( !is_mem ){
		pPager->zFilename = (char *)&pPager[1];
		rc = VEDIS_OK;
		if( pVfs->xFullPathname ){
			rc = pVfs->xFullPathname(pVfs,zFilename,pVfs->mxPathname + nLen,pPager->zFilename);
		}
		if( rc != VEDIS_OK ){
			/* Simple filename copy */
			SyMemcpy(zFilename,pPager->zFilename,nLen);
			pPager->zFilename[nLen] = 0;
			rc = VEDIS_OK;
		}else{
			nLen = SyStrlen(pPager->zFilename);
		}
		pPager->zJournal = (char *) SyMemBackendAlloc(pPager->pAllocator,nLen + sizeof(VEDIS_JOURNAL_FILE_SUFFIX) + sizeof(char));
		if( pPager->zJournal == 0 ){
			rc = VEDIS_NOMEM;
			goto fail;
		}
		/* Copy filename */
		SyMemcpy(pPager->zFilename,pPager->zJournal,nLen);
		/* Copy journal suffix */
		SyMemcpy(VEDIS_JOURNAL_FILE_SUFFIX,&pPager->zJournal[nLen],sizeof(VEDIS_JOURNAL_FILE_SUFFIX)-1);
		/* Append the nul terminator to the journal path */
		pPager->zJournal[nLen + ( sizeof(VEDIS_JOURNAL_FILE_SUFFIX) - 1)] = 0;
	}
	/* Finally, register the selected KV engine */
	rc = vedisPagerRegisterKvEngine(pPager,pMethods);
	if( rc != VEDIS_OK ){
		goto fail;
	}
	/* Set the pager state */
	if( pPager->is_mem ){
		pPager->iState = PAGER_WRITER_FINISHED;
		pPager->iLock = EXCLUSIVE_LOCK;
	}else{
		pPager->iState = PAGER_OPEN;
		pPager->iLock = NO_LOCK;
	}
	/* All done, ready for processing */
	return VEDIS_OK;
fail:
	SyMemBackendFree(&pDb->sMem,pPager);
	return rc;
}
/*
 * Return TRUE if we are dealing with an in-memory database.
 */
VEDIS_PRIVATE int vedisPagerisMemStore(vedis *pStore)
{
	return pStore->pPager->is_mem;
}
/*
 * Set a cache limit. Note that, this is a simple hint, the pager is not
 * forced to honor this limit.
 */
VEDIS_PRIVATE int vedisPagerSetCachesize(Pager *pPager,int mxPage)
{
	if( mxPage < 256 ){
		return VEDIS_INVALID;
	}
	pPager->nCacheMax = mxPage;
	return VEDIS_OK;
}
/*
 * Set the user commit callback.
 */
VEDIS_PRIVATE int vedisPagerSetCommitCallback(Pager *pPager,int (*xCommit)(void *),void *pUserdata)
{
	pPager->xCommit = xCommit;
	pPager->pCommitData = pUserdata;
	return VEDIS_OK;
}
/*
 * Shutdown the page cache. Free all memory and close the database file.
 */
VEDIS_PRIVATE int vedisPagerClose(Pager *pPager)
{
	/* Release the KV engine */
	pager_release_kv_engine(pPager);
	if( pPager->iOpenFlags & VEDIS_OPEN_MMAP ){
		const vedis_vfs *pVfs = vedisExportBuiltinVfs();
		if( pVfs && pVfs->xUnmap && pPager->pMmap ){
			pVfs->xUnmap(pPager->pMmap,pPager->dbByteSize);
		}
	}
	if( !pPager->is_mem && pPager->iState > PAGER_OPEN ){
		/* Release all lock on this database handle */
		pager_unlock_db(pPager,NO_LOCK);
		/* Close the file  */
		vedisOsCloseFree(pPager->pAllocator,pPager->pfd);
	}
	if( pPager->pVec ){
		vedisBitvecDestroy(pPager->pVec);
		pPager->pVec = 0;
	}
	return VEDIS_OK;
}
/*
 * Generate a random string.
 */
VEDIS_PRIVATE void vedisPagerRandomString(Pager *pPager,char *zBuf,sxu32 nLen)
{
	static const char zBase[] = {"abcdefghijklmnopqrstuvwxyz"}; /* English Alphabet */
	sxu32 i;
	/* Generate a binary string first */
	SyRandomness(&pPager->sPrng,zBuf,nLen);
	/* Turn the binary string into english based alphabet */
	for( i = 0 ; i < nLen ; ++i ){
		 zBuf[i] = zBase[zBuf[i] % (sizeof(zBase)-1)];
	 }
}
/*
 * Generate a random number.
 */
VEDIS_PRIVATE sxu32 vedisPagerRandomNum(Pager *pPager)
{
	sxu32 iNum;
	SyRandomness(&pPager->sPrng,(void *)&iNum,sizeof(iNum));
	return iNum;
}
/* Exported KV IO Methods */
/* 
 * Refer to [vedisPagerAcquire()]
 */
static int vedisKvIoPageGet(vedis_kv_handle pHandle,pgno iNum,vedis_page **ppPage)
{
	int rc;
	rc = vedisPagerAcquire((Pager *)pHandle,iNum,ppPage,0,0);
	return rc;
}
/* 
 * Refer to [vedisPagerAcquire()]
 */
static int vedisKvIoPageLookup(vedis_kv_handle pHandle,pgno iNum,vedis_page **ppPage)
{
	int rc;
	rc = vedisPagerAcquire((Pager *)pHandle,iNum,ppPage,1,0);
	return rc;
}
/* 
 * Refer to [vedisPagerAcquire()]
 */
static int vedisKvIoNewPage(vedis_kv_handle pHandle,vedis_page **ppPage)
{
	Pager *pPager = (Pager *)pHandle;
	int rc;
	/* 
	 * Acquire a reader-lock first so that pPager->dbSize get initialized.
	 */
	rc = pager_shared_lock(pPager);
	if( rc == VEDIS_OK ){
		rc = vedisPagerAcquire(pPager,pPager->dbSize == 0 ? /* Page 0 is reserved */ 1 : pPager->dbSize ,ppPage,0,0);
	}
	return rc;
}
/* 
 * Refer to [vedisPageWrite()]
 */
static int vedisKvIopageWrite(vedis_page *pPage)
{
	int rc;
	if( pPage == 0 ){
		/* TICKET 1433-0348 */
		return VEDIS_OK;
	}
	rc = vedisPageWrite(pPage);
	return rc;
}
/* 
 * Refer to [vedisPagerDontWrite()]
 */
static int vedisKvIoPageDontWrite(vedis_page *pPage)
{
	int rc;
	if( pPage == 0 ){
		/* TICKET 1433-0348 */
		return VEDIS_OK;
	}
	rc = vedisPagerDontWrite(pPage);
	return rc;
}
/* 
 * Refer to [vedisBitvecSet()]
 */
static int vedisKvIoPageDontJournal(vedis_page *pRaw)
{
	Page *pPage = (Page *)pRaw;
	Pager *pPager;
	if( pPage == 0 ){
		/* TICKET 1433-0348 */
		return VEDIS_OK;
	}
	pPager = pPage->pPager;
	if( pPager->iState >= PAGER_WRITER_LOCKED ){
		if( !pPager->no_jrnl && pPager->pVec && !vedisBitvecTest(pPager->pVec,pPage->pgno) ){
			vedisBitvecSet(pPager->pVec,pPage->pgno);
		}
	}
	return VEDIS_OK;
}
/* 
 * Do not add a page to the hot dirty list.
 */
static int vedisKvIoPageDontMakeHot(vedis_page *pRaw)
{
	Page *pPage = (Page *)pRaw;
	
	if( pPage == 0 ){
		/* TICKET 1433-0348 */
		return VEDIS_OK;
	}
	pPage->flags |= PAGE_DONT_MAKE_HOT;
	return VEDIS_OK;
}
/* 
 * Refer to [page_ref()]
 */
static int vedisKvIopage_ref(vedis_page *pPage)
{
	if( pPage ){
		page_ref((Page *)pPage);
	}
	return VEDIS_OK;
}
/* 
 * Refer to [page_unref()]
 */
static int vedisKvIoPageUnRef(vedis_page *pPage)
{
	if( pPage ){
		page_unref((Page *)pPage);
	}
	return VEDIS_OK;
}
/* 
 * Refer to the declaration of the [Pager] structure
 */
static int vedisKvIoReadOnly(vedis_kv_handle pHandle)
{
	return ((Pager *)pHandle)->is_rdonly;
}
/* 
 * Refer to the declaration of the [Pager] structure
 */
static int vedisKvIoPageSize(vedis_kv_handle pHandle)
{
	return ((Pager *)pHandle)->iPageSize;
}
/* 
 * Refer to the declaration of the [Pager] structure
 */
static unsigned char * vedisKvIoTempPage(vedis_kv_handle pHandle)
{
	return ((Pager *)pHandle)->zTmpPage;
}
/* 
 * Set a page unpin callback.
 * Refer to the declaration of the [Pager] structure
 */
static void vedisKvIoPageUnpin(vedis_kv_handle pHandle,void (*xPageUnpin)(void *))
{
	Pager *pPager = (Pager *)pHandle;
	pPager->xPageUnpin = xPageUnpin;
}
/* 
 * Set a page reload callback.
 * Refer to the declaration of the [Pager] structure
 */
static void vedisKvIoPageReload(vedis_kv_handle pHandle,void (*xPageReload)(void *))
{
	Pager *pPager = (Pager *)pHandle;
	pPager->xPageReload = xPageReload;
}
/* 
 * Log an error.
 * Refer to the declaration of the [Pager] structure
 */
static void vedisKvIoErr(vedis_kv_handle pHandle,const char *zErr)
{
	Pager *pPager = (Pager *)pHandle;
	vedisGenError(pPager->pDb,zErr);
}
/*
 * Init an instance of the [vedis_kv_io] structure.
 */
static int pager_kv_io_init(Pager *pPager,vedis_kv_methods *pMethods,vedis_kv_io *pIo)
{
	pIo->pHandle =  pPager;
	pIo->pMethods = pMethods;
	
	pIo->xGet    = vedisKvIoPageGet;
	pIo->xLookup = vedisKvIoPageLookup;
	pIo->xNew    = vedisKvIoNewPage;
	
	pIo->xWrite     = vedisKvIopageWrite; 
	pIo->xDontWrite = vedisKvIoPageDontWrite;
	pIo->xDontJournal = vedisKvIoPageDontJournal;
	pIo->xDontMkHot = vedisKvIoPageDontMakeHot;

	pIo->xPageRef   = vedisKvIopage_ref;
	pIo->xPageUnref = vedisKvIoPageUnRef;

	pIo->xPageSize = vedisKvIoPageSize;
	pIo->xReadOnly = vedisKvIoReadOnly;

	pIo->xTmpPage =  vedisKvIoTempPage;

	pIo->xSetUnpin = vedisKvIoPageUnpin;
	pIo->xSetReload = vedisKvIoPageReload;

	pIo->xErr = vedisKvIoErr;

	return VEDIS_OK;
}
/*
 * ----------------------------------------------------------
 * File: os_win.c
 * MD5: 8f05b9895ac8989f395417dcf864fa74
 * ----------------------------------------------------------
 */
/*
 * Symisc Vedis: An Embeddable NoSQL (Post Modern) Database Engine.
 * Copyright (C) 2012-2013, Symisc Systems http://vedis.org/
 * Version 1.1.6
 * For information on licensing, redistribution of this file, and for a DISCLAIMER OF ALL WARRANTIES
 * please contact Symisc Systems via:
 *       legal@symisc.net
 *       licensing@symisc.net
 *       contact@symisc.net
 * or visit:
 *      http://vedis.org/licensing.html
 */
 /* $SymiscID: os_win.c v1.2 Win7 2012-11-10 12:10 devel <chm@symisc.net> $ */
#ifndef VEDIS_AMALGAMATION
#include "vedisInt.h"
#endif
/* Omit the whole layer from the build if compiling for platforms other than Windows */
#ifdef __WINNT__
/* This file contains code that is specific to windows. (Mostly SQLite3 source tree) */
#include <Windows.h>
/*
** Some microsoft compilers lack this definition.
*/
#ifndef INVALID_FILE_ATTRIBUTES
# define INVALID_FILE_ATTRIBUTES ((DWORD)-1) 
#endif
/*
** WinCE lacks native support for file locking so we have to fake it
** with some code of our own.
*/
#ifdef __WIN_CE__
typedef struct winceLock {
  int nReaders;       /* Number of reader locks obtained */
  BOOL bPending;      /* Indicates a pending lock has been obtained */
  BOOL bReserved;     /* Indicates a reserved lock has been obtained */
  BOOL b

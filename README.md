vedis
=====

An Embedded Implementation of Redis. http://vedis.symisc.net

Overview
--------

Vedis is an embeddable datastore C library built with over 70 [commands](http://vedis.symisc.net/commands.html) similar in concept to Redis but without the networking layer since Vedis run in the same process of the host application.


Unlike most other datastores (i.e. memcache, Redis), Vedis does not have a separate server process. Vedis reads and writes directly to ordinary disk files. A complete database with multiple collections, is contained in a single disk file. The database file format is cross-platform, you can freely copy a database between 32-bit and 64-bit systems or between big-endian and little-endian architectures.

Vedis is a self-contained C library without dependency. It requires very minimal support from external libraries or from the operating system. This makes it well suited for use in embedded devices that lack the support infrastructure of a desktop computer. This also makes Vedis appropriate for use within applications that need to run without modification on a wide variety of computers of varying configurations.

Features
--------

* Serverless, datastore engine.
* Transactional (ACID) datastore.
* Built with over 70 commands similar to the standard Redis commands.
* Zero configuration.
* Single database file, does not use temporary files.
* Cross-platform file format.
* Standard Key/Value store.
* Support for on-disk as well in-memory datastore.
* Thread safe and full reentrant.
* Simple, Clean and easy to use API.
* Support Terabyte sized databases. 

Vedis in 5 Minutes or Less
--------------------------

The principal task of a datastore engine is to store and retrieve records as fast as possible. Vedis support both structured and raw data storage.


Structured data storage is presented to clients via the command execution interface (CEI). Basically, you execute one or more commands ala Redis (i.e. SET key value; GET key, HSET...) via [vedis_exec()](http://vedis.symisc.net/c_api/vedis_exec.html) and you extract the execution result (The return value of the command) via [vedis_exec_result()](http://vedis.symisc.net/c_api/vedis_exec_result.html). Refer to the [following page](http://vedis.symisc.net/commands.html) for the list of built-in commands.


Raw data storage is presented to clients via the Key/Value store interfaces. Vedis is a standard key/value store similar to Berkeley DB, Tokyo Cabinet, LevelDB, etc. but with a rich feature set including support for transactions (ACID), concurrent reader, etc.

Under the KV store, both keys and values are treated as simple arrays of bytes, so content can be anything from ASCII strings, binary blob and even disk files. The KV store layer is presented to clients via a set of interfaces, these includes: [vedis_kv_store()](http://vedis.symisc.net/c_api/vedis_kv_store.html), [vedis_kv_append()](http://vedis.symisc.net/c_api/vedis_kv_append.html), [vedis_kv_fetch_callback()](http://vedis.symisc.net/c_api/vedis_kv_fetch_callback.html), [vedis_kv_append_fmt()](http://vedis.symisc.net/c_api/vedis_kv_append.html), etc.



    vedis *pStore; /* Datastore handle */
    int rc;

    /* Create our datastore */
    rc = vedis_open(&pStore,argc > 1 ? argv[1] /* On-disk DB */ : ":mem:"/* In-mem DB */);
    if( rc != VEDIS_OK ){  /* Seriously? */  return; }

    /* Execute the simplest command */
    rc = vedis_exec(pStore,"SET test 'Hello World'",-1);
    if( rc != VEDIS_OK ){ /* Handle error */ }

    /* Another simple command (Multiple set) */
    rc = vedis_exec(pStore,"MSET username james age 27 mail dude@example.com",-1);
    if( rc != VEDIS_OK ){ /* Handle error */ }

    /* A quite complex command (Multiple hash set) using foreign data */
    rc = vedis_exec_fmt(pStore,
         "HMSET config pid %d user %s os %s scm %s",
          1024    /* pid */,
          "dean", /* user */
          "FreeBSD", /* OS */
          "Git"      /* SCM */
       );
    if( rc != VEDIS_OK ){ /* Handle error */ }

    /* Fetch some data */
    rc = vedis_exec(pStore,"GET test",-1);
    if( rc != VEDIS_OK ){ /* Seriously? */ }

    /* Extract the return value of the last executed command (i.e. 'GET test') " */
    vedis_exec_result(pStore,&pResult);
    {
        const char *zResponse;
         /* Cast the vedis object to a string */
         zResponse = vedis_value_to_string(pResult,0);
         /* Output */
         printf(" test ==> %s\n",zResponse); /* test ==> 'Hello world' */
    }

    vedis_exec(pStore,"GET mail",-1);
    /* 'GET mail' return value */
    vedis_exec_result(pStore,&pResult);
    {
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

    /* Extract hashtable data */
    vedis_exec(pStore,"HGET config pid",-1); /* 1024 */
    vedis_exec_result(pStore,&pResult);
    {
      int pid;
      /* Cast to integer */
      pid = vedis_value_to_int(pResult);
      /* Output */
      printf("pid ==> %d\n",pid); /* Should be 1024 */
    }
    /* Finally, auto-commit the transaction and close our datastore */
    vedis_close(pStore);



* The datastore is created on line 5 using a call to [vedis_open()](http://vedis.symisc.net/c_api/vedis_open.html). This is often the first Vedis API call that an application makes and is a prerequisite in order to play with Vedis.
* As you can see, executing commands (ala Redis) under Vedis is pretty simple and involve only a single call to vedis_exec() or vedis_exec_fmt(). This is done on line 9, 13, 17, 45 on our example regardless how much the executed command is complex.
* Execution result (i.e. Return value) of the last executed command is extracted via vedis_exec_result(). This is done on line 27, 31, 40, 54 in our example.
* After that, the host application need to cast this object value (i.e. Return value of the last executed command) to the desired C type (String, Integer, Double or Boolean). For this purpose, a set of smart interfaces is available: vedis_value_to_string(), vedis_value_to_int(), vedis_value_to_bool(),  etc. This done on line 35, 46, 64 and 76.
* Working with commands which returns an object value of type array (i.e. MGET, HMGET, HVALS, CMD_LIST, etc.) is straightforward and involve only a single call to vedis_array_walk() or vedis_array_next_elem(). The first interface expect a user supplied callback which is invoked for each entry in the array while the latter iterate over the array elements one after one.
* Finally, the transaction is auto-committed and our datastore is closed on line 81 using the vedis_close() interface.
* Enhancing Vedis with foreign (i.e. User defined) commands is pretty simple and involve only a single call to vedis_register_command(). All of the built-in commands are installed using exactly this interface. 

Download, License and Support
-----------------------------

visit http://vedis.symisc.net


/* This file was generated automatically by Zephir do not modify it! */

#ifndef PHP_BEEFRAMEWORK_H
#define PHP_BEEFRAMEWORK_H 1

#ifdef PHP_WIN32
#define ZEPHIR_RELEASE 1
#endif

#include "kernel/globals.h"

#define PHP_BEEFRAMEWORK_NAME        "beeframework"
#define PHP_BEEFRAMEWORK_VERSION     "1.0.0"
#define PHP_BEEFRAMEWORK_EXTNAME     "beeframework"
#define PHP_BEEFRAMEWORK_AUTHOR      "Lei Mengcheng<mengch.lei@foxmail.com>"


ZEND_BEGIN_MODULE_GLOBALS(beeframework)

	int initialized;

	/* Memory */
	zephir_memory_entry *start_memory; /**< The first preallocated frame */
	zephir_memory_entry *end_memory; /**< The last preallocate frame */
	zephir_memory_entry *active_memory; /**< The current memory frame */

	/* Virtual Symbol Tables */
	zephir_symbol_table *active_symbol_table;

	/** Function cache */
	HashTable *fcache;

	zephir_fcall_cache_entry *scache[ZEPHIR_MAX_CACHE_SLOTS];

	/* Cache enabled */
	unsigned int cache_enabled;

	/* Max recursion control */
	unsigned int recursive_lock;

	/* Global constants */
	zval *global_true;
	zval *global_false;
	zval *global_null;
	
ZEND_END_MODULE_GLOBALS(beeframework)

#ifdef ZTS
#include "TSRM.h"
#endif

ZEND_EXTERN_MODULE_GLOBALS(beeframework)

#ifdef ZTS
	#define ZEPHIR_GLOBAL(v) TSRMG(beeframework_globals_id, zend_beeframework_globals *, v)
#else
	#define ZEPHIR_GLOBAL(v) (beeframework_globals.v)
#endif

#ifdef ZTS
	#define ZEPHIR_VGLOBAL ((zend_beeframework_globals *) (*((void ***) tsrm_ls))[TSRM_UNSHUFFLE_RSRC_ID(beeframework_globals_id)])
#else
	#define ZEPHIR_VGLOBAL &(beeframework_globals)
#endif

#define ZEPHIR_API ZEND_API

#define zephir_globals_def beeframework_globals
#define zend_zephir_globals_def zend_beeframework_globals

extern zend_module_entry beeframework_module_entry;
#define phpext_beeframework_ptr &beeframework_module_entry

#endif

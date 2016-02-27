
/* This file was generated automatically by Zephir do not modify it! */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#if PHP_VERSION_ID < 50500
#include <locale.h>
#endif

#include "php_ext.h"
#include "beeframework.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/globals.h"
#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"



zend_class_entry *beeframework_model_adapterinterface_ce;
zend_class_entry *beeframework_base_ce;
zend_class_entry *beeframework_exception_ce;
zend_class_entry *beeframework_0__closure_ce;
zend_class_entry *beeframework_app_ce;
zend_class_entry *beeframework_controller_ce;
zend_class_entry *beeframework_input_ce;
zend_class_entry *beeframework_loader_ce;
zend_class_entry *beeframework_logger_ce;
zend_class_entry *beeframework_model_adapter_ce;
zend_class_entry *beeframework_model_adapter_mysql_ce;
zend_class_entry *beeframework_model_ce;
zend_class_entry *beeframework_model_exception_ce;
zend_class_entry *beeframework_router_ce;
zend_class_entry *beeframework_utils_ce;
zend_class_entry *beeframework_view_ce;

ZEND_DECLARE_MODULE_GLOBALS(beeframework)

PHP_INI_BEGIN()
	
PHP_INI_END()

static PHP_MINIT_FUNCTION(beeframework)
{
#if PHP_VERSION_ID < 50500
	char* old_lc_all = setlocale(LC_ALL, NULL);
	if (old_lc_all) {
		size_t len = strlen(old_lc_all);
		char *tmp  = calloc(len+1, 1);
		if (UNEXPECTED(!tmp)) {
			return FAILURE;
		}

		memcpy(tmp, old_lc_all, len);
		old_lc_all = tmp;
	}

	setlocale(LC_ALL, "C");
#endif
	REGISTER_INI_ENTRIES();
	ZEPHIR_INIT(BeeFramework_Model_AdapterInterface);
	ZEPHIR_INIT(BeeFramework_Base);
	ZEPHIR_INIT(BeeFramework_Exception);
	ZEPHIR_INIT(BeeFramework_App);
	ZEPHIR_INIT(BeeFramework_Controller);
	ZEPHIR_INIT(BeeFramework_Input);
	ZEPHIR_INIT(BeeFramework_Loader);
	ZEPHIR_INIT(BeeFramework_Logger);
	ZEPHIR_INIT(BeeFramework_Model);
	ZEPHIR_INIT(BeeFramework_Model_Adapter);
	ZEPHIR_INIT(BeeFramework_Model_Adapter_Mysql);
	ZEPHIR_INIT(BeeFramework_Model_Exception);
	ZEPHIR_INIT(BeeFramework_Router);
	ZEPHIR_INIT(BeeFramework_Utils);
	ZEPHIR_INIT(BeeFramework_View);
	ZEPHIR_INIT(beeframework_0__closure);

#if PHP_VERSION_ID < 50500
	setlocale(LC_ALL, old_lc_all);
	free(old_lc_all);
#endif
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(beeframework)
{

	zephir_deinitialize_memory(TSRMLS_C);
	UNREGISTER_INI_ENTRIES();
	return SUCCESS;
}
#endif

/**
 * Initialize globals on each request or each thread started
 */
static void php_zephir_init_globals(zend_beeframework_globals *beeframework_globals TSRMLS_DC)
{
	beeframework_globals->initialized = 0;

	/* Memory options */
	beeframework_globals->active_memory = NULL;

	/* Virtual Symbol Tables */
	beeframework_globals->active_symbol_table = NULL;

	/* Cache Enabled */
	beeframework_globals->cache_enabled = 1;

	/* Recursive Lock */
	beeframework_globals->recursive_lock = 0;

	/* Static cache */
	memset(beeframework_globals->scache, '\0', sizeof(zephir_fcall_cache_entry*) * ZEPHIR_MAX_CACHE_SLOTS);


}

static PHP_RINIT_FUNCTION(beeframework)
{

	zend_beeframework_globals *beeframework_globals_ptr = ZEPHIR_VGLOBAL;

	php_zephir_init_globals(beeframework_globals_ptr TSRMLS_CC);
	//zephir_init_interned_strings(TSRMLS_C);

	zephir_initialize_memory(beeframework_globals_ptr TSRMLS_CC);

	zephir_init_static_properties_BeeFramework_Base(TSRMLS_C);

	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(beeframework)
{
	zephir_deinitialize_memory(TSRMLS_C);
	return SUCCESS;
}

static PHP_MINFO_FUNCTION(beeframework)
{
	php_info_print_table_start();
	php_info_print_table_header(2, PHP_BEEFRAMEWORK_NAME, "enabled");
	php_info_print_table_row(2, "Author", PHP_BEEFRAMEWORK_AUTHOR);
	php_info_print_table_row(2, "Version", PHP_BEEFRAMEWORK_VERSION);
	php_info_print_table_row(2, "Build Date", __DATE__ " " __TIME__ );
	php_info_print_table_end();

	DISPLAY_INI_ENTRIES();
}

static PHP_GINIT_FUNCTION(beeframework)
{
	php_zephir_init_globals(beeframework_globals TSRMLS_CC);
}

static PHP_GSHUTDOWN_FUNCTION(beeframework)
{

}


zend_function_entry php_beeframework_functions[] = {
ZEND_FE_END

};

zend_module_entry beeframework_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	NULL,
	PHP_BEEFRAMEWORK_EXTNAME,
	php_beeframework_functions,
	PHP_MINIT(beeframework),
#ifndef ZEPHIR_RELEASE
	PHP_MSHUTDOWN(beeframework),
#else
	NULL,
#endif
	PHP_RINIT(beeframework),
	PHP_RSHUTDOWN(beeframework),
	PHP_MINFO(beeframework),
	PHP_BEEFRAMEWORK_VERSION,
	ZEND_MODULE_GLOBALS(beeframework),
	PHP_GINIT(beeframework),
	PHP_GSHUTDOWN(beeframework),
	NULL,
	STANDARD_MODULE_PROPERTIES_EX
};

#ifdef COMPILE_DL_BEEFRAMEWORK
ZEND_GET_MODULE(beeframework)
#endif

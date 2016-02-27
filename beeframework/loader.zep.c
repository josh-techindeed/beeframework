
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/concat.h"
#include "kernel/object.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(BeeFramework_Loader) {

	ZEPHIR_REGISTER_CLASS_EX(BeeFramework, Loader, beeframework, loader, beeframework_base_ce, beeframework_loader_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(BeeFramework_Loader, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_PARENT(NULL, beeframework_loader_ce, this_ptr, "__construct", &_0, 3);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(BeeFramework_Loader, load_config) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *file_path;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &file_path);



	ZEPHIR_RETURN_CALL_FUNCTION("parse_ini_file", NULL, 7, file_path, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(BeeFramework_Loader, getConf) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *file_name, *file_path = NULL, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &file_name);



	_0 = zephir_fetch_static_property_ce(beeframework_base_ce, SL("config") TSRMLS_CC);
	zephir_array_fetch_string(&_1, _0, SL("config_path"), PH_NOISY | PH_READONLY, "beeframework/Loader.zep", 20 TSRMLS_CC);
	ZEPHIR_INIT_VAR(file_path);
	ZEPHIR_CONCAT_VV(file_path, _1, file_name);
	ZEPHIR_RETURN_CALL_SELF("load_config", NULL, 0, file_path);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(BeeFramework_Loader, getAppConf) {

	zval *app_file_path = NULL, *_0, *_1;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_static_property_ce(beeframework_base_ce, SL("config") TSRMLS_CC);
	zephir_array_fetch_string(&_1, _0, SL("config_path"), PH_NOISY | PH_READONLY, "beeframework/Loader.zep", 27 TSRMLS_CC);
	ZEPHIR_INIT_VAR(app_file_path);
	ZEPHIR_CONCAT_VS(app_file_path, _1, "/application.ini");
	ZEPHIR_RETURN_CALL_SELF("load_config", NULL, 0, app_file_path);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(BeeFramework_Loader, getDbConf) {

	zval *db_file_path = NULL, *_0, *_1;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_static_property_ce(beeframework_base_ce, SL("config") TSRMLS_CC);
	zephir_array_fetch_string(&_1, _0, SL("config_path"), PH_NOISY | PH_READONLY, "beeframework/Loader.zep", 34 TSRMLS_CC);
	ZEPHIR_INIT_VAR(db_file_path);
	ZEPHIR_CONCAT_VS(db_file_path, _1, "/database.ini");
	ZEPHIR_RETURN_CALL_SELF("load_config", NULL, 0, db_file_path);
	zephir_check_call_status();
	RETURN_MM();

}


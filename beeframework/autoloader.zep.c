
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
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/object.h"
#include "kernel/variables.h"
#include "kernel/require.h"


ZEPHIR_INIT_CLASS(BeeFramework_Autoloader) {

	ZEPHIR_REGISTER_CLASS(BeeFramework, Autoloader, beeframework, autoloader, beeframework_autoloader_method_entry, 0);

	zend_declare_property_null(beeframework_autoloader_ce, SL("_config"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(BeeFramework_Autoloader, __construct) {

	zval *_1;
	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_0, this_ptr);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "loader", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_CALL_FUNCTION(NULL, "spl_autoload_register", NULL, 5, _0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(BeeFramework_Autoloader, loader) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *className, *app_path = NULL, *_0 = NULL, *models_path = NULL, *filePath = NULL, *_1, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &className);



	ZEPHIR_CALL_FUNCTION(&_0, "getcwd", NULL, 1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(app_path);
	ZEPHIR_CONCAT_VS(app_path, _0, "/..");
	ZEPHIR_INIT_VAR(models_path);
	ZEPHIR_CONCAT_VS(models_path, app_path, "/models");
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_config"), PH_NOISY_CC);
	zephir_array_fetch_string(&_2, _1, SL("models_path"), PH_NOISY | PH_READONLY, "beeframework/Autoloader.zep", 22 TSRMLS_CC);
	ZEPHIR_INIT_VAR(filePath);
	ZEPHIR_CONCAT_VSVS(filePath, _2, "/", className, ".php");
	zephir_var_dump(&filePath TSRMLS_CC);
	if (zephir_require_zval(filePath TSRMLS_CC) == FAILURE) {
		RETURN_MM_NULL();
	}
	ZEPHIR_MM_RESTORE();

}


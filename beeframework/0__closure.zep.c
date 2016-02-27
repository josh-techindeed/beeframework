
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
#include "kernel/concat.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/require.h"


ZEPHIR_INIT_CLASS(beeframework_0__closure) {

	ZEPHIR_REGISTER_CLASS(beeframework, 0__closure, beeframework, 0__closure, beeframework_0__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;

}

PHP_METHOD(beeframework_0__closure, __invoke) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *className, *app_path = NULL, *models_path = NULL, *file_path = NULL, *_0 = NULL, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &className);



	ZEPHIR_CALL_FUNCTION(&_0, "getcwd", NULL, 1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(app_path);
	ZEPHIR_CONCAT_VS(app_path, _0, "/..");
	ZEPHIR_INIT_VAR(models_path);
	ZEPHIR_CONCAT_VSS(models_path, app_path, "/", "models");
	ZEPHIR_INIT_VAR(file_path);
	ZEPHIR_CONCAT_VSVS(file_path, models_path, "/", className, ".php");
	ZEPHIR_CALL_FUNCTION(&_1, "is_file", NULL, 19, file_path);
	zephir_check_call_status();
	if (zephir_is_true(_1)) {
		if (zephir_require_zval(file_path TSRMLS_CC) == FAILURE) {
			RETURN_MM_NULL();
		}
	}
	ZEPHIR_MM_RESTORE();

}


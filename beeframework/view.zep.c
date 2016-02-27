
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
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/file.h"
#include "kernel/require.h"
#include "kernel/exception.h"


ZEPHIR_INIT_CLASS(BeeFramework_View) {

	ZEPHIR_REGISTER_CLASS_EX(BeeFramework, View, beeframework, view, beeframework_base_ce, beeframework_view_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(BeeFramework_View, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_PARENT(NULL, beeframework_view_ce, this_ptr, "__construct", &_0, 3);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(BeeFramework_View, render) {

	zend_bool _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *template, *data = NULL, *file_path = NULL, *_1, *_2, *_3$$5, *_4$$5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &template, &data);

	if (!data) {
		ZEPHIR_INIT_VAR(data);
		ZVAL_STRING(data, "", 1);
	}


	_0 = !(ZEPHIR_IS_EMPTY(data));
	if (_0) {
		_0 = Z_TYPE_P(data) == IS_ARRAY;
	}
	if (_0) {
		ZEPHIR_MAKE_REF(data);
		ZEPHIR_CALL_FUNCTION(NULL, "extract", NULL, 17, data);
		ZEPHIR_UNREF(data);
		zephir_check_call_status();
	}
	_1 = zephir_fetch_static_property_ce(beeframework_base_ce, SL("config") TSRMLS_CC);
	zephir_array_fetch_string(&_2, _1, SL("views_path"), PH_NOISY | PH_READONLY, "beeframework/View.zep", 21 TSRMLS_CC);
	ZEPHIR_INIT_VAR(file_path);
	ZEPHIR_CONCAT_VSV(file_path, _2, "/", template);
	if ((zephir_file_exists(file_path TSRMLS_CC) == SUCCESS)) {
		if (zephir_require_zval(file_path TSRMLS_CC) == FAILURE) {
			RETURN_MM_NULL();
		}
	} else {
		ZEPHIR_INIT_VAR(_3$$5);
		object_init_ex(_3$$5, beeframework_exception_ce);
		ZEPHIR_INIT_VAR(_4$$5);
		ZEPHIR_CONCAT_SVS(_4$$5, "Load template failure, Reason: ", template, " not exists");
		ZEPHIR_CALL_METHOD(NULL, _3$$5, "__construct", NULL, 18, _4$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(_3$$5, "beeframework/View.zep", 25 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();

}



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
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "kernel/array.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(BeeFramework_Input) {

	ZEPHIR_REGISTER_CLASS(BeeFramework, Input, beeframework, input, beeframework_input_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(BeeFramework_Input, xss_clean) {

	zval *_3;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *value = NULL, *_0 = NULL, *_1 = NULL, *_2 = NULL, _4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value);

	ZEPHIR_SEPARATE_PARAM(value);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "/([\\x00-\\x08,\\x0b-\\x0c,\\x0e-\\x19])/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", NULL, 6, _0, _1, value);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(value, _2);
	ZEPHIR_INIT_NVAR(_0);
	ZEPHIR_INIT_VAR(_3);
	zephir_create_array(_3, 8, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "\"", 1);
	zephir_array_fast_append(_3, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "\\", 1);
	zephir_array_fast_append(_3, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "'", 1);
	zephir_array_fast_append(_3, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "/", 1);
	zephir_array_fast_append(_3, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "..", 1);
	zephir_array_fast_append(_3, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "../", 1);
	zephir_array_fast_append(_3, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "./", 1);
	zephir_array_fast_append(_3, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "//", 1);
	zephir_array_fast_append(_3, _1);
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_STRING(&_4, "", 0);
	zephir_fast_str_replace(&_0, _3, &_4, value TSRMLS_CC);
	ZEPHIR_CPY_WRT(value, _0);
	RETVAL_ZVAL(value, 1, 0);
	RETURN_MM();

}

PHP_METHOD(BeeFramework_Input, _fetch_from_array) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool remove_xss;
	zval *arr, *index, *remove_xss_param = NULL, *_0$$3 = NULL, *_1$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &arr, &index, &remove_xss_param);

	if (!remove_xss_param) {
		remove_xss = 1;
	} else {
		remove_xss = zephir_get_boolval(remove_xss_param);
	}


	if (zephir_array_isset(arr, index)) {
		ZEPHIR_INIT_VAR(_0$$3);
		if (remove_xss) {
			zephir_array_fetch(&_1$$3, arr, index, PH_NOISY | PH_READONLY, "beeframework/Input.zep", 16 TSRMLS_CC);
			ZEPHIR_CALL_SELF(&_0$$3, "xss_clean", NULL, 0, _1$$3);
			zephir_check_call_status();
		} else {
			zephir_array_fetch(&_0$$3, arr, index, PH_NOISY, "beeframework/Input.zep", 16 TSRMLS_CC);
		}
		RETURN_CCTOR(_0$$3);
	}
	RETURN_MM_BOOL(0);

}

PHP_METHOD(BeeFramework_Input, get) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool remove_xss;
	zval *index = NULL, *remove_xss_param = NULL, *_GET, *_0 = NULL, *_1;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_GET, SS("_GET") TSRMLS_CC);
	zephir_fetch_params(1, 0, 2, &index, &remove_xss_param);

	if (!index) {
		ZEPHIR_INIT_VAR(index);
		ZVAL_STRING(index, "", 1);
	}
	if (!remove_xss_param) {
		remove_xss = 1;
	} else {
		remove_xss = zephir_get_boolval(remove_xss_param);
	}


	ZEPHIR_INIT_VAR(_0);
	if (ZEPHIR_IS_EMPTY(index)) {
		ZEPHIR_CPY_WRT(_0, _GET);
	} else {
		ZEPHIR_INIT_VAR(_1);
		if (remove_xss) {
			ZVAL_BOOL(_1, 1);
		} else {
			ZVAL_BOOL(_1, 0);
		}
		ZEPHIR_CALL_SELF(&_0, "_fetch_from_array", NULL, 0, _GET, index, _1);
		zephir_check_call_status();
	}
	RETURN_CCTOR(_0);

}

PHP_METHOD(BeeFramework_Input, post) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool remove_xss;
	zval *index = NULL, *remove_xss_param = NULL, *_POST, *_0 = NULL, *_1;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_POST, SS("_POST") TSRMLS_CC);
	zephir_fetch_params(1, 0, 2, &index, &remove_xss_param);

	if (!index) {
		ZEPHIR_INIT_VAR(index);
		ZVAL_STRING(index, "", 1);
	}
	if (!remove_xss_param) {
		remove_xss = 1;
	} else {
		remove_xss = zephir_get_boolval(remove_xss_param);
	}


	ZEPHIR_INIT_VAR(_0);
	if (ZEPHIR_IS_EMPTY(index)) {
		ZEPHIR_CPY_WRT(_0, _POST);
	} else {
		ZEPHIR_INIT_VAR(_1);
		if (remove_xss) {
			ZVAL_BOOL(_1, 1);
		} else {
			ZVAL_BOOL(_1, 0);
		}
		ZEPHIR_CALL_SELF(&_0, "_fetch_from_array", NULL, 0, _POST, index, _1);
		zephir_check_call_status();
	}
	RETURN_CCTOR(_0);

}


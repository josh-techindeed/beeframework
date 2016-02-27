
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
#include "kernel/string.h"
#include "kernel/memory.h"
#include "kernel/hash.h"
#include "kernel/array.h"
#include "kernel/fcall.h"


ZEPHIR_INIT_CLASS(BeeFramework_Utils) {

	ZEPHIR_REGISTER_CLASS(BeeFramework, Utils, beeframework, utils, beeframework_utils_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(BeeFramework_Utils, parse_str) {

	HashTable *_1;
	HashPosition _0;
	zval *query_string, *arr_query_string = NULL, *item = NULL, **_2, *arr_item$$3 = NULL, *_3$$3, *_4$$3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &query_string);



	ZEPHIR_INIT_VAR(arr_query_string);
	zephir_fast_explode_str(arr_query_string, SL("&"), query_string, LONG_MAX TSRMLS_CC);
	zephir_is_iterable(arr_query_string, &_1, &_0, 1, 0, "beeframework/Utils.zep", 17);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(item, _2);
		ZEPHIR_INIT_NVAR(arr_item$$3);
		zephir_fast_explode_str(arr_item$$3, SL("="), item, LONG_MAX TSRMLS_CC);
		zephir_array_fetch_long(&_3$$3, arr_item$$3, 1, PH_NOISY | PH_READONLY, "beeframework/Utils.zep", 15 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(_4$$3);
		zephir_array_fetch_long(&_4$$3, arr_item$$3, 0, PH_NOISY, "beeframework/Utils.zep", 15 TSRMLS_CC);
		zephir_array_update_zval(&arr_query_string, _4$$3, &_3$$3, PH_COPY | PH_SEPARATE);
	}
	zend_hash_destroy(_1);
	FREE_HASHTABLE(_1);
	RETURN_CCTOR(arr_query_string);

}

PHP_METHOD(BeeFramework_Utils, parse_uri) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *request_uri, *arr_request_uri = NULL, _0, *_1, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &request_uri);



	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "/\\//", 0);
	ZEPHIR_CALL_FUNCTION(&arr_request_uri, "preg_split", NULL, 16, &_0, request_uri);
	zephir_check_call_status();
	zephir_array_fetch_long(&_1, arr_request_uri, 0, PH_NOISY | PH_READONLY, "beeframework/Utils.zep", 25 TSRMLS_CC);
	zephir_array_update_string(&arr_request_uri, SL("c"), &_1, PH_COPY | PH_SEPARATE);
	zephir_array_fetch_long(&_2, arr_request_uri, 1, PH_NOISY | PH_READONLY, "beeframework/Utils.zep", 26 TSRMLS_CC);
	zephir_array_update_string(&arr_request_uri, SL("a"), &_2, PH_COPY | PH_SEPARATE);
	RETURN_CCTOR(arr_request_uri);

}


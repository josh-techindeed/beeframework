
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
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/object.h"
#include "kernel/concat.h"
#include "kernel/file.h"
#include "kernel/require.h"


ZEPHIR_INIT_CLASS(BeeFramework_Router) {

	ZEPHIR_REGISTER_CLASS_EX(BeeFramework, Router, beeframework, router, beeframework_base_ce, beeframework_router_method_entry, 0);

	zend_declare_property_string(beeframework_router_ce, SL("_defaultController"), "home", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(beeframework_router_ce, SL("_defaultAction"), "index", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(beeframework_router_ce, SL("notFound"), ZEND_ACC_PUBLIC TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(BeeFramework_Router, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_PARENT(NULL, beeframework_router_ce, this_ptr, "__construct", &_0, 3);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(BeeFramework_Router, _parse_uri_auto) {

	zend_bool _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_SERVER, *query_string = NULL, *request_uri = NULL, *_1, *_2, _3;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);

	ZEPHIR_OBS_VAR(query_string);
	zephir_array_fetch_string(&query_string, _SERVER, SL("QUERY_STRING"), PH_NOISY, "beeframework/Router.zep", 20 TSRMLS_CC);
	ZEPHIR_OBS_VAR(request_uri);
	zephir_array_fetch_string(&request_uri, _SERVER, SL("REQUEST_URI"), PH_NOISY, "beeframework/Router.zep", 21 TSRMLS_CC);
	_0 = !(ZEPHIR_IS_EMPTY(query_string));
	if (_0) {
		ZEPHIR_INIT_VAR(_1);
		ZEPHIR_INIT_VAR(_2);
		ZEPHIR_SINIT_VAR(_3);
		ZVAL_STRING(&_3, "/c=/", 0);
		zephir_preg_match(_2, &_3, query_string, _1, 0, 0 , 0  TSRMLS_CC);
		_0 = zephir_is_true(_2);
	}
	if (_0) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_parse_query_string", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	} else {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_parse_request_uri", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}

}

PHP_METHOD(BeeFramework_Router, _parse_query_string) {

	zend_bool _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_5 = NULL;
	zval *_SERVER, *arrClassAction = NULL, *query_string = NULL, *parse_query_string = NULL, *_1, *_2, _3, *_4$$3 = NULL, *_6$$4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);

	ZEPHIR_OBS_VAR(query_string);
	zephir_array_fetch_string(&query_string, _SERVER, SL("QUERY_STRING"), PH_NOISY, "beeframework/Router.zep", 35 TSRMLS_CC);
	_0 = ZEPHIR_IS_EMPTY(query_string);
	if (!(_0)) {
		ZEPHIR_INIT_VAR(_1);
		ZEPHIR_INIT_VAR(_2);
		ZEPHIR_SINIT_VAR(_3);
		ZVAL_STRING(&_3, "/c=/", 0);
		zephir_preg_match(_2, &_3, query_string, _1, 0, 0 , 0  TSRMLS_CC);
		_0 = !zephir_is_true(_2);
	}
	ZEPHIR_INIT_VAR(arrClassAction);
	if (_0) {
		zephir_create_array(arrClassAction, 2, 0 TSRMLS_CC);
		ZEPHIR_OBS_VAR(_4$$3);
		zephir_read_property_this(&_4$$3, this_ptr, SL("_defaultController"), PH_NOISY_CC);
		zephir_array_update_string(&arrClassAction, SL("c"), &_4$$3, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(_4$$3);
		zephir_read_property_this(&_4$$3, this_ptr, SL("_defaultAction"), PH_NOISY_CC);
		zephir_array_update_string(&arrClassAction, SL("a"), &_4$$3, PH_COPY | PH_SEPARATE);
	} else {
		ZEPHIR_CALL_CE_STATIC(&parse_query_string, beeframework_utils_ce, "parse_str", &_5, 14, query_string);
		zephir_check_call_status();
		zephir_create_array(arrClassAction, 2, 0 TSRMLS_CC);
		ZEPHIR_OBS_VAR(_6$$4);
		zephir_array_fetch_string(&_6$$4, parse_query_string, SL("c"), PH_NOISY, "beeframework/Router.zep", 40 TSRMLS_CC);
		zephir_array_update_string(&arrClassAction, SL("c"), &_6$$4, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(_6$$4);
		zephir_array_fetch_string(&_6$$4, parse_query_string, SL("a"), PH_NOISY, "beeframework/Router.zep", 40 TSRMLS_CC);
		zephir_array_update_string(&arrClassAction, SL("a"), &_6$$4, PH_COPY | PH_SEPARATE);
	}
	RETURN_CCTOR(arrClassAction);

}

PHP_METHOD(BeeFramework_Router, _parse_request_uri) {

	zend_bool _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_23 = NULL;
	zval *_SERVER, *arrClassAction = NULL, *request_uri = NULL, *parse_request_uri = NULL, *_0, *_2, *_3, _8, _9, *_10, *strClassAction = NULL, *_13, *_14, _15, *_4$$3, *_5$$3, *_6$$3, _7$$3, _11$$4, *_12$$4, *pos$$5 = NULL, _16$$5, _17$$5, *_18$$7 = NULL, *_19$$8, *_20$$8, _21$$8, *_22$$9, *_24$$10 = NULL;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);

	ZEPHIR_OBS_VAR(request_uri);
	zephir_array_fetch_string(&request_uri, _SERVER, SL("REQUEST_URI"), PH_NOISY, "beeframework/Router.zep", 51 TSRMLS_CC);
	_0 = zephir_fetch_static_property_ce(beeframework_base_ce, SL("config") TSRMLS_CC);
	_1 = zephir_array_isset_string(_0, SS("base_url"));
	if (_1) {
		_2 = zephir_fetch_static_property_ce(beeframework_base_ce, SL("config") TSRMLS_CC);
		ZEPHIR_OBS_VAR(_3);
		zephir_array_fetch_string(&_3, _2, SL("base_url"), PH_NOISY, "beeframework/Router.zep", 52 TSRMLS_CC);
		_1 = !(ZEPHIR_IS_EMPTY(_3));
	}
	if (_1) {
		ZEPHIR_INIT_VAR(_4$$3);
		_5$$3 = zephir_fetch_static_property_ce(beeframework_base_ce, SL("config") TSRMLS_CC);
		zephir_array_fetch_string(&_6$$3, _5$$3, SL("base_url"), PH_NOISY | PH_READONLY, "beeframework/Router.zep", 53 TSRMLS_CC);
		ZEPHIR_SINIT_VAR(_7$$3);
		ZVAL_STRING(&_7$$3, "", 0);
		zephir_fast_str_replace(&_4$$3, _6$$3, &_7$$3, request_uri TSRMLS_CC);
		ZEPHIR_CPY_WRT(request_uri, _4$$3);
	}
	ZEPHIR_SINIT_VAR(_8);
	ZVAL_LONG(&_8, 0);
	ZEPHIR_SINIT_VAR(_9);
	ZVAL_LONG(&_9, 1);
	ZEPHIR_INIT_VAR(_10);
	zephir_substr(_10, request_uri, 0 , 1 , 0);
	if (ZEPHIR_IS_STRING(_10, "/")) {
		ZEPHIR_SINIT_VAR(_11$$4);
		ZVAL_LONG(&_11$$4, 1);
		ZEPHIR_INIT_VAR(_12$$4);
		zephir_substr(_12$$4, request_uri, 1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
		ZEPHIR_CPY_WRT(request_uri, _12$$4);
	}
	ZEPHIR_INIT_VAR(_13);
	ZEPHIR_INIT_VAR(_14);
	ZEPHIR_SINIT_VAR(_15);
	ZVAL_STRING(&_15, "/\\?/", 0);
	zephir_preg_match(_14, &_15, request_uri, _13, 0, 0 , 0  TSRMLS_CC);
	if (zephir_is_true(_14)) {
		ZEPHIR_SINIT_VAR(_16$$5);
		ZVAL_STRING(&_16$$5, "?", 0);
		ZEPHIR_INIT_VAR(pos$$5);
		zephir_fast_strpos(pos$$5, request_uri, &_16$$5, 0 );
		if (zephir_is_true(pos$$5)) {
			ZEPHIR_SINIT_VAR(_17$$5);
			ZVAL_LONG(&_17$$5, 0);
			ZEPHIR_INIT_VAR(strClassAction);
			zephir_substr(strClassAction, request_uri, 0 , zephir_get_intval(pos$$5), 0);
		} else {
			ZEPHIR_INIT_NVAR(strClassAction);
			ZVAL_STRING(strClassAction, "", 1);
		}
	} else {
		ZEPHIR_CPY_WRT(strClassAction, request_uri);
	}
	if (ZEPHIR_IS_EMPTY(strClassAction)) {
		ZEPHIR_INIT_VAR(arrClassAction);
		zephir_create_array(arrClassAction, 2, 0 TSRMLS_CC);
		ZEPHIR_OBS_VAR(_18$$7);
		zephir_read_property_this(&_18$$7, this_ptr, SL("_defaultController"), PH_NOISY_CC);
		zephir_array_update_string(&arrClassAction, SL("c"), &_18$$7, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(_18$$7);
		zephir_read_property_this(&_18$$7, this_ptr, SL("_defaultAction"), PH_NOISY_CC);
		zephir_array_update_string(&arrClassAction, SL("a"), &_18$$7, PH_COPY | PH_SEPARATE);
	} else {
		ZEPHIR_INIT_VAR(_19$$8);
		ZEPHIR_INIT_VAR(_20$$8);
		ZEPHIR_SINIT_VAR(_21$$8);
		ZVAL_STRING(&_21$$8, "/\\//", 0);
		zephir_preg_match(_20$$8, &_21$$8, strClassAction, _19$$8, 0, 0 , 0  TSRMLS_CC);
		ZEPHIR_INIT_NVAR(arrClassAction);
		if (!(zephir_is_true(_20$$8))) {
			zephir_create_array(arrClassAction, 2, 0 TSRMLS_CC);
			zephir_array_update_string(&arrClassAction, SL("c"), &strClassAction, PH_COPY | PH_SEPARATE);
			ZEPHIR_OBS_VAR(_22$$9);
			zephir_read_property_this(&_22$$9, this_ptr, SL("_defaultAction"), PH_NOISY_CC);
			zephir_array_update_string(&arrClassAction, SL("a"), &_22$$9, PH_COPY | PH_SEPARATE);
		} else {
			ZEPHIR_CALL_CE_STATIC(&parse_request_uri, beeframework_utils_ce, "parse_uri", &_23, 15, strClassAction);
			zephir_check_call_status();
			zephir_create_array(arrClassAction, 2, 0 TSRMLS_CC);
			ZEPHIR_OBS_VAR(_24$$10);
			zephir_array_fetch_string(&_24$$10, parse_request_uri, SL("c"), PH_NOISY, "beeframework/Router.zep", 75 TSRMLS_CC);
			zephir_array_update_string(&arrClassAction, SL("c"), &_24$$10, PH_COPY | PH_SEPARATE);
			ZEPHIR_OBS_NVAR(_24$$10);
			zephir_array_fetch_string(&_24$$10, parse_request_uri, SL("a"), PH_NOISY, "beeframework/Router.zep", 75 TSRMLS_CC);
			zephir_array_update_string(&arrClassAction, SL("a"), &_24$$10, PH_COPY | PH_SEPARATE);
		}
	}
	RETURN_CCTOR(arrClassAction);

}

/**
 * Parse URI
 *
 * Analytic URL and turn into class and method
 *
 * return array [$class, $method]
 */
PHP_METHOD(BeeFramework_Router, parseURI) {

	zval *arrClassAction = NULL, *uri_protocol = NULL, *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_static_property_ce(beeframework_base_ce, SL("config") TSRMLS_CC);
	ZEPHIR_OBS_VAR(uri_protocol);
	zephir_array_fetch_string(&uri_protocol, _0, SL("uri_protocol"), PH_NOISY, "beeframework/Router.zep", 94 TSRMLS_CC);
	do {
		if (ZEPHIR_IS_STRING(uri_protocol, "AUTO")) {
			ZEPHIR_CALL_METHOD(&arrClassAction, this_ptr, "_parse_uri_auto", NULL, 0);
			zephir_check_call_status();
			break;
		}
		if (ZEPHIR_IS_STRING(uri_protocol, "QUERY_STRING")) {
			ZEPHIR_CALL_METHOD(&arrClassAction, this_ptr, "_parse_query_string", NULL, 0);
			zephir_check_call_status();
			break;
		}
		if (ZEPHIR_IS_STRING(uri_protocol, "PATH_INFO")) {
			ZEPHIR_CALL_METHOD(&arrClassAction, this_ptr, "_parse_request_uri", NULL, 0);
			zephir_check_call_status();
			break;
		}
	} while(0);

	RETURN_CCTOR(arrClassAction);

}

/**
 * Call Method
 *
 * @param object $class
 * @param string $method
 */
PHP_METHOD(BeeFramework_Router, callMethod) {

	zval *_0, *_2$$3;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *method = NULL;
	zval *instance, *method_param = NULL, *_1$$3, *_3$$4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &instance, &method_param);

	zephir_get_strval(method, method_param);


	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_0, instance);
	zephir_array_fast_append(_0, method);
	if (zephir_is_callable(_0 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_1$$3);
		ZEPHIR_INIT_VAR(_2$$3);
		zephir_create_array(_2$$3, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(_2$$3, instance);
		zephir_array_fast_append(_2$$3, method);
		ZEPHIR_CALL_USER_FUNC(_1$$3, _2$$3);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(_3$$4);
		ZVAL_LONG(_3$$4, 404);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "error", NULL, 0, _3$$4);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(BeeFramework_Router, dispatch) {

	zval *parseURI = NULL, *className = NULL, *actionName = NULL, *classPath = NULL, *_0, *_1, *_2, *_3, *_4, *classInstance = NULL, *_5$$4, *_6$$5;
	zephir_fcall_cache_entry *_7 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&parseURI, this_ptr, "parseuri", NULL, 0);
	zephir_check_call_status();
	zephir_array_fetch_string(&_0, parseURI, SL("c"), PH_NOISY | PH_READONLY, "beeframework/Router.zep", 133 TSRMLS_CC);
	ZEPHIR_INIT_VAR(className);
	zephir_ucfirst(className, _0);
	zephir_array_fetch_string(&_1, parseURI, SL("a"), PH_NOISY | PH_READONLY, "beeframework/Router.zep", 134 TSRMLS_CC);
	ZEPHIR_INIT_VAR(actionName);
	zephir_fast_strtolower(actionName, _1);
	_2 = zephir_fetch_static_property_ce(beeframework_base_ce, SL("config") TSRMLS_CC);
	zephir_array_fetch_string(&_3, _2, SL("controllers_path"), PH_NOISY | PH_READONLY, "beeframework/Router.zep", 136 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_4);
	zephir_fast_strtolower(_4, className);
	ZEPHIR_INIT_VAR(classPath);
	ZEPHIR_CONCAT_VSVS(classPath, _3, "/", _4, ".php");
	if ((zephir_file_exists(classPath TSRMLS_CC) == SUCCESS)) {
		if (zephir_require_zval(classPath TSRMLS_CC) == FAILURE) {
			RETURN_MM_NULL();
		}
	} else {
		ZEPHIR_INIT_VAR(_5$$4);
		ZVAL_LONG(_5$$4, 404);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "error", NULL, 0, _5$$4);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(classInstance);
	ZEPHIR_LAST_CALL_STATUS = zephir_create_instance(classInstance, className TSRMLS_CC);
	zephir_check_call_status();
	if (ZEPHIR_IS_EMPTY(actionName)) {
		_6$$5 = zephir_fetch_nproperty_this(this_ptr, SL("_defaultAction"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "callmethod", &_7, 0, classInstance, _6$$5);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "callmethod", &_7, 0, classInstance, actionName);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Error
 *
 * @param int $code
 */
PHP_METHOD(BeeFramework_Router, error) {

	zval *code_param = NULL, *_0$$3, *_1$$4, *_2$$4;
	int code, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &code_param);

	if (!code_param) {
		code = 500;
	} else {
		code = zephir_get_intval(code_param);
	}


	if (code == 404) {
		_0$$3 = zephir_fetch_nproperty_this(this_ptr, SL("notFound"), PH_NOISY_CC);
		if (zephir_is_callable(_0$$3 TSRMLS_CC)) {
			ZEPHIR_INIT_VAR(_1$$4);
			_2$$4 = zephir_fetch_nproperty_this(this_ptr, SL("notFound"), PH_NOISY_CC);
			ZEPHIR_CALL_USER_FUNC(_1$$4, _2$$4);
			zephir_check_call_status();
		} else {
			php_printf("%s", "404 Not Found");
		}
	} else {
		php_printf("%s", "Error {code}");
	}
	ZEPHIR_MM_RESTORE();

}


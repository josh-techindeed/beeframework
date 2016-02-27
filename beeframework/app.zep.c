
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
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(BeeFramework_App) {

	ZEPHIR_REGISTER_CLASS_EX(BeeFramework, App, beeframework, app, beeframework_base_ce, beeframework_app_method_entry, 0);

	zend_declare_property_null(beeframework_app_ce, SL("_router"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(BeeFramework_App, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_PARENT(NULL, beeframework_app_ce, this_ptr, "__construct", &_0, 3);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(BeeFramework_App, init) {

	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	object_init_ex(_0, beeframework_router_ce);
	ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, 4);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_router"), _0 TSRMLS_CC);
	RETURN_THIS();

}

PHP_METHOD(BeeFramework_App, getConfig) {

	zval *_0;


	_0 = zephir_fetch_static_property_ce(beeframework_app_ce, SL("config") TSRMLS_CC);
	RETURN_CTORW(_0);

}

PHP_METHOD(BeeFramework_App, dispatch) {

	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_router"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "dispatch", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}


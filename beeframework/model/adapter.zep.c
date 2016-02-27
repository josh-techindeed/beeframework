
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/string.h"
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/concat.h"
#include "kernel/fcall.h"


ZEPHIR_INIT_CLASS(BeeFramework_Model_Adapter) {

	ZEPHIR_REGISTER_CLASS(BeeFramework\\Model, Adapter, beeframework, model_adapter, beeframework_model_adapter_method_entry, 0);

	zend_declare_property_null(beeframework_model_adapter_ce, SL("__instance"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(BeeFramework_Model_Adapter, factory) {

	zval *_3$$3;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *config, *type = NULL, *_0, *_1, *_4, *className$$3 = NULL, *classInstance$$3 = NULL, *_2$$3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &config);



	zephir_array_fetch_string(&_0, config, SL("type"), PH_NOISY | PH_READONLY, "beeframework/Model/Adapter.zep", 10 TSRMLS_CC);
	ZEPHIR_INIT_VAR(type);
	zephir_ucfirst(type, _0);
	_1 = zephir_fetch_static_property_ce(beeframework_model_adapter_ce, SL("__instance") TSRMLS_CC);
	if (Z_TYPE_P(_1) == IS_NULL) {
		ZEPHIR_INIT_VAR(className$$3);
		ZEPHIR_CONCAT_SV(className$$3, "\\BeeFramework\\Model\\Adapter\\", type);
		ZEPHIR_INIT_VAR(classInstance$$3);
		object_init_ex(classInstance$$3, zephir_get_internal_ce(SS("reflectionclass") TSRMLS_CC));
		ZEPHIR_CALL_METHOD(NULL, classInstance$$3, "__construct", NULL, 12, className$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_3$$3);
		zephir_create_array(_3$$3, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(_3$$3, config);
		ZEPHIR_CALL_METHOD(&_2$$3, classInstance$$3, "newinstanceargs", NULL, 13, _3$$3);
		zephir_check_call_status();
		zephir_update_static_property_ce(beeframework_model_adapter_ce, SL("__instance"), &_2$$3 TSRMLS_CC);
	}
	_4 = zephir_fetch_static_property_ce(beeframework_model_adapter_ce, SL("__instance") TSRMLS_CC);
	RETURN_CTOR(_4);

}


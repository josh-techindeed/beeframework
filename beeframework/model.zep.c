
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
#include "kernel/object.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(BeeFramework_Model) {

	ZEPHIR_REGISTER_CLASS_EX(BeeFramework, Model, beeframework, model, beeframework_base_ce, beeframework_model_method_entry, 0);

	zend_declare_property_null(beeframework_model_ce, SL("db_config"), ZEND_ACC_PUBLIC|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_null(beeframework_model_ce, SL("database"), ZEND_ACC_PUBLIC TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(BeeFramework_Model, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *cluster = NULL, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &cluster);

	if (!cluster) {
		ZEPHIR_INIT_VAR(cluster);
		ZVAL_STRING(cluster, "default", 1);
	}


	ZEPHIR_CALL_CE_STATIC(&_0, beeframework_loader_ce, "getdbconf", &_1, 11);
	zephir_check_call_status();
	zephir_update_static_property_ce(beeframework_model_ce, SL("db_config"), &_0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(BeeFramework_Model, getDbConf) {

	zval *cluster = NULL, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &cluster);

	if (!cluster) {
		ZEPHIR_INIT_VAR(cluster);
		ZVAL_STRING(cluster, "default", 1);
	}


	_0 = zephir_fetch_static_property_ce(beeframework_model_ce, SL("db_config") TSRMLS_CC);
	zephir_array_fetch(&_1, _0, cluster, PH_NOISY | PH_READONLY, "beeframework/Model.zep", 20 TSRMLS_CC);
	RETURN_CTOR(_1);

}


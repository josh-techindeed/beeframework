
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
#include "kernel/object.h"
#include "kernel/array.h"


/**
 * BeeFramework\Base
 *
 * All framework base class
 */
ZEPHIR_INIT_CLASS(BeeFramework_Base) {

	ZEPHIR_REGISTER_CLASS(BeeFramework, Base, beeframework, base, beeframework_base_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(beeframework_base_ce, SL("config"), ZEND_ACC_PUBLIC|ZEND_ACC_STATIC TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(BeeFramework_Base, __construct) {

	zval *app_path = NULL, *_0 = NULL, *_1 = NULL, *app_config = NULL, *_3, *_4, *_5;
	zephir_fcall_cache_entry *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(&_0, "getcwd", NULL, 1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(app_path);
	ZEPHIR_CONCAT_VSS(app_path, _0, "/", "..");
	zephir_update_static_property_array_multi_ce(beeframework_base_ce, SL("config"), &app_path TSRMLS_CC, SL("s"), 2, SL("app_path"));
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_VSS(_1, app_path, "/", "config");
	zephir_update_static_property_array_multi_ce(beeframework_base_ce, SL("config"), &_1 TSRMLS_CC, SL("s"), 2, SL("config_path"));
	ZEPHIR_INIT_LNVAR(_1);
	ZEPHIR_CONCAT_VSS(_1, app_path, "/", "controllers");
	zephir_update_static_property_array_multi_ce(beeframework_base_ce, SL("config"), &_1 TSRMLS_CC, SL("s"), 2, SL("controllers_path"));
	ZEPHIR_INIT_LNVAR(_1);
	ZEPHIR_CONCAT_VSS(_1, app_path, "/", "views");
	zephir_update_static_property_array_multi_ce(beeframework_base_ce, SL("config"), &_1 TSRMLS_CC, SL("s"), 2, SL("views_path"));
	ZEPHIR_INIT_LNVAR(_1);
	ZEPHIR_CONCAT_VSS(_1, app_path, "/", "models");
	zephir_update_static_property_array_multi_ce(beeframework_base_ce, SL("config"), &_1 TSRMLS_CC, SL("s"), 2, SL("models_path"));
	ZEPHIR_INIT_LNVAR(_1);
	ZEPHIR_CONCAT_VSS(_1, app_path, "/", "logs");
	zephir_update_static_property_array_multi_ce(beeframework_base_ce, SL("config"), &_1 TSRMLS_CC, SL("s"), 2, SL("logs_path"));
	ZEPHIR_INIT_LNVAR(_1);
	ZEPHIR_CONCAT_VSS(_1, app_path, "/", "libraries");
	zephir_update_static_property_array_multi_ce(beeframework_base_ce, SL("config"), &_1 TSRMLS_CC, SL("s"), 2, SL("libraries_path"));
	ZEPHIR_INIT_LNVAR(_1);
	ZEPHIR_CONCAT_VSS(_1, app_path, "/", "public");
	zephir_update_static_property_array_multi_ce(beeframework_base_ce, SL("config"), &_1 TSRMLS_CC, SL("s"), 2, SL("public_path"));
	ZEPHIR_INIT_LNVAR(_1);
	ZEPHIR_CONCAT_VSS(_1, app_path, "/", "vendor");
	zephir_update_static_property_array_multi_ce(beeframework_base_ce, SL("config"), &_1 TSRMLS_CC, SL("s"), 2, SL("vendor_path"));
	ZEPHIR_INIT_LNVAR(_1);
	ZEPHIR_CONCAT_VSS(_1, app_path, "/", "helpers");
	zephir_update_static_property_array_multi_ce(beeframework_base_ce, SL("config"), &_1 TSRMLS_CC, SL("s"), 2, SL("helpers_path"));
	ZEPHIR_CALL_CE_STATIC(&app_config, beeframework_loader_ce, "getappconf", &_2, 2);
	zephir_check_call_status();
	zephir_array_fetch_string(&_3, app_config, SL("application"), PH_NOISY | PH_READONLY, "beeframework/Base.zep", 33 TSRMLS_CC);
	ZEPHIR_CPY_WRT(app_config, _3);
	ZEPHIR_INIT_VAR(_4);
	_5 = zephir_fetch_static_property_ce(beeframework_base_ce, SL("config") TSRMLS_CC);
	zephir_fast_array_merge(_4, &(_5), &(app_config) TSRMLS_CC);
	zephir_update_static_property_ce(beeframework_base_ce, SL("config"), &_4 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

void zephir_init_static_properties_BeeFramework_Base(TSRMLS_D) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_static_property_ce(beeframework_base_ce, SL("config"), &_0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}


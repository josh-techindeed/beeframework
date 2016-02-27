
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
#include "kernel/object.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(BeeFramework_Controller) {

	ZEPHIR_REGISTER_CLASS_EX(BeeFramework, Controller, beeframework, controller, beeframework_base_ce, beeframework_controller_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(BeeFramework_Controller, __construct) {

	zval *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_PARENT(NULL, beeframework_controller_ce, this_ptr, "__construct", &_0, 3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_INIT_NVAR(_1);
	zephir_create_closure_ex(_1, NULL, beeframework_0__closure_ce, SS("__invoke") TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(NULL, "spl_autoload_register", NULL, 5, _1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}



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


ZEPHIR_INIT_CLASS(BeeFramework_Main) {

	ZEPHIR_REGISTER_CLASS(BeeFramework, Main, beeframework, main, beeframework_main_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(BeeFramework_Main, init) {

	

	php_printf("%s", "beeframework");

}


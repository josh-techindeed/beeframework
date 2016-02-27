
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


ZEPHIR_INIT_CLASS(BeeFramework_Bootstrap) {

	ZEPHIR_REGISTER_CLASS(BeeFramework, Bootstrap, beeframework, bootstrap, beeframework_bootstrap_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(BeeFramework_Bootstrap, run) {

	

	php_printf("%s", "beeframework");

}


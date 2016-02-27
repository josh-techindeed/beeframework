
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(BeeFramework_Model_AdapterInterface) {

	ZEPHIR_REGISTER_INTERFACE(BeeFramework\\Model, AdapterInterface, beeframework, model_adapterinterface, beeframework_model_adapterinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(BeeFramework_Model_AdapterInterface, test);


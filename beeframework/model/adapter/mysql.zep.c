
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/array.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(BeeFramework_Model_Adapter_Mysql) {

	ZEPHIR_REGISTER_CLASS(BeeFramework\\Model\\Adapter, Mysql, beeframework, model_adapter_mysql, beeframework_model_adapter_mysql_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(BeeFramework_Model_Adapter_Mysql, __construct) {

	zval *config, *host = NULL, *user = NULL, *passwd = NULL, *dbname = NULL, *port = NULL;

	zephir_fetch_params(0, 1, 0, &config);



	if (zephir_array_isset_string(config, SS("host"))) {
		zephir_array_fetch_string(&host, config, SL("host"), PH_NOISY | PH_READONLY, "beeframework/Model/Adapter/Mysql.zep", 13 TSRMLS_CC);
	}
	if (zephir_array_isset_string(config, SS("user"))) {
		zephir_array_fetch_string(&user, config, SL("user"), PH_NOISY | PH_READONLY, "beeframework/Model/Adapter/Mysql.zep", 16 TSRMLS_CC);
	}
	if (zephir_array_isset_string(config, SS("passwd"))) {
		zephir_array_fetch_string(&passwd, config, SL("passwd"), PH_NOISY | PH_READONLY, "beeframework/Model/Adapter/Mysql.zep", 19 TSRMLS_CC);
	}
	if (zephir_array_isset_string(config, SS("dbname"))) {
		zephir_array_fetch_string(&dbname, config, SL("dbname"), PH_NOISY | PH_READONLY, "beeframework/Model/Adapter/Mysql.zep", 22 TSRMLS_CC);
	}
	if (zephir_array_isset_string(config, SS("port"))) {
		zephir_array_fetch_string(&port, config, SL("port"), PH_NOISY | PH_READONLY, "beeframework/Model/Adapter/Mysql.zep", 25 TSRMLS_CC);
	}

}


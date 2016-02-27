
extern zend_class_entry *beeframework_model_adapter_mysql_ce;

ZEPHIR_INIT_CLASS(BeeFramework_Model_Adapter_Mysql);

PHP_METHOD(BeeFramework_Model_Adapter_Mysql, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_beeframework_model_adapter_mysql___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, config)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(beeframework_model_adapter_mysql_method_entry) {
	PHP_ME(BeeFramework_Model_Adapter_Mysql, __construct, arginfo_beeframework_model_adapter_mysql___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};

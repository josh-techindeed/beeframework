
extern zend_class_entry *beeframework_model_adapter_ce;

ZEPHIR_INIT_CLASS(BeeFramework_Model_Adapter);

PHP_METHOD(BeeFramework_Model_Adapter, factory);

ZEND_BEGIN_ARG_INFO_EX(arginfo_beeframework_model_adapter_factory, 0, 0, 1)
	ZEND_ARG_INFO(0, config)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(beeframework_model_adapter_method_entry) {
	PHP_ME(BeeFramework_Model_Adapter, factory, arginfo_beeframework_model_adapter_factory, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};

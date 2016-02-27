
extern zend_class_entry *beeframework_config_ce;

ZEPHIR_INIT_CLASS(BeeFramework_Config);

PHP_METHOD(BeeFramework_Config, init);
PHP_METHOD(BeeFramework_Config, dispater);

ZEPHIR_INIT_FUNCS(beeframework_config_method_entry) {
	PHP_ME(BeeFramework_Config, init, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(BeeFramework_Config, dispater, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

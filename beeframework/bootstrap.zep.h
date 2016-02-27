
extern zend_class_entry *beeframework_bootstrap_ce;

ZEPHIR_INIT_CLASS(BeeFramework_Bootstrap);

PHP_METHOD(BeeFramework_Bootstrap, run);

ZEPHIR_INIT_FUNCS(beeframework_bootstrap_method_entry) {
	PHP_ME(BeeFramework_Bootstrap, run, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

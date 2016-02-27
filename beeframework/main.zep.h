
extern zend_class_entry *beeframework_main_ce;

ZEPHIR_INIT_CLASS(BeeFramework_Main);

PHP_METHOD(BeeFramework_Main, init);

ZEPHIR_INIT_FUNCS(beeframework_main_method_entry) {
	PHP_ME(BeeFramework_Main, init, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};


extern zend_class_entry *beeframework_app_ce;

ZEPHIR_INIT_CLASS(BeeFramework_App);

PHP_METHOD(BeeFramework_App, __construct);
PHP_METHOD(BeeFramework_App, init);
PHP_METHOD(BeeFramework_App, getConfig);
PHP_METHOD(BeeFramework_App, dispatch);

ZEPHIR_INIT_FUNCS(beeframework_app_method_entry) {
	PHP_ME(BeeFramework_App, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(BeeFramework_App, init, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(BeeFramework_App, getConfig, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(BeeFramework_App, dispatch, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

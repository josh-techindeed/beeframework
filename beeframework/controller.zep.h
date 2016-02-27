
extern zend_class_entry *beeframework_controller_ce;

ZEPHIR_INIT_CLASS(BeeFramework_Controller);

PHP_METHOD(BeeFramework_Controller, __construct);

ZEPHIR_INIT_FUNCS(beeframework_controller_method_entry) {
	PHP_ME(BeeFramework_Controller, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};

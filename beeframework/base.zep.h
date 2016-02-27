
extern zend_class_entry *beeframework_base_ce;

ZEPHIR_INIT_CLASS(BeeFramework_Base);

PHP_METHOD(BeeFramework_Base, __construct);
void zephir_init_static_properties_BeeFramework_Base(TSRMLS_D);

ZEPHIR_INIT_FUNCS(beeframework_base_method_entry) {
	PHP_ME(BeeFramework_Base, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};


extern zend_class_entry *beeframework_autoloader_ce;

ZEPHIR_INIT_CLASS(BeeFramework_Autoloader);

PHP_METHOD(BeeFramework_Autoloader, __construct);
PHP_METHOD(BeeFramework_Autoloader, loader);

ZEND_BEGIN_ARG_INFO_EX(arginfo_beeframework_autoloader_loader, 0, 0, 1)
	ZEND_ARG_INFO(0, className)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(beeframework_autoloader_method_entry) {
	PHP_ME(BeeFramework_Autoloader, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(BeeFramework_Autoloader, loader, arginfo_beeframework_autoloader_loader, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

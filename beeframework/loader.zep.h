
extern zend_class_entry *beeframework_loader_ce;

ZEPHIR_INIT_CLASS(BeeFramework_Loader);

PHP_METHOD(BeeFramework_Loader, __construct);
PHP_METHOD(BeeFramework_Loader, load_config);
PHP_METHOD(BeeFramework_Loader, getConf);
PHP_METHOD(BeeFramework_Loader, getAppConf);
PHP_METHOD(BeeFramework_Loader, getDbConf);

ZEND_BEGIN_ARG_INFO_EX(arginfo_beeframework_loader_load_config, 0, 0, 1)
	ZEND_ARG_INFO(0, file_path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_beeframework_loader_getconf, 0, 0, 1)
	ZEND_ARG_INFO(0, file_name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(beeframework_loader_method_entry) {
	PHP_ME(BeeFramework_Loader, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(BeeFramework_Loader, load_config, arginfo_beeframework_loader_load_config, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(BeeFramework_Loader, getConf, arginfo_beeframework_loader_getconf, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(BeeFramework_Loader, getAppConf, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(BeeFramework_Loader, getDbConf, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};

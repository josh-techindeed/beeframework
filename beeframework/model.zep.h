
extern zend_class_entry *beeframework_model_ce;

ZEPHIR_INIT_CLASS(BeeFramework_Model);

PHP_METHOD(BeeFramework_Model, __construct);
PHP_METHOD(BeeFramework_Model, getDbConf);

ZEND_BEGIN_ARG_INFO_EX(arginfo_beeframework_model___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, cluster)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_beeframework_model_getdbconf, 0, 0, 0)
	ZEND_ARG_INFO(0, cluster)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(beeframework_model_method_entry) {
	PHP_ME(BeeFramework_Model, __construct, arginfo_beeframework_model___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(BeeFramework_Model, getDbConf, arginfo_beeframework_model_getdbconf, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

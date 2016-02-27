
extern zend_class_entry *beeframework_input_ce;

ZEPHIR_INIT_CLASS(BeeFramework_Input);

PHP_METHOD(BeeFramework_Input, xss_clean);
PHP_METHOD(BeeFramework_Input, _fetch_from_array);
PHP_METHOD(BeeFramework_Input, get);
PHP_METHOD(BeeFramework_Input, post);

ZEND_BEGIN_ARG_INFO_EX(arginfo_beeframework_input_xss_clean, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_beeframework_input__fetch_from_array, 0, 0, 2)
	ZEND_ARG_INFO(0, arr)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, remove_xss)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_beeframework_input_get, 0, 0, 0)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, remove_xss)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_beeframework_input_post, 0, 0, 0)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, remove_xss)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(beeframework_input_method_entry) {
	PHP_ME(BeeFramework_Input, xss_clean, arginfo_beeframework_input_xss_clean, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(BeeFramework_Input, _fetch_from_array, arginfo_beeframework_input__fetch_from_array, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(BeeFramework_Input, get, arginfo_beeframework_input_get, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(BeeFramework_Input, post, arginfo_beeframework_input_post, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};

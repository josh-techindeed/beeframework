
extern zend_class_entry *beeframework_utils_ce;

ZEPHIR_INIT_CLASS(BeeFramework_Utils);

PHP_METHOD(BeeFramework_Utils, parse_str);
PHP_METHOD(BeeFramework_Utils, parse_uri);

ZEND_BEGIN_ARG_INFO_EX(arginfo_beeframework_utils_parse_str, 0, 0, 1)
	ZEND_ARG_INFO(0, query_string)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_beeframework_utils_parse_uri, 0, 0, 1)
	ZEND_ARG_INFO(0, request_uri)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(beeframework_utils_method_entry) {
	PHP_ME(BeeFramework_Utils, parse_str, arginfo_beeframework_utils_parse_str, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(BeeFramework_Utils, parse_uri, arginfo_beeframework_utils_parse_uri, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};

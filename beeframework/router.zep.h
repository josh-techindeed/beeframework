
extern zend_class_entry *beeframework_router_ce;

ZEPHIR_INIT_CLASS(BeeFramework_Router);

PHP_METHOD(BeeFramework_Router, __construct);
PHP_METHOD(BeeFramework_Router, _parse_uri_auto);
PHP_METHOD(BeeFramework_Router, _parse_query_string);
PHP_METHOD(BeeFramework_Router, _parse_request_uri);
PHP_METHOD(BeeFramework_Router, parseURI);
PHP_METHOD(BeeFramework_Router, callMethod);
PHP_METHOD(BeeFramework_Router, dispatch);
PHP_METHOD(BeeFramework_Router, error);

ZEND_BEGIN_ARG_INFO_EX(arginfo_beeframework_router_callmethod, 0, 0, 2)
	ZEND_ARG_INFO(0, instance)
	ZEND_ARG_INFO(0, method)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_beeframework_router_error, 0, 0, 0)
	ZEND_ARG_INFO(0, code)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(beeframework_router_method_entry) {
	PHP_ME(BeeFramework_Router, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(BeeFramework_Router, _parse_uri_auto, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(BeeFramework_Router, _parse_query_string, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(BeeFramework_Router, _parse_request_uri, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(BeeFramework_Router, parseURI, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(BeeFramework_Router, callMethod, arginfo_beeframework_router_callmethod, ZEND_ACC_PUBLIC)
	PHP_ME(BeeFramework_Router, dispatch, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(BeeFramework_Router, error, arginfo_beeframework_router_error, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

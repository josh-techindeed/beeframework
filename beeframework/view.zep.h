
extern zend_class_entry *beeframework_view_ce;

ZEPHIR_INIT_CLASS(BeeFramework_View);

PHP_METHOD(BeeFramework_View, __construct);
PHP_METHOD(BeeFramework_View, render);

ZEND_BEGIN_ARG_INFO_EX(arginfo_beeframework_view_render, 0, 0, 1)
	ZEND_ARG_INFO(0, template)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(beeframework_view_method_entry) {
	PHP_ME(BeeFramework_View, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(BeeFramework_View, render, arginfo_beeframework_view_render, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};

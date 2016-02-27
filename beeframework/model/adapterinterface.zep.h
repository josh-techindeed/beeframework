
extern zend_class_entry *beeframework_model_adapterinterface_ce;

ZEPHIR_INIT_CLASS(BeeFramework_Model_AdapterInterface);

ZEPHIR_INIT_FUNCS(beeframework_model_adapterinterface_method_entry) {
	PHP_ABSTRACT_ME(BeeFramework_Model_AdapterInterface, test, NULL)
	PHP_FE_END
};


extern zend_class_entry *beeframework_logger_ce;

ZEPHIR_INIT_CLASS(BeeFramework_Logger);

PHP_METHOD(BeeFramework_Logger, __construct);
PHP_METHOD(BeeFramework_Logger, writeLog);
PHP_METHOD(BeeFramework_Logger, fatal);
PHP_METHOD(BeeFramework_Logger, warning);
PHP_METHOD(BeeFramework_Logger, notice);

ZEND_BEGIN_ARG_INFO_EX(arginfo_beeframework_logger_writelog, 0, 0, 2)
	ZEND_ARG_INFO(0, level)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_beeframework_logger_fatal, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_beeframework_logger_warning, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_beeframework_logger_notice, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(beeframework_logger_method_entry) {
	PHP_ME(BeeFramework_Logger, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(BeeFramework_Logger, writeLog, arginfo_beeframework_logger_writelog, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(BeeFramework_Logger, fatal, arginfo_beeframework_logger_fatal, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(BeeFramework_Logger, warning, arginfo_beeframework_logger_warning, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(BeeFramework_Logger, notice, arginfo_beeframework_logger_notice, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};

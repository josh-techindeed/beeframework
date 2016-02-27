
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(BeeFramework_Logger) {

	ZEPHIR_REGISTER_CLASS_EX(BeeFramework, Logger, beeframework, logger, beeframework_base_ce, beeframework_logger_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(BeeFramework_Logger, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_PARENT(NULL, beeframework_logger_ce, this_ptr, "__construct", &_0, 3);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(BeeFramework_Logger, writeLog) {

	zend_bool _5;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_8 = NULL;
	zval *level = NULL, *message = NULL, *_0, *log_file = NULL, *_1, *_2, *_3, *_4, _6 = zval_used_for_init, *_7 = NULL, *debug_trace = NULL, *_9 = NULL, *_10, *_11, *_12, *_13, *_14;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &level, &message);

	ZEPHIR_SEPARATE_PARAM(level);
	ZEPHIR_SEPARATE_PARAM(message);


	ZEPHIR_INIT_VAR(_0);
	zephir_fast_strtoupper(_0, level);
	ZEPHIR_CPY_WRT(level, _0);
	_1 = zephir_fetch_static_property_ce(beeframework_base_ce, SL("config") TSRMLS_CC);
	zephir_array_fetch_string(&_2, _1, SL("logs_path"), PH_NOISY | PH_READONLY, "beeframework/Logger.zep", 17 TSRMLS_CC);
	_3 = zephir_fetch_static_property_ce(beeframework_base_ce, SL("config") TSRMLS_CC);
	zephir_array_fetch_string(&_4, _3, SL("app_name"), PH_NOISY | PH_READONLY, "beeframework/Logger.zep", 17 TSRMLS_CC);
	ZEPHIR_INIT_VAR(log_file);
	ZEPHIR_CONCAT_VSVS(log_file, _2, "/", _4, ".log");
	_5 = ZEPHIR_IS_STRING(level, "FATAL");
	if (!(_5)) {
		_5 = ZEPHIR_IS_STRING(level, "WARNING");
	}
	if (_5) {
		zephir_concat_self_str(&log_file, SL(".wf.") TSRMLS_CC);
	}
	ZEPHIR_SINIT_VAR(_6);
	ZVAL_STRING(&_6, "Ymd", 0);
	ZEPHIR_CALL_FUNCTION(&_7, "date", &_8, 8, &_6);
	zephir_check_call_status();
	zephir_concat_self(&log_file, _7 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&debug_trace, "debug_backtrace", NULL, 9);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_6);
	ZVAL_STRING(&_6, "Y-m-d H:i:s", 0);
	ZEPHIR_CALL_FUNCTION(&_9, "date", &_8, 8, &_6);
	zephir_check_call_status();
	zephir_array_fetch_long(&_10, debug_trace, 1, PH_NOISY | PH_READONLY, "beeframework/Logger.zep", 25 TSRMLS_CC);
	zephir_array_fetch_string(&_11, _10, SL("file"), PH_NOISY | PH_READONLY, "beeframework/Logger.zep", 25 TSRMLS_CC);
	zephir_array_fetch_long(&_12, debug_trace, 1, PH_NOISY | PH_READONLY, "beeframework/Logger.zep", 25 TSRMLS_CC);
	zephir_array_fetch_string(&_13, _12, SL("line"), PH_NOISY | PH_READONLY, "beeframework/Logger.zep", 25 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_14);
	ZEPHIR_CONCAT_VSVSVSVSVS(_14, _9, " ", level, " FILE=", _11, " LINE=", _13, " MSG=", message, "\n");
	ZEPHIR_CPY_WRT(message, _14);
	ZEPHIR_SINIT_NVAR(_6);
	ZVAL_LONG(&_6, 8);
	ZEPHIR_CALL_FUNCTION(NULL, "file_put_contents", NULL, 10, log_file, message, &_6);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(BeeFramework_Logger, fatal) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *message, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "FATAL", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_SELF(NULL, "writelog", NULL, 0, _0, message);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(BeeFramework_Logger, warning) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *message, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "WARNING", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_SELF(NULL, "writelog", NULL, 0, _0, message);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(BeeFramework_Logger, notice) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *message, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "NOTICE", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_SELF(NULL, "writelog", NULL, 0, _0, message);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}


PHP_ARG_ENABLE(beeframework, whether to enable beeframework, [ --enable-beeframework   Enable Beeframework])

if test "$PHP_BEEFRAMEWORK" = "yes"; then

	

	if ! test "x" = "x"; then
		PHP_EVAL_LIBLINE(, BEEFRAMEWORK_SHARED_LIBADD)
	fi

	AC_DEFINE(HAVE_BEEFRAMEWORK, 1, [Whether you have Beeframework])
	beeframework_sources="beeframework.c kernel/main.c kernel/memory.c kernel/exception.c kernel/hash.c kernel/debug.c kernel/backtrace.c kernel/object.c kernel/array.c kernel/extended/array.c kernel/string.c kernel/fcall.c kernel/extended/fcall.c kernel/require.c kernel/file.c kernel/operators.c kernel/math.c kernel/concat.c kernel/variables.c kernel/filter.c kernel/iterator.c kernel/time.c kernel/exit.c beeframework/base.zep.c
	beeframework/exception.zep.c
	beeframework/app.zep.c
	beeframework/controller.zep.c
	beeframework/input.zep.c
	beeframework/loader.zep.c
	beeframework/logger.zep.c
	beeframework/model.zep.c
	beeframework/model/adapter.zep.c
	beeframework/model/adapter/mysql.zep.c
	beeframework/model/adapterinterface.zep.c
	beeframework/model/exception.zep.c
	beeframework/router.zep.c
	beeframework/utils.zep.c
	beeframework/view.zep.c
	beeframework/0__closure.zep.c "
	PHP_NEW_EXTENSION(beeframework, $beeframework_sources, $ext_shared,, )
	PHP_SUBST(BEEFRAMEWORK_SHARED_LIBADD)

	old_CPPFLAGS=$CPPFLAGS
	CPPFLAGS="$CPPFLAGS $INCLUDES"

	AC_CHECK_DECL(
		[HAVE_BUNDLED_PCRE],
		[
			AC_CHECK_HEADERS(
				[ext/pcre/php_pcre.h],
				[
					PHP_ADD_EXTENSION_DEP([beeframework], [pcre])
					AC_DEFINE([ZEPHIR_USE_PHP_PCRE], [1], [Whether PHP pcre extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	AC_CHECK_DECL(
		[HAVE_JSON],
		[
			AC_CHECK_HEADERS(
				[ext/json/php_json.h],
				[
					PHP_ADD_EXTENSION_DEP([beeframework], [json])
					AC_DEFINE([ZEPHIR_USE_PHP_JSON], [1], [Whether PHP json extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	CPPFLAGS=$old_CPPFLAGS

	PHP_INSTALL_HEADERS([ext/beeframework], [php_BEEFRAMEWORK.h])

fi

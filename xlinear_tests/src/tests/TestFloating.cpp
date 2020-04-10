//
// Created by xgallom on 4/10/20.
//

#include "TestFloating.h"

#include <xlinear/Floating.h>
#include <cmath>

const char *TestFloating::name()
{
	return "floating";
}

void TestFloating::execute()
{
	Double constructed(6.5);
	static constexpr Double constExpr = 4.4;

	constructed += constExpr;
	test(constructed == 6.5 + 4.4, constructed, " == ", 6.5 + 4.4);

	constructed -= constExpr;
	test(constructed == 6.5, constructed, " == ", 6.5);

	constructed *= constExpr;
	test(constructed == 6.5 * 4.4, constructed, " == ", 6.5 * 4.4);

	constructed /= constExpr;
	test(constructed == 6.5, constructed, " == ", 6.5);

	test(constructed + constExpr == 6.5 + 4.4, constructed + constExpr, " == ", 6.5 + 4.4);
	test(constructed - constExpr == 6.5 - 4.4, constructed - constExpr, " == ", 6.5 - 4.4);
	test(constructed * constExpr == 6.5 * 4.4, constructed * constExpr, " == ", 6.5 * 4.4);
	test(constructed / constExpr == 6.5 / 4.4, constructed / constExpr, " == ", 6.5 / 4.4);

	test(constructed + 4.4 == 6.5 + 4.4, constructed + 4.4, " == ", 6.5 + 4.4);
	test(constructed - 0xff000000u == 6.5 - 0xff000000u, constructed - 0xff000000u, " == ", 6.5 - 0xff000000u);
	test(constructed * 2 == 6.5 * 2, constructed * 2, " == ", 6.5 * 2);
	test(constructed / 1.5f == 6.5 / 1.5f, constructed / 1.5f, " == ", 6.5 / 1.5f);
}

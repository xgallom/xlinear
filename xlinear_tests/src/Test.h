//
// Created by xgallom on 4/9/20.
//

#ifndef XLINEAR_XLINEAR_TESTS_SRC_TEST_H
#define XLINEAR_XLINEAR_TESTS_SRC_TEST_H

#include <memory>

class Test {
public:
	virtual ~Test() = default;

	virtual const char *name() = 0;
	virtual void execute() = 0;
};

#endif //XLINEAR_XLINEAR_TESTS_SRC_TEST_H

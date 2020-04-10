//
// Created by xgallom on 4/10/20.
//

#ifndef XLINEAR_ROOT_XLINEAR_TESTS_SRC_TESTS_TESTFLOATING_H
#define XLINEAR_ROOT_XLINEAR_TESTS_SRC_TESTS_TESTFLOATING_H

#include "../Test.h"

class TestFloating : public Test {
public:
	~TestFloating() final = default;

	const char *name() final;
	void execute() final;

	static inline std::unique_ptr<Test> Create() { return std::make_unique<TestFloating>(); };
};


#endif //XLINEAR_ROOT_XLINEAR_TESTS_SRC_TESTS_TESTFLOATING_H

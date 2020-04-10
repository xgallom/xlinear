//
// Created by xgallom on 4/9/20.
//

#ifndef XLINEAR_XLINEAR_TESTS_SRC_TESTS_TESTMATRIX_H
#define XLINEAR_XLINEAR_TESTS_SRC_TESTS_TESTMATRIX_H

#include "../Test.h"

class TestMatrix : public Test {
public:
	~TestMatrix() final = default;

	const char *name() final;
	void execute() final;

	static inline std::unique_ptr<Test> Create() { return std::make_unique<TestMatrix>(); };
};

#endif //XLINEAR_XLINEAR_TESTS_SRC_TESTS_TESTMATRIX_H

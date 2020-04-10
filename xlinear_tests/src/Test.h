//
// Created by xgallom on 4/9/20.
//

#ifndef XLINEAR_XLINEAR_TESTS_SRC_TEST_H
#define XLINEAR_XLINEAR_TESTS_SRC_TEST_H

#include <memory>
#include <sstream>

class Test {
public:
	virtual ~Test() = default;

	virtual const char *name() = 0;
	virtual void execute() = 0;

	template<typename ... Args>
	void testImpl(bool check, Args ... message) const
	{
		if(!check) {
			std::stringstream ss;
			(ss << ... << std::forward<Args>(message));
			throw std::logic_error(ss.str());
		}
	}
};

#define test(check, ...) testImpl((check), __FILE__, ":", __LINE__, ": Test ", name(), " failed: ", __VA_ARGS__)

#endif //XLINEAR_XLINEAR_TESTS_SRC_TEST_H

//
// Created by xgallom on 4/10/20.
//

#ifndef XLINEAR_ROOT_XLINEAR_INCLUDE_XLINEAR_FLOATING_FLOATING_H
#define XLINEAR_ROOT_XLINEAR_INCLUDE_XLINEAR_FLOATING_FLOATING_H

#include "FloatingPoint.h"

namespace floating {
	extern template
	class FloatingPoint<long double>;

	extern template
	class FloatingPoint<double>;

	extern template
	class FloatingPoint<float>;
}

using LongDouble = floating::FloatingPoint<long double>;
using Double = floating::FloatingPoint<double>;
using Float = floating::FloatingPoint<float>;

#endif //XLINEAR_ROOT_XLINEAR_INCLUDE_XLINEAR_FLOATING_FLOATING_H

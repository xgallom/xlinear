//
// Created by xgallom on 4/10/20.
//

#ifndef XLINEAR_ROOT_XLINEAR_INCLUDE_XLINEAR_FLOATING_FLOATINGOPERATORS_H
#define XLINEAR_ROOT_XLINEAR_INCLUDE_XLINEAR_FLOATING_FLOATINGOPERATORS_H

#include "FloatingPoint.h"

template<typename DT>
floating::FloatingPoint<DT> operator+(floating::FloatingPoint<DT> left, const floating::FloatingPoint<DT> &right)
{
	return left += right;
}

template<typename DT>
floating::FloatingPoint<DT> operator-(floating::FloatingPoint<DT> left, const floating::FloatingPoint<DT> &right)
{
	return left -= right;
}

template<typename DT>
floating::FloatingPoint<DT> operator*(floating::FloatingPoint<DT> left, const floating::FloatingPoint<DT> &right)
{
	return left *= right;
}

template<typename DT>
floating::FloatingPoint<DT> operator/(floating::FloatingPoint<DT> left, const floating::FloatingPoint<DT> &right)
{
	return left /= right;
}

template<typename DT, typename FT, typename std::enable_if_t<
		std::is_convertible_v<FT, DT> &&
		std::is_arithmetic_v<FT>, bool> = true>
floating::FloatingPoint<DT> operator+(floating::FloatingPoint<DT> left, const FT &right) { return left += right; }
template<typename DT, typename FT, typename std::enable_if_t<
		std::is_convertible_v<FT, DT> &&
		std::is_arithmetic_v<FT>, bool> = true>
floating::FloatingPoint<DT> operator-(floating::FloatingPoint<DT> left, const FT &right) { return left -= right; }
template<typename DT, typename FT, typename std::enable_if_t<
		std::is_convertible_v<FT, DT> &&
		std::is_arithmetic_v<FT>, bool> = true>
floating::FloatingPoint<DT> operator*(floating::FloatingPoint<DT> left, const FT &right) { return left *= right; }
template<typename DT, typename FT, typename std::enable_if_t<
		std::is_convertible_v<FT, DT> &&
		std::is_arithmetic_v<FT>, bool> = true>
floating::FloatingPoint<DT> operator/(floating::FloatingPoint<DT> left, const FT &right) { return left /= right; }

#endif //XLINEAR_ROOT_XLINEAR_INCLUDE_XLINEAR_FLOATING_FLOATINGOPERATORS_H

//
// Created by xgallom on 4/10/20.
//

#ifndef XLINEAR_XLINEAR_INCLUDE_XLINEAR_MATRIX_SCALAROPERATORS_H
#define XLINEAR_XLINEAR_INCLUDE_XLINEAR_MATRIX_SCALAROPERATORS_H

#include "ScalarMatrix.h"

template<typename DT>
ScalarMatrix<DT> operator+(ScalarMatrix<DT> left, const ScalarMatrix<DT> &right) { return left += right; }
template<typename DT>
ScalarMatrix<DT> operator-(ScalarMatrix<DT> left, const ScalarMatrix<DT> &right) { return left -= right; }
template<typename DT>
ScalarMatrix<DT> operator*(ScalarMatrix<DT> left, const ScalarMatrix<DT> &right) { return left *= right; }
template<typename DT>
ScalarMatrix<DT> operator/(ScalarMatrix<DT> left, const ScalarMatrix<DT> &right) { return left /= right; }

template<typename DT>
ScalarMatrix<DT> operator+(ScalarMatrix<DT> left, const DT &right) { return left += right; }
template<typename DT>
ScalarMatrix<DT> operator-(ScalarMatrix<DT> left, const DT &right) { return left -= right; }
template<typename DT>
ScalarMatrix<DT> operator*(ScalarMatrix<DT> left, const DT &right) { return left *= right; }
template<typename DT>
ScalarMatrix<DT> operator/(ScalarMatrix<DT> left, const DT &right) { return left /= right; }

template<typename DT>
ScalarMatrix<DT> operator+(const DT &left, ScalarMatrix<DT> right) { return right += left; }
template<typename DT>
ScalarMatrix<DT> operator-(const DT &left, ScalarMatrix<DT> right) { return right.negate() += left; }
template<typename DT>
ScalarMatrix<DT> operator*(const DT &left, ScalarMatrix<DT>right) { return right *= left; }
template<typename DT>
ScalarMatrix<DT> operator/(const DT &left, ScalarMatrix<DT> right) { return right.divide(left); }

#endif //XLINEAR_XLINEAR_INCLUDE_XLINEAR_MATRIX_SCALAROPERATORS_H

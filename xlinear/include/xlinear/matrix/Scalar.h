//
// Created by xgallom on 4/10/20.
//

#ifndef XLINEAR_XLINEAR_INCLUDE_XLINEAR_MATRIX_SCALAR_H
#define XLINEAR_XLINEAR_INCLUDE_XLINEAR_MATRIX_SCALAR_H

#include "ScalarMatrix.h"

extern template class matrix::StaticMatrix<long double, 1, 1>;
extern template class matrix::StaticMatrix<double, 1, 1>;
extern template class matrix::StaticMatrix<float, 1, 1>;

extern template class matrix::ScalarMatrix<long double>;
extern template class matrix::ScalarMatrix<double>;
extern template class matrix::ScalarMatrix<float>;

using LongDouble = matrix::ScalarMatrix<long double>;
using Double = matrix::ScalarMatrix<double>;
using Float = matrix::ScalarMatrix<float>;

#endif //XLINEAR_XLINEAR_INCLUDE_XLINEAR_MATRIX_SCALAR_H

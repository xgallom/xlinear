//
// Created by xgallom on 4/10/20.
//

#ifndef XLINEAR_XLINEAR_INCLUDE_XLINEAR_MATRIX_SCALAR_H
#define XLINEAR_XLINEAR_INCLUDE_XLINEAR_MATRIX_SCALAR_H

#include "ScalarMatrix.h"

extern template class ScalarMatrix<long double>;
extern template class ScalarMatrix<double>;
extern template class ScalarMatrix<float>;

using LongDouble = ScalarMatrix<long double>;
using Double = ScalarMatrix<double>;
using Float = ScalarMatrix<float>;

#endif //XLINEAR_XLINEAR_INCLUDE_XLINEAR_MATRIX_SCALAR_H

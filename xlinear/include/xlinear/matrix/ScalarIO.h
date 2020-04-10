//
// Created by xgallom on 4/10/20.
//

#ifndef XLINEAR_XLINEAR_INCLUDE_XLINEAR_MATRIX_SCALARIO_H
#define XLINEAR_XLINEAR_INCLUDE_XLINEAR_MATRIX_SCALARIO_H

#include "ScalarMatrix.h"

#include <istream>
#include <ostream>

template<typename DT>
std::ostream &operator<<(std::ostream &out, const matrix::ScalarMatrix<DT> &object) { return out << object[0]; }

template<typename DT>
std::istream &operator>>(std::istream &in, matrix::ScalarMatrix<DT> &object) { return in >> object[0]; }

template<typename DT>
std::ostream &operator<<(std::ostream &out, const matrix::StaticMatrix<DT, 1, 1> &object) { return out << object[0]; }

template<typename DT>
std::istream &operator>>(std::istream &in, matrix::StaticMatrix<DT, 1, 1> &object) { return in >> object[0]; }

#endif //XLINEAR_XLINEAR_INCLUDE_XLINEAR_MATRIX_SCALARIO_H

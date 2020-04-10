//
// Created by xgallom on 4/10/20.
//

#ifndef XLINEAR_ROOT_XLINEAR_INCLUDE_XLINEAR_FLOATING_FLOATINGIO_H
#define XLINEAR_ROOT_XLINEAR_INCLUDE_XLINEAR_FLOATING_FLOATINGIO_H

#include "FloatingPoint.h"

#include <istream>
#include <ostream>

template<typename DT>
std::ostream &operator<<(std::ostream &out, const floating::FloatingPoint<DT> &object) { return out << object.value(); }

template<typename DT>
std::istream &operator>>(std::istream &in, floating::FloatingPoint<DT> &object) { return in >> object.ref(); }

#endif //XLINEAR_ROOT_XLINEAR_INCLUDE_XLINEAR_FLOATING_FLOATINGIO_H

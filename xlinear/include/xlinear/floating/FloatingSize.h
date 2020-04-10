//
// Created by xgallom on 4/10/20.
//

#ifndef XLINEAR_ROOT_XLINEAR_INCLUDE_XLINEAR_FLOATING_FLOATINGSIZE_H
#define XLINEAR_ROOT_XLINEAR_INCLUDE_XLINEAR_FLOATING_FLOATINGSIZE_H

#include <cstddef>
#include <cstdint>

namespace floating {
	template<size_t Size>
	struct SizeTypeImpl {
		using Unsigned = uint32_t;
	};

	template<>
	struct SizeTypeImpl<4> {
		using Unsigned = uint32_t;
	};

	template<>
	struct SizeTypeImpl<8> {
		using Unsigned = uint64_t;
	};

	template<>
	struct SizeTypeImpl<16> {
		using Unsigned = uint64_t[2];
	};

	template<typename FP>
	using SizeType = SizeTypeImpl<sizeof(FP)>;
}

#endif //XLINEAR_ROOT_XLINEAR_INCLUDE_XLINEAR_FLOATING_FLOATINGSIZE_H

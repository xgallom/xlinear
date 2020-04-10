//
// Created by xgallom on 4/10/20.
//

#ifndef XLINEAR_ROOT_XLINEAR_INCLUDE_XLINEAR_FLOATING_FLOATINGCOMPARE_H
#define XLINEAR_ROOT_XLINEAR_INCLUDE_XLINEAR_FLOATING_FLOATINGCOMPARE_H

#include <xlinear/config/floating.h>

#if XLINEAR_CFG_FLOATING_USE_ULP_COMPARE

#include "FloatingSize.h"
#include <limits>

namespace floating {
	static constexpr size_t MaxUlpCompareDistance = XLINEAR_CFG_FLOATING_ULP_MAX_COMPARE_DISTANCE;

	template<typename FP>
	struct FloatingCompare {
		using Type = FP;
		using Bits = typename SizeType<FP>::Unsigned;

		static constexpr size_t BitCount = 8 * sizeof(FP);
		static constexpr size_t FractionBitCount = std::numeric_limits<FP>::digits - 1;
		static constexpr size_t ExponentBitCount = BitCount - 1 - FractionBitCount;

		static constexpr Bits SignBitMask = Bits{1} << (BitCount - 1);
		static constexpr Bits FractionBitMask = ~Bits{0} >> (ExponentBitCount + 1);
		static constexpr Bits ExponentBitMask = ~(SignBitMask | FractionBitMask);

		static inline Bits ExponentBits(const Bits &fp) noexcept { return ExponentBitMask & fp; }
		static inline Bits FractionBits(const Bits &fp) noexcept { return FractionBitMask & fp; }

		static inline Bits Biased(const Bits &fp) noexcept
		{
			return SignBitMask & fp ? ~fp + 1 : SignBitMask | fp;
		}

		static inline Bits UlpDistance(const Bits &left, const Bits &right) noexcept
		{
			const Bits biasedLeft = Biased(left), biasedRight = Biased(right);
			return biasedLeft >= biasedRight ? biasedLeft - biasedRight : biasedRight - biasedLeft;
		}

		static inline bool IsNan(const Bits &fp) noexcept
		{
			return ExponentBits(fp) == ExponentBitMask && FractionBits(fp);
		}

		static inline bool IsSame(const Bits &left, const Bits &right) noexcept
		{
			if(IsNan(left) || IsNan(right))
				return false;
			return UlpDistance(left, right) <= MaxUlpCompareDistance;
		}
	};

	template<>
	struct FloatingCompare<long double> {
		using Type = long double;
		using Bits = typename SizeType<long double>::Unsigned;

		static inline bool IsSame(const Bits &left, const Bits &right) noexcept
		{
			// TODO: Implement
			return left == right;
		}
	};
}

#endif

#endif //XLINEAR_ROOT_XLINEAR_INCLUDE_XLINEAR_FLOATING_FLOATINGCOMPARE_H

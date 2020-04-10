//
// Created by xgallom on 4/10/20.
//

#ifndef XLINEAR_ROOT_XLINEAR_INCLUDE_XLINEAR_FLOATING_FLOATINGPOINT_H
#define XLINEAR_ROOT_XLINEAR_INCLUDE_XLINEAR_FLOATING_FLOATINGPOINT_H

#include "FloatingCompare.h"
#include <numeric>

namespace floating {
	template<typename _DataType>
	class FloatingPoint {
	public:
		using DataType = _DataType;
#if XLINEAR_CFG_FLOATING_USE_ULP_COMPARE
		using BitType = typename SizeType<DataType>::Unsigned;
		using Compare = FloatingCompare<DataType>;
#endif

	private:
#if XLINEAR_CFG_FLOATING_USE_ULP_COMPARE
		union {
			DataType m_value = {};
			BitType m_bitValue;
		};
#else
		DataType m_value;
#endif

	public:
		constexpr FloatingPoint() noexcept = default;
		constexpr FloatingPoint(const FloatingPoint &) noexcept = default;
		constexpr FloatingPoint(FloatingPoint &&) noexcept = default;
		constexpr FloatingPoint &operator=(const FloatingPoint &) noexcept = default;
		constexpr FloatingPoint &operator=(FloatingPoint &&) noexcept = default;

		constexpr FloatingPoint(const DataType &value) noexcept : m_value{value} {}

		constexpr DataType value() const noexcept { return m_value; }
		constexpr DataType &ref() noexcept { return m_value; }
		constexpr const DataType &ref() const noexcept { return m_value; }

		constexpr FloatingPoint &negate() noexcept
		{
			m_value = -m_value;
			return *this;
		}

		constexpr FloatingPoint operator-() const noexcept
		{
			FloatingPoint result{*this};
			return result.negate();
		}

		constexpr FloatingPoint &operator+=(const FloatingPoint &other) noexcept
		{
			m_value += other.m_value;
			return *this;
		}
		constexpr FloatingPoint &operator-=(const FloatingPoint &other) noexcept
		{
			m_value -= other.m_value;
			return *this;
		}
		constexpr FloatingPoint &operator*=(const FloatingPoint &other) noexcept
		{
			m_value *= other.m_value;
			return *this;
		}
		constexpr FloatingPoint &operator/=(const FloatingPoint &other)
		{
			m_value /= other.m_value;
			return *this;
		}

		template<typename DT, typename std::enable_if_t<
				std::is_convertible_v<DT, DataType> &&
				std::is_arithmetic_v<DT>, bool> = true>
		constexpr FloatingPoint &operator+=(const DT &other) noexcept
		{
			m_value += other;
			return *this;
		}
		template<typename DT, typename std::enable_if_t<
				std::is_convertible_v<DT, DataType> &&
				std::is_arithmetic_v<DT>, bool> = true>
		constexpr FloatingPoint &operator-=(const DT &other) noexcept
		{
			m_value -= other;
			return *this;
		}
		template<typename DT, typename std::enable_if_t<
				std::is_convertible_v<DT, DataType> &&
				std::is_arithmetic_v<DT>, bool> = true>
		constexpr FloatingPoint &operator*=(const DT &other) noexcept
		{
			m_value *= other;
			return *this;
		}
		template<typename DT, typename std::enable_if_t<
				std::is_convertible_v<DT, DataType> &&
				std::is_arithmetic_v<DT>, bool> = true>
		constexpr FloatingPoint &operator/=(const DT &other)
		{
			m_value /= other;
			return *this;
		}

		explicit constexpr operator DataType() const noexcept { return m_value; }

		constexpr bool operator==(const FloatingPoint &other) const noexcept
		{
#if XLINEAR_CFG_FLOATING_USE_ULP_COMPARE
			return Compare::IsSame(m_bitValue, other.m_bitValue);
#else
			return m_value == other.m_value;
#endif
		}
		constexpr bool operator!=(const FloatingPoint &other) const noexcept { return !(*this == other); }
		constexpr bool operator<(const FloatingPoint &other) const noexcept { return m_value < other.m_value; }
		constexpr bool operator>(const FloatingPoint &other) const noexcept { return m_value > other.m_value; }
		constexpr bool operator<=(const FloatingPoint &other) const noexcept { return *this < other || *this == other; }
		constexpr bool operator>=(const FloatingPoint &other) const noexcept { return *this > other || *this == other; }
	};
}

#include "FloatingIO.h"
#include "FloatingOperators.h"

#endif //XLINEAR_ROOT_XLINEAR_INCLUDE_XLINEAR_FLOATING_FLOATINGPOINT_H

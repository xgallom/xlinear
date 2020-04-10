//
// Created by xgallom on 4/9/20.
//

#ifndef XLINEAR_XLINEAR_INCLUDE_XLINEAR_MATRIX_SCALARMATRIX_H
#define XLINEAR_XLINEAR_INCLUDE_XLINEAR_MATRIX_SCALARMATRIX_H

#include "StaticMatrix.h"
#include "xlinear/floating/FloatingCompare.h"

namespace matrix {
	template<typename _DataType>
	class ScalarMatrix : public StaticMatrix<_DataType, 1, 1> {
	public:
		using DataType = _DataType;
		using Self = ScalarMatrix<DataType>;
		using Parent = StaticMatrix<DataType, 1, 1>;

	protected:
		using StaticMatrix<_DataType, 1, 1>::m_data;

	public:
		ScalarMatrix() = default;
		ScalarMatrix(const ScalarMatrix &) = default;
		ScalarMatrix(ScalarMatrix &&) noexcept = default;
		ScalarMatrix &operator=(const ScalarMatrix &) = default;
		ScalarMatrix &operator=(ScalarMatrix &&) noexcept = default;
		ScalarMatrix(const Parent &parent) : Parent{parent} {}
		ScalarMatrix(Parent &&parent) noexcept : Parent{std::move(parent)} {}
		ScalarMatrix &operator=(const Parent &parent)
		{
			reinterpret_cast<Parent &>(*this) = parent;
			return *this;
		};
		ScalarMatrix &operator=(Parent &&parent) noexcept
		{
			reinterpret_cast<Parent &>(*this) = std::move(parent);
			return *this;
		};
		~ScalarMatrix() = default;

		ScalarMatrix(const DataType &value) : Parent{{{value}}} {}

		[[nodiscard]] inline size_t size() const { return 1; }
		[[nodiscard]] inline size_t rows() const { return 1; }
		[[nodiscard]] inline size_t cols() const { return 1; }

		[[nodiscard]] inline DataType &operator[](size_t index)
		{
			assert(index == 0);
			return m_data[0];
		}
		[[nodiscard]] inline const DataType &operator[](size_t index) const
		{
			assert(index == 0);
			return m_data[0];
		}
		[[nodiscard]] inline DataType &operator()(size_t row, size_t col)
		{
			assert(row == 0 && col == 0);
			return m_data[0];
		}
		[[nodiscard]] inline const DataType &operator()(size_t row, size_t col) const
		{
			assert(row == 0 && col == 0);
			return m_data[0];
		}

		static Self Create(const DataType &value) { return Self{value}; }

		ScalarMatrix &negate()
		{
			m_data[0] = -m_data[0];
			return *this;
		}

		ScalarMatrix &invert()
		{
			m_data[0] = 1.0 / m_data[0];
			return *this;
		}

		ScalarMatrix &divide(const DataType &value)
		{
			m_data[0] = value / m_data[0];
			return *this;
		}

		ScalarMatrix operator-() const
		{
			ScalarMatrix result(*this);
			return result.negate();
		}

		ScalarMatrix &operator+=(const Parent &other)
		{
			m_data[0] += other[0];
			return *this;
		}
		ScalarMatrix &operator-=(const Parent &other)
		{
			m_data[0] -= other[0];
			return *this;
		}
		ScalarMatrix &operator*=(const Parent &other)
		{
			m_data[0] *= other[0];
			return *this;
		}
		ScalarMatrix &operator/=(const Parent &other)
		{
			m_data[0] /= other[0];
			return *this;
		}

		ScalarMatrix &operator+=(const DataType &other)
		{
			m_data[0] += other;
			return *this;
		}
		ScalarMatrix &operator-=(const DataType &other)
		{
			m_data[0] -= other;
			return *this;
		}
		ScalarMatrix &operator*=(const DataType &other)
		{
			m_data[0] *= other;
			return *this;
		}
		ScalarMatrix &operator/=(const DataType &other)
		{
			m_data[0] /= other;
			return *this;
		}

		DataType value() const { return m_data[0]; }
		explicit operator DataType() const { return value(); }

		[[nodiscard]] bool operator==(const Parent &other) const { return *this == other[0]; }
		[[nodiscard]] bool operator!=(const Parent &other) const { return *this != other[0]; }
		[[nodiscard]] bool operator<(const Parent &other) const { return m_data[0] < other[0]; }
		[[nodiscard]] bool operator>(const Parent &other) const { return m_data[0] > other[0]; }
		[[nodiscard]] bool operator<=(const Parent &other) const { return m_data[0] <= other[0]; }
		[[nodiscard]] bool operator>=(const Parent &other) const { return m_data[0] >= other[0]; }

		[[nodiscard]] bool operator==(const DataType &other) const { return m_data[0] == other; }
		[[nodiscard]] bool operator!=(const DataType &other) const { return m_data[0] != other; }
		[[nodiscard]] bool operator<(const DataType &other) const { return m_data[0] < other; }
		[[nodiscard]] bool operator>(const DataType &other) const { return m_data[0] > other; }
		[[nodiscard]] bool operator<=(const DataType &other) const { return m_data[0] <= other; }
		[[nodiscard]] bool operator>=(const DataType &other) const { return m_data[0] >= other; }

		template<typename NewType>
		NewType to() const { return NewType(m_data[0]); }
	};
}

#include "ScalarOperators.h"
#include "ScalarIO.h"

#endif //XLINEAR_XLINEAR_INCLUDE_XLINEAR_MATRIX_SCALARMATRIX_H

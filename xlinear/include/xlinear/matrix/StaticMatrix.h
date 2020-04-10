//
// Created by xgallom on 4/10/20.
//

#ifndef XLINEAR_XLINEAR_INCLUDE_XLINEAR_MATRIX_STATICMATRIX_H
#define XLINEAR_XLINEAR_INCLUDE_XLINEAR_MATRIX_STATICMATRIX_H

#include <algorithm>
#include <cassert>

namespace matrix {
	template<typename _DataType, size_t _Rows, size_t _Cols>
	class StaticMatrix {
	public:
		using DataType = _DataType;
		static constexpr size_t Rows = _Rows, Cols = _Cols, Size = Rows * Cols;
		using Self = StaticMatrix<DataType, Rows, Cols>;

	protected:
		DataType m_data[Size] = {};

	public:
		StaticMatrix() = default;
		StaticMatrix(const StaticMatrix &) = default;
		StaticMatrix(StaticMatrix &&) noexcept = default;
		StaticMatrix &operator=(const StaticMatrix &) = default;
		StaticMatrix &operator=(StaticMatrix &&) noexcept = default;
		~StaticMatrix() = default;

		StaticMatrix(const DataType (&value)[Rows][Cols])
		{
			const DataType *othervalue = value[0];
			for(auto &value : *this)
				value = *othervalue++;
		}

		[[nodiscard]] inline size_t size() const { return Size; }
		[[nodiscard]] inline size_t rows() const { return Rows; }
		[[nodiscard]] inline size_t cols() const { return Cols; }

		[[nodiscard]] inline DataType &operator[](size_t index)
		{
			assert(index < Size);
			return m_data[index];
		}
		[[nodiscard]] inline const DataType &operator[](size_t index) const
		{
			assert(index < Size);
			return m_data[index];
		}
		[[nodiscard]] inline DataType &operator()(size_t row, size_t col)
		{
			assert(row < Rows && col < Cols);
			return m_data[row * Cols + col];
		}
		[[nodiscard]] inline const DataType &operator()(size_t row, size_t col) const
		{
			assert(row < Rows && col < Cols);
			return m_data[row * Cols + col];
		}

		[[nodiscard]] inline DataType *begin() { return m_data; }
		[[nodiscard]] inline const DataType *begin() const { return m_data; }
		[[nodiscard]] inline DataType *end() { return m_data + Size; }
		[[nodiscard]] inline const DataType *end() const { return m_data + Size; }

		static Self Create(const DataType (&value)[Rows][Cols]) { return Self{value}; }

		Self &negate()
		{
			for(auto &value : *this)
				value = -value;
			return *this;
		}

		Self &invert()
		{
			for(auto &value : *this)
				value = DataType(1.0) / value;
			return *this;
		}

		Self &divide(const DataType &value)
		{
			for(auto &data : *this)
				data = value / data;
			return *this;
		}

		StaticMatrix operator-() const
		{
			StaticMatrix result(*this);
			return result.negate();
		}

		StaticMatrix &operator+=(const StaticMatrix &other)
		{
			auto otherValue = other.begin();
			for(auto &value : *this)
				value += *otherValue++;
			return *this;
		}
		StaticMatrix &operator-=(const StaticMatrix &other)
		{
			auto otherValue = other.begin();
			for(auto &value : *this)
				value -= *otherValue++;
			return *this;
		}

		StaticMatrix &operator+=(const DataType &other)
		{
			for(auto &value : *this)
				value += other;
			return *this;
		}
		StaticMatrix &operator-=(const DataType &other)
		{
			for(auto &value : *this)
				value -= other;
			return *this;
		}
		StaticMatrix &operator*=(const DataType &other)
		{
			for(auto &value : *this)
				value *= other;
			return *this;
		}
		StaticMatrix &operator/=(const DataType &other)
		{
			for(auto &value : *this)
				value /= other;
			return *this;
		}

		template<typename NewType>
		NewType to() const { return NewType(m_data); }
	};
}

#endif //XLINEAR_XLINEAR_INCLUDE_XLINEAR_MATRIX_STATICMATRIX_H

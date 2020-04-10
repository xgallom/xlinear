//
// Created by xgallom on 4/9/20.
//

#ifndef XLINEAR_XLINEAR_INCLUDE_XLINEAR_MATRIX_SCALARMATRIX_H
#define XLINEAR_XLINEAR_INCLUDE_XLINEAR_MATRIX_SCALARMATRIX_H

#include <cassert>
#include <cstddef>

template<typename _DataType>
class ScalarMatrix {
public:
	using DataType = _DataType;
	using Self = ScalarMatrix<DataType>;

private:
	DataType m_data = {};

public:
	ScalarMatrix() = default;
	ScalarMatrix(const ScalarMatrix &) = default;
	ScalarMatrix(ScalarMatrix &&) noexcept = default;
	ScalarMatrix &operator=(const ScalarMatrix &) = default;
	ScalarMatrix &operator=(ScalarMatrix &&) noexcept = default;
	~ScalarMatrix() = default;

	ScalarMatrix(const DataType &value) : m_data{value} {}

	[[nodiscard]] inline size_t size() const { return 1; }
	[[nodiscard]] inline size_t rows() const { return 1; }
	[[nodiscard]] inline size_t cols() const { return 1; }

	[[nodiscard]] inline DataType &operator[](size_t index)
	{
		assert(index == 0);
		return m_data;
	}
	[[nodiscard]] inline const DataType &operator[](size_t index) const
	{
		assert(index == 0);
		return m_data;
	}
	[[nodiscard]] inline DataType &operator()(size_t row, size_t col)
	{
		assert(row == 0 && col == 0);
		return m_data;
	}
	[[nodiscard]] inline const DataType &operator()(size_t row, size_t col) const
	{
		assert(row == 0 && col == 0);
		return m_data;
	}

	static Self Create(const DataType &value) { return Self{value}; }

	ScalarMatrix &negate()
	{
		m_data = -m_data;
		return *this;
	}

	ScalarMatrix &invert()
	{
		m_data = 1.0 / m_data;
		return *this;
	}

	ScalarMatrix &divide(const DataType &value)
	{
		m_data = value / m_data;
		return *this;
	}

	ScalarMatrix operator-() const
	{
		ScalarMatrix result(*this);
		return result.negate();
	}

	ScalarMatrix &operator+=(const ScalarMatrix &other)
	{
		m_data += other.m_data;
		return *this;
	}
	ScalarMatrix &operator-=(const ScalarMatrix &other)
	{
		m_data -= other.m_data;
		return *this;
	}
	ScalarMatrix &operator*=(const ScalarMatrix &other)
	{
		m_data *= other.m_data;
		return *this;
	}
	ScalarMatrix &operator/=(const ScalarMatrix &other)
	{
		m_data /= other.m_data;
		return *this;
	}

	ScalarMatrix &operator+=(const DataType &other)
	{
		m_data += other;
		return *this;
	}
	ScalarMatrix &operator-=(const DataType &other)
	{
		m_data -= other;
		return *this;
	}
	ScalarMatrix &operator*=(const DataType &other)
	{
		m_data *= other;
		return *this;
	}
	ScalarMatrix &operator/=(const DataType &other)
	{
		m_data /= other;
		return *this;
	}

	DataType value() const { return m_data; }
	explicit operator DataType() const { return value(); }

	[[nodiscard]] bool operator==(const ScalarMatrix &other) const { return m_data == other.m_data; }
	[[nodiscard]] bool operator!=(const ScalarMatrix &other) const { return m_data != other.m_data; }
	[[nodiscard]] bool operator<(const ScalarMatrix &other) const { return m_data < other.m_data; }
	[[nodiscard]] bool operator>(const ScalarMatrix &other) const { return m_data > other.m_data; }
	[[nodiscard]] bool operator<=(const ScalarMatrix &other) const { return m_data <= other.m_data; }
	[[nodiscard]] bool operator>=(const ScalarMatrix &other) const { return m_data >= other.m_data; }

	[[nodiscard]] bool operator==(const DataType &other) const { return m_data == other; }
	[[nodiscard]] bool operator!=(const DataType &other) const { return m_data != other; }
	[[nodiscard]] bool operator<(const DataType &other) const { return m_data < other; }
	[[nodiscard]] bool operator>(const DataType &other) const { return m_data > other; }
	[[nodiscard]] bool operator<=(const DataType &other) const { return m_data <= other; }
	[[nodiscard]] bool operator>=(const DataType &other) const { return m_data >= other; }

	template<typename NewType>
	NewType to() const { return NewType(m_data); }
};

#include "ScalarOperators.h"
#include "ScalarIO.h"

#endif //XLINEAR_XLINEAR_INCLUDE_XLINEAR_MATRIX_SCALARMATRIX_H

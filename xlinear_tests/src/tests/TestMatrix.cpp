//
// Created by xgallom on 4/9/20.
//

#include "TestMatrix.h"

#include <xlinear/matrix/Scalar.h>
#include <iostream>
#include <sstream>

const char *TestMatrix::name()
{
	return "matrix";
}

template<typename DataType>
static void testIO(const char *input, const DataType &value)
{
	std::stringstream ss(input);
	matrix::ScalarMatrix<DataType> scalar;
	ss >> scalar;
	if(scalar != value)
		throw std::logic_error("Failed scalar stream input");

	ss << scalar;
	if(ss.str() != input)
		throw std::logic_error("Failed scalar stream output");
}

void TestMatrix::execute()
{
	Float aFloat(-16);
	LongDouble longDouble(1525);
	Double constructed(6.5);
	const Double assigned = 4.4;

	constructed += assigned;
	if(constructed != 6.5 + 4.4)
		throw std::logic_error("Addition of scalars failed");

	constructed -= assigned;
	if(constructed != 6.5)
		throw std::logic_error("Subtraction of scalars failed");

	constructed *= assigned;
	if(constructed != 6.5 * 4.4)
		throw std::logic_error("Multiplication of scalars failed");

	constructed /= assigned;
	if(constructed != 6.5)
		throw std::logic_error("Division of scalars failed");


	constructed += 4.4;
	if(constructed != 6.5 + 4.4)
		throw std::logic_error("Addition of scalar and double failed");

	constructed -= 4.4;
	if(constructed != 6.5)
		throw std::logic_error("Subtraction of scalar and double failed");

	constructed *= 4.4;
	if(constructed != 6.5 * 4.4)
		throw std::logic_error("Multiplication of scalar and double failed");

	constructed /= 4.4;
	if(constructed != 6.5)
		throw std::logic_error("Division of scalar and double failed");


	if(constructed + assigned != 6.5 + 4.4)
		throw std::logic_error("Addition of scalars failed");

	if(constructed - assigned != 6.5 - 4.4)
		throw std::logic_error("Subtraction of scalars failed");

	if(constructed * assigned != 6.5 * 4.4)
		throw std::logic_error("Multiplication of scalars failed");

	if(constructed / assigned != 6.5 / 4.4)
		throw std::logic_error("Division of scalars failed");


	if(constructed + 4.4 != 6.5 + 4.4)
		throw std::logic_error("Addition of scalar and double failed");

	if(6.5 - assigned != 6.5 - 4.4)
		throw std::logic_error("Subtraction of scalar and double failed");

	if(constructed * 4.4 != 6.5 * 4.4)
		throw std::logic_error("Multiplication of scalar and double failed");

	if(6.5 / assigned != 6.5 / 4.4)
		throw std::logic_error("Division of scalar and double failed");

	if(constructed + aFloat.to<Double>() != 6.5 + -16.0)
		throw std::logic_error("Conversion of Float to Double failed");

	testIO("122.4e20", 122.4e20);
	testIO("122.4", 122.4f);
	testIO("122.4", 122.4l);
}

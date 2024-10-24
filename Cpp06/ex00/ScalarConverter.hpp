// ScalarConverter.hpp
#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <string>

class ScalarConverter {
public:
	static void convert(const std::string& literal);

private:
	static bool isChar(const std::string& literal);
	static bool isInt(const std::string& literal);
	static bool isFloat(const std::string& literal);
	static bool isDouble(const std::string& literal);

	static void displayChar(double value);
	static void displayInt(double value);
	static void displayFloat(double value);
	static void displayDouble(double value);
};

#endif

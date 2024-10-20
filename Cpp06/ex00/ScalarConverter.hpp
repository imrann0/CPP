#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter {

	public:
		static void convert(std::string value);
		static std::string control(std::string value);
		static void	print(std::string value);
	private:
		ScalarConverter();
		static int _int;
		static char _char;
		static float _float;
		static double _double;
};

#endif

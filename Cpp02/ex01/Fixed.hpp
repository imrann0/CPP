#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed
{
	public:
		Fixed();
		~Fixed();
		Fixed(int const num);
		Fixed(float const num);
		Fixed(Fixed const &fix);
		Fixed& operator=(Fixed const &fix);
		int getRawBits( void ) const;
		void setRawBits( int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
	private:
		int _value;
		static const int _bits = 8;
};

std::ostream&	operator<<(std::ostream &o, Fixed const &fixed);

#endif

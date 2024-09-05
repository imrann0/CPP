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

		Fixed&	operator=(Fixed const &fix);
		bool	operator>(Fixed const &fix);
		bool	operator>=(Fixed const &fix);
		bool	operator<(Fixed const &fix);
		bool	operator<=(Fixed const &fix);
		bool	operator==(Fixed const &fix);
		bool	operator!=(Fixed const &fix);
		Fixed	operator+(Fixed const &fix);
		Fixed	operator-(Fixed const &fix);
		Fixed	operator*(Fixed const &fix);
		Fixed	operator/(Fixed const &fix);

		Fixed	&operator++();
		Fixed	operator++(int);
		Fixed	&operator--();
		Fixed	operator--(int);

		static Fixed&		max(Fixed &fix1, Fixed &fix2);
		static const Fixed&	max(Fixed const &fix1, Fixed const &fix2);
		static Fixed&		min(Fixed &fix1, Fixed &fix2);
		static const Fixed&	min(Fixed const &fix1, Fixed const &fix2);

		int		getRawBits( void ) const;
		void	setRawBits( int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
	private:
		int _value;
		static const int _bits = 8;
};

std::ostream&	operator<<(std::ostream &o, Fixed const &fixed);

#endif

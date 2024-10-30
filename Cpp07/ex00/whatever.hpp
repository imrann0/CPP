#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename	A>
void swap(A &a, A &b)
{
	A c = a;
	a = b;
	b = c;
}
template <typename	I>
I min(const I &a, const I &b)
{
	return (a < b ? a : b);
}
template <typename B>

B max(const B &a, const B &b)
{
	return (a > b ? a : b);
}

#endif

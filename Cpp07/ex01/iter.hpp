#ifndef ITER_HPP
# define ITER_HPP

template <typename T>
void iter(T *array, int len, void (foo)(T &a))
{
	for (int i = 0; i < len; i++)
		foo(array[i]);
}


#endif

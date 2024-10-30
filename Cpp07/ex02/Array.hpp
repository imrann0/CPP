#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <stdexcept>

template <class T>
class Array
{
	public:
		Array() : _elements(0), _size(0) {}

		~Array() {
			delete[] _elements;
		}

		Array(unsigned int size) : _size(size)
		{
			_elements = new T[size]();
		}

		Array(const Array &copy) : _size(copy._size)
		{
			_elements = new T[_size];
			for (unsigned int i = 0; i < _size; ++i)
				_elements[i] = copy._elements[i];
		}

		Array& operator=(const Array &opt)
		{
			std::cout << "Array Copy Assignment Operator Called" << std::endl;
			if (this != &opt)
			{
				delete[] _elements;
				_size = opt._size;
				_elements = new T[_size];
				for (unsigned int i = 0; i < _size; ++i)
					_elements[i] = opt._elements[i];
			}
			return *this;
		}

		T& operator[](unsigned int index) const {
			if (index >= _size)
				throw std::out_of_range("Index out of bounds");
			return _elements[index];
		}

		unsigned int size() const {
			return _size;
		}

	private:
		T *_elements;
		unsigned int _size;
};

#endif

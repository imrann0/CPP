#include "Span.hpp"
#include <algorithm>
#include <iostream>

Span::Span() { std::cout << "Default Constructor Called" << std::endl; }
Span::~Span() {std::cout << "Default Destructor Called" << std::endl; }
Span::Span(unsigned int N) {std::cout << "Size Constructor Caled " << std::endl; _n = N;}
size_t Span::size() const { return (_numbers.size()); }
size_t Span::capacity() const { return (_numbers.capacity()); }

Span::Span(const Span &copy)
{
	this->_n = copy._n;
	_numbers.resize(copy._numbers.size());
	for (size_t i = 0; i < copy._numbers.size(); i++)
		_numbers[i] = copy._numbers[i];
}

Span& Span::operator=(const Span &opt)
{
	if (this != &opt)
	{
		this->_n = opt._n;
		_numbers.resize(opt._numbers.size());
		for (size_t i = 0; i < opt._numbers.size(); i++)
			_numbers[i] = opt._numbers[i];
	}
	return (*this);
}

int	Span::shortestSpan() const
{
	if (_numbers.size() < 2)
		throw std::logic_error("Yeterli sayı yok.");
	int min_span = 0;
	std::vector<int> tmp = _numbers;

	std::sort(tmp.begin(), tmp.end());

	min_span = tmp[1] - tmp[0];

	for (size_t i = 1; i < tmp.size(); i++)
	{
		int span = tmp[i + 1] - tmp[i];
		if (span < min_span)
			min_span = span;
	}
	return (min_span);
}

int Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw std::logic_error("Yeterli sayı yok.");

	int max_number = *std::max_element(_numbers.begin(), _numbers.end());
	int min_number = *std::min_element(_numbers.begin(), _numbers.end());

	return (max_number - min_number);
}

void Span::addNumber(int value)
{
	if (_numbers.size() >= _n)
			throw std::overflow_error("Maksimum kapasiteye ulaşıldı.");
	_numbers.push_back(value);
}

void Span::addNumbers(iterator begin, iterator end)
{
	size_t count = std::distance(begin, end);

	if (_numbers.size() + count > _n)
		throw std::overflow_error("Not enough space in Span for the new numbers");
	_numbers.insert(_numbers.end(), begin, end);
}

void Span::print() const
{
	for (size_t i = 0; i < _numbers.size(); i++)
		std::cout << _numbers[i] << " ";
	std::cout << std::endl;
}

void Span::iprint()
{
	std::vector<int>::iterator it = _numbers.begin();
	for ( ; it != _numbers.end(); it++)
		std::cout << *it << std::endl;
}


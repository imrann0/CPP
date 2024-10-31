#ifndef SPAN_HPP
#define SPAN_HPP

#include <cstddef>
#include <vector>

class Span
{
	public:
		Span();
		Span(unsigned int N);
		~Span();
		Span(const Span &copy);
		Span& operator=(const Span &opt);

		void addNumber(int value);
		int shortestSpan() const;
		int longestSpan() const;
		size_t size() const;
		size_t capacity() const;
		void print() const;

	private:
		unsigned int _n;
		std::vector<int> _numbers;
};

#endif

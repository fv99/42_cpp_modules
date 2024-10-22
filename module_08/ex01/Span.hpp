#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <limits>


class Span
{
	private:
		std::vector<int> _arr;
		unsigned int _N;

		Span();

	public:
		Span(unsigned int n);
		Span(const Span &src);

		~Span();

		Span &operator=(const Span &src);

		void addNumber(int number);
		void addRandomNumbers(unsigned int num);
		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;
};
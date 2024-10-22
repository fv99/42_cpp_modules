#include "Span.hpp"

Span::Span(): _N(0) {}

Span::Span(unsigned int n): _N(n) {}

Span::Span(const Span &src): _arr(src._arr), _N(src._N) {}

Span::~Span() {}

Span &Span::operator=(const Span &src)
{
	if (this != &src)
	{
		_arr = src._arr;
		_N = src._N;
	}
	return *this;
}

void Span::addNumber(int number)
{
	if (_arr.size() >= _N)
		throw std::out_of_range("Error: Span is full");
	_arr.push_back(number);
}

// using std::sort to sort the array
unsigned int Span::shortestSpan() const
{
	if (_arr.size() < 2)
		throw std::logic_error("Error: Not enough numbers to find a span");

	std::vector<int> sorted(_arr);
	std::sort(sorted.begin(), sorted.end());

	unsigned int min = std::numeric_limits<int>::max();
	for (std::vector<int>::size_type i = 0; i < sorted.size() - 1; ++i)
	{
		unsigned int span = sorted[i + 1] - sorted[i];
		if (span < min)
			min = span;
	}
	return min;
}

unsigned int Span::longestSpan() const
{
    if (_arr.size() < 2)
        throw std::logic_error("Not enough numbers to find a span");

    int min = *std::min_element(_arr.begin(), _arr.end());
    int max = *std::max_element(_arr.begin(), _arr.end());
    return static_cast<unsigned int>(max) - min;
}

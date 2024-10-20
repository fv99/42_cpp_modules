#pragma once

#include <iostream>

template<typename SWAP>

void swap(SWAP &a, SWAP &b)
{
	SWAP temp = a;
	a = b;
	b = temp;
}

template<typename _MIN>

const _MIN &min(const _MIN &a, const _MIN &b)
{
	return (a <= b ? a : b);
}

template<typename _MAX>

const _MAX &max(const _MAX &a, const _MAX &b)
{
	return (a >= b ? a : b);
}

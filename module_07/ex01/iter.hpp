#pragma once

#include <string>

template <typename ITER>

void iter(ITER *arr, size_t len, void (*fun)(ITER &))
{
	if (arr == NULL || fun == NULL)
		return ;
	for (size_t i = 0; i < len; i++)
		fun(arr[i]);
}

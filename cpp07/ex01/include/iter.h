#pragma once

#	include <cstdlib>

template <typename type>
void iter(type *array, size_t const size, void (*function)(type&)) {
	if (!array || !function) return;
	for (size_t i = 0; i < size; i++) function(array[i]);
}

template <typename type>
void iter(type const* array, size_t const size, void (*fun)(type const&)) {
	if (!array || !fun) return;
	for (size_t i = 0; i < size; i++) fun(array[i]);
}
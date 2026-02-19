#pragma once

template <typename T> void swap(T& a, T& b) {
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T> T const& min(T& a, T& b) {
	if (a < b) return a;
	else return b;
}
template <typename T> T const& max(T& a, T& b) {
	if (a > b) return a;
	else return b;
}
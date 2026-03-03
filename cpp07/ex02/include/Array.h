#pragma once

#include <stdexcept>
#include <iostream>

template <typename type>
class Array {
	private:
		type* _elements;
		unsigned int _size;

	public:
		Array() {
			_elements = new type[0];
			_size = 0;
		}
		Array(unsigned int n){
			_elements = new type[n]();
			_size = n;
		}
		Array(Array const& copy) {_elements = new type[0]; *this = copy;}
		Array& operator=(Array const& copy) {
			if (this != &copy) {
				delete[] _elements;
				_size = copy._size;
				_elements = new type[_size]();
				for (size_t i = 0; i < _size; i++) _elements[i] = copy._elements[i];
			}
			return *this;
		}
		~Array() {delete[] _elements;}

		type& operator[](unsigned int idx) {
			if (idx >= _size) throw std::out_of_range("Index out of bounds");
			return _elements[idx];
		}
		type const& operator[](unsigned int idx) const {
			if (idx >= _size) throw std::out_of_range("Index out of bounds");
			return _elements[idx];
		}

		unsigned int size() const {return _size;}
};
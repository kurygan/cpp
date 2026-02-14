#include "Data.h"

Data::Data() {
	this->size = std::rand() % 100;
	std::cout << "Data Constructor has been called (" << this->size << ")" << std::endl;
}

Data::Data(Data const& copy) { *this = copy; }
Data::~Data() {}
Data& Data::operator=(Data const& copy) {
	if (this != &copy)
		this->size = copy.getSize();
	return *this;
}

size_t Data::getSize() const { return this->size; }
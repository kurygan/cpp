#include "Serializer.h"

uintptr_t Serializer::serialize(Data* ptr) {
	uintptr_t ret = reinterpret_cast<uintptr_t>(ptr);
	return ret;
}

Data* Serializer::reserialize(uintptr_t raw) {
	Data* ret = reinterpret_cast<Data*>(raw);
	return ret;
}
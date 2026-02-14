#pragma once

#	include "Data.h"
#	include <stdint.h>

class Serializer {
	public:
		uintptr_t static serialize(Data* ptr);
		Data static* reserialize(uintptr_t raw);
	private:
		Serializer();
		Serializer(Serializer const& copy);
		Serializer operator=(Serializer const& copy);
		~Serializer();
};
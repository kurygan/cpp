#pragma once

#	include <string>
#	include <iostream>
#	include <cstdlib>

class Data {
	public:
		Data();
		Data(Data const& copy);
		Data& operator=(Data const& copy);
		~Data();

		size_t getSize() const;

	private:
		size_t size;
};
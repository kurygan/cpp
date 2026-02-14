#include "Serializer.h"
#include <ctime>

int main() {
	std::srand(std::time(NULL));
	Data* obj = new Data();
	uintptr_t raw_add = Serializer::serialize(obj);

	Data* obj2 = Serializer::reserialize(raw_add);
	std::cout << "Obj2 Data size is " << obj2->getSize() << std::endl;

	delete obj;
	return 0;
}
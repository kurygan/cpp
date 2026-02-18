#include "Base.h"

Base* generate(void) {
	int temp = std::rand() % 3;
	temp++;
	Base* ret;

	switch (temp) {
		case 1:
			ret = new A(); break;
		case 2:
			ret = new B(); break;
		default:
			ret = new C(); break;
	}
	return ret;
}
void identify(Base* base) {
	if (dynamic_cast<A*>(base)) std::cout << "Type A Identified" << std::endl;
	if (dynamic_cast<B*>(base)) std::cout << "Type B Identified" << std::endl;
	if (dynamic_cast<C*>(base)) std::cout << "Type C Identified" << std::endl;
}
void identify(Base& base) {
	try {
		A& a = dynamic_cast<A&>(base);
		(void)a;
		std::cout << "Type A Identified" << std::endl;
		return;
	} catch(const std::exception& e) {}
	try {
		B& b = dynamic_cast<B&>(base);
		(void)b;
		std::cout << "Type B Identified" << std::endl;
		return;
	} catch(const std::exception& e) {}
	try {
		C& c = dynamic_cast<C&>(base);
		(void)c;
		std::cout << "Type C Identified" << std::endl;
		return;
	} catch(const std::exception& e) {}
}
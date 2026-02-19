#include <iostream>
#include <string>
#include "template.h"
#define GREEN "\033[1;32m"
#define RES "\033[0m"

class Class {
	private:
		int _num;
	public:
		Class(int n): _num(n) {}

		bool operator==(Class const& right) const {return _num == right._num;}
		bool operator!=(Class const& right) const {return _num != right._num;}
		bool operator>(Class const& right) const {return _num > right._num;}
		bool operator<(Class const& right) const {return _num < right._num;}
		bool operator>=(Class const& right) const {return _num >= right._num;}
		bool operator<=(Class const& right) const {return _num <= right._num;}

		int getNum() const {return _num;}
};

std::ostream& operator<<(std::ostream& out, Class const& a) {
	out << a.getNum();
	return out;
}

void printTitle(std::string title) {std::cout << GREEN << title << RES << std::endl;}

int main(void) {
	printTitle("\n-- 42 Subject --");

	int a = 2, b = 3;

	std::cout << "a = " << a << "\tb = " << b << std::endl;
	::swap(a, b);
	std::cout << "a = " << a << "\tb = " << b << std::endl;
	std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

	std::string string1 = "Hello World!";
	std::string string2 = "Hello Underworld!";
	std::cout << "string1 = " << string1 << "\t\tstring2 = " << string2 << std::endl;
	::swap(string1, string2);
	std::cout << "string1 = " << string1 << "\tstring2 = " << string2 << std::endl;
	std::cout << "min(string1, string2) = " << ::min(string1, string2) << std::endl;
	std::cout << "max(string1, string2) = " << ::max(string1, string2) << std::endl;

	printTitle("\n-- Complex Class --");
	Class class1(42);
	Class class2(24);

	std::cout << "class1 = " << class1 << "\tclass2 = " << class2 << std::endl;
	::swap(class1, class2);
	std::cout << "class1 = " << class1 << "\tclass2 = " << class2 << std::endl;
	std::cout << "min(class1, class2) = " << ::min(class1, class2) << std::endl;
	std::cout << "max(class1, class2) = " << ::max(class1, class2) << std::endl;

	return 0;
}
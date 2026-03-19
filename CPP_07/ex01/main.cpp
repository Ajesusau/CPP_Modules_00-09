#include <iostream>
#include "iter.hpp"

void toUpper(char &c) {
	if (c >= 'a' && c <= 'z') {
		c -= 32;
	}
}

int main() {
	std::string a = "hola mundo";
	::iter(&a[0], 4, toUpper);
	std::cout << a << std::endl;
}

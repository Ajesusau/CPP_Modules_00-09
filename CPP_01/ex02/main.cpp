#include <iostream>

int main (void)
{
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;
	std::cout << "-------------------MEMORY------------------" << std::endl;
	std::cout << "String: " << &string << std::endl;
	std::cout << "Pointer: " << stringPTR << std::endl;
	std::cout << "Reference: " << &stringREF << std::endl;
	std::cout << "-------------------VALUE-------------------" << std::endl;
	std::cout << "String: " << string << std::endl;
	std::cout << "Pointer: " << *stringPTR << std::endl;
	std::cout << "Reference: " << stringREF << std::endl;
	return 0;
}
#include <iostream>
#include "Harl.hpp"

int	main()
{
	Harl harl;
	std::cout << "-------------------TEST_DEBUGB-------------------" << std::endl;
	harl.complain("DEBUG");
	std::cout << "-------------------TEST_INFO---------------------" << std::endl;
	harl.complain("INFO");
	std::cout << "-------------------TEST_WARNING------------------" << std::endl;
	harl.complain("WARNING");
	std::cout << "-------------------TEST_ERROR--------------------" << std::endl;
	harl.complain("ERROR");
	std::cout << "-------------------TEST_WRONG--------------------" << std::endl;
	harl.complain("OTHER");
	return 0;
}

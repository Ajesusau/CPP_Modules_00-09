#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

std::string	ft_replace(std::string text, std::string find, std::string replace)
{
	size_t		pos = 0;
	size_t 		found;
	std::string	result;

	while((found = text.find(find, pos)) != std::string::npos)
	{
		result += text.substr(pos, found - pos) + replace;
		pos = found + find.length();
	}
	result += text.substr(pos, text.length() - pos);
	return result;
}

int	main(int argc, char **argv)
{
	if (argc == 4)
	{
		std::string filename = argv[1];
		std::string find = argv[2];
		std::string replace = argv[3];
		std::string outputFilename = filename + ".replace";
		if (find.empty() || replace.empty()) 
		{
			std::cout << "Error: Empty string" << std::endl;
			return 1;
		}
		std::ifstream inputFile(filename.c_str());
		if (!inputFile.is_open()) {
			std::cout << "The file could not be opened." << std::endl;
			return 1;
		}
		std::ofstream outputFile(outputFilename.c_str());
		if (!outputFile.is_open()) {
			std::cout << "The file could not be created." << std::endl;
			return 1;
		}
		std::stringstream buffer;
		buffer << inputFile.rdbuf();
		std::string text = buffer.str();
		outputFile << ft_replace(text, find, replace);
	}
	else
		std::cout << "Required program parameters: filename, s1, s2" << std::endl;
	return 0;
}
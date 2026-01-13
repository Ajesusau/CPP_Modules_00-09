#include <iostream>
#include <cctype>

int	main(int argc, char **argv) {
	int	i;
	int	j;

	i = 1;
	if (argc >= 2)
	{
		while (argv[i])
		{
			j = 0;
			while (argv[i][j])
			{
				std::cout << static_cast<char>(toupper(argv[i][j]));
				j++;
			}
			i++;
		}
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return 0;
}

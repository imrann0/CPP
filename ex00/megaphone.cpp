#include <iostream>

int	main(int ar, char **av)
{
	int	i;
	int	j;

	if (ar == 1)
	{
		std::string empty = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
		std::cout << empty << std::endl;
	}
	else
	{
		i = 1;
		while (av[i])
		{
			std::string str = av[i];
			j = 0;
			while (j < str.length())
			{
				std::cout << (char)toupper(av[i][j]);
				j++;
			}
			std::cout << " ";
			i++;
		}
		std::cout << std::endl;
	}

}

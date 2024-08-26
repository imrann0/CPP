#include <iostream>
#include <fstream>

int main(int ar, char **av)
{
	std::ifstream	input;
	std::ofstream	output;
	std::string		filereplace;
	size_t			rep;
	std::string 	line;
	std::string		s1;
	std::string		s2;

	if (ar != 4)
		return (std::cout << "invalid argument count" << std::endl, 1);
	s1 = av[2];
	s2 = av[3];
	input.open(av[1]);
	if (!input.good())
		return (std::cout << "file could not be opened" << std::endl, 1);
	filereplace = (std::string)av[1] + ".replace";
	output.open(filereplace);
	if (!output.good())
		return (std::cout << "file could not be opened" << std::endl, 1);

	while (std::getline(input, line))
	{
		rep = line.find(s1); 
		while(rep != std::string::npos)
		{
			output << line.substr(0, rep) << s2;
			line = line.substr(rep + s1.length());
			rep = line.find(s1);
		}
		output << line << std::endl;
	}
	input.close();
	output.close();

}

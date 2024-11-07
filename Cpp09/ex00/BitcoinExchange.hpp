#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <iostream>


typedef std::map<std::string, double>::iterator it;

class BitcoinExchange
{
	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &copy);
		BitcoinExchange& operator=(BitcoinExchange const &opt);
		void ReadInput(std::string file);
		void print();


		class FileOpenException : public std::exception {
			public:
				const char * what() const throw() {
					return "File could not be opened";
				};
		};
		class InvalidArgumentException : public std::exception {
			public:
				const char* what() const throw() {
					return "Invalid argument encountered in file";
				}
		};

	private:
		std::map<std::string, double> _data;
};


#endif

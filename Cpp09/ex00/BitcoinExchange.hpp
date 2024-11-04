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
		void print();

	private:
		std::map<std::string, double> _data;
};


#endif

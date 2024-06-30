#include <iostream>

class Contact
{
	private:
		std::string first_name;
		std::string	last_name;
		std::string	nick_name;
		std::string	pohne_number;
	public:
		Contact();
		~Contact();
		std::string get_first_name();
		std::string get_last_name();
		std::string get_nick_name();
		std::string get_phone_number();
		void	set_first_name(std::string name);
		void	set_last_name(std::string last);
		void	set_nick_name(std::string nick);
		void	set_phone_number(std::string phone);
};

#include <iostream>

class Contact
{
	private:
		std::string name;
		std::string	surname;
		std::string	nick_name;
		std::string	pohne_number;
		std::string secret;
	public:
		Contact();
		~Contact();
		std::string get_name();
		std::string get_surname();
		std::string get_nick_name();
		std::string get_phone_number();
		std::string get_secret();
		void	set_name(std::string name);
		void	set_surname(std::string surname);
		void	set_nick_name(std::string nick);
		void	set_phone_number(std::string phone);
		void	set_secret(std::string secret);
};

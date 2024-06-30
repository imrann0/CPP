#include <iostream>

class Contact
{
	private:
		std::string first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	pohne_number;
	public:
		Contact();
		~Contact();
		std::string get_first_name();
		void	set_first_name(std::string name);
};

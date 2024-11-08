#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <stdexcept>

class RPN {
public:
	RPN(const std::string& expression);
	RPN(const RPN &copy);
	RPN& operator=(const RPN &opt);
	~RPN();

	int		evaluate();
	bool	isOperator(const std::string& token) const;
	int		performOperation(int a, int b, const std::string& op) const;

private:
	std::string _expression;
};

#endif



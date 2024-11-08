#include "RPN.hpp"
#include <sstream>
#include <iostream>
#include <cstdlib>

RPN::RPN(const std::string& expression) : _expression(expression) {}
RPN::~RPN() {}
RPN::RPN(const RPN &copy) { this->_expression = copy._expression;}

RPN& RPN::operator=(const RPN &opt)
{
		if (this != &opt)
		{
			_expression = opt._expression;
		}
		return *this;
}

bool RPN::isOperator(const std::string& token) const
{
	return token == "+" || token == "-" || token == "*" || token == "/";
}

int RPN::performOperation(int a, int b, const std::string& op) const
{
	if (op == "+")
		return a + b;
	else if (op == "-")
		return a - b;
	else if (op == "*")
		return a * b;
	else if (op == "/")
	{
		if (b == 0) throw std::runtime_error("Error: Division by zero");
		return a / b;
	}
	throw std::runtime_error("Error: Invalid operator");
}

int RPN::evaluate() {
	std::stack<int> stack;
	std::istringstream tokens(_expression);
	std::string token;

	while (tokens >> token)
	{
		if (std::isdigit(token[0]))
			stack.push(std::atoi(token.c_str()));
		else if (isOperator(token))
		{
			if (stack.size() < 2) throw std::runtime_error("Error: Insufficient operands");

			int b = stack.top();
			stack.pop();
			int a = stack.top();
			stack.pop();
			int result = performOperation(a, b, token);
			stack.push(result);
		} else {
			throw std::runtime_error("Error: Invalid token");
		}
	}
	if (stack.size() != 1) throw std::runtime_error("Error: Invalid expression");

	return stack.top();
}

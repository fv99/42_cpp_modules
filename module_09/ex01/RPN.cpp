#include "RPN.hpp"

RPN::RPN(void) {}

RPN::RPN(const RPN &src): _stack(src._stack) {}

RPN::~RPN(void) {}

RPN &RPN::operator=(const RPN &src)
{
    if (this != &src)
    {
        _stack = src._stack;
    }
    return *this;
}

bool RPN::checkOperator(const std::string &op) const
{
    return (op == "+" || op == "-" || op == "*" || op == "/");
}

int RPN::applyOperator(const std::string &op, int operand1, int operand2)
{
    if (op == "+")
        return operand1 + operand2;
    else if (op == "-")
        return operand1 - operand2;
    else if (op == "*")
        return operand1 * operand2;
    else if (op == "/")
    {
        if (operand2 == 0)
        {
            std::cerr << "Error: Cannot divide by 0" << std::endl;
            exit(EXIT_FAILURE);
        }
        return operand1 / operand2;
    }
    else
    {
        std::cerr << "Error: Failed to apply operator" << std::endl;
        exit(EXIT_FAILURE);
    }
}

int RPN::calculate(const std::string &expression)
{
	std::istringstream iss(expression);
	std::string token;

	while (iss >> token)
	{
		if (token.length() == 1 && std::isdigit(token[0]))
		{
            int number = token[0] - '0';
            _stack.push(number);
        }	
		else if (checkOperator(token))
		{
			if (_stack.size() < 2)
			{
				std::cerr << "Error: Invalid number of operands" << std::endl;
        		exit(EXIT_FAILURE);
			}
			int operand2 = _stack.top();
            _stack.pop();
            int operand1 = _stack.top();
            _stack.pop();

            int result = applyOperator(token, operand1, operand2);
            _stack.push(result);

		}
		else
        {
            std::cerr << "Error: Calculation failure" << std::endl;
            exit(EXIT_FAILURE);
        }
	}
	if (_stack.size() != 1)
    {
        std::cerr << "Error: More than 1 number in stack" << std::endl;
        exit(EXIT_FAILURE);
    }

    return _stack.top();
}

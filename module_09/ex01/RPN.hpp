#pragma once

#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cstdlib>
#include <iomanip>

class RPN
{
	private:
		std::stack<int> _stack;

		bool checkOperator(const std::string &op) const;
    	int applyOperator(const std::string &op, int operand1, int operand2);

		public:
		RPN(void);
		RPN(const RPN &src);
		~RPN(void);
		RPN &operator=(const RPN &src);
		
		int calculate(const std::string &expression);


};

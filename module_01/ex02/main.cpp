#include <iostream>

int main(void)
{
	std::string	string;
	std::string *stringPTR;
	std::string &stringREF = string;

	stringPTR = &string;

	string = "HI THIS IS BRAIN";

	std::cout << "string address: " << &string << std::endl;
	std::cout << "stringPTR address: " << stringPTR << std::endl;
	std::cout << "stringREF address: " << &stringREF << std::endl;
	
	std::cout << "string value: " << string << std::endl;
	std::cout << "stringPTR value: " << *stringPTR << std::endl;
	std::cout << "stringREF value: " << stringREF << std::endl;

	return (0);
}

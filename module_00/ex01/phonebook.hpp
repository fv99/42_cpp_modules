
#include <iostream>
#include <iomanip>
#include <string>

class Contact
{
    public:
        std::string name;
        std::string last_name;
        std::string nick;
        std::string phone;
        std::string secret;
    
    void display(void)
    {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Last name: " << last_name << std::endl;
        std::cout << "Nick name: " << nick << std::endl;
        std::cout << "Phone number: " << phone << std::endl;
        std::cout << "Darkest secret: " << secret << std::endl;
    }
};

class PhoneBook
{
    public:
        Contact contacts[8];
        int num;

    
};

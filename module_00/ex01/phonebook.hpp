#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <string>

class Contact
{
private:
    std::string name;
    std::string last_name;
    std::string nick;
    std::string phone;
    std::string secret;

public:
    void display(void);
    friend class PhoneBook;
};

class PhoneBook
{
private:
    Contact contacts[8];
    int num;

public:
    void add_contact();
    void search_contact();
};

#endif // PHONEBOOK_HPP

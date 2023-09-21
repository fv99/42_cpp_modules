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
    void setContactInfo(const std::string& n, const std::string& ln, const std::string& nk, const std::string& ph, const std::string& sc);
    std::string getNamePreview() const;
    std::string getLastNamePreview() const;
    std::string getNickPreview() const;
    std::string getPhonePreview() const;
};

class PhoneBook
{
private:
    Contact contacts[8];
    int num;

public:
    void add_contact();
    void search_contact();

    PhoneBook();
    ~PhoneBook();
};

#endif

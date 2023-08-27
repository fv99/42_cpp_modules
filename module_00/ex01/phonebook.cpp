// phonebook.cpp
#include "phonebook.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <limits>

void Contact::display()
{
    std::cout << "Name: " << name << std::endl;
    std::cout << "Last name: " << last_name << std::endl;
    std::cout << "Nick name: " << nick << std::endl;
    std::cout << "Phone number: " << phone << std::endl;
    std::cout << "Darkest secret: " << secret << std::endl;
}

void Contact::setContactInfo(const std::string& n, const std::string& ln, const std::string& nk, const std::string& ph, const std::string& sc)
{
    name = n;
    last_name = ln;
    nick = nk;
    phone = ph;
    secret = sc;
}

std::string Contact::getNamePreview() const
{
    return name.substr(0, 9);
}

std::string Contact::getLastNamePreview() const
{
    return last_name.substr(0, 9);
}

std::string Contact::getNickPreview() const
{
    return nick.substr(0, 9);
}

std::string Contact::getPhonePreview() const
{
    return phone.substr(0, 9);
}

void PhoneBook::add_contact()
{
    system("clear");
    std::cout << "\t Adding a contact" << std::endl;

    if (num >= 8)
    {
        std::cout << "Phone book is full. Overwriting the oldest contact." << std::endl;

        for (int i = 0; i < num - 1; i++)
            contacts[i] = contacts[i + 1];
        num--;
    }

    // Rest of the code for input and clearing...
    std::string name, last_name, nick, phone, secret;

    std::cout << "Enter first name:" << std::endl;
    std::cin >> name;
    system("clear");

    std::cout << "Enter last name:" << std::endl;
    std::cin >> last_name;
    system("clear");

    std::cout << "Enter nick name:" << std::endl;
    std::cin >> nick;
    system("clear");

    std::cout << "Enter phone number:" << std::endl;
    std::cin >> phone;
    system("clear");

    std::cout << "Enter darkest secret:" << std::endl;
    std::cin >> secret;
    system("clear");

    contacts[num].setContactInfo(name, last_name, nick, phone, secret);

    // Increment num after adding a contact
    num++;
}

void PhoneBook::search_contact()
{
    int index;
    std::cout << "---------------------------------------------------------------" << std::endl;

    for (int i = 0; i < num; i++)
    {
        std::cout << std::right << std::setw(10) << i << " | ";
        std::cout << std::right << std::setw(10) << contacts[i].getNamePreview() << " | ";
        std::cout << std::right << std::setw(10) << contacts[i].getLastNamePreview() << " | ";
        std::cout << std::right << std::setw(10) << contacts[i].getNickPreview() << " | ";
        std::cout << std::right << std::setw(10) << contacts[i].getPhonePreview() << std::endl;
    }

    do
    {
        std::cout << "Select index to display (0-" << num - 1 << "): ";
        std::cin >> index;

        if (!std::cin.good() || index < 0 || index > 7)
        {
            std::cout << "ERROR: please input a valid integer between 0 and 7" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
            contacts[index].display();
            break;
        }
    } while (true);}

int main(void)
{
    PhoneBook phonebook;

    while (1)
    {
        std::cout << "Commands: ADD, SEARCH, EXIT" << std::endl;
        std::string command;
        std::cin >> command;

        if (command == "ADD")
            phonebook.add_contact(); // Call add_contact() using the phonebook instance
        else if (command == "SEARCH")
            phonebook.search_contact(); // Call search_contact() using the phonebook instance
        else if (command == "EXIT")
            break;
        else
        {
            std::cout << "ERROR: command not found" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    return 0;
}

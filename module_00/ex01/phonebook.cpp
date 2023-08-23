#include "phonebook.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

void add_contact(PhoneBook& phonebook);
void search_contact(PhoneBook& phonebook);

void add_contact(PhoneBook& phonebook)
{
    system("clear");
    std::cout << "\t Adding a contact" << std::endl;

    for (int i = phonebook.num - 1; i >= 0; i--)
        phonebook.contacts[i + 1] = phonebook.contacts[i];

    std::cout << "Enter first name:" << std::endl;
    std::cin >> phonebook.contacts[0].name;
    system("clear");

    std::cout << "Enter last name:" << std::endl;
    std::cin >> phonebook.contacts[0].last_name;
    system("clear");

    std::cout << "Enter nick name:" << std::endl;
    std::cin >> phonebook.contacts[0].nick;
    system("clear");

    std::cout << "Enter phone number:" << std::endl;
    std::cin >> phonebook.contacts[0].phone;
    system("clear");

    std::cout << "Enter darkest secret:" << std::endl;
    std::cin >> phonebook.contacts[0].secret;
    system("clear");

    if (phonebook.num < 8)
        phonebook.num++;
}

void search_contact(PhoneBook& phonebook)
{
    int index;

    std::cout << std::setw(10) << "Index | " << "Name | " << "Last name | " << "Phone no. " << std::endl;
    std::cout << "------------------------------------------------------------" << std::endl;

    for (int i = 0; i < phonebook.num; i++)
    {
        std::cout << std::right << std::setw(10) << i << " | ";
        std::cout << std::right << std::setw(10) << phonebook.contacts[i].name.substr(0, 9) << " | ";
        std::cout << std::right << std::setw(10) << phonebook.contacts[i].last_name.substr(0, 9) << " | ";
        std::cout << std::right << std::setw(10) << phonebook.contacts[i].nick.substr(0, 9) << " | ";
        std::cout << std::right << std::setw(10) << phonebook.contacts[i].phone.substr(0, 9) << std::endl;
    }

    do
    {
        std::cout << "Select index to display (0-" << phonebook.num - 1 << "): ";
        std::cin >> index;

        if (index < 0 || index >= phonebook.num)
            std::cout << "Invalid index. Enter a valid index." << std::endl;
        else
        {
            phonebook.contacts[index].display();
            break;
        }
    } while (true);

}

int main(void)
{
    PhoneBook phonebook;

    while (1)
    {
        std::cout << "Commands: ADD, SEARCH, EXIT" << std::endl;
        std::string command;
        std::cin >> command;

        if (command == "ADD")
            add_contact(phonebook);
        else if (command == "SEARCH")
            search_contact(phonebook);
        else if (command == "EXIT")
            break;
        else
            std::cout << "ERROR: command not found" << std::endl;
    }
    return (0);
}
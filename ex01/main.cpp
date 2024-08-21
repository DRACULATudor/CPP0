#include "Phonebook.hpp"
#include "Phonebook.hpp"
#include <iostream>
#include <cctype>

bool checknumbers(std::string index)
{
    for (int i = 0; i < index.length(); i++)
    {
        if (!::isdigit(index[i]))
        {
            return (false);
        }
    }
    return (true);
}

int main()
{
    Phonebook phonebook;
    std::string cmd;
    std::string index;
    int returnal = 0;
    while (42)
    {

        std::cout << "Enter command: ";
        std::getline(std::cin, cmd);
        if (cmd == "ADD")
        {
            returnal = phonebook.addContact();
        }
        else if (cmd == "SEARCH" && returnal)
        {
            phonebook.displayContacts();
            std::cout << "Enter the index of the contact for more details: ";
            std::getline(std::cin, index);
            if (checknumbers(index) && !index.empty())
            {
                if (std::stoi(index) >= 0 && std::stoi(index) < phonebook.getContact())
                    phonebook.searchContact(std::stoi(index));
                else
                    std::cerr << "Index for contacts out of bounds !" << std::endl;
            }
            else
                std::cerr << "Index must be a number !" << std::endl;
        }
        else if (cmd == "EXIT")
            break;
        else
        {
            std::cout << "The command: '" << cmd << "' does not exist!" << std::endl;
            std::cout << "The commands are: ADD, SEARCH or EXIT " << std::endl;
        }
    }
    return 0;
}

#include "Phonebook.hpp"

Phonebook::Phonebook() : cont_count(0), oldest_cont_index(0)
{
}

int Phonebook::addContact()
{
    std::string firstName, lastName, nickname, phoneNumber, darkestSecret;

    std::cout << "Enter first name: ";
    std::getline(std::cin, firstName);
    if (firstName.empty())
    {
        std::cout << "Can't have empty first name !" << std::endl;
        return (0);
    }
    std::cout << "Enter last name: ";
    std::getline(std::cin, lastName);
    if (firstName.empty())
    {
        std::cout << "Can't have empty last name !" << std::endl;
        return (0);
    }
    std::cout << "Enter  nickname: ";
    std::getline(std::cin, nickname);
    std::cout << "Enter phonenumber: ";
    std::getline(std::cin, phoneNumber);
    if (!checknumbers(phoneNumber) || phoneNumber.empty())
    {
        std::cout << "The phone number can only contain numbers !" << std::endl;
        return (0);
    }
    std::cout << "Enter darkest secret: ";
    std::getline(std::cin, darkestSecret);

    Contact newContact;

    newContact.setFirstName(firstName);
    newContact.setLastName(lastName);
    newContact.setNickname(nickname);
    newContact.setPhoneNumber(phoneNumber);
    newContact.setDarkestSecret(darkestSecret);
    newContact.setIndex(oldest_cont_index);

    contacts[oldest_cont_index] = newContact;
    if (cont_count < 8)
    {
        cont_count++;
    }
    oldest_cont_index = (oldest_cont_index + 1) % 8;
    return (1);
}

void Phonebook::displayContacts() const
{
    // contacts[i] == my array of bojects represneting the contacts by te index
    std::cout << std::setw(10) << "Index" << "|";
    std::cout << std::setw(10) << "First Name" << "|";
    std::cout << std::setw(10) << "Last Name" << "|";
    std::cout << std::setw(10) << "Nickname" << "|";
    std::cout << std::endl;
    std::cout << "--------------------------------------------" << std::endl;

    for (int i = 0; i < cont_count; i++)
    {
        std::cout << std::setw(10) << contacts[i].getIndex() << "|";
        std::cout << std::setw(10) << truncateString(contacts[i].getFirstName()) << "|";
        std::cout << std::setw(10) << truncateString(contacts[i].getLastName()) << "|";
        std::cout << std::setw(10) << truncateString(contacts[i].getNickname()) << "|" << std::endl;
        std::cout << "--------------------------------------------" << std::endl;
    }
}

std::string Phonebook::truncateString(const std::string &str) const
{
    if (str.length() > 10)
    {
        return (str.substr(0, 9) + ".");
    }
    return (str);
}

void Phonebook::searchContact(int index) const
{
    bool found = false;

    for (int i = 0; i < cont_count; i++)
    {
        if (contacts[i].getIndex() == index)
        {
            std::cout << "First name: " << contacts[i].getFirstName() << std::endl;
            std::cout << "Last name: " << contacts[i].getLastName() << std::endl;
            std::cout << "Nickname: " << contacts[i].getNickname() << std::endl;
            std::cout << "Phonenumber: " << contacts[i].getPhoneNumber() << std::endl;
            std::cout << "Darkest secret : " << contacts[i].getDarkestSecret() << std::endl;
            found = true;
        }
    }
    if (!found)
    {
        std::cout << "We are sorry the contact can not be found" << std::endl;
    }
}

int Phonebook::getContact() const
{
    return cont_count;
}
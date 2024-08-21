#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <iomanip>
#include <string>
#include "Contact.hpp"

class Phonebook
{

private:
    Contact contacts[8];
    int cont_count;
    int oldest_cont_index;
    std::string truncateString(const std::string &str) const;

public:
    Phonebook();
    int addContact();
    void searchContact(int index) const;
    void displayContacts() const;
    void exit();
    int getContact() const;
};

bool checknumbers(std::string index);

#endif
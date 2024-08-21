#ifndef CONTACT_H
#define CONTACT_H

#include <string>

class Contact
{
private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;
    int index;
public:
    Contact() = default;

    Contact(const std::string &firstName, const std::string &lastName, const std::string &nickname, const std::string &phoneNumber, const std::string &darkestSecret);
    ~Contact();

    // Getter methods
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickname() const;
    std::string getPhoneNumber() const;
    std::string getDarkestSecret() const;
    int getIndex()const;

    void setFirstName(const std::string &firstName);
    void setLastName(const std::string &lastName);
    void setNickname(const std::string &nickname);
    void setPhoneNumber(const std::string &phoneNumber);
    void setDarkestSecret(const std::string &darkestSecret);
    void setIndex(int index);
};

#endif
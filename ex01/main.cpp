#include "Phonebook.hpp"
#include <cctype>
#include <iostream>

bool	checknumbers(std::string index)
{
	for (int i = 0; i < index.length(); i++)
	{
		if (!std::isdigit(index[i]))
		{
			return (false);
		}
	}
	return (true);
}

std::string is_space(std::string &space)
{
	int	start;
	int	end;

	start = 0;
	end = space.size() - 1;
	while (start < space.size() && space[start] == ' ')
		start++;
	while (end >= start && space[end] == ' ')
		end--;
	return (space.substr(start, end - start + 1));
}

std::string skipin_space(std::string &space)
{
	int	i;

	i = 0;
	std::string ret;
	while (i < space.size())
	{
		while (i < space.size() && space[i] == ' ')
		{
			i++;
		}
		if (i < space.size())
		{
			ret += space[i];
			i++;
		}
	}
	return (ret);
}

void	handle_sigquit(int signal)
{
	std::cout << "\nCTRL + \\" <<  std::endl;
	exit(1);
}

int	main(void)
{
	Phonebook	phonebook;
	int			returnal;

	std::string cmd;
	std::string index;
	returnal = 0;
	signal(SIGQUIT, handle_sigquit);
	while (42)
	{
		std::cout << "Enter command: ";
		std::getline(std::cin, cmd);
		cmd = is_space(cmd);
		cmd = skipin_space(cmd);
		if (cmd == "ADD")
		{
			returnal = phonebook.addContact();
			if (returnal == 0)
				break ;
		}
		else if (cmd == "SEARCH" && returnal)
		{
			phonebook.displayContacts();
			std::cout << "Enter the index of the contact for more details: ";
			std::getline(std::cin, index);
			if (checknumbers(index) && !index.empty())
			{
				if (std::stoi(index) >= 0
					&& std::stoi(index) < phonebook.getContact())
					phonebook.searchContact(std::stoi(index));
				else
					std::cerr << "Index for contacts out of bounds !" << std::endl;
			}
			else
				std::cerr << "Index must be a number/positive value ! " << std::endl;
		}
		else if (cmd == "SEARCH" && !returnal)
			std::cout << "No contacts have been added !" << std::endl;
		else if (cmd == "EXIT")
			break ;
		else
		{
			if (std::cin.eof())
			{
				std::cout << "\nEnd of input detected. Exiting..." << std::endl;
				exit(1);
			}
			std::cout << "The command: '" << cmd << "' does not exist!" << std::endl;
			std::cout << "The commands are: ADD, SEARCH or EXIT " << std::endl;
		}
	}
	return (0);
}

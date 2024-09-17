#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <ostream>
#include <string>
#include <stdlib.h>
#include "../Colors.hpp"


const std::string	add_contact_info(const std::string &data)
{
	std::cout << NGREEN <<"Please enter the new contact " << data << " > " << RESET;
	std::string prompt;
	std::getline(std::cin, prompt);
	if(std::cin.eof())
		exit(1);
	if(data == "phone number")
		while(!only_digit_string(prompt))
		{
			std::cout << BIRED << "You need an only digit number > " << RESET;
			std::getline(std::cin, prompt);
			if(std::cin.eof())
				exit(1);
		}
	while(prompt.empty())
	{
		std::cout << BIRED << "Please enter regular " << data << " > " << RESET;
		std::getline(std::cin, prompt);
		if(std::cin.eof())
			exit(1);
	}
	return prompt;
}

void	add_contact_in_phonebook(PhoneBook &phonebook){
	Contact contact;
	contact.set_fname(add_contact_info("first name"));
	contact.set_lname(add_contact_info("last name"));
	contact.set_phone_number(add_contact_info("phone number"));
	contact.set_nickname(add_contact_info("nickname"));
	contact.set_darkest_secret(add_contact_info("darkest secret"));
	phonebook.set_contact_list(contact);
	std::cout << phonebook.get_contact_number() << std::endl;
	std::cout << NGREEN << "Contact " << NCYAN << contact.get_fname() << NGREEN << " added succesfully\n" << RESET;
}

void	print_welcome(bool welcome){
	if(welcome == true){
		std::cout << std::setw(40);
		std::cout << NCYAN "Welcome to the Phonebook\n";
	}
	std::cout << BLUE "- You can add a new contact using " NGREEN "ADD\n" RESET;
	std::cout << BLUE "- You can display all contact added using " NGREEN "SEARCH\n" RESET;
	std::cout << BLUE "- You can quit the phonebook using " NGREEN "EXIT\n" RESET;
}

int main() {
	PhoneBook phonebook;
	print_welcome(true);
	std::cout << NBLUE << "PhoneBook > " << RESET;
    for (std::string line; std::getline(std::cin, line);) {
		if(line == "ADD")
			add_contact_in_phonebook(phonebook);
		else if(line == "SEARCH")
		{
			phonebook.display_phonebook();
			phonebook.print_contact_infos();
		}
		else if(line == "EXIT"){
			std::cout << "bye bye\n";
			return (0);
		}
		else if(line == "")
			;
		else if(line == "HELP")
			print_welcome(0);
		else
			std::cout << RED "Invalid command, type" BIRED " HELP " RED "to see all commands\n" RESET;
		std::cout << NBLUE << "PhoneBook > " << RESET;
    }
    return 0;
}
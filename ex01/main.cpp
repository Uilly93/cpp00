#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>
#include "../Colors.hpp"

int	only_digit_string(std::string &prompt)
{
	for(int i = 0; prompt[i]; i++){
		if(isdigit(prompt[i])){
			return 1;
		}
	}
	return 0;
}

const std::string	add_contact_info(const std::string &data)
{
	std::cout << NGREEN <<"Please enter the new contact " << data << " > " << RESET;
	std::string prompt;
	std::getline(std::cin, prompt);
	if(data == "phone number")
		while(!only_digit_string(prompt))
		{
			std::cout << BIRED << "You need an only digit number > " << RESET;
			std::getline(std::cin, prompt);
		}
	while(prompt.empty())
	{
		std::cout << BIRED << "Please enter regular " << data << " > " << RESET;
		std::getline(std::cin, prompt);
	}
	return prompt;
}

void	add_contact_in_phonebook(PhoneBook phonebook){
	Contact contact;
	contact.set_phone_number(add_contact_info("phone number"));
	contact.set_fname(add_contact_info("first name"));
	contact.set_lname(add_contact_info("last name"));
	contact.set_nickname(add_contact_info("nickname"));
	contact.set_darkest_secret(add_contact_info("darkest secret"));
	phonebook.set_contact_list(contact);
}

int main() {

	// std::string line;
	// std::getline(std::cin, line)
	PhoneBook phonebook;
	std::cout << NBLUE << "PhoneBook > " << RESET;
    for (std::string line; std::getline(std::cin, line);) {
		if(line == "EXIT"){
			std::cout << "bye bye\n";
			return (0);
		}
		if(line == "ADD")
			add_contact_in_phonebook(phonebook);
		std::cout << NBLUE << "PhoneBook > " << RESET;
    }
    return 0;
}
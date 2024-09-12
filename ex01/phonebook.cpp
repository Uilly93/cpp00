#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>

PhoneBook::PhoneBook(){
	contact_number = 0;
}

const std::string	add_contact_info(const std::string &data)
{
	std::cout << "Please enter the new contact " << data << std::endl;
	std::string prompt;
	std::getline(std::cin, prompt);
	while(prompt.empty()){
		std::cout << "please enter regular first name";
		std::getline(std::cin, prompt);
	}
	return prompt;
}


int main() {

	// std::string line;
	// std::getline(std::cin, line)
	PhoneBook list;
    for (std::string line; std::getline(std::cin, line);) {
		if(line == "EXIT"){
			std::cout << "bye bye\n";
			return (0);
		}
		if(line == "ADD"){
			Contact contact;
			contact.set_fname(add_contact_info("first name"));
			contact.set_lname(add_contact_info("last name"));
			contact.set_nickname(add_contact_info("nickname"));
			contact.set_phone_number(add_contact_info("phone number"));
			contact.set_darkest_secret(add_contact_info("darkest secret"));
			list[]
		}
        // std::cout << line << std::endl;
    }
    return 0;
}
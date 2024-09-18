#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include "../Colors.hpp"

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
			phonebook.add_contact_in_phonebook(phonebook);
		else if(line == "SEARCH")
		{
			if(phonebook.display_phonebook())
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
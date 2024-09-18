#include "PhoneBook.hpp"
#include "../Colors.hpp"

PhoneBook::PhoneBook(){
	_contact_number = 0;
	_index = 0;
}

PhoneBook::~PhoneBook (){
	;
}

std::size_t PhoneBook::get_contact_number (){
	return _contact_number;
}

const std::string	add_contact_info(const std::string &data){
	std::cout << NGREEN <<"Please enter the new contact " << data << " > " << RESET;
	std::string prompt;
	std::getline(std::cin, prompt);
	if(std::cin.eof())
		std::exit(1);
	if(data == "phone number")
		while(!only_digit_string(prompt))
		{
			std::cout << BIRED << "You need an only digit number > " << RESET;
			std::getline(std::cin, prompt);
			if(std::cin.eof())
				std::exit(1);
		}
	while(prompt.empty())
	{
		std::cout << BIRED << "Please enter regular " << data << " > " << RESET;
		std::getline(std::cin, prompt);
		if(std::cin.eof())
			std::exit(1);
	}
	return prompt;
}

void	PhoneBook::add_contact_in_phonebook(PhoneBook &phonebook){
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

void PhoneBook::set_contact_list(Contact &contact){

	if(_index == 8)
		_index = 0;
	_contacts[_index] = contact;
	_contact_number += 1;
	_index += 1;
	if(_contact_number > 8)
		_contact_number = 8;
}

std::string	print_data(std::string data)
{
	if(data.size() > 10)
	{
		data.resize(10);
		data[9] = '.';
	}
	return data;
}

void	PhoneBook::display_contact(std::size_t index){
	std::cout << std::setw(54);
	std::cout << "*-------------------------------------------*" << std::endl;
	std::cout << std::setw(10);
	std::cout << "|";
	std::cout << std::setw(10);
	std::cout << index;
	std::cout << "|";
	std::cout << std::setw(10);
	std::cout << print_data(_contacts[index].get_fname());
	std::cout << "|";
	std::cout << std::setw(10);
	std::cout << print_data(_contacts[index].get_lname());
	std::cout << "|";
	std::cout << std::setw(10);
	std::cout << print_data(_contacts[index].get_nickname());
	std::cout << "|" << std::endl;
	std::cout << std::setw(54);
	std::cout << "*-------------------------------------------*" << std::endl;
}

int PhoneBook::display_phonebook(){
	if(_contact_number > 0)
	{
		std::cout << std::setw(48) << NCYAN "PHONEBOOK\n" RESET;
		std::cout << std::setw(55) << NPURPLE BLINK "Select a contact\n" RESET;
		std::cout << std::setw(21);
		std::cout << BG_BLUE "|" RESET;
		std::cout << std::setw(21);
		std::cout << BG_BLUE "     index" RESET;
		std::cout << BG_BLUE "|" RESET;
		std::cout << std::setw(21);
		std::cout << BG_BLUE "First Name" RESET;
		std::cout << BG_BLUE "|" RESET;
		std::cout << std::setw(21);
		std::cout << BG_BLUE " Last Name" RESET;
		std::cout << BG_BLUE "|" RESET;
		std::cout << std::setw(21);
		std::cout << BG_BLUE "  Nickname" RESET;
		std::cout << BG_BLUE "|" RESET << std::endl;
		for(std::size_t i = 0; i < _contact_number; i++)
			display_contact(i);
		std::cout << std::setw(55) << NPURPLE BLINK "Select a contact\n" RESET;
		return (1);
	}
	else
	{
		std::cout << NRED "No contact in the phonebook\n" RESET;
		return (0);
	}
}

int	only_digit_string(std::string &prompt)
{
	for(int i = 0; prompt[i]; i++){
		if(isdigit(prompt[i])){
			return 1;
		}
	}
	return 0;
}

std::size_t	PhoneBook::select_contact(){
	std::cout << NGREEN "Select the contact index you want display > " RESET;
	std::string prompt;
	while(1)
	{
		std::getline(std::cin, prompt);
		if(std::cin.eof())
			std::exit(1);
		if(prompt.size() > 1)
		{
			std::cout << BIRED << "Invalid index > " << RESET;
			continue ;
		}
		std::size_t index = std::atoi(prompt.c_str());
		if(prompt.empty() || !only_digit_string(prompt))
		{
			std::cout << BIRED << "Invalid index > " << RESET;
			continue ;
		}
		if(index > 7 || index < 0 || index > get_contact_number() - 1)
		{
			std::cout << BIRED << "Invalid index > " << RESET;
			continue ;
		}
		return (index);
	}
}

void	PhoneBook::print_contact_infos(){
	std::size_t index = select_contact();
	std::cout << GREEN "Contact index " NGREEN << index << GREEN " First Name is: " NGREEN << _contacts[index].get_fname() << RESET << std::endl;
	std::cout << GREEN "Contact index " NGREEN << index << GREEN " Last Name is: " NGREEN << _contacts[index].get_lname() << RESET << std::endl;
	std::cout << GREEN "Contact index " NGREEN << index << GREEN " Phone Number is: " NGREEN << _contacts[index].get_phone_number() << RESET << std::endl;
	std::cout << GREEN "Contact index " NGREEN << index << GREEN " Nickname is: " NGREEN << _contacts[index].get_nickname() << RESET << std::endl;
	std::cout << GREEN "Contact index " NGREEN << index << GREEN " Darkest secret is: " NGREEN << _contacts[index].get_darkest_secret() << RESET << std::endl;
}

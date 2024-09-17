#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "../Colors.hpp"
#include <string>

PhoneBook::PhoneBook(){
	_contact_number = 0;
	_index = 0;
}

PhoneBook::~PhoneBook (){
	;
	// std::cout << "Destructor Called\n";
}

std::size_t PhoneBook::get_contact_number (){
	return _contact_number;
}

// void PhoneBook::set_contact_number(std::size_t number){
// 	_contact_number = number;
// }

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

void PhoneBook::display_phonebook(){
	if(_contact_number > 0)
	{
		std::cout << std::setw(48) << NCYAN "PHONEBOOK\n" RESET;
		std::cout << std::setw(59) << NPURPLE "\033[5mSelect a contact\033[0m\n" RESET;
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
		std::cout << std::setw(59) << NPURPLE "\033[5mSelect a contact\033[0m\n" RESET;
	}
	else
		std::cout << NRED "No contact in the phonebook\n" RESET;
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
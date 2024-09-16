#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <cstddef>
#include <iostream>
#include <iterator>
#include <string>

PhoneBook::PhoneBook(){
	_contact_number = 0;
}

PhoneBook::~PhoneBook (){
	;
	// std::cout << "Destructor Called\n";
}

std::size_t PhoneBook::get_contact_number (){
	return _contact_number;
}

void PhoneBook::set_contact_number(std::size_t number){
	_contact_number = number;
}

void PhoneBook::set_contact_list(Contact &contact){

	if(_contact_number == 7)
		_contact_number = 0;
	_contacts[_contact_number] = contact;
	_contact_number += 1;
}

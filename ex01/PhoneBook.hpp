# ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

#include <cstddef>
#include <iostream>
#include "Contact.hpp"

class PhoneBook{
	public:
	PhoneBook();
	~PhoneBook();
	void set_contact_number(std::size_t number);
	std::size_t get_contact_number();
	std::size_t set_contact_number();
	void set_contact_list(Contact &contact);
	// Contact
	private:
	Contact 	_contacts[8];
	std::size_t _contact_number;
};

# endif
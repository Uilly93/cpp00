# ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

#include <cstddef>
#include <iostream>
#include "Contact.hpp"

class PhoneBook{
	public:
	PhoneBook();
	~PhoneBook();
	const std::size_t get_contact_number() const;
	// Contact
	void set_contact_number(std::size_t number);
	private:
	Contact 	_contacts[8];
	std::size_t _contact_number;
};

# endif
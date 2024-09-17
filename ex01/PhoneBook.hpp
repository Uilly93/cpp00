# ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

#include <cstddef>
#include <iostream>
#include "Contact.hpp"

int	only_digit_string(std::string &prompt);

class PhoneBook{
	public:
	PhoneBook();
	~PhoneBook();
	// Contact
	void		set_contact_list(Contact &contact);
	void 		display_phonebook();
	void 		set_contact_number(std::size_t number);
	std::size_t	get_contact_number();
	std::size_t	set_contact_number();
	void		display_contact(std::size_t index);
	std::size_t	select_contact();
	void		print_contact_infos();
	private:
	// void	PhoneBook::search_contact(Contact &contact);
	Contact 	_contacts[8];
	std::size_t	_index;
	std::size_t _contact_number;
};

# endif
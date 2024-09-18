# ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

#include <cstdlib>
#include <iomanip>
#include <cstddef>
#include <iostream>
#include "Contact.hpp"

int	only_digit_string(std::string &prompt);

class PhoneBook{
	public:
	PhoneBook();
	~PhoneBook();
	void		add_contact_in_phonebook(PhoneBook &phonebook);
	void		print_contact_infos();
	int			display_phonebook();
	private:
	void		display_contact(std::size_t index);
	void		set_contact_list(Contact &contact);
	void 		set_contact_number(std::size_t number);
	std::size_t	get_contact_number();
	std::size_t	set_contact_number();
	std::size_t	select_contact();
	Contact 	_contacts[8];
	std::size_t	_index;
	std::size_t _contact_number;
};

# endif
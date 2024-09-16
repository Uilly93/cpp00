# ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class Contact{
	public:
	Contact ();
	~Contact ();
	const std::string &get_fname() const;
	const std::string &get_lname() const;
	const std::string &get_nickname() const;
	const std::string &get_phone_number() const;
	const std::string &get_darkest_secret() const;
	void set_fname(const std::string &fname);
	void set_lname(const std::string &lname);
	void set_nickname(const std::string &nickname);
	void set_phone_number(const std::string &phone_number);
	void set_darkest_secret(const std::string &darkest_secret);
	private:
	std::string _first_name;
	std::string _last_name;
	std::string _nickname;
	std::string _phone_number;
	std::string _darkest_secret;
};

# endif
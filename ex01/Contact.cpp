#include "Contact.hpp"
#include <iostream>

	Contact::Contact (){
		_first_name = "";
		_last_name = "";
		_nickname = "";
		_phone_number = "";
		_darkest_secret = "";
		std::cout << "Constructor Called\n";
	}

	Contact::Contact(std::string first, std::string last,
		std::string nick, std::string phone, std::string secret){
		_first_name = "";
		_last_name = "";
		_nickname = "";
		_phone_number = "";
		_darkest_secret = "";
		std::cout << "Constructor Called\n";
	}
	Contact::~Contact (){
		std::cout << "Destructor Called\n";
	}
	const std::string &Contact::get_fname() const{
		return _first_name;
	}
	const std::string &Contact::get_lname() const{
		return _last_name;
	}
	const std::string &Contact::get_nickname() const{
		return _nickname;
	}
	const std::string &Contact::get_phone_number() const{
		return _phone_number;
	}
	const std::string &Contact::get_darkest_secret() const{
		return _darkest_secret;
	}
	void Contact::set_fname(const std::string &fname){
		_first_name = fname;
	}
	void Contact::set_lname(const std::string &lname){
		_last_name = lname;
	}
	void Contact::set_nickname(const std::string &nickname){
		_nickname = nickname;
	}
	void Contact::set_phone_number(const std::string &phone_number){
		_phone_number = phone_number;
	}
	void Contact::set_darkest_secret(const std::string &darkest_secret){
		_darkest_secret = darkest_secret;
	}
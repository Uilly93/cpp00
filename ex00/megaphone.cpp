#include <iostream>
#include <cctype>


int main(int ac, char **av){

	int i = 0;
	int j = 1;


	if(ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return 0;
	}
	while(av[j])
	{
		i = 0;
		while(av[j][i])
		{
			std::cout << (char)std::toupper(av[j][i]);
			i++;
		}
		std::cout << " ";
		j++;
	}
	std::cout << std::endl;
	return 0;
}

// int main(){
// 	Test example;
// 	Test example2("Gangplank");

// 	std::cout << "My name is : "<< example.getName() << std::endl;
// 	std::cout << "My name is : "<< example2.getName() << std::endl;

// 	example.setName("hello");
// 	std::cout << "My name is : "<< example.getName() << std::endl;
// }

// Test::Test() : _name("") {
// 	std::cout << "Consctructor called" << std::endl;
// };

// Test::Test(const std::string &name) : _name(name) {
// 	std::cout << "Parametrized Consctructor called" << std::endl;
// 	this->_name = name;
// }

// Test::~Test(){
// 	std::cout << "Destructor called" << std::endl;
// }

// Test::Test(const Test &other) : _name(other._name) {
// 	_name = other._name;
// 	std::cout << "Copy constructor called" << std::endl;
// }

// Test& Test::operator=(const Test &other){
// 	if (this != &other) {
// 		_name = other._name;
// 	}
// 	return *this;
// }

// void Test::setName(const std::string &name) {
// 	_name = name;
// }

// const std::string &Test::getName() const {
// 	return _name;
// }

// cstd::cout << CYAN << "greikgerogr" << RESET << std::endl;

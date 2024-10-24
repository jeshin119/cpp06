#include <iostream>
#include <string>
#include <iomanip>
#include "ScalarConverter.hpp"

int main(int ac, char** av){
	if (ac != 2){
		std::cerr<< "\e[0;31mError: argc\e[0;m\n";
		return (1);
	}
	ScalarConverter::converter(std::string(av[1]));
}
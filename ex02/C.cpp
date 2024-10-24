#include <iostream>
#include "C.hpp"

std::string	C::operator+(const std::string& str) const{
	return ("C" + str);
}
#include <string>
#include "A.hpp"

std::string	A::operator+(const std::string& str) const{
	return ("A" + str);
}
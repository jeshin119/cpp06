#include <ostream>
#include "B.hpp"

std::string	B::operator+(const std::string& str) const{
	return ("B" + str);
}
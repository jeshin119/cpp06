#ifndef __A_H__
#define __A_H__

#include <ostream>
#include "Base.hpp"

class	A: public Base{
	public:
		virtual ~A(){};

		std::string	operator+(const std::string& str) const;
};
#endif
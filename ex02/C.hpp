#ifndef __C_H__
#define __C_H__

#include <ostream>
#include "Base.hpp"

class	C: public Base{
	public:
		virtual ~C(){};
		std::string	operator+(const std::string& str) const;

};
#endif
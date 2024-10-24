#ifndef __B_H__
#define __B_H__

#include <ostream>
#include "Base.hpp"

class	B: public Base{
	public:
		virtual ~B(){};
		std::string	operator+(const std::string& str) const;
};

#endif
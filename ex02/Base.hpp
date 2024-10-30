#ifndef __BASE_H__
#define __BASE_H__

#include <string>
#include <ostream>

class Base{
	public:
		virtual ~Base(){};
};

class	A: public Base{
	public:
		virtual ~A(){};

		std::string	operator+(const std::string& str) const{
			return ("A" + str);
		}
};

class	B: public Base{
	public:
		virtual ~B(){};
		std::string	operator+(const std::string& str) const{
			return ("B" + str);
		}
};

class	C: public Base{
	public:
		virtual ~C(){};
		std::string	operator+(const std::string& str) const{
			return ("C" + str);
		}
};
#endif
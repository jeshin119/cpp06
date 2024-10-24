#include <iostream>
#include "Base.hpp"

int main(){
	Base	base;
	Base*	Derived = base.generate();

	base.identify(Derived);
	base.identify(*Derived);
	delete Derived;
}
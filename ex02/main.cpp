#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"

Base*	generate(void);
void	identify(Base* p);
void	identify(Base& p);

int main(){
	srand(time(0));

	Base*	Derived = generate();

	identify(Derived);
	identify(*Derived);

	delete Derived;
}

Base*	generate(void){
	enum classTable{
		AClass=0,BClass=1,CClass=2
	};
	int i = rand()%3;
	switch(i){
		case(AClass):
			return (static_cast<Base*>(new A));
		case(BClass):
			return (static_cast<Base*>(new B));
		case(CClass):
			return (static_cast<Base*>(new C));
	}
	return (NULL);
}

void	identify(Base* p){
	if (dynamic_cast<A*>(p)){
		std::cout<<"Actual pointer type is A\n";
	}
	if (dynamic_cast<B*>(p)){
		std::cout<<"Actual pointer type is B\n";
	}
	if (dynamic_cast<C*>(p)){
		std::cout<<"Actual pointer type is C\n";
	}
}

void	identify(Base& p){
	std::string acutalType;
	try{
		acutalType = dynamic_cast<A&>(p) + "\n";
		std::cout<< "Acutal reference type is " + acutalType;
	}catch(std::exception& e){
	}
	try{
		acutalType = dynamic_cast<B&>(p) + "\n";
		std::cout<< "Acutal reference type is " + acutalType;
	}catch(std::exception& e){}
	try{
		acutalType = dynamic_cast<C&>(p) + "\n";
		std::cout<< "Acutal reference type is " + acutalType;
	}catch(std::exception& e){
	}
}
#include <string>
#include <iostream>
#include "ScalarConverter.hpp"

//static members
static std::string sTypes[]={"Char","Int","Float","Double"};
static std::string sPseudoLiteralsOfFloat[]={"+inff","-inff","nanf"};
static std::string sPseudoLiteralsOfDouble[]={"+inf","-inf","nan"};
static std::string sType;
static std::string sPseudoLiteral;

//othodox canonical form
ScalarConverter::ScalarConverter(){}
ScalarConverter::~ScalarConverter(){}
ScalarConverter::ScalarConverter(const ScalarConverter& rhs){
	if (&rhs == this){;}
}
ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& rhs){
	if (&rhs == this){
		return (*this);
	}
	return (*this);
}
ScalarConverter::InvaildInputException::~InvaildInputException()throw(){};

//static function
static void	checkInput(std::string input){
	//check input is empty
	if (input.size()==0){
		throw (ScalarConverter::InvaildInputException("\e[0;31mError: Empty input\e[0;m\n"));
	}
	//check input is char
	if (input.size()==1){
		sType = "char";
		return ;
	}
	//check input is pseudo literals of float
	for(int i=0;i<3;i++){
		if (input == sPseudoLiteralsOfFloat[i]){
			sType = "float";
			sPseudoLiteral = sPseudoLiteralsOfFloat[i];
			return ;
		}
	}
	//check input is pseudo literals of float
	for(int i=0;i<3;i++){
		if (input == sPseudoLiteralsOfDouble[i]){
			sType = "double";
			sPseudoLiteral = sPseudoLiteralsOfDouble[i];
			return ;
		}
	}
	//check input is string e.g. "test", "12asdf", "41.09.", "11.0ff", "11f", "+42", "-42-"
	int dotCnt=0;
	int fCnt=0;
	int	signCnt=0;
	size_t i=-1;
	size_t	size=input.size();

	if (input[0]=='-' || input [0]=='+')
		i++;signCnt++;
	while (++i < size){
		if (isdigit(input[i]))
			continue;
		switch(input[i]){
			case('.'):
				dotCnt++;
				if (i == 0 || (signCnt && i == 1) || (i == size-1) || (dotCnt > 1))
					throw (ScalarConverter::InvaildInputException("\e[0;31mError: Invaild input\e[0;m\n"));
			case('f'):
				if (i != size-1)
					throw (ScalarConverter::InvaildInputException("\e[0;31mError: Invaild input\e[0;m\n"));
				fCnt++;
			default:
				throw (ScalarConverter::InvaildInputException("\e[0;31mError: Invaild input\e[0;m\n"));
		}
	}
	if (fCnt && !dotCnt)
		throw (ScalarConverter::InvaildInputException("\e[0;31mError: Invaild input\e[0;m\n"));
	if (fCnt)
		sType="float";
	else if (dotCnt)
		sType="double";
	else
		sType="int";
}

void	ScalarConverter::converter(std::string input){
	try{
		checkInput(input);
	}catch(std::exception& e){
		std::cerr<<e.what(); return ;
	}
	std::cout<<sType<<"\n";
	std::cout<<sPseudoLiteral<<"\n";
}
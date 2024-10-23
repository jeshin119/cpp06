#include <string>
#include <iostream>
#include "ScalarConverter.hpp"

static std::string types[]={"Char","Int","Float","Double"};
static std::string pseudoLiterals[]={"+inff","-inff","nanf","+inf","-inf","nan"};
static std::string _type;
static std::string _pseudoLiteral;

ScalarConverter::ScalarConverter(){}
ScalarConverter::~ScalarConverter(){}
ScalarConverter::ScalarConverter(const ScalarConverter& rhs){
	if (&rhs == this){
		;
	}
}
ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& rhs){
	if (&rhs == this){
		return (*this);
	}
	return (*this);
}

static void	checkVaildInput(std::string input){
	//check input is empty
	if (input.size()==0){
		throw (ScalarConverter::InvaildInputException("\e[0;31mError: Empty input\e[0;m\n"));
	}
	//check input is pseudo literals
	for(int i=0;i<6;i++){
		if (input == pseudoLiterals[i])
			return ;
	}
	//check input is string e.g. "test", "12asdf", "41.09.", "11.0ff", "11f"
	int dotCnt=0;
	int fCnt=0;
	for (int i=0;i<input.size();i++){
		if (!isdigit(input[i]))
	}
	int start = 0;
	int end =0;
	do{
		end = input.find(".", start);
		start = end + 1;
		dotCnt++;
	} while (end != std::string::npos);
	if (dotCnt>1){
		throw (ScalarConverter::InvaildInputException("\e[0;31mError: Invaild input\e[0;m\n"));
	}

	start = 0;
	end =0;
	do{
		end = input.find(".", start);
		start = end + 1;
		dotCnt++;
	} while (end != std::string::npos);
	if (fmarkCnt>1){
		throw (ScalarConverter::InvaildInputException("\e[0;31mError: Invaild input\e[0;m\n"));
	}
}

static std::string getType(std::string input){
	if (input.size()==1){
		return ("Char");
	}
	int i;
}

static void	converter(std::string input){
	int type = -1;

	try{
		checkVaildInput(input);
	}catch(std::exception& e){
		std::cerr<<e.what();
		return ;
	}
}
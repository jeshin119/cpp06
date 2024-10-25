#include <string>
#include <iostream>
#include "ScalarConverter.hpp"
#include <iomanip>

typedef long long ll;

//static members
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
		sType="char";
		if (isdigit(input[0])){
			sType = "int";
		}
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
	size_t	i=-1;
	size_t	size=input.size();

	if (input[0]=='-' || input [0]=='+'){
		i++;signCnt++;
	}
	while (++i < size){
		if (isdigit(input[i]))
			continue;
		switch(input[i]){
			case('.'):
				dotCnt++;
				if (i == 0 || (signCnt && i == 1) || (i == size-1) || (dotCnt > 1))
					throw (ScalarConverter::InvaildInputException("\e[0;31mError: Invaild input, dot\e[0;m\n"));
				break;
			case('f'):
				fCnt++;
				if (i != size-1)
					throw (ScalarConverter::InvaildInputException("\e[0;31mError: Invaild input, f\e[0;m\n"));
				break;
			default:
				throw (ScalarConverter::InvaildInputException("\e[0;31mError: Invaild input, text\e[0;m\n"));
		}
	}
	if (fCnt && !dotCnt)
		throw (ScalarConverter::InvaildInputException("\e[0;31mError: Invaild input, no dot float\e[0;m\n"));
	if (!dotCnt && input[0] == '0')
		throw (ScalarConverter::InvaildInputException("\e[0;31mError: Invaild input, not decimal\e[0;m\n"));
	if (fCnt)
		sType="float";
	else if (dotCnt)
		sType="double";
	else
		sType="int";
}
void	ft_stoc(std::string& input){
	//char
	if (isprint(input[0]))
		std::cout<<"char: "<<static_cast<char>(input[0])<<"\n";
	else
		std::cout<<"char: Non displayable\n";
	//int
	std::cout<<"int: "<<static_cast<int>(input[0])<<"\n";
	//float
	std::cout<<std::fixed<<std::setprecision(1);
	std::cout<<"float: "<<static_cast<float>(input[0])<<"f"<<"\n";
	//double
	std::cout<<"double: "<<static_cast<double>(input[0])<<"\n";
}
void	ft_stoi(std::string& input){
	ll tmp;
	//convert string to long long type
	try{
		tmp = std::stoll(input);
	}catch(std::exception& e){
		std::cerr<<"\e[0;31mError: "<<e.what()<<"\e[0;m\n";
		return ;
	}
	//char
	if (tmp != static_cast<char>(tmp))
		std::cout<<"char: Overflow\n";
	else if (!isprint(tmp))
		std::cout<<"char: Non displayable\n";
	else
		std::cout<<"char: "<<static_cast<char>(tmp)<<"\n";
	//int
	if (tmp != static_cast<int>(tmp))
		std::cout<<"int: Overflow\n";
	else
		std::cout<<"int: "<<static_cast<int>(tmp)<<"\n";
	//float
	std::cout<<std::fixed<<std::setprecision(1);
	std::cout<<"float: "<<static_cast<float>(tmp)<<"f"<<"\n";
	//double
	std::cout<<"double: "<<static_cast<double>(tmp)<<"\n";
}
void	ft_stof(std::string input){
	double tmp;
	//convert string to long long type
	try{
		tmp = std::stod(input);
	}catch(std::exception& e){
		std::cerr<<"\e[0;31mError: "<<e.what()<<"\e[0;m\n";
		return ;
	}

	//char
	if (static_cast<int>(tmp) != static_cast<char>(tmp)){
		std::cout<<"char: Overflow\n";
	}else if (!isprint(tmp)){
		std::cout<<"char: Non displayable\n";
	}else{
		std::cout<<"char: "<<static_cast<char>(tmp)<<"\n";
	}
	//int
	if (static_cast<long long>(tmp) != static_cast<int>(tmp)){
		std::cout<<"int: Overflow\n";
	}else{
		std::cout<<"int: "<<static_cast<int>(tmp)<<"\n";
	}
	std::cout<<std::fixed<<std::setprecision(1);
	std::cout<<"float: "<<static_cast<float>(tmp)<<"f"<<"\n";
	std::cout<<"double: "<<static_cast<double>(tmp)<<"\n";
}
void	ft_stod(std::string input){
	double tmp;

	//convert string to long long type
	try{
		tmp = std::stod(input);
	}catch(std::exception& e){
		std::cerr<<"\e[0;31mError: "<<e.what()<<"\e[0;m\n";
		return ;
	}

	//char
	if (static_cast<int>(tmp) != static_cast<char>(tmp))
		std::cout<<"char: Overflow\n";
	else if (!isprint(static_cast<char>(tmp)))
		std::cout<<"char: Non displayable\n";
	else
		std::cout<<"char: "<<static_cast<char>(tmp)<<"\n";
	//int
	if (static_cast<long long>(tmp) != static_cast<int>(tmp))
		std::cout<<"int: Overflow\n";
	else
		std::cout<<"int: "<<static_cast<int>(tmp)<<"\n";
	//float
	std::cout<<std::fixed<<std::setprecision(1);
	std::cout<<"float: "<<static_cast<float>(tmp)<<"f"<<"\n";
	//double
	std::cout<<"double: "<<static_cast<double>(tmp)<<"\n";
}

void	ScalarConverter::converter(std::string input){
	// input check
	try{
		checkInput(input);
	}catch(std::exception& e){
		std::cerr<<e.what();
		return ;
	}
	//handle pseudo literal
	if (sPseudoLiteral.size()){
		std::cout<<"char: impossible\n";
		std::cout<<"int: impossible\n";
		
		if (sType == "float"){ //in case of float pseudo literal
			std::cout<<"float: "<<sPseudoLiteral<<"\n";
			sPseudoLiteral.pop_back();
			std::cout<<"double: "<<sPseudoLiteral<<"\n";
		}
		else{ //in case of double pseudo literal
			std::cout<<"float: "<<sPseudoLiteral+"f"<<"\n";
			std::cout<<"double: "<<sPseudoLiteral<<"\n";
		}
		return ;
	}
	// get type in type table
	std::string typeTable[]={"char","int","float","double"};
	int pos;
	for(pos=0;pos<4;pos++){
		if (sType == typeTable[pos]) break;
	}
	enum eTypeTable{
		eChar=0,eInt=1,eFloat=2,eDouble=3
	};
	// convert input to suitable type
	switch(pos){
		case(eChar):
			ft_stoc(input);
			break;
		case(eInt):
			ft_stoi(input);
			break;
		case(eFloat):
			ft_stof(input);
			break;
		case(eDouble):
			ft_stod(input);
			break;
	}
}
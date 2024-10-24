#ifndef __SCALARCONVERTER_H__
#define __SCALARCONVERTER_H__

#include <string>
#include <exception>

class ScalarConverter{
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter& rhs);

		ScalarConverter&	operator=(const ScalarConverter& rhs);

	public:
		static void	converter(std::string input);

		class	InvaildInputException:public std::exception{
			private:
				std::string _message;
			public:
				virtual	~InvaildInputException() throw();
						InvaildInputException(const std::string& msg):_message(msg){}
				const char* what() const throw(){
					return (_message.c_str());
				}
		};
};
#endif
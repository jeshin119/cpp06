#include "Data.hpp"

Data::Data():_data(0){}
Data::Data(int data): _data(data){}
Data::~Data(){}
Data::Data(const Data& rhs): _data(rhs._data){}

Data&	Data::operator=(const Data& rhs){
	if (&rhs == this){
		return (*this);
	}
	_data = rhs._data;
	return (*this);
}
#include <iostream>
#include <cstdint>
#include "Data.hpp"
#include "Serializer.hpp"

int main(){
	Data		originData;

	std::cout<< &originData<<"\n";
	std::cout<< Serializer::deserialize(Serializer::serialize(&originData));
}
#include <iostream>
#include <fstream>
#include "Data.hpp"
#include "Serializer.hpp"

int main()
{
	Data* data = new Data;
	data->id = 42;
	data->name = "Data";
	std::cout << data << std::endl;
	{
		std::ofstream	output;
		std::ifstream	input;
		std::string line;
		uintptr_t serializedData  = Serializer::serialize(data);
		output.open("deneme");
		if (!output.good())
			return (std::cout << "file could not be opened" << std::endl, 1);
		output << serializedData << std::endl;
		output.close();
		input.open("deneme");
		if (!input.good()) {
			std::cout << "File could not be opened for reading" << std::endl;
			return 1;
		}
		uintptr_t a;
		input >> a;
		input.close();
		Data* deserializedData = Serializer::deserialize(a);

		std::cout << deserializedData->id << " " << deserializedData->name << std::endl;
		std::cout << deserializedData << std::endl;
	}


	/*uintptr_t serializedData  = Serializer::serialize(data);
	std::cout << serializedData << std::endl;

	Data* deserializedData = Serializer::deserialize(serializedData);
	std::cout << deserializedData->id << " " << deserializedData->name << std::endl;

	delete data;*/

	return 0;
}

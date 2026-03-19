#include <iostream>
#include "Data.hpp"
#include "Serializer.hpp"

int main() {

	Data *data = new Data;
	data->name = "test_name";
	data->lasName = "test_lastname";
	data->age = 42;

	uintptr_t raw = Serializer::serialize(data);
	Data *serialized = Serializer::deserialize(raw);

	std::cout << serialized->name << std::endl;
	std::cout << serialized->lasName << std::endl;
	std::cout << serialized->age << std::endl;

	delete data;
}

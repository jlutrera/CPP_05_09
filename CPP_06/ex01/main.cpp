#include "serial.hpp"

int main()
{
	Serial serial;
	Data *data;
	Data *data2;

	data = new Data;
	data->raw = 42;
	std::cout << "data->raw = " << data->raw << std::endl;
	serial.serialize(data);
	std::cout << "serial.getSerial() = " << serial.getSerial() << std::endl;
	data2 = serial.deserialize(serial.getSerial());
	std::cout << "data2->raw = " << data2->raw << std::endl;
	delete data;
	delete data2;

	return (0);
}
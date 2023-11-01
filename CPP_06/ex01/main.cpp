# include "serial.hpp"

int main()
{
	Data 		*data = new Data;
	uintptr_t	serial;
	Data 		*data2;

	data->name = "John Doe";
	data->age = 42;
	std::cout << "data->name = " << data->name << std::endl;
	std::cout << "data->age = " << data->age << std::endl;

	serial = serialize(data);
	std::cout << "\nserial = 0x";
	std::cout << std::hex << serial << std::dec << std::endl;
	
	data2 = deserialize(serial);
	std::cout << "\ndata2->name = " << data2->name << std::endl;
	std::cout << "data2->age = " << data2->age << std::endl;

	delete data;
	return (0);
}

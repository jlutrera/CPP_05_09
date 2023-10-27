#include "serial.hpp"

Serial::Serial() : _serial(0)
{
}

Serial::~Serial()
{
}

Serial::Serial(const Serial &copy)
{
	*this = copy;
}

Serial &Serial::operator=(const Serial &copy)
{
	if (this != &copy)
		_serial = copy._serial;
	return (*this);
}

uintptr_t Serial::getSerial() const
{
	return (_serial);
}

uintptr_t Serial::serialize(Data *ptr)
{
	_serial = reinterpret_cast<uintptr_t>(ptr->raw);
	return (_serial);
}

Data *Serial::deserialize(uintptr_t raw)
{
	Data *data = new Data;

	data->raw = raw;
	return (reinterpret_cast<Data *>(data));
}

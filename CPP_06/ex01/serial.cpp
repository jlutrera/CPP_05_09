#include "serial.hpp"

uintptr_t serialize(Data *data)
{
	return (reinterpret_cast<uintptr_t>(data));
}

Data *deserialize(uintptr_t ptr)
{
	return (reinterpret_cast<Data *>(ptr));
}

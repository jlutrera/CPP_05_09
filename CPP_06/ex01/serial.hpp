#ifndef SERIAL_HPP
# define SERIAL_HPP

# include <iostream>
# include <stdint.h>

struct Data
{
	std::string name;
	int 		age;
};

uintptr_t	serialize(Data *data);
Data 		*deserialize(uintptr_t ptr);

#endif

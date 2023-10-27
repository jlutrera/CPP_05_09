#ifndef SERIAL_HPP
# define SERIAL_HPP

# include <iostream>

typedef unsigned int uintptr_t;

struct Data
{
	uintptr_t raw;
};

class Serial
{
	private:
		uintptr_t _serial;
	public:
		Serial(void);
		Serial(const Serial &copy);
		~Serial(void);
		Serial &operator=(const Serial &copy);
		uintptr_t getSerial(void) const;

		uintptr_t serialize(Data *ptr);
		Data *deserialize(uintptr_t raw);
};


#endif
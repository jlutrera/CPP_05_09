#include "convert.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Wrong number of arguments" << std::endl;
		return (1);
	}
	Convert conv(argv[1]);
	conv.DetectLiteral(argv[1]);
	conv.display(argv[1]);
	
	return (0);
}

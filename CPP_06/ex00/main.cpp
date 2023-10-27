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
	if (conv.getType() == "char")
		conv.IsChar(conv.getChar());
	else if (conv.getType() == "double" ||
			 conv.getType() == "int" ||
			 conv.getType() == "float")
		conv.IsNumber(conv.getNumber());
	else if (conv.getType() == "special")
		conv.IsSpecial(argv[1]);
	else
		conv.IsImpossible();
	return (0);
}

NAME	= 	iter
#Flags
CC		= 	c++
CFLAGS	= 	-Wall -Wextra -Werror -std=c++98
RM		= 	rm -rf

#Files
SRC		=	main.cpp
HEADER	=	iter.hpp
OBJ		= 	$(SRC:.cpp=.o)

#Colors:
GREEN	=	\e[92;5;118m
YELLOW	=	\e[93;5;226m
GRAY	=	\e[33;2;37m
RESET	=	\e[0m
CURSIVE	=	\e[33;3m

#Rules
all		: 	$(NAME)

%.o		:	%.cpp $(HEADER)
			printf "$(CURSIVE)$(GRAY) 	- Compiling $@... $(RESET)\n"
			$(CC) $(CFLAGS) -c $< -o $@

$(NAME)	: 	$(OBJ)
			printf "$(CURSIVE)$(GRAY) 	- Linking $(NAME)... $(RESET)\n"
			$(CC) $(CFLAGS) $^ -o $(NAME)
			printf "$(GREEN)    - Executable ready.\n$(RESET)"

clean	:
			$(RM) $(OBJ)
			printf "$(YELLOW)    - Object removed.$(RESET)\n"

fclean	:	clean
			$(RM) $(NAME)
			printf "$(YELLOW)    - Executable removed.$(RESET)\n"

re		: 	clean all

.PHONY	: 	all clean re fclean

.SILENT	: 	clean fclean all $(NAME) $(OBJ)
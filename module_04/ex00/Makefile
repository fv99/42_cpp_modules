CC			=	c++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98 -pedantic -fsanitize=address -g
NAME		=	animals
SRCS		=	main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp
RM			=	rm -f

YELLOW		=	\033[0;33m;
GREEN		=	\033[0;32m
RESET		=	\033[0m

all: $(NAME)

$(NAME): $(SRCS)
	@echo "$(YELLOW)Compiling and linking: $(GREEN)$<$(RESET)"
	${CC} ${CFLAGS} -o ${NAME} ${SRCS}

clean:
	@echo "$(YELLOW)Removing excutables...$(RESET)"
	${RM} ${NAME}

re: fclean all

.PHONY: all clean re

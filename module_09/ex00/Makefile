CC			=	c++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98 -pedantic -fsanitize=address
NAME		=	btc
SRCS		=	main.cpp
RM			=	rm -f

GREEN		=	$(shell printf "\033[0;32m")
YELLOW		=	$(shell printf "\033[0;33m")
RESET		=	$(shell printf "\033[0m")

all: $(NAME)

$(NAME): $(SRCS)
	@echo "$(YELLOW)Compiling and linking: $(GREEN)$<$(RESET)"
	${CC} ${CFLAGS} -o ${NAME} ${SRCS}

clean:
	@echo "$(YELLOW)Removing excutables...$(RESET)"
	${RM} ${NAME}

re: fclean all

.PHONY: all clean re

NAME = Philos

SRC = main/main.c main/valid.c main/routine.c main/init.c main/threads.c main/tools.c
OBJ = $(SRC:.c=.o)

INC = head
CFLAGS = -Wextra -Werror -Wall -pthread -I $(INC)

RM = rm -rf
CC = gcc

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "\033[0;35m⚙️ Compiling: $< ⚙️\033[0m"

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -o $(NAME) $(CFLAGS)
	@echo "\033[0;32m🎉 $(NAME) ready to go! 🚀🎉\033[0m"

clean:
	@$(RM) $(OBJ)
	@rm -f debug_log.txt
	@echo "\033[0;34m🧹 Object files cleaned! 🧹\033[0m"

fclean: clean
	@$(RM) $(NAME)
	@echo "\033[0;31m❌ Executable $(NAME) removed! ❌\033[0m"

re: fclean all

.PHONY: all clean fclean re


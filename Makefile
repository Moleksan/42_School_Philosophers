NAME = philo

SRC = src/main.c src/valid.c src/routine.c src/init.c src/threads.c src/tools.c
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

valgrind: all
	@echo "\033[0;36m🔍 Running Valgrind... 🔍\033[0m"
	@$(VALGRIND)

hellgrind: all
	@echo "\033[0;31m🔥 Running Hellgrind (thread checker)... 🔥\033[0m"
	@$(HELLGRIND)

clean:
	@$(RM) $(OBJ)
	@rm -f debug_log.txt
	@echo "\033[0;34m🧹 Object files cleaned! 🧹\033[0m"

fclean: clean
	@$(RM) $(NAME)
	@echo "\033[0;31m❌ Executable $(NAME) removed! ❌\033[0m"

re: fclean all

.PHONY: all clean fclean re

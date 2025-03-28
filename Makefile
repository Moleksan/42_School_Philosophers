NAME = Philos

# Указываем исходные файлы, относительные к текущей папке (от папки, где находится Makefile)
SRC = main/main.c main/valid.c main/init_philo.c main/debug.c main/init_simulation.c main/tools.c
OBJ = $(SRC:.c=.o)

# Папка с заголовочными файлами
INC = include
CFLAGS = -Wextra -Werror -Wall -pthread -I $(INC)

# Убираем объектные файлы и исполнимые файлы
RM = rm -rf
CC = gcc

# Основная цель
all: $(NAME)

# Правило компиляции объектов из исходников
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "\033[0;35m⚙️ Compiling: $< ⚙️\033[0m"

# Линковка объектных файлов в исполнимый файл
$(NAME): $(OBJ)
	@$(CC) $(OBJ) -o $(NAME) $(CFLAGS)
	@echo "\033[0;32m🎉 $(NAME) ready to go! 🚀🎉\033[0m"

# Очистка объектных файлов
clean:
	@$(RM) $(OBJ)
	@rm -f debug_log.txt
	@echo "\033[0;34m🧹 Object files cleaned! 🧹\033[0m"

# Полная очистка
fclean: clean
	@$(RM) $(NAME)
	@echo "\033[0;31m❌ Executable $(NAME) removed! ❌\033[0m"

# Пересборка проекта
re: fclean all

# Убираем файлы, которые не являются реальными
.PHONY: all clean fclean re



CC         = gcc
CC_FLAGS   = -Wall -Wextra -Werror -g

NAME       = philosophers
SRCS_DIR   = src
OBJS_DIR   = obj
INC_DIR    = include
SRCS       = main.c check_input.c

SRCS_F     = $(addprefix $(SRCS_DIR)/, $(SRCS))
OBJS       = $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

all: $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	@echo "Compiling: $<"
	$(CC) $(CC_FLAGS) -I$(INC_DIR) -c $< -o $@

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(NAME): $(OBJS)
	@echo "Linking: $(NAME)"
	$(CC) $(CC_FLAGS) $(OBJS) -o $(NAME)
	@echo "Done"

clean:
	@rm -rf $(OBJS_DIR)
	@echo "Objects cleaned."

fclean: clean
	@rm -f $(NAME)
	@echo "Executable removed."

re: fclean all

.PHONY: all clean fclean re

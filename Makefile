###############################################################################
#                                  VARIABLES                                  #
###############################################################################
NAME = push_swap
BONUS_NAME = checker
CC = cc
CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g3
RESET=\033[0m
BLACK=\033[1;30m
RED=\033[1;31m
GREEN=\033[1;32m
YELLOW=\033[1;33m
BLUE=\033[1;34m
MAGENTA=\033[1;35m
CYAN=\033[1;36m
WHITE=\033[1;37m
LIBFT_DIR = ./libft/
LIBFT = $(LIBFT_DIR)libft.a
HEADERS = ./
SRCS_DIR = ./sources/
SRCS =	operations.c \
		parsing.c \
		sort.c \
		sort_utils.c \
		sort_utils_2.c \
		stack_utils.c
SRCS_PATH = $(addprefix $(SRCS_DIR), $(SRCS))
OBJS_DIR = ./objects/
OBJS = $(SRCS:%.c=%.o)
OBJS_PATH = $(addprefix $(OBJS_DIR), $(OBJS))

all: $(NAME)

bonus: $(BONUS_NAME)

$(NAME): $(OBJS_DIR) $(OBJS_PATH)
	@make -s -C $(LIBFT_DIR) converters checkers printf strings
	@$(CC) $(CFLAGS) $(OBJS_PATH) $(LIBFT) push_swap.c -o $(NAME)
	@echo "$(BLUE)PROGRAM $(GREEN)CREATED: $(CYAN)push_swap$(RESET)"

$(BONUS_NAME): $(OBJS_DIR) $(OBJS_PATH) 
	@make -s -C $(LIBFT_DIR) converters checkers printf strings gnl
	@$(CC) $(CFLAGS) $(OBJS_PATH) $(LIBFT) checker.c -o $(BONUS_NAME)
	@echo "$(BLUE)PROGRAM $(GREEN)CREATED: $(CYAN)checker$(RESET)"

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(OBJS_PATH): $(SRCS_PATH)
	@make -s $(OBJS)

$(OBJS):
	@$(CC) $(CFLAGS) -c -I $(HEADERS) $(SRCS_DIR)$(@:%.o=%.c) -o $(OBJS_DIR)$@

clean:
	@make -s -C libft/ fclean
	@rm -rf $(OBJS_DIR)

fclean: clean
	@rm -f $(NAME) $(BONUS_NAME)
	@echo "$(BLUE)PROGRAM $(RED)DESTROYED: $(CYAN)checker.$(RESET)"
	@echo "$(BLUE)PROGRAM $(RED)DESTROYED: $(CYAN)push_swap.$(RESET)"

re: fclean all

.PHONY: all clean fclean re
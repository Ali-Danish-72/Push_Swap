###############################################################################
#                                  VARIABLES                                  #
###############################################################################
NAME = push_swap
BONUS_NAME = checker
CC = cc
CFLAGS = -Wall -Werror -Wextra
RESET=\033[0m
RED=\033[1;31m
GREEN=\033[1;32m
BLUE=\033[1;34m
CYAN=\033[1;36m
LIBFT_DIR = ./libft/
LIBFT = $(LIBFT_DIR)libft.a
HEADERS = ./
SRCS_DIR = ./sources/
SRCS = operations.c parsing.c sort.c sort_utils.c sort_utils_2.c stack_utils.c
SRCS_PATH = $(addprefix $(SRCS_DIR), $(SRCS))
OBJS_DIR = ./objects/
OBJS = $(SRCS:%.c=%.o)
OBJS_PATH = $(addprefix $(OBJS_DIR), $(OBJS)) $(addprefix $(OBJS_DIR), push_swap.o) 
BONUS_OBJS_PATH = $(addprefix $(OBJS_DIR), $(OBJS)) $(addprefix $(OBJS_DIR), checker.o) 

all: $(NAME)

bonus: $(BONUS_NAME)

$(NAME): $(OBJS_DIR) $(OBJS_PATH) $(SRCS_DIR)push_swap.c
	@make -s -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) -c -I $(HEADERS) $(SRCS_DIR)push_swap.c -o $(OBJS_DIR)push_swap.o
	@$(CC) $(CFLAGS) $(OBJS_PATH) $(LIBFT)  -o $(NAME)
	@echo "$(BLUE)PROGRAM $(GREEN)CREATED: $(CYAN)push_swap$(RESET)"

$(BONUS_NAME): $(OBJS_DIR) $(OBJS_PATH) $(SRCS_DIR)checker_bonus.c
	@make -s -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) -c -I $(HEADERS) $(SRCS_DIR)checker_bonus.c -o $(OBJS_DIR)checker.o
	@$(CC) $(CFLAGS) $(BONUS_OBJS_PATH) $(LIBFT) -o $(BONUS_NAME)
	@echo "$(BLUE)PROGRAM $(GREEN)CREATED: $(CYAN)checker$(RESET)"

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(OBJS_PATH): $(SRCS_PATH)
	@make -s $(OBJS)

$(OBJS):
	@$(CC) $(CFLAGS) -c -I $(HEADERS) $(SRCS_DIR)$(@:%.o=%.c) -o $(OBJS_DIR)$@

clean:
	@make -s -C $(LIBFT_DIR) fclean
	@rm -rf $(OBJS_DIR)

fclean: clean
	@rm -rf $(NAME) $(BONUS_NAME)
	@echo "$(BLUE)PROGRAM $(RED)DESTROYED: $(CYAN)push_swap$(RESET)"
	@echo "$(BLUE)PROGRAM $(RED)DESTROYED: $(CYAN)checker$(RESET)"

re: fclean all

.PHONY: all clean fclean re

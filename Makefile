###############################################################################
#                                  VARIABLES                                  #
###############################################################################
NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra 
LIBFT_DIR = ./libft/
LIBFT = $(LIBFT_DIR)libft.a
HEADERS = ./
SRCS_DIR = ./sources/
SRCS =	clear.c \
		main.c \
		parse.c \
		push.c \
		reverse_rotation.c \
		rotation.c \
		swap.c \
		sorting.c
#		utils.c
SRCS_PATH = $(addprefix $(SRCS_DIR), $(SRCS))
OBJS_DIR = ./objects/
OBJS = $(SRCS:%.c=%.o)
OBJS_PATH = $(addprefix $(OBJS_DIR), $(OBJS))

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS_PATH)
	@make -s -C $(LIBFT_DIR) converters checkers printf strings > /dev/null
	@$(CC) $(CFLAGS) $(OBJS_PATH) $(LIBFT) -o $(NAME)
	@echo "ARCHIVE CREATED: libft.a"
	@echo "PROGRAM CREATED: push_swap"

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
	@rm -f $(NAME)
	@echo "PROGRAM DESTROYED: push_swap."

re: fclean all

.PHONY: all clean fclean re
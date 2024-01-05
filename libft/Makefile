###############################################################################
#                                  VARIABLES                                  #
###############################################################################
NAME = libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra -g3
RESET=\033[0m
RED=\033[1;31m
GREEN=\033[1;32m
YELLOW=\033[1;33m
BLUE=\033[1;34m
MAGENTA=\033[1;35m
CYAN=\033[1;36m
OBJS = \
	$(CHECKERS_OBJ) \
	$(CONVERTERS_OBJ) \
	$(GNL_OBJ) \
	$(PRINTF_OBJ) \
	$(STRINGS_OBJS)
HEAD = ./
SRC_PATH = ./srcs/

all: $(NAME)

###############################################################################
#                                  CHECKERS                                   #
###############################################################################
CHECKERS_DIR = $(SRC_PATH)checkers/
CHECKERS_FILE = ft_isdigit.c
CHECKERS_SRC = $(addprefix $(CHECKERS_DIR), $(CHECKERS_FILE))
CHECKERS_OBJ = $(CHECKERS_SRC:.c=.o)

$(CHECKERS_OBJ): %.o: %.c
	@if ! $(CC) $(CFLAGS) -c -I $(HEAD) $< -o $@; then \
	echo "$(YELLOW)ERROR WHILE COMPILING THE CHECKER FUNCTION!!!$(RESET)"; \
	fi

checkers: $(CHECKERS_OBJ)
	@ar rcs $(NAME) $(CHECKERS_OBJ)

###############################################################################
#                                  CONVERTERS                                 #
###############################################################################
CONVERTERS_DIR = $(SRC_PATH)converters/
CONVERTERS_FILE = ft_atoi.c
CONVERTERS_SRC = $(addprefix $(CONVERTERS_DIR), $(CONVERTERS_FILE))
CONVERTERS_OBJ = $(CONVERTERS_SRC:.c=.o)

$(CONVERTERS_OBJ): %.o: %.c
	@if ! $(CC) $(CFLAGS) -c -I $(HEAD) $< -o $@; then \
	echo "$(YELLOW)ERROR WHILE COMPILING THE CONVERTER FUNCTION!!!$(RESET)"; \
	fi

converters: $(CONVERTERS_OBJ)
	@ar rcs $(NAME) $(CONVERTERS_OBJ)

###############################################################################
#                                GET NEXT LINE                                #
###############################################################################
GNL_DIR = $(SRC_PATH)gnl/
GNL_FILE = get_next_line.c
GNL_SRC = $(addprefix $(GNL_DIR), $(GNL_FILE))
GNL_OBJ = $(GNL_SRC:.c=.o)

$(GNL_OBJ): %.o: %.c
	@if ! $(CC) $(CFLAGS) -c -I $(HEAD) $< -o $@; then \
	echo "$(YELLOW)ERROR WHILE COMPILING THE GET_NEXT_LINE FUNCTION!!!$(RESET)"; \
	fi

gnl: $(GNL_OBJ)
	@ar rcs $(NAME) $(GNL_OBJ)

###############################################################################
#                                   PRINTF                                    #
###############################################################################
PRINTF_DIR = $(SRC_PATH)printf/
PRINTF_FILE = ft_printf.c
PRINTF_SRC = $(addprefix $(PRINTF_DIR), $(PRINTF_FILE))
PRINTF_OBJ = $(PRINTF_SRC:.c=.o)

$(PRINTF_OBJ): %.o: %.c
	@if ! $(CC) $(CFLAGS) -c -I $(HEAD) $< -o $@; then \
	echo "$(YELLOW)ERROR WHILE COMPILING THE PRINTF FUNCTION!!!$(RESET)"; \
	fi

printf: $(PRINTF_OBJ)
	@ar rcs $(NAME) $(PRINTF_OBJ)

###############################################################################
#                                  STRINGS                                    #
###############################################################################
STRINGS_DIR = $(SRC_PATH)strings/
STRINGS_FILES = ft_split.c ft_strlen.c ft_substr.c ft_strnstr.c ft_strncmp.c
STRINGS_SRCS = $(addprefix $(STRINGS_DIR), $(STRINGS_FILES))
STRINGS_OBJS = $(STRINGS_SRCS:.c=.o)

$(STRINGS_OBJS): %.o: %.c
	@if ! $(CC) $(CFLAGS) -c -I $(HEAD) $< -o $@; then \
	echo "$(YELLOW)ERROR WHILE COMPILING THE STRING FUNCTIONS!!!$(RESET)"; \
	fi

strings: $(STRINGS_OBJS)
	@ar rcs $(NAME) $(STRINGS_OBJS)

###############################################################################
#                                  COMPLETE                                   #
###############################################################################
$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "$(BLUE)ARCHIVE $(GREEN)CREATED: $(CYAN)libft.a$(RESET)"

clean:
	@rm -f $(OBJS)
	@echo "$(BLUE)OBJECTS $(RED)DESTROYED$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(BLUE)ARCHIVE $(RED)DESTROYED: $(CYAN)libft.a$(RESET)"

re: fclean all

.PHONY: all clean fclean re
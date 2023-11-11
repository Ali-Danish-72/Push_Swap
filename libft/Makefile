###############################################################################
#                                  VARIABLES                                  #
###############################################################################
NAME = libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
OBJS = \
	$(CHECKERS_OBJS) \
	$(CONVERTERS_OBJS) \
	$(GNL_OBJS) \
	$(LISTS_OBJS) \
	$(MEMORY_OBJS) \
	$(PRINTF_OBJS) \
	$(PUT_FD_OBJS) \
	$(STRINGS_OBJS)
HEAD = ./
SRC_PATH = ./srcs/

all: $(NAME)

###############################################################################
#                                  CHECKERS                                   #
###############################################################################
CHECKERS_DIR = $(SRC_PATH)checkers/
CHECKERS_FILES = \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c
CHECKERS_SRCS = $(addprefix $(CHECKERS_DIR), $(CHECKERS_FILES))
CHECKERS_OBJS = $(CHECKERS_SRCS:.c=.o)

$(CHECKERS_OBJS): %.o: %.c
	@if ! $(CC) $(CFLAGS) -c -I $(HEAD) $< -o $@; then \
	echo "ERROR WHILE COMPILING THE CHECKER FUNCTIONS!!!"; \
	fi

checkers: $(CHECKERS_OBJS)
	@ar rcs $(NAME) $(CHECKERS_OBJS)
	@echo "ARCHIVE with checkers functions CREATED: libft.a"

###############################################################################
#                                  CONVERTERS                                 #
###############################################################################
CONVERTERS_DIR = $(SRC_PATH)converters/
CONVERTERS_FILES = \
		ft_absolute.c \
		ft_atoi.c \
		ft_itoa.c \
		ft_tolower.c \
		ft_toupper.c
CONVERTERS_SRCS = $(addprefix $(CONVERTERS_DIR), $(CONVERTERS_FILES))
CONVERTERS_OBJS = $(CONVERTERS_SRCS:.c=.o)

$(CONVERTERS_OBJS): %.o: %.c
	@if ! $(CC) $(CFLAGS) -c -I $(HEAD) $< -o $@; then \
	echo "ERROR WHILE COMPILING THE CONVERTERS FUNCTIONS!!!"; \
	fi

converters: $(CONVERTERS_OBJS)
	@ar rcs $(NAME) $(CONVERTERS_OBJS)
	@echo "ARCHIVE with converters functions CREATED: libft.a"

###############################################################################
#                                GET NEXT LINE                                #
###############################################################################
GNL_DIR = $(SRC_PATH)gnl/
GNL_FILES = \
		get_next_line.c
GNL_SRCS = $(addprefix $(GNL_DIR), $(GNL_FILES))
GNL_OBJS = $(GNL_SRCS:.c=.o)

$(GNL_OBJS): %.o: %.c
	@if ! $(CC) $(CFLAGS) -c -I $(HEAD) $< -o $@; then \
	echo "ERROR WHILE COMPILING THE GET_NEXT_LINE FUNCTION!!!"; \
	fi

gnl: $(GNL_OBJS)
	@ar rcs $(NAME) $(GNL_OBJS)
	@echo "ARCHIVE with the get_next_line function CREATED: libft.a"

###############################################################################
#                                   LISTS                                     #
###############################################################################
LISTS_DIR = $(SRC_PATH)lists/
LISTS_FILES = \
		ft_lstadd_back.c \
		ft_lstadd_front.c \
		ft_lstclear.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstlast.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_lstsize.c
LISTS_SRCS = $(addprefix $(LISTS_DIR), $(LISTS_FILES))
LISTS_OBJS = $(LISTS_SRCS:.c=.o)

$(LISTS_OBJS): %.o: %.c
	@if ! $(CC) $(CFLAGS) -c -I $(HEAD) $< -o $@; then \
	echo "ERROR WHILE COMPILING THE LIST FUNCTIONS!!!"; \
	fi

lists: $(LISTS_OBJS)
	@ar rcs $(NAME) $(LISTS_OBJS)
	@echo "ARCHIVE with list functions CREATED: libft.a"

###############################################################################
#                                   MEMORY                                    #
###############################################################################
MEMORY_DIR = $(SRC_PATH)memory/
MEMORY_FILES = \
		ft_bzero.c \
		ft_calloc.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c
MEMORY_SRCS = $(addprefix $(MEMORY_DIR), $(MEMORY_FILES))
MEMORY_OBJS = $(MEMORY_SRCS:.c=.o)

$(MEMORY_OBJS): %.o: %.c
	@if ! $(CC) $(CFLAGS) -c -I $(HEAD) $< -o $@; then \
	echo "ERROR WHILE COMPILING THE MEMORY FUNCTIONS!!!"; \
	fi

memory: $(MEMORY_OBJS)
	@ar rcs $(NAME) $(MEMORY_OBJS)
	@echo "ARCHIVE with memory functions CREATED: libft.a"

###############################################################################
#                                   PRINTF                                    #
###############################################################################
PRINTF_DIR = $(SRC_PATH)printf/
PRINTF_FILES = \
		address_print.c \
		char_print.c \
		ft_printf.c \
		hexa_print.c \
		num_print.c \
		str_print.c \
		unsigned_base_print.c
PRINTF_SRCS = $(addprefix $(PRINTF_DIR), $(PRINTF_FILES))
PRINTF_OBJS = $(PRINTF_SRCS:.c=.o)

$(PRINTF_OBJS): %.o: %.c
	@if ! $(CC) $(CFLAGS) -c -I $(HEAD) $< -o $@; then \
	echo "ERROR WHILE COMPILING THE PRINTF FUNCTION!!!"; \
	fi

printf: $(PRINTF_OBJS)
	@ar rcs $(NAME) $(PRINTF_OBJS)
	@echo "ARCHIVE with printf functions CREATED: libft.a"

###############################################################################
#                                   PUT_FD                                    #
###############################################################################
PUT_FD_DIR = $(SRC_PATH)put_fd/
PUT_FD_FILES = \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putnbr_base_fd.c \
		ft_putstr_fd.c
PUT_FD_SRCS = $(addprefix $(PUT_FD_DIR), $(PUT_FD_FILES))
PUT_FD_OBJS = $(PUT_FD_SRCS:.c=.o)

$(PUT_FD_OBJS): %.o: %.c
	@if ! $(CC) $(CFLAGS) -c -I $(HEAD) $< -o $@; then \
	echo "ERROR WHILE COMPILING THE PUT_FD FUNCTIONS!!!"; \
	fi

put_fd: $(PUT_FD_OBJS)
	@ar rcs $(NAME) $(PUT_FD_OBJS)
	@echo "ARCHIVE with put_fd functions CREATED: libft.a"

###############################################################################
#                                  STRINGS                                    #
###############################################################################
STRINGS_DIR = $(SRC_PATH)strings/
STRINGS_FILES = \
		ft_split.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strrchr.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strtrim.c \
		ft_substr.c
STRINGS_SRCS = $(addprefix $(STRINGS_DIR), $(STRINGS_FILES))
STRINGS_OBJS = $(STRINGS_SRCS:.c=.o)

$(STRINGS_OBJS): %.o: %.c
	@if ! $(CC) $(CFLAGS) -c -I $(HEAD) $< -o $@; then \
	echo "ERROR WHILE COMPILING THE STRING FUNCTIONS!!!"; \
	fi

strings: $(STRINGS_OBJS)
	@ar rcs $(NAME) $(STRINGS_OBJS)
	@echo "ARCHIVE with string functions CREATED: libft.a"

###############################################################################
#                                  COMPLETE                                   #
###############################################################################
$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "ARCHIVE with all functions CREATED: libft.a"

clean:
	@rm -f $(OBJS)
	@echo "OBJECTS DESTROYED"

fclean: clean
	@rm -f $(NAME)
	@echo "ARCHIVE DESTROYED: libft.a"

re: fclean all

.PHONY: all clean fclean re

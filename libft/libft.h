/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:21:19 by mdanish           #+#    #+#             */
/*   Updated: 2023/11/13 17:36:12 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdint.h>
# include <limits.h>
# include <stdarg.h>
# include <fcntl.h>

/*****************************************************************************/
/*								MACROS										 */
/*****************************************************************************/
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

# define HEX_LOW "0123456789abcdef"
# define HEX_UP "0123456789ABCDEF"
# define DECIMAL "0123456789"

/*****************************************************************************/
/*								MEMORY										 */
/*****************************************************************************/
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memchr(void const *s, int c, size_t n);
int		ft_memcmp(void const *s1, void const *s2, size_t n);
void	*ft_memcpy(void *dst, void const *src, size_t n);
void	*ft_memmove(void *dst, void const *src, size_t n);
void	*ft_memset(void *b, int c, size_t len);

/*****************************************************************************/
/*								CHECKERS									 */
/*****************************************************************************/
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);

/*****************************************************************************/
/*								STRINGS										 */
/*****************************************************************************/
void	free_split(char **split, size_t word_count);
char	**ft_split(char const *src, char delim);
char	*ft_strchr(char const *s, int c);
char	*ft_strdup(char const *s1);
void	ft_striteri(char const *s, void (*f)(unsigned int, char *));
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, char const *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, char const*src, size_t dstsize);
size_t	ft_strlen(char const *str);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(char const *s1, char const *s2, size_t n);
char	*ft_strnstr(char const *haystack, char const *needle, size_t len);
char	*ft_strrchr(char const *s, int c);
char	*ft_strtrim(char const *s, char const *set);
char	*ft_substr(char const *s, size_t start, size_t len);

/*****************************************************************************/
/*								CONVERTERS									 */
/*****************************************************************************/
size_t	ft_absolute(long number);
long	ft_atoi(char const *str);
char	*ft_itoa(long int n);
int		ft_tolower(int c);
int		ft_toupper(int c);

/*****************************************************************************/
/*								COUNTERS									 */
/*****************************************************************************/
size_t	word_counter(char const *src, char delim);
size_t	word_length(char const *src, char delim);
size_t	ft_absolute(long number);

/*****************************************************************************/
/*							STANDARD PRINTERS								 */
/*****************************************************************************/
void	ft_putchar_fd(char character, int fd);
void	ft_putendl_fd(char *string, int fd);
void	ft_putnbr_fd(long int number, int fd);
void	ft_putunbr_base_fd(long int number, int fd, char *base, int base_len);
void	ft_putstr_fd(char *string, int fd);

/*****************************************************************************/
/*								LISTS										 */
/*****************************************************************************/
void	ft_lstadd_back(t_list **lst, t_list *new_node);
void	ft_lstadd_front(t_list **lst, t_list *new_node);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);

/*****************************************************************************/
/*							FT_PRINTF										 */
/*****************************************************************************/

size_t	print_address(void *variable, int fd);
size_t	print_character(int character, int fd);
size_t	print_hexadecimal(size_t number, char specifier, int fd);
size_t	print_number(long int number, int fd);
size_t	ft_printf(char *string, int fd, ...);
size_t	print_string(char const *string, int fd);
size_t	print_unsigned_base(size_t num, int fd, char *base, size_t base_len);

/*****************************************************************************/
/*							GET_NEXT_LINE									 */
/*****************************************************************************/
char	*get_next_line(int fd);

#endif
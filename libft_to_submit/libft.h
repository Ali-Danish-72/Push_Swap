/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:21:19 by mdanish           #+#    #+#             */
/*   Updated: 2023/12/05 02:14:56 by mdanish          ###   ########.fr       */
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
/*								CHECKERS									 */
/*****************************************************************************/
int		ft_isdigit(int c);

/*****************************************************************************/
/*								STRINGS										 */
/*****************************************************************************/
void	free_split(char **split, size_t word_count);
char	**ft_split(char const *src, char delim);
size_t	ft_strlen(char const *str);
int		ft_strncmp(char const *s1, char const *s2, size_t n);
char	*ft_strnstr(char const *haystack, char const *needle, size_t len);
char	*ft_substr(char const *s, size_t start, size_t len);

/*****************************************************************************/
/*								CONVERTERS									 */
/*****************************************************************************/
long	ft_atoi(char const *str);

/*****************************************************************************/
/*								COUNTERS									 */
/*****************************************************************************/
size_t	word_counter(char const *src, char delim);

/*****************************************************************************/
/*								FT_PRINTF									 */
/*****************************************************************************/
void	ft_printf(char *str, int fd, int character);

/*****************************************************************************/
/*								GET_NEXT_LINE								 */
/*****************************************************************************/
char	*get_next_line(int fd);

#endif
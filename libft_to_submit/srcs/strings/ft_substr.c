/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 17:58:28 by mdanish           #+#    #+#             */
/*   Updated: 2023/12/05 01:15:44 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_substr(char const *s, size_t start, size_t len)
{
	char	*string;
	char	*str;
	size_t	s_len;

	if (!s || !len)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len <= len)
		len = s_len - start;
	if ((start + len) > s_len)
		len--;
	if (s_len < start || !s_len || (len == (size_t)-1))
		len = 0;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	string = str;
	s += start;
	while (len--)
		*str++ = *s++;
	*str = '\0';
	return (string);
}

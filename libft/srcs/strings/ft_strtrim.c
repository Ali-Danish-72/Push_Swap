/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:58:49 by mdanish           #+#    #+#             */
/*   Updated: 2023/10/23 14:28:02 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static int	char_trim(char s, char const *set)
{
	while (*set)
	{
		if (*set == s)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s, char const *set)
{
	char	*start;
	char	*end;
	char	*trim;
	char	*result;

	if (!s)
		return (NULL);
	if (!set)
		return ((char *)s);
	start = (char *)s;
	while (char_trim(*start, set))
		start++;
	end = (char *)s + (ft_strlen(s) - 1);
	while (char_trim(*end, set))
		end--;
	trim = (char *)malloc(end - start + 1);
	if (!trim)
		return (NULL);
	result = trim;
	while (start != end)
		*trim++ = *start++;
	*trim = '\0';
	return (result);
}

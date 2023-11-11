/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:56:24 by mdanish           #+#    #+#             */
/*   Updated: 2023/10/23 15:42:48 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	needle_match(char const *haystack, char const *needle, size_t len)
{
	while (len && *haystack++ == *needle++)
		len--;
	if (!len)
		return (1);
	return (0);
}

char	*ft_strnstr(char const *haystack, char const *needle, size_t len)
{
	if (!needle || !*needle)
		return ((char *)haystack);
	if (!haystack)
		return (NULL);
	while (*haystack)
	{
		if (needle_match(haystack, needle, len))
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 19:48:44 by mdanish           #+#    #+#             */
/*   Updated: 2023/11/04 14:12:34 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

size_t	word_length(char const *src, char delim)
{
	size_t	length;

	length = 0;
	while (*src != delim && *src++)
		length++;
	return (length);
}

size_t	word_counter(char const *src, char delim)
{
	size_t	ctr;

	ctr = 0;
	while (*src)
	{
		while (*src == delim && *src)
			src++;
		if (*src)
			ctr++;
		while (*src != delim && *src)
			src++;
	}
	return (ctr);
}

void	free_split(char **split, size_t word_count)
{
	while (word_count--)
		free(*(split + word_count));
	free(split);
}

char	**ft_split(char const *src, char delim)
{
	char	**split;
	char	**result;
	size_t	word_count;
	size_t	word_len;

	if (!src || !delim)
		return (NULL);
	word_count = word_counter(src, delim);
	result = malloc((word_count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	split = result;
	while (word_count--)
	{
		while (*src == delim && *src)
			src++;
		word_len = word_length(src, delim);
		*result = ft_substr(src, 0, word_len);
		if (!(*result))
			return (free_split(split, result - split), NULL);
		src += word_len;
		result++;
	}
	*result = NULL;
	return (split);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 06:48:06 by mdanish           #+#    #+#             */
/*   Updated: 2023/09/26 12:59:11 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

size_t	ft_strlcat(char *dst, char const *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	total;

	if (!src || !dst)
		return (0);
	dst_len = 0;
	while (*(dst + dst_len) && dst_len < dstsize)
		dst_len++;
	if (dst_len == dstsize)
		return (dstsize + ft_strlen(src));
	else
		total = dst_len + ft_strlen(src);
	while ((dst_len + 1 < dstsize) && *src)
		*(dst + dst_len++) = *src++;
	*(dst + dst_len) = '\0';
	return (total);
}

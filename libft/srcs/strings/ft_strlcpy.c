/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 18:49:27 by mdanish           #+#    #+#             */
/*   Updated: 2023/10/23 14:28:02 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

size_t	ft_strlcpy(char *dst, char const*src, size_t dstsize)
{
	if (!dst || !src)
		return (0);
	if (!dstsize)
		return (ft_strlen(src));
	dstsize--;
	while (dstsize-- && *src)
		*dst++ = *src++;
	*dst = '\0';
	return (ft_strlen(src));
}

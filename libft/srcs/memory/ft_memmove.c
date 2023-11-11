/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 08:43:54 by mdanish           #+#    #+#             */
/*   Updated: 2023/10/23 14:28:02 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	*ft_memmove(void *dst, void const *src, size_t n)
{
	void	*dest;

	dest = dst;
	if (!dst || !src || dst == src)
		return (dst);
	if (dst > src)
	{
		while (n--)
			*((char *)dst + n) = *((char *)src + n);
	}
	else
	{
		while (n--)
			*(char *)dst++ = *(char *)src++;
	}
	return (dest);
}

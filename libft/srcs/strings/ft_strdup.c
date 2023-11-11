/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 08:49:38 by mdanish           #+#    #+#             */
/*   Updated: 2023/10/23 14:28:02 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strdup(char const *s1)
{
	char	*dup;
	char	*result;

	if (!s1)
		return (NULL);
	dup = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!dup)
		return (NULL);
	result = (char *)dup;
	while (*s1)
		*dup++ = *s1++;
	*dup = '\0';
	return (result);
}

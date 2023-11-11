/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 12:21:42 by mdanish           #+#    #+#             */
/*   Updated: 2023/11/03 20:40:37 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	digit_counter(long number)
{
	int	counter;

	if (number == 0)
		return (1);
	counter = 0;
	if (number < 0)
		counter++;
	while (number)
	{
		counter++;
		number /= 10;
	}
	return (counter);
}

char	*ft_itoa(long number)
{
	int		ctr;
	size_t	num;
	char	*str;

	ctr = digit_counter(number);
	str = (char *)malloc(sizeof(char) * (ctr + 1));
	if (!str)
		return (NULL);
	*(str + ctr) = '\0';
	num = ft_absolute(number);
	while (ctr--)
	{
		*(str + ctr) = (num % 10 + 48);
		num /= 10;
	}
	if (number < 0)
		*str = '-';
	return (str);
}

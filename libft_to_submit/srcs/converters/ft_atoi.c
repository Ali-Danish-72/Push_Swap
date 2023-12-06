/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:19:26 by mdanish           #+#    #+#             */
/*   Updated: 2023/10/25 18:02:44 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

long int	ft_atoi(char const *str)
{
	int			sign;
	long int	nb;

	nb = 0;
	sign = 1;
	while (*str == 32 || (*str > 8 && *str < 14))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-' && str++)
		sign = -1;
	while (*str == 48)
		str++;
	while (*str > 47 && *str < 58)
		nb = (nb * 10) + *str++ - 48;
	return (nb * sign);
}

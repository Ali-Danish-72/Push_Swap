/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:05:21 by mdanish           #+#    #+#             */
/*   Updated: 2023/11/08 18:37:01 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_stack *stack, char type)
{
	if (type == 'a' || type == 'r')
	{
		if (!stack->a || stack->a == stack->a->next)
			return ;
		stack->a = stack->a->next;
	}
	if (type == 'b' || type == 'r')
	{
		if (!stack->b || stack->b == stack->b->next)
			return ;
		stack->b = stack->b->next;
	}
	ft_printf("r%c\n", 1, type);
}

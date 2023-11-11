/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 20:26:25 by mdanish           #+#    #+#             */
/*   Updated: 2023/11/08 18:37:57 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse_rotate(t_stack *stack, char type)
{
	if (type == 'a' || type == 'r')
	{
		if (!stack->a || stack->a->value == stack->a->prev->value)
			return ;
		stack->a = stack->a->prev;
	}
	if (type == 'b' || type == 'r')
	{
		if (!stack->b || stack->b->value == stack->b->prev->value)
			return ;
		stack->b = stack->b->prev;
	}
	ft_printf("rr%c\n", 1, type);
}
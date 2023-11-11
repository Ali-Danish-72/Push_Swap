/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:54:18 by mdanish           #+#    #+#             */
/*   Updated: 2023/11/08 18:40:19 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_values(t_stack *stack, char type)
{

	int	store;
	if (type == 'a' || type == 's')
	{
		store = stack->a->next->value;
		stack->a->next->value = stack->a->value;
		stack->a->value = store;
	}
	if (type == 'b' || type == 's')
	{
		store = stack->b->next->value;
		stack->b->next->value = stack->b->value;
		stack->b->value = store;
	}
	ft_printf("s%c\n", 1, type);
}

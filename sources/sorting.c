/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:52:43 by mdanish           #+#    #+#             */
/*   Updated: 2023/11/12 07:00:58 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_stack *stack)
{
	if (stack->a->value > stack->a->next->value && stack->a->next->value
		< stack->a->prev->value && stack->a->value < stack->a->prev->value)
		swap_values(stack, 'a');
	else if (stack->a->value > stack->a->next->value && stack->a->next->value
		< stack->a->prev->value && stack->a->value > stack->a->prev->value)
		rotate(stack, 'a');
	else if (stack->a->value < stack->a->next->value && stack->a->next->value
		> stack->a->prev->value && stack->a->value > stack->a->prev->value)
		reverse_rotate(stack, 'a');
	else if (stack->a->value < stack->a->next->value && stack->a->next->value
		> stack->a->prev->value && stack->a->value < stack->a->prev->value)
	{
		swap_values(stack, 'a');
		rotate(stack, 'a');
	}
	else if (stack->a->value > stack->a->next->value && stack->a->next->value
		> stack->a->prev->value && stack->a->value > stack->a->prev->value)
	{
		swap_values(stack, 'a');
		reverse_rotate(stack, 'a');
	}
}

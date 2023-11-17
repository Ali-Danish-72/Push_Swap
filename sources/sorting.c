/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:52:43 by mdanish           #+#    #+#             */
/*   Updated: 2023/11/13 19:28:04 by mdanish          ###   ########.fr       */
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

void	start_sort(t_stack *stack)
{
	push_b(stack);
	push_b(stack);
	find_max(stack, 0, 1);
	
}

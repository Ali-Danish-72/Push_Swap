/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:47:55 by mdanish           #+#    #+#             */
/*   Updated: 2023/11/30 19:35:14 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	send_min_to_top(t_stack *stack)
{
	t_node	*store;
	int		moves;

	store = stack->a;
	find_min(*stack->a, &stack->min_a, stack->size_a);
	while (store->value != stack->min_a)
		store = store->next;
	if (store->index > (stack->size_a / 2))
	{
		moves = stack->size_a - store->index;
		while (moves--)
			reverse_rotate(stack, 'a');
	}
	else
		while (store->index--)
			rotate(stack, 'a');
}

void	initialize_the_stack(t_stack *stack)
{
	stack->b = NULL;
	stack->size_b = 0;
	stack->a_rot = 0;
	stack->b_rot = 0;
	stack->a_rev_rot = 0;
	stack->b_rev_rot = 0;
	stack->min_a = INT32_MAX;
	stack->max_a = INT32_MIN;
	stack->min_b = INT32_MAX;
	stack->max_b = INT32_MIN;
	stack->cheapest_move = 0;
	list_size(stack, 1, 0);
	find_min(*stack->a, &stack->min_a, stack->size_a);
	find_max(*stack->a, &stack->max_a, stack->size_a);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 01:17:10 by mdanish           #+#    #+#             */
/*   Updated: 2023/11/29 16:04:34 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reset_stack(t_stack *stack)
{
	stack->a_rot = 0;
	stack->a_rev_rot = 0;
	stack->b_rot = 0;
	stack->b_rev_rot = 0;
	stack->cheapest_move = 0;
	if (stack->b->value > stack->max_b)
		stack->max_b = stack->b->value;
	if (stack->b->value < stack->min_b)
		stack->min_b = stack->b->value;
}

void	set_rotations(t_stack *stack, t_node a_to_top, t_node b_to_top)
{
	if (a_to_top.index > (stack->size_a / 2))
		stack->a_rev_rot = stack->size_a - a_to_top.index + 1;
	else
		stack->a_rot = a_to_top.index;
	if (b_to_top.index > (stack->size_b / 2))
		stack->b_rev_rot = stack->size_b - b_to_top.index;
	else
		stack->b_rot = b_to_top.index;
}

int	send_b_max_to_the_top(t_stack *stack, t_node *send_to_top)
{
	t_node	*store;

	store = stack->b;
	while (store->value != stack->max_b)
		store = store->next;
	*send_to_top = *store;
	if (store->index > (stack->size_b / 2))
		return (stack->size_b - store->index);
	return (store->index);
}

int	set_b_moves(t_stack *stack, int value, t_node *send_to_top)
{
	t_node	*store;
	int		diff;

	if (value > stack->max_b || value < stack->min_b)
		return (send_b_max_to_the_top(stack, send_to_top));
	store = stack->b;
	diff = 0;
	while (store)
	{
		if (value > store->value && value < store->prev->value
			&& (!diff || diff > store->prev->value - store->value))
		{
			diff = store->prev->value - store->value;
			*send_to_top = *store;
		}
		if (store->next == stack->b)
			break ;
		store = store->next;
	}
	if (send_to_top->index > (stack->size_b / 2))
		return (stack->size_b - send_to_top->index);
	return (send_to_top->index);
}

void	find_cheapest_move_to_b(t_stack *stack)
{
	t_node	*store;
	t_node	a_to_top;
	t_node	b_to_top;
	t_node	b_to_top_store;
	int		total;

	store = stack->a;
	while (store)
	{
		if (store->index > (stack->size_a / 2))
			total = stack->size_a - store->index;
		else
			total = store->index;
		total += set_b_moves(stack, store->value, &b_to_top_store) + 1;
		if (!stack->cheapest_move || stack->cheapest_move > total)
		{
			stack->cheapest_move = total;
			a_to_top = *store;
			b_to_top = b_to_top_store;
		}
		if (stack->cheapest_move < 3 || store->next == stack->a)
			break ;
		store = store->next;
	}
	set_rotations(stack, a_to_top, b_to_top);
}

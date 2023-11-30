/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:52:43 by mdanish           #+#    #+#             */
/*   Updated: 2023/11/30 19:33:46 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_stack *stack)
{
	if (stack->a->value > stack->a->next->value
		&& stack->a->value > stack->a->prev->value)
	{
		rotate(stack, 'a');
		if (stack->a->value > stack->a->next->value)
			swap_values(stack, 'a');
	}
	else if (stack->a->value < stack->a->prev->value)
	{
		swap_values(stack, 'a');
		if (stack->a->value > stack->a->next->value)
			rotate(stack, 'a');
	}
	else
		reverse_rotate(stack, 'a');
}

void	execute_rotations(t_stack *stack)
{
	while (stack->a_rot && stack->b_rot)
	{
		rotate(stack, 'r');
		stack->a_rot--;
		stack->b_rot--;
	}
	while (stack->a_rev_rot && stack->b_rev_rot)
	{
		reverse_rotate(stack, 'r');
		stack->a_rev_rot--;
		stack->b_rev_rot--;
	}
	while (stack->a_rot--)
		rotate(stack, 'a');
	while (stack->b_rot--)
		rotate(stack, 'b');
	while (stack->a_rev_rot--)
		reverse_rotate(stack, 'a');
	while (stack->b_rev_rot--)
		reverse_rotate(stack, 'b');
}

void	set_stack_b_straight(t_stack *stack)
{
	t_node	*store;

	store = stack->b;
	while (store->value != stack->max_b)
		store = store->next;
	if (store->index > (stack->size_b / 2))
		stack->b_rev_rot = stack->size_b - store->index;
	else
		stack->b_rot = store->index;
	execute_rotations(stack);
	reset_stack(stack);
}

void	send_the_node_to_b(t_stack *stack)
{
	find_cheapest_move_to_b(stack);
	execute_rotations(stack);
	push(stack, 'b');
	list_size(stack, 1, 1);
	reset_stack(stack);
}

void	sort(t_stack *stack)
{
	push(stack, 'b');
	push(stack, 'b');
	list_size(stack, 1, 1);
	find_max(*stack->b, &stack->max_b, stack->size_b);
	find_min(*stack->b, &stack->min_b, stack->size_b);
	while (stack->size_a-- > 3)
		send_the_node_to_b(stack);
	set_stack_b_straight(stack);
	if (!(stack->a->value < stack->a->next->value
			&& stack->a->next->value < stack->a->prev->value))
		sort_three(stack);
	stack->max_a = stack->a->prev->value;
	stack->min_a = stack->a->value;
	if (stack->max_a > stack->max_b)
		reverse_rotate(stack, 'a');
	while (stack->size_b--)
	{
		while (stack->a->prev->value < stack->a->value
			&& stack->b && stack->a->prev->value > stack->b->value)
			reverse_rotate(stack, 'a');
		push(stack, 'a');
	}
	list_size(stack, 1, 0);
	send_min_to_top(stack);
}

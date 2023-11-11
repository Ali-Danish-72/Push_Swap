/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:47:55 by mdanish           #+#    #+#             */
/*   Updated: 2023/11/08 21:53:41 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	find_max(t_stack *stack, char type)
{
	t_stack	*stack_store;

	stack_store = stack;
	if (type == 'a')
	{
		stack->max_a = stack->a->value;
		while (stack_store->size_a--)
		{
			if (stack->max_a < stack_store->a->next->value)
				stack->max_a = stack_store->a->next->value;
		}
	}
	if (type == 'b')
	{
		stack->max_b = stack->b->value;
		while (stack_store->size_b--)
		{
			if (stack->max_b < stack_store->b->next->value)
				stack->max_b = stack_store->b->next->value;
		}
	}
}

void	find_min(t_stack *stack, char type)
{
	t_stack	*stack_store;

	stack_store = stack;
	if (type == 'a')
	{
		stack->min_a = stack->a->value;
		while (stack_store->size_a--)
		{
			if (stack->min_a > stack_store->a->next->value)
				stack->min_a = stack_store->a->next->value;
		}
	}
	if (type == 'b')
	{
		stack->min_b = stack->b->value;
		while (stack_store->size_b--)
		{
			if (stack->min_b > stack_store->b->next->value)
				stack->min_b = stack_store->b->next->value;
		}
	}
}

void	list_size(t_stack *stack, int measure_a, int measure_b)
{
	int		list_size;
	t_node	*store;

	list_size = 0;
	if (measure_a)
	{
		store = stack->a;
		while (store && (!list_size++ || store != stack->a))
			store = store->next;
		stack->size_a = list_size;
		if (list_size)
			stack->size_a--;
	}
	if (measure_b)
	{
		store = stack->b;
		while (store && (!list_size++ || store != stack->b))
			store = store->next;
		stack->size_b = list_size;
		if (list_size)
			stack->size_b--;
	}
}

void	assign_index(t_stack *stack, char type)
{
	t_node	*store;
	int		index;

	index = 0;
	if (type == 'a')
	{
		store = stack->a;
		while (index++ < stack->size_a)
		{
			store->index = index;
			store = store->next;
		}
	}
	else if (type == 'b')
	{
		store = stack->b;
		while (index++ < stack->size_b)
		{
			store->index = index;
			store = store->next;
		}
	}
}

int	check_sort(t_stack	stack, char type)
{
	if (type == 'a')
	{
		while (stack.size_a--)
		{
			if (stack.a->value > stack.a->next->value && stack.size_a > 0)
				return (0);
			stack.a = stack.a->next;
		}
	}
	else if (type == 'b')
	{
		while (stack.size_b--)
		{
			if (stack.b->value < stack.b->next->value && stack.size_b > 0)
				return (0);
			stack.b = stack.b->next;
		}
	}
	return (1);
}

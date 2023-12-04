/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 20:45:15 by mdanish           #+#    #+#             */
/*   Updated: 2023/12/04 14:50:08 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	call_exit(int status, void *values, void *ptr)
{
	if (status == 7)
		ft_printf("KO\n", 1);
	else if (status)
		ft_printf("Error\n", 2);
	free(ptr);
	free(values);
	exit(status);
}

void	clear_stack_and_exit(int status, void *values, t_stack stack)
{
	t_node	*store;

	while (stack.size_a--)
	{
		if (status == 3)
			store = stack.a->prev;
		else
			store = stack.a->next;
		free(stack.a);
		stack.a = store;
	}
	call_exit(status, values, NULL);
}

void	find_max(t_node stack, int *max, int stack_size)
{
	*max = stack.value;
	while (--stack_size)
	{
		if (*max < stack.next->value)
			*max = stack.next->value;
		stack = *stack.next;
	}
}

void	find_min(t_node stack, int *min, int stack_size)
{
	*min = stack.value;
	while (--stack_size)
	{
		if (*min > stack.next->value)
			*min = stack.next->value;
		stack = *stack.next;
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
		while (store != stack->a || !list_size)
		{
			store->index = list_size++;
			store = store->next;
		}
		stack->size_a = list_size;
	}
	list_size = 0;
	if (measure_b)
	{
		store = stack->b;
		while (store != stack->b || !list_size)
		{
			store->index = list_size++;
			store = store->next;
		}
		stack->size_b = list_size;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 20:30:27 by mdanish           #+#    #+#             */
/*   Updated: 2023/12/03 16:06:01 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_node(t_node **stack, t_node *node_to_push)
{
	if (!*stack)
	{
		(*stack) = node_to_push;
		(*stack)->next = node_to_push;
		(*stack)->prev = node_to_push;
	}
	else
	{
		node_to_push->next = (*stack);
		node_to_push->prev = (*stack)->prev;
		(*stack)->prev->next = node_to_push;
		(*stack)->prev = node_to_push;
		(*stack) = node_to_push;
	}
}

void	push(t_stack *stack, char type)
{
	t_node	*node_to_push;

	if (type == 'a')
	{
		node_to_push = stack->b;
		if (stack->size_b == 0)
			stack->b = NULL;
		else
		{
			stack->b->prev->next = stack->b->next;
			stack->b->next->prev = stack->b->prev;
			stack->b = stack->b->next;
		}
		push_node(&stack->a, node_to_push);
	}
	else
	{
		node_to_push = stack->a;
		stack->a->prev->next = stack->a->next;
		stack->a->next->prev = stack->a->prev;
		stack->a = stack->a->next;
		push_node(&stack->b, node_to_push);
	}
	ft_printf("p%c\n", 1, type);
}

void	reverse_rotate(t_stack *stack, char type)
{
	if (type == 'a' || type == 'r')
	{
		if (stack->a && stack->a != stack->a->prev)
			stack->a = stack->a->prev;
	}
	if (type == 'b' || type == 'r')
	{
		if (stack->b && stack->b != stack->b->prev)
			stack->b = stack->b->prev;
	}
	ft_printf("rr%c\n", 1, type);
}

void	rotate(t_stack *stack, char type)
{
	if (type == 'a' || type == 'r')
	{
		if (stack->a && stack->a != stack->a->next)
			stack->a = stack->a->next;
	}
	if (type == 'b' || type == 'r')
	{
		if (stack->b && stack->b != stack->b->next)
			stack->b = stack->b->next;
	}
	ft_printf("r%c\n", 1, type);
}

void	swap_values(t_stack *stack, char type)
{
	int	store;

	if (type == 'a' || type == 's')
	{
		if (stack->a && stack->a != stack->a->next)
		{
			store = stack->a->next->value;
			stack->a->next->value = stack->a->value;
			stack->a->value = store;
		}
	}
	if (type == 'b' || type == 's')
	{
		if (stack->a && stack->a != stack->a->next)
		{
			store = stack->b->next->value;
			stack->b->next->value = stack->b->value;
			stack->b->value = store;
		}
	}
	ft_printf("s%c\n", 1, type);
}

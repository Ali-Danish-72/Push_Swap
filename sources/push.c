/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 20:30:27 by mdanish           #+#    #+#             */
/*   Updated: 2023/11/08 13:22:59 by mdanish          ###   ########.fr       */
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

void	push_a(t_stack *stack)
{
	t_node	*node_to_push;

	if (!(stack->b))
		return ;
	node_to_push = stack->b;
	if (stack->size_b == 1)
		stack->b = NULL;
	else
	{
		stack->b->prev->next = stack->b->next;
		stack->b->next->prev = stack->b->prev;
		stack->b = stack->b->next;
	}
	push_node(&stack->a, node_to_push);
	list_size(stack, 1, 1);
	ft_printf("pa\n", 1);
}

void	push_b(t_stack *stack)
{
	t_node	*node_to_push;

	if (!(stack->a))
		return ;
	node_to_push = stack->a;
	if (stack->size_a == 1)
		stack->a = NULL;
	else
	{
		stack->a->prev->next = stack->a->next;
		stack->a->next->prev = stack->a->prev;
		stack->a = stack->a->next;
	}
	push_node(&stack->b, node_to_push);
	list_size(stack, 1, 1);
	ft_printf("pb\n", 1);
}








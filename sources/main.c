/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:05:55 by mdanish           #+#    #+#             */
/*   Updated: 2023/11/12 06:55:39 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	initialize(t_stack *stack)
{
	stack->b = NULL;
	stack->size_b = 0;
	find_max(stack, 'a');
}

void	print_stack(t_stack stack, char type)
{
	if (type == 'a')
	{
		while (stack.size_a--)
		{
			ft_printf("%d: %d\n", 1, stack.size_a, stack.a->value);
			stack.a = stack.a->next;
		}
	}
	if (type == 'b')
	{
		while (stack.size_b--)
		{
			ft_printf("%d\n", 1, stack.b->value);
			stack.b = stack.b->next;
		}
	}
}

int	main(int ac, char **av)
{
	t_stack	stack;
	// t_node *store;

	if (ac == 1)
		exit(0);
	stack = parse(--ac, ++av);
	if (check_sort(stack, 'a'))
		clear_stack_and_exit(0, NULL, stack);
	initialize(&stack);
	// print_stack(stack, 'a');
	// print_stack(stack, 'a');
	// print_stack(stack, 'a');
	// print_stack(stack, 'a');
	reverse_rotate(&stack, 'a');
	rotate(&stack, 'a');
	swap_values(&stack, 'a');
	push_b(&stack);
	push_b(&stack);
	push_b(&stack);
	push_b(&stack);
	reverse_rotate(&stack, 'b');
	rotate(&stack, 'b');
	swap_values(&stack, 'b');
	rotate(&stack, 'r');
	reverse_rotate(&stack, 'r');
	swap_values(&stack, 's');
	push_a(&stack);
	push_a(&stack);
	push_a(&stack);
	push_a(&stack);
	// sort(&stack);
	clear_stack_and_exit(0, NULL, stack);
}

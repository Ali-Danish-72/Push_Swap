/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 13:12:06 by mdanish           #+#    #+#             */
/*   Updated: 2023/12/06 14:26:22 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	execute_operations(int command, t_stack *stack)
{
	if (!command)
		swap_values(stack, 'a');
	else if (command == 4)
		swap_values(stack, 'b');
	else if (command == 8)
		swap_values(stack, 's');
	else if (command == 12)
		rotate(stack, 'a');
	else if (command == 16)
		rotate(stack, 'b');
	else if (command == 20)
		rotate(stack, 'r');
	else if (command == 24)
		reverse_rotate(stack, 'a');
	else if (command == 29)
		reverse_rotate(stack, 'b');
	else if (command == 34)
		reverse_rotate(stack, 'r');
	else if (command == 39)
		push(stack, 'a');
	else if (command == 43)
		push(stack, 'b');
}

int	check_sort(t_stack stack)
{
	t_node	*store;

	store = stack.a;
	while (store)
	{
		if (store->value > store->next->value && store->next != stack.a)
			return (0);
		if (store->next == stack.a)
			break ;
		store = store->next;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	stack;
	char	*line;
	char	*diff;

	if (ac == 1)
		exit(0);
	line = get_next_line(0);
	if (!ft_strncmp(line, "Error\n", 6))
		call_exit(6, line, NULL);
	stack = parse(--ac, ++av);
	initialize_the_stack(&stack);
	stack.print_operations = 0;
	while (line)
	{
		diff = ft_strnstr(OPERATIONS, line, 3);
		if (!diff)
			clear_stack_and_exit(7, line, stack);
		free(line);
		execute_operations(OPERATIONS - diff, &stack);
		line = get_next_line(0);
	}
	if (check_sort(stack) || stack.b)
		clear_stack_and_exit(8, line, stack);
	ft_printf("\033[1;32mOK\n\033[0m", 1, 0);
	clear_stack_and_exit(0, line, stack);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 13:12:06 by mdanish           #+#    #+#             */
/*   Updated: 2023/12/04 20:09:53 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	while (stack.size_a-- > 1)
	{
		if (stack.a->value > stack.a->next->value)
			return (0);
		stack.a = stack.a->next;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	stack;
	char	*line = NULL;
	char	*diff = NULL;

	line = get_next_line(0);
	if (ac == 1 || !ft_strncmp(line, "Error\n", 6))
		call_exit(0, line, NULL);
	stack = parse(--ac, ++av);
	initialize_the_stack(&stack);
	while (line)
	{
		diff = ft_strnstr(OPERATIONS, line, ft_strlen(line));
		if (!diff)
			clear_stack_and_exit(6, line, stack);
		free(line);
		execute_operations(OPERATIONS - diff, &stack);
		line = get_next_line(0);
	}
	if (check_sort(stack))
		clear_stack_and_exit(7, line, stack);
	ft_printf("OK\n", 1);
	clear_stack_and_exit(0, line, stack);
}

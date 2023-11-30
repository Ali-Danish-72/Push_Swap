/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:05:55 by mdanish           #+#    #+#             */
/*   Updated: 2023/11/30 19:36:20 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	stack;

	if (ac == 1)
		exit(0);
	stack = parse(--ac, ++av);
	initialize_the_stack(&stack);
	if (stack.size_a < 4)
		sort_three(&stack);
	else
		sort(&stack);
	clear_stack_and_exit(0, NULL, stack);
}

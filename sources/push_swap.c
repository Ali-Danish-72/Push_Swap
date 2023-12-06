/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:05:55 by mdanish           #+#    #+#             */
/*   Updated: 2023/12/06 14:12:32 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int ac, char **av)
{
	t_stack	stack;
	int		i;
	int		j;

	if (ac == 1)
		exit(0);
	i = 0;
	while (i < ac)
	{
		j = 0;
		while (av[i][j] == ' ')
			j++;
		if (!**(av + i) || !*(*(av + i) + j))
			call_exit(1, NULL, NULL);
		i++;
	}
	stack = parse(--ac, ++av);
	initialize_the_stack(&stack);
	if (stack.size_a < 4)
		sort_three(&stack);
	else
		sort(&stack);
	clear_stack_and_exit(0, NULL, stack);
}

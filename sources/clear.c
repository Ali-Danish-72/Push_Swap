/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 20:45:15 by mdanish           #+#    #+#             */
/*   Updated: 2023/11/08 13:32:02 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	call_exit(int status, void *values, void *ptr)
{
	if (status)
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
	while (stack.size_b--)
	{
		store = stack.b->next;
		free(stack.b);
		stack.b = store;
	}
	call_exit(status, values, NULL);
}

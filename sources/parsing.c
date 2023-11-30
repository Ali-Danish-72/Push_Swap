/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:32:55 by mdanish           #+#    #+#             */
/*   Updated: 2023/11/30 18:00:30 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	create_stack(long int *values, long int *store, int num_ctr, int ac)
{
	t_stack	stack;
	t_node	*next_node;

	stack.size_a = num_ctr;
	stack.a = (t_node *)malloc(sizeof(t_node));
	while (num_ctr--)
	{
		next_node = (t_node *)malloc(sizeof(t_node));
		if (!stack.a || !next_node)
			clear_stack_and_exit(2, store, stack);
		stack.a->value = *values++;
		next_node->prev = stack.a;
		stack.a->next = next_node;
		if (num_ctr)
			stack.a = next_node;
		else
			free(next_node);
	}
	next_node = stack.a;
	while (ac--)
		stack.a = stack.a->prev;
	next_node->next = stack.a;
	stack.a->prev = next_node;
	free(store);
	return (stack);
}

void	check_duplicates_and_sort(int count, long int *values)
{
	int	i;
	int	j;

	if (count == 1)
		call_exit(0, values, NULL);
	i = -1;
	while (++i < count - 1)
	{
		j = i + 1;
		while (j < count)
		{
			if (*(values + i) == *(values + j++))
				call_exit(5, values, NULL);
		}
	}
	j = 0;
	while (j < count - 1 && *(values + j) < *(values + j + 1))
		j++;
	if (j == count - 1)
		call_exit(0, values, NULL);
}

int	validate_integer(char *input, long int *value)
{
	char	*store;

	store = input;
	if (*input == '-')
	{
		input++;
		if (!ft_isdigit(*input))
			return (3);
	}
	while (*input)
	{
		if (!ft_isdigit(*input++))
			return (3);
	}
	*value = ft_atoi(store);
	if (*value > INT32_MAX || *value < INT32_MIN)
		return (4);
	return (0);
}

long	*splitter(int ac, char **av, int *num_count, long int *values)
{
	int			i;
	int			status;
	int			*store;
	char		**split;
	long int	*values_copy;

	values_copy = values;
	store = num_count;
	while (ac--)
	{
		split = ft_split(*av++, ' ');
		if (!split)
			call_exit(2, values, store);
		i = -1;
		while (++i < *num_count)
		{
			status = validate_integer(*(split + i), values_copy++);
			if (status)
				break ;
		}
		free_split(split, *num_count++);
		if (status)
			call_exit(status, values, store);
	}
	return (values);
}

t_stack	parse(int ac, char **av)
{
	int			i;
	int			num_ctr;
	int			*num_count;
	long int	*values;

	num_count = (int *)malloc(ac * sizeof(int));
	if (!num_count)
		call_exit(1, NULL, NULL);
	i = -1;
	num_ctr = 0;
	while (++i < ac)
	{
		*(num_count + i) = word_counter(*(av + i), ' ');
		num_ctr += *(num_count + i);
	}
	values = (long int *)malloc(sizeof(long int) * num_ctr);
	if (!values)
		call_exit(1, num_count, NULL);
	values = splitter(ac, av, num_count, values);
	free (num_count);
	check_duplicates_and_sort(num_ctr, values);
	return (create_stack(values, values, num_ctr, num_ctr - 1));
}

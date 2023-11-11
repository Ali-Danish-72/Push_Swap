/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:43:27 by mdanish           #+#    #+#             */
/*   Updated: 2023/11/08 20:55:40 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node	*a;
	t_node	*b;
	int		size_a;
	int		size_b;
	int		max_a;
	int		max_b;
	int		min_a;
	int		min_b;
	int		a_rot;
	int		a_rev_rot;
	int		b_rot;
	int		b_rev_rot;
}			t_stack;

//	PROGRAM EXIT CODES:
//	0 = Successful completion of the program.
//	1 = Malloc fail while creating the stack.
//	2 = Malloc fail while parsing the parameters.
//	3 = Characters other than integers detected.
//	4 = Parameter is outside the range of an type int.
//	5 = Duplicate parameters detected.

// The top of the stack is going to be the begin node.
// All the operations will be mainly done through the
// head of the list as well as the one right after the head.

/*****************************************************************************/
/*									PARSER									 */
/*****************************************************************************/
/*****************************************************************************/
/*								   SORTERS									 */
/*****************************************************************************/
/*****************************************************************************/
/*								  OPERATIONS								 */
/*****************************************************************************/

void	call_exit(int status, void *values, void *ptr);
void	check_duplicates(int count, long int *values);
void	clear_stack_and_exit(int status, void *values, t_stack stack);
t_stack	create_stack(long int *values, long int *store, int num_ctr, int ac);
t_stack	parse(int ac, char **av);
int		validate_integer(char *input, long int *value);
void	list_size(t_stack *stack, int measure_a, int measure_b);

void	assign_index(t_stack *stack, char type);
int		check_sort(t_stack	stack, char type);
void	sort_three(t_stack *a);
void	sort(t_stack *stack);

void	swap_values(t_stack *stack, char type);
void	rotate(t_stack *stack, char type);
void	reverse_rotate(t_stack *stack, char type);
void	push_node(t_node **stack, t_node *node_to_push);
void	push_a(t_stack *stack);
void	push_b(t_stack *stack);
void	print_stack(t_stack stack, char type);

void	find_max(t_stack *stack, char type);

#endif
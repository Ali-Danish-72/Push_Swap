/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:43:27 by mdanish           #+#    #+#             */
/*   Updated: 2023/11/30 19:33:30 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

/*****************************************************************************/
/*									STRUCTS									 */
/*****************************************************************************/
typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*a;
	t_node			*b;
	int				size_a;
	int				size_b;
	int				max_a;
	int				max_b;
	int				min_a;
	int				min_b;
	int				cheapest_move;
	int				a_rot;
	int				a_rev_rot;
	int				b_rot;
	int				b_rev_rot;
}					t_stack;

/*****************************************************************************/
/*									PARSING									 */
/*****************************************************************************/
int		validate_integer(char *input, long int *value);
long	*splitter(int ac, char **av, int *num_count, long int *values);
t_stack	create_stack(long int *values, long int *store, int num_ctr, int ac);
t_stack	parse(int ac, char **av);
void	check_duplicates_and_sort(int count, long int *values);

/*****************************************************************************/
/*								  OPERATIONS								 */
/*****************************************************************************/
void	push(t_stack *stack, char type);
void	push_node(t_node **stack, t_node *node_to_push);
void	reverse_rotate(t_stack *stack, char type);
void	rotate(t_stack *stack, char type);
void	swap_values(t_stack *stack, char type);

/*****************************************************************************/
/*									SORTING									 */
/*****************************************************************************/
int		set_b_moves(t_stack *stack, int value, t_node *send_to_top);
int		send_b_max_to_the_top(t_stack *stack, t_node *send_to_top);
void	execute_rotations(t_stack *stack);
void	find_cheapest_move_to_b(t_stack *stack);
void	reset_stack(t_stack *stack);
void	send_min_to_top(t_stack *stack);
void	send_the_node_to_b(t_stack *stack);
void	set_rotations(t_stack *stack, t_node a_to_top, t_node b_to_top);
void	set_stack_b_straight(t_stack *stack);
void	sort(t_stack *stack);
void	sort_three(t_stack *stack);

/*****************************************************************************/
/*									STACK									 */
/*****************************************************************************/
void	call_exit(int status, void *values, void *ptr);
void	clear_stack_and_exit(int status, void *values, t_stack stack);
void	find_max(t_node stack, int *max, int stack_size);
void	find_min(t_node stack, int *min, int stack_size);
void	initialize_the_stack(t_stack *stack);
void	list_size(t_stack *stack, int measure_a, int measure_b);

//	PROGRAM EXIT CODES:
//	0 = Successful completion of the program.
//	1 = Malloc fail while creating the stack.
//	2 = Malloc fail while parsing the parameters.
//	3 = Characters other than integers detected.
//	4 = Parameter is outside the range of an type int.
//	5 = Duplicate parameters detected.

#endif
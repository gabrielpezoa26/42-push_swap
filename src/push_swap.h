/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:55:04 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/02/14 13:35:28 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_list
{
	int				index;
	int				value;
	struct s_list	*next;
}				t_stack;

/*--------PARSER--------*/
t_stack	*init_stack_a(char **argv);
void	free_split_argv(char **split_argv);
int		validate_input(int *argc, char ***argv, char ***split_argv_ref);

/*--------OPERATIONS--------*/
// swap
void	sa(t_stack **stack);
void	sb(t_stack **stack);
void	ss(t_stack **stack_a, t_stack **stack_b);

// pushes
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);

// rotates
void	rb(t_stack **b);
void	ra(t_stack **a);
void	rr(t_stack **a, t_stack **b);

// reverse_rotates
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

/*------SORT_SMALL--------*/
void	sort_three(t_stack **list);
void	sort_four(t_stack **a, t_stack **b);
void	sort_five(t_stack **a, t_stack **b);

/*-------SORT_LARGE-------*/
void	radix(t_stack **stack_a, t_stack **stack_b);

/*---------UTILS--------*/
int		has_duplicates(t_stack *stack, int n);
void	free_stack(t_stack **stack);
t_stack	*find_last(t_stack *stack);
int		stack_size(t_stack *list);
void	assign_indices(t_stack *list);

/*--------SORT_UTILS----*/
void	sort_three_helper(t_stack **list);
int		is_sorted(t_stack **list);

/*--------PARSE_UTILS----*/
int		process_single_argument(int *argc, char ***argv);
int		check_arguments(int argc, char **argv);

#endif
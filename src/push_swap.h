/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:55:04 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/02/11 21:46:03 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"
# include <stdbool.h>

typedef struct s_stack
{
	int				number;
	int				index;
	int				value;
	struct s_stack	*next;
	struct s_stack	*before;
}				t_stack;

// --------PARSER--------
int		validate_input(int arg_count, char **arg_value);
t_stack	*init_stack_a(char **argv);

// --------OPERATIONS--------

// swap
void	sa(t_stack **stack);
void	sb(t_stack **stack);
void	ss(t_stack **stack_a, t_stack **stack_b);

// pushes
void pa(t_stack **a, t_stack **b, bool print);
void pb(t_stack **a, t_stack **b, bool print);

// rotate
void	ra(t_stack_point **a, bool print);
void	rb(t_stack_point **b, bool print);
void	rr(t_stack_point **a, t_stack_point **b, bool print);

// --------UTILS--------
int has_duplicates(t_stack *stack, int n);
void	free_stack(t_stack **stack);
#endif
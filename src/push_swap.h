/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:55:04 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/02/11 22:34:44 by gabriel          ###   ########.fr       */
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
	// struct s_stack	*before;
}				t_node;

// --------PARSER--------
t_node	*init_stack_a(char **argv);
int		validate_input(int arg_count, char **arg_value);

// --------OPERATIONS--------
// swap
void	sa(t_node **stack);
void	sb(t_node **stack);
void	ss(t_node **stack_a, t_node **stack_b);

// pushes
void pa(t_node **a, t_node **b, bool print);
void pb(t_node **a, t_node **b, bool print);

// rotate
void	rb(t_node **b, bool print);
void	ra(t_node **a, bool print);
void	rr(t_node **a, t_node **b, bool print);

// --------UTILS--------
int has_duplicates(t_node *stack, int n);
void	free_stack(t_node **stack);
t_node *find_last(t_node *stack);
#endif
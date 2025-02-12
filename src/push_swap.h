/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:55:04 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/02/12 17:42:29 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"
# include <stdbool.h>

typedef struct s_list
{
	int				index;
	int				value;
	struct s_list	*next;
}				t_stack;

/*--------PARSER--------*/
t_stack	*init_stack_a(char **argv);
int		validate_input(int arg_count, char **arg_value);

/*--------OPERATIONS--------*/
// swap
void	sa(t_stack **stack);
void	sb(t_stack **stack);
void	ss(t_stack **stack_a, t_stack **stack_b);

// pushes
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);

// rotate
void	rb(t_stack **b);
void	ra(t_stack **a);
void	rr(t_stack **a, t_stack **b);

// reverse_rotate
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

/*------SORT_SMALL--------*/
void	sort_three(t_stack **list);
void	sort_five(t_stack **a, t_stack **b);

/*-------SORT_LARGE-------*/
void	ft_radix(t_stack *list);

/*---------UTILS--------*/
int		has_duplicates(t_stack *stack, int n);
void	free_stack(t_stack **stack);
t_stack	*find_last(t_stack *stack);
int		list_size(t_stack *list);
void	assign_indices(t_stack *list);

int		ft_lstsize_mod(t_stack *mango);

//------TESTE-----
// void potato_mango_teste(t_node *list);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:55:04 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/02/11 18:31:31 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"

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

// swaps
void	sa(t_stack **stack);
void	sb(t_stack **stack);
void	ss(t_stack **stack_a, t_stack **stack_b);

//pushes
// --------UTILS--------
int		has_duplicates(t_stack *stack, int n);
void	free_stack(t_stack **stack);
#endif
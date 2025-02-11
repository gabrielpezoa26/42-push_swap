/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_pushes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:40:51 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/02/11 17:27:38 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void push(t_stack **dest, t_stack**src)
{
	t_stack *push_point;

	if (*src == NULL)
		return ;
	push_point = *src;
	*src = (*src)-> next;
	if (*src != NULL)
		(*src)->before = NULL;
	push_point->before == NULL;
	
}

void	pa(t_stack_node **a, t_stack_node **b, bool print)
{
	push(a, b); 
	if (!print) 
		ft_printf("pa\n");
}

void	pb(t_stack_node **a, t_stack_node **b, bool print)
{
	push(b, a); 
	if (!print) 
		ft_printf("pb\n");
}

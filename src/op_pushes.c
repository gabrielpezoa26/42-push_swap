/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_pushes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:40:51 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/02/11 21:42:03 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **dest, t_stack **src)
{
	t_stack	*push_point;

	if (!*src)
		return ;
	push_point = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->before = NULL;
	push_point->before = NULL;
	if (!*dest)
	{
		*dest = push_point;
		push_point->next = NULL;
	}
	else
	{
		push_point->next = *dest;
		push_point->next->before = push_point;
		*dest = push_point;
	}
}

void	pa(t_stack **a, t_stack **b, bool print)
{
	push(a, b); 
	if (!print) 
		ft_printf("pa\n");
}

void	pb(t_stack **a, t_stack **b, bool print)
{
	push(b, a);
	if (!print)
		ft_printf("pb\n");
}

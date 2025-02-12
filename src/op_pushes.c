/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_pushes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:40:51 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/02/11 22:35:50 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_node **dest, t_node **src)
{
	t_node	*push_point;

	if (!src || !*src)
		return ;
	push_point = *src;
	*src = (*src)->next;
	push_point->next = *dest;
	*dest = push_point;
}

void	pa(t_node **a, t_node **b, bool print)
{
	push(a, b);
	if (!print)
		ft_printf("pa\n");
}

void	pb(t_node **a, t_node **b, bool print)
{
	push(b, a);
	if (!print)
		ft_printf("pb\n");
}

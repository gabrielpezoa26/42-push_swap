/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 22:09:31 by gabriel           #+#    #+#             */
/*   Updated: 2025/02/13 00:05:24 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	execute_sort_three(t_stack **list)
{
	int	a;
	int	b;
	int	c;

	a = (*list)->value;
	b = (*list)->next->value;
	c = (*list)->next->next->value;
	if (a > b && b > c)
	{
		sa(list);
		rra(list);
	}
	else if (a > c && c > b)
		ra(list);
	else if (b > a && a > c)
		sa(list);
	else if (b > c && c > a)
		rra(list);
	else if (c > a && a > b)
		rra(list);
}

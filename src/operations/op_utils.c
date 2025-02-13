/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 22:09:31 by gabriel           #+#    #+#             */
/*   Updated: 2025/02/13 00:18:28 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	apply_sort_three(t_stack **list, int a, int b, int c)
{
	if (a > b && b > c)
	{
		sa(list);
		rra(list);
	}
	else if (a > c && c > b)
		ra(list);
	else if (a > b && a < c)
		sa(list);
	else if (b > a && a > c)
		rra(list);
	else if (b > c && c > a)
	{
		sa(list);
		ra(list);
	}
}

void	execute_sort_three(t_stack **list)
{
	int	a;
	int	b;
	int	c;

	a = (*list)->value;
	b = (*list)->next->value;
	c = (*list)->next->next->value;
	if (a > b && b > c)      // 3 2 1 → sa + rra
	{
		sa(list);
		rra(list);
	}
	else if (a > c && c > b) // 3 1 2 → ra
		ra(list);
	else if (a < b && b > c && a < c) // 1 3 2 (Middle is exactly in second position)
	{
		rra(list);
		sa(list);
	}
	else if (a > b && a < c) // 2 1 3 → sa
		sa(list);
	else if (b > a && a > c) // 2 3 1 → rra
		rra(list);
	else if (b > c && c > a) // 1 3 2 → sa + ra
	{
		sa(list);
		ra(list);
	}
}

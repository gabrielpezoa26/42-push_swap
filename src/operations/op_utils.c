/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 22:09:31 by gabriel           #+#    #+#             */
/*   Updated: 2025/02/12 22:31:04 by gabriel          ###   ########.fr       */
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
	if (a > b && b > c) // 3 2 1 → Swap + Reverse Rotate
	{
		sa(list);
		rra(list);
	}
	else if (a > c && c > b) // 3 1 2 → Rotate
		ra(list);
	else if (b > a && a > c) // 2 1 3 → Swap
		sa(list);
	else if (b > c && c > a) // 1 3 2 → Reverse Rotate
		rra(list);
	else if (c > a && a > b) // 2 3 1 → Reverse Rotate
		rra(list);
}

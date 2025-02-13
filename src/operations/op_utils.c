/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 22:09:31 by gabriel           #+#    #+#             */
/*   Updated: 2025/02/13 01:09:33 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(t_stack **list)
{
	t_stack	*current;

	current = *list;
	while (current && current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

static void	handle_middle_in_second(t_stack **list)
{
	rra(list);
	sa(list);
}

static void	apply_sort_three(t_stack **list, int a, int b, int c)
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
	if (a < b && b > c && a < c)
		handle_middle_in_second(list);
	else
		apply_sort_three(list, a, b, c);
}

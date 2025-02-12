/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 22:52:11 by gabriel           #+#    #+#             */
/*   Updated: 2025/02/11 23:35:06 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_node **list)
{
	int	a;
	int	b;
	int	c;

	if (!*list || !(*list)->next || !(*list)->next->next)
		return ;
	a = (*list)->value;
	b = (*list)->next->value;
	c = (*list)->next->next->value;
	if (a > b && b > c)
	{
		sa(list, true);
		rra(list, true);
	}
	else if (a > c && c > b)
		ra(list, true);
	else if (b > a && a > c)
	{
		sa(list, true);
		ra(list, true);
	}
	else if (b > c && c > a)
		rra(list, true);
	else if (c > a && a > b)
		sa(list, true);
}

static t_node	*find_min(t_node *list)
{
	t_node	*min;

	min = list;
	while (list)
	{
		if (list->value < min->value)
			min = list;
		list = list->next;
	}
	return (min);
}

void	sort_five(t_node **a, t_node **b)
{
	t_node	*min;

	if (list_size(*a) != 5)
		return ;
	min = find_min(*a);
	while (*a != min)
		ra(a, true);
	pb(a, b, true);
	if (list_size(*a) == 4)
	{
		min = find_min(*a);
		while (*a != min)
			ra(a, true);
		pb(a, b, true);
	}
	sort_three(a);
	pa(a, b, true);
	pa(a, b, true);
}

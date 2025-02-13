/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 22:52:11 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/02/13 18:14:36 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_stack	*find_min(t_stack *list)
{
	t_stack	*min;

	if (!list)
		return (NULL);
	min = list;
	while (list)
	{
		if (list->value < min->value)
			min = list;
		list = list->next;
	}
	return (min);
}

void	sort_three(t_stack **list)
{
	if (!*list || !(*list)->next || !(*list)->next->next)
		return ;
	sort_three_helper(list);
}

void	sort_four(t_stack **a, t_stack **b)
{
	t_stack	*min;

	min = find_min(*a);
	if (*a == min)
	{
		pb(a, b);
		sort_three(a);
		pa(a, b);
		return ;
	}
	while (*a != min)
		ra(a);
	pb(a, b);
	sort_three(a);
	pa(a, b);
}

void	sort_five(t_stack **a, t_stack **b)
{
	t_stack	*min;

	if (stack_size(*a) != 5)
		return ;
	min = find_min(*a);
	while (*a != min)
		ra(a);
	pb(a, b);
	if (stack_size(*a) == 4)
	{
		min = find_min(*a);
		while (*a != min)
			ra(a);
		pb(a, b);
	}
	sort_three(a);
	pa(a, b);
	pa(a, b);
}

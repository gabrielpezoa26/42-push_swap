/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 22:52:11 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/02/12 17:51:11 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_stack	*find_min(t_stack *list)
{
	t_stack	*min;

	min = list;
	while (list)
	{
		if (list->value < min->value)
			min = list;
		list = list->next;
	}
	return (min);
}

void	sort_five(t_stack **a, t_stack **b)
{
	t_stack	*min;

	// ft_printf("sort five\n");  //debug
	if (list_size(*a) != 5)
		return ;
	min = find_min(*a);
	while (*a != min)
		ra(a);
	pb(a, b);
	if (list_size(*a) == 4)
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

void	sort_three(t_stack **list)
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
		sa(list);
		rra(list);
	}
	else if (a > c && c > b)
		ra(list);
	else if (b > a && a > c)
	{
		sa(list);
		ra(list);
	}
	else if (b > c && c > a)
		rra(list);
	else if (c > a && a > b)
		sa(list);
}

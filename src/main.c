/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 23:41:46 by gabriel           #+#    #+#             */
/*   Updated: 2025/02/13 11:18:34 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	decide_approach(t_stack **a, t_stack **b)
{
	int	size;

	if (is_sorted(a))
		return ;
	size = list_size(*a);
	if (size == 2)
	{
		if ((*a)->value > (*a)->next->value)
			sa(a);
	}
	else if (size == 3)
		sort_three(a);
	else if (size == 4)
		sort_four(a, b);
	else if (size == 5)
		sort_five(a, b);
	else if (size > 5)
	{
		assign_indices(*a);
		radix(a, b);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (validate_input(argc, argv) != 0)
		return (1);
	a = init_stack_a(argv + 1);
	b = NULL;
	if (!a)
	{
		ft_printf("Error\n");
		return (1);
	}
	decide_approach(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}

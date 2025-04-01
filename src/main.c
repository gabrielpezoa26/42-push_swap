/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 23:41:46 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/04/01 13:21:16 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	decide_approach(t_stack **a, t_stack **b)
{
	int	size;

	if (is_sorted(a))
		return ;
	size = stack_size(*a);
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
	else
	{
		assign_indices(*a);
		radix(a, b);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**split_argv;

	split_argv = NULL;
	if (validate_input(&argc, &argv, &split_argv) == 1)
		return (1);
	a = init_stack_a(argv + 1);
	b = NULL;
	if (!a)
	{
		ft_printf("Error\n");
		free_split_argv(split_argv);
		return (1);
	}
	decide_approach(&a, &b);
	free_stack(&a);
	free_stack(&b);
	free_split_argv(split_argv);
	return (0);
}

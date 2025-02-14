/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 23:41:46 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/02/13 21:22:18 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	decide_approach(t_stack **a, t_stack **b)
{
	int	size;

	if (is_sorted(a) != 0)
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
	else if (size > 5)
	{
		assign_indices(*a);
		radix(a, b);
	}
}

static void free_split(char **split)
{
	int i;

	i = 0;
	while(split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (validate_input(&argc, &argv) == 1)
	{
		free_split(argv);
		return (1);
	}
	a = init_stack_a(argv + 1);
	b = NULL;
	if (!a)
	{
		free_split(argv);
		ft_printf("Error\n");
		return (1);
	}
	decide_approach(&a, &b);
	free_stack(&a);
	free_stack(&b);
	// free_split(argv);
	return (0);
}

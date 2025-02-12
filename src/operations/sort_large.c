/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 22:53:45 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/02/12 20:38:22 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	count_bits(t_stack **potato)
{
	t_stack *top;
	int max = 0;
	int bit_count = 0;

	top = *potato;
	while (top)
	{
		if (top->index > max)
			max = top->index;
		top = top->next;
	}
	while ((max >> bit_count) > 0)
		bit_count++;
	return (bit_count);
}

void radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *top_a;
	int i = 0, j;
	int size = ft_lstsize_mod(*stack_a);
	int max_bits = count_bits(stack_a);

	while (i < max_bits)
	{
		j = 0;
		top_a = *stack_a;
		while (j < size)
		{
			if (((top_a->index >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			top_a = *stack_a;
			j++;
		}
		while (*stack_b)
			pa(stack_a, stack_b);
		i++;
	}
}
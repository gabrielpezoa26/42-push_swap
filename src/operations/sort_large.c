/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 22:53:45 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/02/12 18:09:14 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	count_bits(t_stack **potato)
{
	t_stack	*top;
	int		max;
	int		bit_count;

	top = *potato;
	max = top->index;
	bit_count = 0;
	while (top)
	{
		if (top->index > max)
			max = top->index;
		top = top->next;
	}
	ft_printf("\nsaiu primeiro while\n");
	ft_printf("bit count:  %d\n", bit_count);
	ft_printf("max:  %d\n", max);
	while ((max >> bit_count) != 0)
	{
		bit_count++;
	}
	ft_printf("fimm\n");
	return (bit_count);
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*top_a;
	int		i;
	int		j;
	int		size;
	int		max_bits;

	i = 0;
	top_a = *stack_a;
	size = ft_lstsize_mod(top_a);
	max_bits = count_bits(stack_a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			top_a = *stack_a;
			if (((top_a->index >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (ft_lstsize_mod(*stack_b) != 0)
			pa(stack_a, stack_b);
		i++;
	}
	ft_printf("exittttt");
}

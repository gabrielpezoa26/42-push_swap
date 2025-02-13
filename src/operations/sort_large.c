/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 22:53:45 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/02/13 18:14:38 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_lstsize_mod(t_stack *list)
{
	int	index;

	index = 0;
	while (list != NULL)
	{
		index++;
		list = list->next;
	}
	return (index);
}

static int	count_bits(t_stack **stack)
{
	t_stack	*top;
	int		max;
	int		bit_count;

	top = *stack;
	max = 0;
	bit_count = 0;
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

void	radix(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	int		j;
	int		size;
	int		max_bits;

	i = 0;
	size = ft_lstsize_mod(*stack_a);
	max_bits = count_bits(stack_a);
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if ((((*stack_a)->index >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			j++;
		}
		while (*stack_b)
			pa(stack_a, stack_b);
		i++;
	}
}

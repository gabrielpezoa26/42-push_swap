/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swaps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 10:42:10 by gabriel           #+#    #+#             */
/*   Updated: 2025/02/11 22:30:07 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **stack)
{
	t_node	*first;
	t_node	*second;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
	ft_printf("sa\n");
}

void	sb(t_node **stack)
{
	t_node	*first;
	t_node	*second;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
	ft_printf("sb\n");
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	sa(stack_a);
	sb(stack_b);
	ft_printf("ss\n");
}

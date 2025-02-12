/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:52:55 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/02/11 22:30:07 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*stack;
	t_node	*temp;

	if (validate_input(argc, argv) != 0)
		return (1);
	stack = init_stack_a(argv + 1);
	if (stack == NULL)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	//teste
	temp = stack;
	while (temp)
	{
		ft_printf("Stack value: %d\n", temp->value);
		temp = temp->next;
	}
	free_stack(&stack);
	return (0);
}

/*
	parser:  verifica se eh numero, qtde, aspas,
	operações: implementar as 11 op
	sorting: depende da qtde de numeros
	tratar edge cases: sem input, já organizado, um nºo só
*/
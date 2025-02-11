/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:52:55 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/02/11 18:28:56 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack;
	t_stack	*temp;

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
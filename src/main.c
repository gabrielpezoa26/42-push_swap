/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:52:55 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/02/04 12:59:40 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack **stack1;
	t_stack **stack2;

	if (!validate_input(argc, argv))
		return (1);
		
	
}

/*
	parser:  verifica se eh numero, qtde, aspas,
	operações: implementar as 11 op
	sorting: depende da qtde de numeros
	tratar edge cases: sem input, já organizado, um nºo só
*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 21:40:23 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/02/04 12:57:21 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_number(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	validate_input(int arg_count, char **arg_value)
{
	int		flag;
	char	*param1;
	char	*param2;

	flag = 0;
	param1 = arg_value[1];
	param2 = arg_value[2];
	if (arg_count != 3)
		ft_printf("Errorrrrr\n");
	if (arg_count == 3 && (!is_number(param1) || !is_number(param2)))
	{
		flag = 1;
		return (flag);
	}
	return (0);
}

/*    PDF:
• If no parameters are specified, the program must not display anything and give the
prompt back.
• In case of error, it must display "Error" followed by a ’\n’ on the standard error.
Errors include for example: some arguments aren’t integers, some arguments are
bigger than an integer and/or there are duplicates.

*/
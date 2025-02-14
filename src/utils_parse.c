/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:55:23 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/02/13 22:54:05 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_number(char *str)
{
	int	i;

	if (str == NULL || *str == '\0')
		return (0);
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

static char	**parse_input_string(char **argv, int *argc)
{
	char	*tmp_str;
	char	**split_argv;
	int		count;

	tmp_str = ft_strjoin("0 ", argv[1]);
	if (!tmp_str)
		return (NULL);
	split_argv = ft_split(tmp_str, ' ');
	free(tmp_str);
	count = 0;
	while (split_argv && split_argv[count])
		count++;
	*argc = count;
	return (split_argv);
}

int	process_single_argument(int *argc, char ***argv)
{
	char	**new_argv;

	if (!(*argv)[1][0])
	{
		ft_printf("Error\n");
		return (1);
	}
	new_argv = parse_input_string(*argv, argc);
	if (!new_argv)
		return (1);
	*argv = new_argv;
	return (0);
}

int	check_arguments(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (check_number(argv[i]) == 0)
		{
			ft_printf("Error\n");
			return (1);
		}
		i++;
	}
	return (0);
}

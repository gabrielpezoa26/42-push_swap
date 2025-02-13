/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 23:43:14 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/02/13 17:15:31 by gcesar-n         ###   ########.fr       */
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

static char	**mango(char **argv, int *argc)
{
	char	*new_argv;
	char	**split_argv;

	new_argv = ft_strjoin("0 ", argv[1]);
	if (!new_argv)
		return (NULL);
	split_argv = ft_split(new_argv, ' ');
	free(new_argv);
	*argc = 0;
	while (split_argv[*argc])
		(*argc)++;
	return (split_argv);
}

int	validate_input(int *argc, char ***argv)
{
	int	i;
	char	**new_argv;

	if (*argc < 2)
		return (1);
	if (*argc == 2 && !(*argv)[1][0])
	{
		ft_printf("Error\n");
		return (1);
	}
	if (*argc == 2)
	{
		new_argv = mango(*argv, argc);
		if (!new_argv)
			return (1);
		*argv = new_argv;
	}
	i = 1;
	while (i < *argc)
	{
		if (check_number((*argv)[i]) == 0)
		{
			ft_printf("Error\n");
			return (1);
		}
		i++;
	}
	return (0);
}

// int	validate_input(int argc, char **argv)
// {
// 	int	i;

// 	if (argc < 2)
// 		return (1);
// 	if (argc == 2 && !argv[1][0])
// 		ft_printf("Error");
// 	if (argc == 2 && argv[1][0])
// 		argv = mango(argv);
// 	i = 1;
// 	while (i < argc)
// 	{
// 		if (check_number(argv[i]) == 0)
// 		{
// 			ft_printf("Error\n");
// 			return (1);
// 		}
// 		i++;
// 	}
// 	return (0);
// }

static long	ft_atol(const char *s, int *error)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*s == ' ' || *s == '\t' || *s == '\n'
		|| *s == '\r' || *s == '\f' || *s == '\v')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (ft_isdigit(*s) != 0)
	{
		result = result * 10 + (*s++ - '0');
		if ((result * sign) > INT_MAX || (result * sign) < INT_MIN)
		{
			*error = 1;
			return (0);
		}
	}
	return (result * sign);
}

static void	append_node(t_stack **stack, int n)
{
	t_stack	*node;
	t_stack	*last_node;

	node = malloc(sizeof(t_stack));
	if (node == NULL)
		return ;
	node->next = NULL;
	node->value = n;
	node->index = -1;
	if (!(*stack))
		*stack = node;
	else
	{
		last_node = *stack;
		while (last_node->next)
			last_node = last_node->next;
		last_node->next = node;
	}
}

t_stack	*init_stack_a(char **argv)
{
	t_stack	*stack;
	long	n;
	int		i;
	int		error;

	stack = NULL;
	i = 0;
	while (argv[i])
	{
		error = 0;
		n = ft_atol(argv[i], &error);
		if (error || has_duplicates(stack, (int)n))
		{
			free_stack(&stack);
			return (NULL);
		}
		append_node(&stack, (int)n);
		i++;
	}
	return (stack);
}

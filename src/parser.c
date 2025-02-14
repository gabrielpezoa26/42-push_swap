/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 23:43:14 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/02/14 15:32:43 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split_argv(char **split_argv)
{
	int	i;

	if (!split_argv)
		return ;
	i = 0;
	while (split_argv[i])
	{
		free(split_argv[i]);
		i++;
	}
	free(split_argv);
}

int	validate_input(int *argc, char ***argv, char ***split_argv_ref)
{
	if (*argc < 2)
		return (1);
	if (*argc == 2)
	{
		if (process_single_argument(argc, argv) == 1)
			return (1);
		*split_argv_ref = *argv;
	}
	return (check_arguments(*argc, *argv));
}

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

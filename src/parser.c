/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 23:43:14 by gabriel           #+#    #+#             */
/*   Updated: 2025/02/11 22:46:42 by gabriel          ###   ########.fr       */
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

int	validate_input(int argc, char **argv)
{
	int	i;

	if (argc < 2)
		return (1);
	i = 1;
	while (i < argc)
	{
		if (check_number(argv[i]) == 0)
		{
			ft_printf("Errorrrr, not a number :(");
			return (1);
		}
		ft_printf("Arg %d: %s\n", i, argv[i]);
		i++;
	}
	return (0);
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

static void	append_node(t_node **stack, int n)
{
	t_node	*node;
	t_node	*last_node;

	node = malloc(sizeof(t_node));
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

t_node	*init_stack_a(char **argv)
{
	t_node	*stack;
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

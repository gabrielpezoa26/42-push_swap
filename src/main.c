/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 23:41:46 by gabriel           #+#    #+#             */
/*   Updated: 2025/02/12 17:44:23 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_stack **a, t_stack **b)
{
	int	size;

	size = list_size(*a);
	ft_printf("sort_stack\n");
	if (size == 2)
		sa(a);
	else if (size == 3)
		sort_three(a);
	else if (size == 5)
		sort_five(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (validate_input(argc, argv) != 0)
		return (1);
	a = init_stack_a(argv + 1);
	b = NULL;
	if (!a)
	{
		ft_printf("Errorrrr :( ");
		return (1);
	}
	sort_stack(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}

//TESTEEEE
// void	potato_mango_teste(t_node *list)
// {
// 	while (list)
// 	{
// 		ft_printf("%d ", list->value);
// 		list = list->next;
// 	}
// 	ft_printf("\n");
// }

// int	main(int argc, char **argv)  //teste
// {
// 	t_node	*a;
// 	t_node	*b;

// 	if (validate_input(argc, argv) != 0)
// 		return (1);
// 	a = init_stack_a(argv + 1);
// 	b = NULL;
// 	if (!a)
// 	{
// 		ft_printf("errorrr :(  ");
// 		return (1);
// 	}
// 	ft_printf("Before sorting: ");
// 	potato_mango_teste(a);

// 	if (list_size(a) == 5)
// 		sort_five(&a, &b);

// 	ft_printf("After sorting: ");
// 	potato_mango_teste(a);
// 	free_stack(&a);
// 	free_stack(&b);
// 	return (0);
// }

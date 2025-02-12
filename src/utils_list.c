/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:19:01 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/02/12 18:04:24 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize_mod(t_stack *mango)
{
	int	index;

	index = 0;
	while (mango != NULL)
	{
		index++;
		mango = mango->next;
	}
	return (index);
}

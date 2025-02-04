/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:19:41 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/02/03 22:57:41 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stack_node	*ft_lstnew(void *content)
{
	t_stack_node	*mango_loko;

	mango_loko = malloc(sizeof(t_stack_node));
	if (mango_loko == NULL)
	{
		return (NULL);
	}
	mango_loko->content = content;
	mango_loko->next = NULL;
	return (mango_loko);
}

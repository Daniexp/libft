/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 16:57:58 by dexposit          #+#    #+#             */
/*   Updated: 2022/02/01 18:06:32 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_block;

	new_block = malloc(sizeof(t_list));
	if (!new_block)
		return (0);
	new_block->content = content;
	new_block->next = 0;
	return (new_block);
}

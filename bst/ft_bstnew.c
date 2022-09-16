/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:04:15 by dexposit          #+#    #+#             */
/*   Updated: 2022/09/16 15:01:34 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_bst	*ft_bstnew(void *content)
{
	t_bst	*new_node;

	new_node = (t_bst *) malloc(sizeof(t_bst));
	if (!new_node)
		return (0);
	new_node->content = content;
	new_node->left = 0;
	new_node->right = 0;
	return (new_node);	
}

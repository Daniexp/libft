/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 16:15:02 by dexposit          #+#    #+#             */
/*   Updated: 2022/01/25 19:04:56 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char		*d;
	const char	*s;
	char		*lasts;
	char		*lastd;

	d = dest;
	s = src;
	if (s > d)
	{
		while (len--)
		{
			*d++ = *s++;
		}
	}
	else
	{
		lasts = (char *)s + (len - 1);
		lastd = d + (len - 1);
		while (len--)
		{
			*lastd-- = *lasts--;
		}
	}
	return (dest);
}

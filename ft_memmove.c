/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreouven <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 00:30:58 by sreouven          #+#    #+#             */
/*   Updated: 2017/11/13 00:31:05 by sreouven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (dst < src)
		while (i < len)
		{
			((char*)dst)[i] = ((char*)src)[i];
			i += 1;
		}
	else
		while (len > 0)
		{
			((char*)dst)[len - 1] = ((char*)src)[len - 1];
			len -= 1;
		}
	return (dst);
}

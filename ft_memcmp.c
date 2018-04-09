/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreouven <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 00:30:30 by sreouven          #+#    #+#             */
/*   Updated: 2017/11/13 00:46:05 by sreouven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*u1;
	char	*u2;

	i = 0;
	u1 = (char*)s1;
	u2 = (char*)s2;
	while (i < n)
	{
		if (u1[i] != u2[i])
			return ((unsigned char)u1[i] - (unsigned char)u2[i]);
		i += 1;
	}
	return (0);
}

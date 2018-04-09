/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreouven <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 00:38:51 by sreouven          #+#    #+#             */
/*   Updated: 2017/11/13 01:02:09 by sreouven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*frch;
	size_t	j;

	j = 0;
	frch = NULL;
	if (s == NULL)
		return (NULL);
	if (!(frch = ft_strnew(len)))
		return (NULL);
	if (len > 0)
	{
		while (j < len)
		{
			frch[j] = s[start + j];
			j += 1;
		}
	}
	frch[j] = '\0';
	return (frch);
}

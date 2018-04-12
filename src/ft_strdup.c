/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreouven <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 00:34:57 by sreouven          #+#    #+#             */
/*   Updated: 2018/03/19 14:05:11 by sreouven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dst;
	int		i;

	i = 0;
	if (!s1)
		return (NULL);
	if (!(dst = (char*)(malloc(sizeof(char) * ft_strlen(s1) + 1))))
		return (NULL);
	while (s1[i] != '\0')
	{
		dst[i] = s1[i];
		i += 1;
	}
	dst[i] = '\0';
	return (dst);
}

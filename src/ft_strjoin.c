/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreouven <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 00:35:45 by sreouven          #+#    #+#             */
/*   Updated: 2017/11/13 09:35:01 by sreouven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (!(s = (char*)malloc(sizeof(s) * ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	while (s1[j] != '\0')
	{
		s[i] = s1[j];
		i += 1;
		j += 1;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		s[i] = s2[j];
		i += 1;
		j += 1;
	}
	s[i] = '\0';
	return (s);
}

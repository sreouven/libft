/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreouven <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 00:38:33 by sreouven          #+#    #+#             */
/*   Updated: 2017/11/13 10:36:59 by sreouven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		nb_mot(char const *s, char c)
{
	int		i;
	int		mots;

	i = 0;
	mots = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i += 1;
		if (s[i] != c && s[i] != '\0')
			mots += 1;
		while (s[i] != c && s[i] != '\0')
			i += 1;
	}
	return (mots);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		j;
	size_t	len;

	if (!s)
		return (NULL);
	j = nb_mot(s, c);
	if (!(tab = malloc(sizeof(tab) * j + 1)))
		return (NULL);
	tab[j] = 0;
	while (*s)
	{
		len = 0;
		while (*s == c && *s)
			s++;
		while (*s != c && *s)
		{
			len += 1;
			s++;
		}
		if (len > 0)
			*tab++ = ft_strsub((s - len), 0, len);
	}
	return (tab - j);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreouven <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 00:39:04 by sreouven          #+#    #+#             */
/*   Updated: 2017/11/13 00:59:50 by sreouven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		ft_first(char const *s)
{
	int		i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i += 1;
	return (i);
}

static int		ft_last(char const *s)
{
	int	j;

	j = ft_strlen(s) - 1;
	while (s[j] == ' ' || s[j] == '\t' || s[j] == '\n')
		j -= 1;
	return (j);
}

char			*ft_strtrim(char const *s)
{
	char	*frch;
	int		len;

	if (!s)
		return (NULL);
	len = ft_last(s) - ft_first(s);
	len = (len < 0) ? -len : len;
	frch = NULL;
	frch = ft_strsub(s, ft_first(s), len + 1);
	return (frch);
}

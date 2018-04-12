/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreouven <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 00:38:19 by sreouven          #+#    #+#             */
/*   Updated: 2017/11/13 00:38:26 by sreouven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*tmp;

	i = ft_strlen(s);
	tmp = NULL;
	while (s[i] != c && i >= 0)
		i -= 1;
	if (c == s[i] || !c)
		return (tmp = (char*)s + i);
	return (tmp);
}

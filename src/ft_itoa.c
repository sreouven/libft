/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreouven <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 09:02:43 by sreouven          #+#    #+#             */
/*   Updated: 2017/11/13 09:03:22 by sreouven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		ft_countlen(long nb)
{
	int		len;

	len = 0;
	if (nb <= 0)
	{
		nb = -nb;
		len += 1;
	}
	while (nb > 0)
	{
		nb /= 10;
		len += 1;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	nb;

	nb = n;
	len = ft_countlen(nb);
	nb = ((nb < 0) ? -nb : nb);
	if (!(str = (char*)malloc(sizeof(str) * len + 1)))
		return (NULL);
	str[len] = '\0';
	while (nb >= 0 && len > 0)
	{
		str[--len] = (nb % 10) + '0';
		nb /= 10;
	}
	if (n < 0)
		str[len] = '-';
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreouven <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 14:47:11 by sreouven          #+#    #+#             */
/*   Updated: 2018/03/19 14:47:18 by sreouven         ###   ########.fr       */
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

char			*ft_itoa_base(int n)
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

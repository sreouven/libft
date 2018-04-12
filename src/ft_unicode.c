/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unicode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreouven <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 13:24:44 by sreouven          #+#    #+#             */
/*   Updated: 2018/03/19 17:24:04 by sreouven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <wchar.h>
#include <stdlib.h>
#include "ft_printf.h"

char	*ft_ctos(int c)
{
	char *str;

	if (!(str = ft_strnew(2)))
		return (NULL);
	str[0] = c;
	return (str);
}

int		ft_wclen(wchar_t c)
{
	if ((MB_CUR_MAX == 1 && c > 0xFF) || c < 0 || (c >= 0xD800 && c < 0xE000))
		return (0);
	if ((c <= 0x7F && MB_CUR_MAX >= 1) || (c <= 0xFF && MB_CUR_MAX == 1))
		return (1);
	else if (c <= 0x7FF && MB_CUR_MAX >= 2)
		return (2);
	else if (c <= 0xFFFF && MB_CUR_MAX >= 3)
		return (3);
	else if (c <= 0x10FFFF && MB_CUR_MAX >= 4)
		return (4);
	return (0);
}

int		ft_putwc(wchar_t c)
{
	int size;

	size = ft_wclen(c);
	if (size != -1)
	{
		return (write(1, &c, size));
	}
	return (-1);
}

int		ft_wcslen(wchar_t *s)
{
	int size;

	size = 0;
	if (!s)
		return (-1);
	while (*s)
	{
		if (!(ft_wclen(*s)))
			return (-1);
		size += ft_wclen(*s);
		s++;
	}
	return (size);
}

char	*ft_wctostr(wchar_t c)
{
	char *str;

	if (!(str = ft_strnew(ft_wclen(c))))
		return (NULL);
	if ((c <= 0x7F && MB_CUR_MAX >= 1) || (c <= 0xFF && MB_CUR_MAX == 1))
		str[0] = (unsigned char)c;
	else if (c <= 0x7FF && MB_CUR_MAX >= 2)
	{
		str[0] = (c >> 6) | 0xC0;
		str[1] = (c & 0x3F) | 0x80;
	}
	else if (c <= 0xFFFF && MB_CUR_MAX >= 3)
	{
		str[0] = (c >> 12) | 0xE0;
		str[1] = (c >> 6 & 0x3F) | 0x80;
		str[2] = (c & 0x3F) | 0x80;
	}
	else if (c <= 0x10FFFF && MB_CUR_MAX >= 4)
	{
		str[0] = (c >> 18) | 0xF0;
		str[1] = (c >> 12 & 0x3F) | 0x80;
		str[2] = (c >> 6 & 0x3F) | 0x80;
		str[3] = (c & 0x3F) | 0x80;
	}
	return (str);
}

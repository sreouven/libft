/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attribut.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreouven <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 17:11:53 by sreouven          #+#    #+#             */
/*   Updated: 2018/03/19 19:14:41 by sreouven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

char	*precision(char *str, t_frmt *ptr)
{
	char	*s;
	int		len;

	len = ft_max(ptr->prec, (int)ft_strlen(str)) - (int)ft_strlen(str);
	if (((len <= 0 && str[0] == '0' && ptr->prec == 0 &&
					(ptr->type != 'o' && ptr->type != 'O')) ||
				((ptr->type == 'o' || ptr->type == 'O') &&
				!ptr->fg_hashtag && ptr->prec == 0 && str[0] == '0')))
	{
		free(str);
		s = ft_strnew(0);
		return (s);
	}
	if (ptr->type == 's' || ptr->type == 'S')
	{
		s = ft_strsub(str, 0, ptr->prec);
		return (s);
	}
	s = (ptr->type == '%') ? ft_strnew(1) : ft_strnew(ptr->prec);
	s = (ptr->type == '%') ? s : (char *)ft_memset(s, '0', len);
	s = ft_strcat(s, str);
	free(str);
	return (s);
}

int		padding(size_t len, t_frmt *ptr, char *str)
{
	char	*padd;
	int		size;

	size = ajust_size((ft_max(ptr->padd, (int)len) - (int)len), ptr, str);
	if (size <= 0)
		return (0);
	padd = ft_strnew(size);
	if ((ptr->fg_zero && !ptr->fg_minus && ptr->prec < 0) ||
	(ptr->fg_zero && !ptr->fg_minus && (ptr->type != 'd' &&
	ptr->type != 'D' && ptr->type != 'x' && ptr->type != 'X' && ptr->type != 'u'
	&& ptr->type != 'U' && ptr->type != 'i' && ptr->type != 'O'
	&& ptr->type != 'o' && ptr->type != 'p')))
	{
		padd = (char *)ft_memset(padd, '0', size);
		size = write(1, padd, size);
	}
	else if (!ptr->fg_hashtag || ptr->prec < 0 ||
			(ptr->fg_zero && ptr->fg_hashtag) ||
			(ptr->fg_hashtag && ptr->prec >= 0))
	{
		padd = (char *)ft_memset(padd, ' ', size);
		size = write(1, padd, size);
	}
	free(padd);
	return (size);
}

int		is_zero(char *str)
{
	while (*str)
		if (*str == '0')
			str++;
		else
			return (1);
	return (0);
}

int		prefix(char *str, t_frmt *ptr)
{
	int		size;

	size = 0;
	if ((ptr->type == 'o' || ptr->type == 'O') &&
			((ptr->fg_hashtag && ((str[0] != '0' && *str)))))
		size += write(1, "0", 1);
	if (ptr->type == 'p' || (ptr->type == 'x' && ptr->fg_hashtag && *str &&
				(!(ft_strlen(str) == 1 && str[0] == '0')) && is_zero(str)))
		size += write(1, "0x", 2);
	if (ptr->type == 'X' && ptr->fg_hashtag && *str &&
			(!(ft_strlen(str) == 1 && str[0] == '0')) && is_zero(str))
		size += write(1, "0X", 2);
	if (ptr->neg)
		size += write(1, "-", 1);
	if (ptr->fg_plus && !ptr->neg &&
		(ptr->type == 'D' || ptr->type == 'd' || ptr->type == 'i'))
		size += write(1, "+", 1);
	if (!ptr->neg && !ptr->fg_plus && ptr->fg_space &&
			(ptr->type == 'd' || ptr->type == 'D' || ptr->type == 'i'))
		size += write(1, " ", 1);
	return (size);
}

int		ajust_size(int len, t_frmt *ptr, char *str)
{
	if ((ptr->type == 'o' || ptr->type == 'O') && ptr->fg_hashtag &&
			((str[0] != '0' && *str) || (ptr->prec > 0 && ptr->fg_zero)))
		len -= 1;
	if (ptr->type == 'p' || (ptr->type == 'x' && ptr->fg_hashtag &&
				((str[0] != '0' && *str) || ptr->prec > 0)))
		len -= 2;
	if (ptr->type == 'X' && ptr->fg_hashtag &&
			((str[0] != '0' && *str) || ptr->prec > 0))
		len -= 2;
	if (ptr->neg || (!ptr->neg && ptr->fg_plus) || (!ptr->neg &&
				!ptr->fg_plus && ptr->fg_space && ptr->type != '%'))
		len -= 1;
	if (ptr->type == '%' && ptr->fg_plus)
		len += 1;
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unicode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreouven <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 13:25:50 by sreouven          #+#    #+#             */
/*   Updated: 2018/03/19 14:25:52 by sreouven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <wchar.h>
#include <stdarg.h>
#include "ft_printf.h"

static int			bigs_prec(wchar_t *s, t_frmt *ptr)
{
	int i;
	int prec;

	i = -1;
	prec = 0;
	while (s[++i])
	{
		if (prec + ft_wclen(s[i]) > ptr->prec)
			break ;
		else
			prec += ft_wclen(s[i]);
	}
	return (prec);
}

int					print_big_c(t_frmt *ptr, va_list *ap)
{
	wint_t	c;
	int		len;
	char	*str;

	c = va_arg(*ap, wchar_t);
	if (!(ft_wclen(c)))
		return (-1);
	len = 0;
	if (!(str = ft_wctostr(c)))
		return (-1);
	if (ptr->fg_minus)
	{
		len += write(1, str, ft_wclen(c));
		len += padding(ft_wclen(c), ptr, str);
	}
	else
	{
		len += padding(ft_wclen(c), ptr, str);
		len += write(1, str, ft_wclen(c));
	}
	return (len);
}

int					print_big_s(t_frmt *ptr, va_list *ap)
{
	wchar_t	*s;
	int		size;
	char	*str;
	char	*tmp;

	size = -1;
	s = va_arg(*ap, wchar_t *);
	ptr->fg_space = 0;
	ptr->fg_plus = 0;
	if (!s)
		return (print_str(ptr, ft_strdup("(null)")));
	if (ft_wcslen(s) == -1)
		return (-1);
	if (!(str = ft_strnew(ft_wcslen(s))))
		return (-1);
	while (s[++size])
	{
		tmp = ft_wctostr(s[size]);
		ft_strcat(str, tmp);
		free(tmp);
	}
	if (ptr->prec != -1)
		ptr->prec = bigs_prec(s, ptr);
	return (print_str(ptr, str));
}

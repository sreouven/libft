/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreouven <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 09:27:17 by sreouven          #+#    #+#             */
/*   Updated: 2018/03/19 13:24:39 by sreouven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

int		analyse(va_list *args, const char *format)
{
	char	*end;
	char	*start;
	int		len;

	end = (char *)format;
	start = (char *)format;
	len = 0;
	while (*end)
	{
		if (*end == '%')
		{
			ft_putnstr(start, end);
			len += parser(args, &end);
			start = end;
		}
		else if (*end != '\0')
		{
			end++;
			len++;
		}
	}
	ft_putnstr(start, end);
	return (len);
}

int		parser(va_list *ap, char **str)
{
	t_frmt		datargs;

	init_format(&datargs);
	pars_flag(str, &datargs);
	pars_padd_prec(str, &datargs);
	pars_modifier(str, &datargs);
	pars_type(str, &datargs);
	return (print_args(&datargs, ap));
}

int		ft_printf(const char *restrict format, ...)
{
	va_list		va;
	int			len;

	len = 0;
	if (format)
	{
		va_start(va, format);
		len = analyse(&va, format);
		va_end(va);
	}
	return (len);
}

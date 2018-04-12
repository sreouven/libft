/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreouven <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 17:24:40 by sreouven          #+#    #+#             */
/*   Updated: 2018/03/19 17:29:23 by sreouven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdlib.h>

int		print_s(t_frmt *ptr, va_list *ap)
{
	char	*str;

	str = ft_strdup(va_arg(*ap, char *));
	ptr->fg_space = 0;
	ptr->fg_plus = 0;
	if (!str)
		str = ft_strdup("(null)");
	if (ptr->type == 's')
		return (print_str(ptr, str));
	return (0);
}

int		print_str(t_frmt *ptr, char *str)
{
	int		res;

	res = 0;
	str = (ptr->prec == -1) ? str : precision(str, ptr);
	if (ptr->fg_zero && !ptr->fg_minus && (!ptr->fg_plus || ptr->prec < 0)
			&& (!(ptr->fg_hashtag && ptr->prec >= 0)))
	{
		res += prefix(str, ptr);
		res += padding(ft_strlen(str), ptr, str);
		res += write(1, str, ft_strlen(str));
	}
	else if (ptr->fg_minus)
	{
		res += prefix(str, ptr);
		res += write(1, str, ft_strlen(str));
		res += padding(ft_strlen(str), ptr, str);
	}
	else
	{
		res += padding(ft_strlen(str), ptr, str);
		res += prefix(str, ptr);
		res += write(1, str, ft_strlen(str));
	}
	free(str);
	return (res);
}

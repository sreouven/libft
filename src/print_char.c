/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreouven <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 17:19:12 by sreouven          #+#    #+#             */
/*   Updated: 2018/03/19 16:29:33 by sreouven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_c(t_frmt *ptr, va_list *ap)
{
	char	c;
	int		res;

	res = 0;
	if (ptr->type == 'C' || (ptr->type == 'c' && ptr->md == MD_L))
		return (print_big_c(ptr, ap));
	c = va_arg(*ap, int);
	if (ptr->fg_zero && !ptr->fg_minus)
	{
		res += (ptr->padd > 1) ? ft_print_nchar('0', ptr->padd - 1) : 0;
		res += write(1, "\0", 1);
		return (res);
	}
	if (ptr->fg_minus)
	{
		res += write(1, &c, 1);
		res += (ptr->padd > 1) ? ft_print_nchar(' ', ptr->padd - 1) : 0;
	}
	else
	{
		res += (ptr->padd > 1) ? ft_print_nchar(' ', ptr->padd - 1) : 0;
		res += write(1, &c, 1);
	}
	return (res);
}

int		ft_print_nchar(char c, int n)
{
	int		res;

	res = 0;
	while (n--)
		res += write(1, &c, 1);
	return (res);
}

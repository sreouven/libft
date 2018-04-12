/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreouven <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 17:22:16 by sreouven          #+#    #+#             */
/*   Updated: 2018/03/19 13:29:15 by sreouven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_di(t_frmt *ptr, va_list *ap)
{
	long long i;

	if (ptr->md == MD_H)
		i = (short)va_arg(*ap, int);
	else if (ptr->md == MD_HH)
		i = (signed char)va_arg(*ap, long long);
	else if (ptr->md == MD_L)
		i = (long)va_arg(*ap, long long);
	else if (ptr->md == MD_LL)
		i = (long long)va_arg(*ap, long long);
	else if (ptr->md == MD_J)
		i = (intmax_t)va_arg(*ap, long long);
	else if (ptr->md == MD_Z)
		i = (size_t)va_arg(*ap, long long);
	else
		i = (int)va_arg(*ap, long long int);
	if (i < 0)
	{
		ptr->neg = 1;
		i = -i;
	}
	return (print_str(ptr, ft_lltoa_base(i, 10)));
}

int		print_xxou(t_frmt *ptr, va_list *ap)
{
	unsigned long long i;

	if (ptr->md == MD_HH)
		i = (unsigned char)va_arg(*ap, unsigned long long int);
	else if (ptr->md == MD_H)
		i = (unsigned short int)va_arg(*ap, unsigned long long int);
	else if (ptr->md == MD_L)
		i = (unsigned long)va_arg(*ap, unsigned long long int);
	else if (ptr->md == MD_LL)
		i = va_arg(*ap, unsigned long long int);
	else if (ptr->md == MD_J)
		i = (uintmax_t)va_arg(*ap, unsigned long long int);
	else if (ptr->md == MD_Z)
		i = (size_t)va_arg(*ap, unsigned long long int);
	else
		i = (unsigned int)va_arg(*ap, unsigned long long int);
	if (ptr->type == 'X')
		return (print_str(ptr, ft_str_upper(ft_lltoa_base(i, 16))));
	else if (ptr->type == 'x')
		return (print_str(ptr, ft_str_lower(ft_lltoa_base(i, 16))));
	else if (ptr->type == 'o')
		return (print_str(ptr, ft_lltoa_base(i, 8)));
	return (print_str(ptr, ft_lltoa_base(i, 10)));
}

int		print_dou(t_frmt *ptr, va_list *ap)
{
	long long int		i;
	unsigned long long	un_i;

	if (ptr->type == 'D')
	{
		i = va_arg(*ap, long int);
		if (i < 0)
		{
			ptr->neg = 1;
			i = -i;
		}
		return (print_str(ptr, ft_lltoa_base(i, 10)));
	}
	un_i = (unsigned long int)va_arg(*ap, long int);
	if (ptr->type == 'O')
		return (print_str(ptr, ft_lltoa_base(un_i, 8)));
	return (print_str(ptr, ft_lltoa_base(un_i, 10)));
}

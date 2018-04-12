/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreouven <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 17:24:13 by sreouven          #+#    #+#             */
/*   Updated: 2018/03/19 13:25:34 by sreouven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_ptr(t_frmt *ptr, va_list *ap)
{
	size_t	i;

	i = va_arg(*ap, size_t);
	ptr->fg_hashtag = 1;
	ptr->fg_space = 0;
	ptr->fg_plus = 0;
	return (print_str(ptr, ft_str_lower(ft_lltoa_base(i, 16))));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreouven <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 17:18:53 by sreouven          #+#    #+#             */
/*   Updated: 2018/03/19 14:39:36 by sreouven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

int		print_args(t_frmt *ptr, va_list *ap)
{
	if (ptr->type == 's' || ptr->type == 'S')
	{
		if (ptr->type == 'S' || (ptr->type == 's' && ptr->md == MD_L))
			return (print_big_s(ptr, ap));
		return (print_s(ptr, ap));
	}
	else if (ptr->type == 'c' || ptr->type == 'C')
		return (print_c(ptr, ap));
	else if (ptr->type == 'd' || ptr->type == 'i')
		return (print_di(ptr, ap));
	else if (ptr->type == 'o' || ptr->type == 'x' || ptr->type == 'X'
			|| ptr->type == 'u')
		return (print_xxou(ptr, ap));
	else if (ptr->type == 'D' || ptr->type == 'O' || ptr->type == 'U')
		return (print_dou(ptr, ap));
	else if (ptr->type == 'p')
		return (print_ptr(ptr, ap));
	return (print_str(ptr, ft_ctos(ptr->type)));
}

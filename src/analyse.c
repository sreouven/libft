/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreouven <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 17:09:20 by sreouven          #+#    #+#             */
/*   Updated: 2018/03/19 13:23:50 by sreouven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

void	init_format(t_frmt *ptr)
{
	ptr->prec = -1;
	ptr->type = 0;
	ptr->fg_minus = 0;
	ptr->fg_hashtag = 0;
	ptr->fg_zero = 0;
	ptr->fg_plus = 0;
	ptr->fg_space = 0;
	ptr->md = 0;
	ptr->size = 0;
	ptr->neg = 0;
	ptr->padd = 0;
}

void	pars_padd_prec(char **str, t_frmt *ptr)
{
	while (**str && (**str >= '0' && **str <= '9'))
		ptr->padd = ptr->padd * 10 + (*(*str)++ - '0');
	if (**str == '.')
	{
		ptr->prec = 0;
		(*str)++;
		while (**str && (**str >= '0' && **str <= '9'))
			ptr->prec = ptr->prec * 10 + (*(*str)++ - '0');
	}
}

void	pars_flag(char **str, t_frmt *ptr)
{
	(*str)++;
	while (**str && (**str == '+' || **str == ' ' || **str == '-'
				|| **str == '#' || **str == '0'))
	{
		if (**str == ' ')
			ptr->fg_space = 1;
		if (**str == '+')
			ptr->fg_plus = 1;
		if (**str == '-')
			ptr->fg_minus = 1;
		if (**str == '0')
			ptr->fg_zero = 1;
		if (**str == '#')
			ptr->fg_hashtag = 1;
		(*str)++;
	}
}

void	pars_modifier(char **str, t_frmt *ptr)
{
	if (**str == 'j' || **str == 'z' || **str == 'h' || **str == 'l')
	{
		if (**str == 'j')
			ptr->md = MD_J;
		else if (**str == 'z')
			ptr->md = MD_Z;
		else if (**str == 'h')
			ptr->md = MD_H;
		else if (**str == 'l')
			ptr->md = MD_L;
		(*str)++;
	}
	if (**str == 'l')
		ptr->md = MD_LL;
	if (**str == 'h')
		ptr->md = MD_HH;
	if (*str && (ptr->md == MD_HH || ptr->md == MD_LL))
		(*str)++;
}

void	pars_type(char **str, t_frmt *ptr)
{
	while (*(*str) == ' ')
		(*str)++;
	ptr->type = **str;
	if (**str)
		(*str)++;
}

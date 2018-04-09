/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreouven <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 14:51:10 by sreouven          #+#    #+#             */
/*   Updated: 2018/03/19 14:51:19 by sreouven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnstr(char *start, char *end)
{
	int		len;

	len = ft_strlen(start) - ft_strlen(end);
	write(1, start, len);
}

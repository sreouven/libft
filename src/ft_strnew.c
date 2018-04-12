/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreouven <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 00:37:51 by sreouven          #+#    #+#             */
/*   Updated: 2017/11/13 00:55:00 by sreouven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*strnew;

	if (!(strnew = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	ft_bzero(strnew, size + 1);
	return (strnew);
}

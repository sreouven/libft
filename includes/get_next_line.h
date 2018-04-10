/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreouven <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 10:26:23 by sreouven          #+#    #+#             */
/*   Updated: 2018/01/14 18:05:06 by sreouven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"

# define BUFF_SIZE 9

typedef struct		s_fd
{
	int				fd;
	int				i;
	int				ret;
	char			str[BUFF_SIZE + 1];
	int				end;
	struct s_fd		*prev;
	struct s_fd		*next;
}					t_fd;

int					get_next_line(const int fd, char **line);

#endif

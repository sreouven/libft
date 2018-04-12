/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreouven <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 15:03:22 by sreouven          #+#    #+#             */
/*   Updated: 2018/01/14 18:04:50 by sreouven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

static t_fd		*add_fd(t_fd *ptr, int fd)
{
	t_fd	*new;

	if (!(new = malloc(sizeof(t_fd))))
		return (NULL);
	new->fd = fd;
	new->ret = 0;
	new->next = NULL;
	new->prev = NULL;
	ft_bzero(new->str, BUFF_SIZE + 1);
	if (ptr && ptr->fd < new->fd)
	{
		new->prev = ptr;
		new->next = ptr->next ? ptr->next : NULL;
		(ptr->next) ? ptr->next->prev = new : 0;
		ptr->next = new;
	}
	else if (ptr && ptr->fd > new->fd)
	{
		new->next = ptr;
		new->prev = ptr->prev ? ptr->prev : NULL;
		(ptr->prev) ? ptr->prev->next = new : 0;
		ptr->prev = new;
	}
	return (new);
}

static t_fd		*find_fd(int fd, t_fd *ptr)
{
	if (ptr && ptr->fd == fd)
		return (ptr);
	if (ptr && ptr->fd > fd)
	{
		if (ptr->prev && ptr->prev->fd >= fd)
			return (find_fd(fd, ptr->prev));
		return (add_fd(ptr, fd));
	}
	if (ptr && ptr->fd < fd)
	{
		if (ptr->next && ptr->next->fd <= fd)
			return (find_fd(fd, ptr->next));
		return (add_fd(ptr, fd));
	}
	return (add_fd(ptr, fd));
}

static t_fd		*del_fd(t_fd *ptr)
{
	if (ptr && !ptr->prev && !ptr->next)
	{
		free(ptr);
		ptr = NULL;
	}
	else if (ptr && ptr->prev && !ptr->next)
	{
		ptr = ptr->prev;
		free(ptr->next);
		ptr->next = NULL;
	}
	else if (ptr && ptr->next && !ptr->prev)
	{
		ptr = ptr->next;
		free(ptr->prev);
		ptr->prev = NULL;
	}
	else if (ptr && ptr->next && ptr->prev)
	{
		ptr->prev->next = ptr->next;
		ptr = ptr->prev;
		free(ptr->next->prev);
		ptr->next->prev = ptr;
	}
	return (ptr);
}

static char		*ft_line(t_fd *ptr, char **line)
{
	char	*new;

	new = NULL;
	ptr->i = 0;
	while (ptr->str[ptr->i] && ptr->str[ptr->i] != '\n')
		ptr->i++;
	if (ptr->str[ptr->i] == '\n')
		ptr->end = 1;
	if (!(new = ft_strnew((ft_strlen(*line) + ptr->i))))
		return (NULL);
	ft_strcpy(new, *line);
	ft_strncat(new, ptr->str, ptr->i);
	free(*line);
	if (ptr->end)
		ptr->i++;
	ft_strncpy(ptr->str, &ptr->str[ptr->i], BUFF_SIZE);
	return (new);
}

int				get_next_line(const int fd, char **line)
{
	static t_fd		*ptr;

	if (fd < 0 || !line || BUFF_SIZE < 1 || (!(ptr = find_fd(fd, ptr))))
		return (-1);
	ptr->end = 0;
	if (!(*line = ft_strnew(1)))
		return (-1);
	while (!ptr->end)
	{
		if (!*ptr->str &&
				((ptr->ret = read(ptr->fd, ptr->str, BUFF_SIZE)) == -1))
			return (-1);
		if (!(*line = ft_line(ptr, line)))
			return (-1);
		if (ptr->ret < BUFF_SIZE)
		{
			if (**line)
				return (1);
			if (!ptr->ret && !*ptr->str && !*line)
				del_fd(ptr);
			return (ptr->ret ? 1 : 0);
		}
	}
	return (1);
}

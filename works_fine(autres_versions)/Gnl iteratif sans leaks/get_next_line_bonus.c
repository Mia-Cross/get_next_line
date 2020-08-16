/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarabe <lemarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 21:28:17 by lemarabe          #+#    #+#             */
/*   Updated: 2019/11/18 16:27:39 by lemarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "get_next_line_bonus.h"

int		read_next_line(int fd, char **line, char **stock)
{
	char	*buf;
	char *to_add;
	char *tmp;
	int limit;
	int ret;

	if (!(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while ((ret = read(fd, buf, BUFFER_SIZE)))
	{
		buf[ret] = 0;
		limit = seek_nl(buf);
		to_add = ft_substr(buf, 0, '\n');
		tmp = *line;
		*line = ft_strcat(tmp, to_add);
		free(tmp);
		if (limit < BUFFER_SIZE)
		{
			*stock = ft_substr(buf, (limit + 1), '\0');
			break;
		}
	}
	free(buf);	
	return (ret);
}

int		get_next_line(int fd, char **line)
{
	static t_struct save;
	int			limit;
	char *tmp;
	int ret;

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	*line = ft_strdup("");
	if (save.stock[fd] && *save.stock[fd])
	{
		limit = seek_nl(save.stock[fd]);
		*line = ft_substr(save.stock[fd], 0, '\n');
		if (save.stock[fd][limit] == '\n')
		{
			tmp = ft_strdup(save.stock[fd]);
//			free(save.stock[fd]);
			save.stock[fd] = ft_substr(tmp, (limit + 1), '\0');
//			free(tmp);
			return (1);
		}
		else
		{
//			free(save.stock[fd]);
			save.stock[fd] = ft_strdup("");
		}	
	}
	ret = read_next_line(fd, line, &save.stock[fd]);
	if (ret == - 1)
		return (-1);
	if (ret < BUFFER_SIZE && !(save.stock[fd]))
		return (0);
	else
		return (1);
}
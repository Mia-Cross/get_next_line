/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarabe <lemarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 21:28:17 by lemarabe          #+#    #+#             */
/*   Updated: 2019/11/19 17:32:10 by lemarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"

int		read_next_line(int fd, char **stock)
{
	char	*tmp;
	char	*buf;
	int		ret;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= 2147483647)
		return (-1);
	if (!(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	if ((ret = read(fd, buf, BUFFER_SIZE)) && ret > 0)
	{
		tmp = ft_strdup(*stock);
		free(*stock);
		buf[ret] = 0;
		*stock = ft_strcat(tmp, buf);
	}
	else
		free(buf);
	return (ret);
}

void	update_strings(char **line, char **stock, int limit)
{
	char	*tmp;
	char	*to_add;

	tmp = *line;
	to_add = ft_substr(*stock, 0, limit);
	*line = ft_strcat(tmp, to_add);
	tmp = ft_strdup(*stock);
	free(*stock);
	*stock = ft_substr(tmp, (limit + 1), (ft_strlen(tmp) - limit - 1));
	free(tmp);
}

int		get_next_line(int fd, char **line)
{
	static t_struct	save;
	int				limit;
	int				ret;

	ret = read_next_line(fd, &(save.stock[fd]));
	if (fd < 0 || line == NULL || ret == -1)
		return (-1);
	if (save.i[fd] == 0)
		*line = ft_strdup("");
	limit = seek_nl(save.stock[fd]);
	save.i[fd] = 1;
	if (save.stock[fd] && save.stock[fd][limit] == '\n')
		save.i[fd] = 0;
	update_strings(line, &(save.stock[fd]), limit);
	if (save.i[fd] == 0)
		return (1);
	if (ret < BUFFER_SIZE && !save.stock[fd])
		return (0);
	return (get_next_line(fd, line));
}

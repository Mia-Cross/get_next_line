/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarabe <lemarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 21:28:17 by lemarabe          #+#    #+#             */
/*   Updated: 2019/11/13 13:22:42 by lemarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line_bonus.h"

int		read_next_line(int fd, char **stock)
{
	char	*tmp;
	char	*buf;
	int		ret;

	if (fd < 0)
		return (-1);
	if (!(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	tmp = *stock;
	if ((ret = read(fd, buf, BUFFER_SIZE)))
	{
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

	tmp = *line;
	*line = ft_strcat(tmp, ft_substr(*stock, 0, limit));
	tmp = *stock;
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
	if (save.i == 1)
		*line = ft_strcat(NULL, NULL);
	limit = seek_nl(save.stock[fd]);
	save.i = 0;
	if (save.stock[fd] && save.stock[fd][limit] == '\n')
		save.i = 1;
	update_strings(line, &(save.stock[fd]), limit);
	if (save.i == 1)
		return (1);
	if (!*(save.stock[fd]) && ret < BUFFER_SIZE)
		return (0);
	return (get_next_line(fd, line));
}

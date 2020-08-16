/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarabe <lemarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 21:28:17 by lemarabe          #+#    #+#             */
/*   Updated: 2019/11/12 21:55:53 by lemarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

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
	static char	*stock[255];
	static int	i;
	int			limit;
	int			ret;

	ret = read_next_line(fd, &stock[fd]);
	if (fd < 0 || line == NULL || ret == -1)
		return (-1);
	if (i == 1)
		*line = ft_strcat(NULL, NULL);
	limit = seek_nl(stock[fd]);
	i = 0;
	if (stock[fd] && stock[fd][limit] == '\n')
		i = 1;
	update_strings(line, &stock[fd], limit);
	if (i == 1)
		return (1);
	if (!*stock[fd] && ret < BUFFER_SIZE)
		return (0);
	return (get_next_line(fd, line));
}

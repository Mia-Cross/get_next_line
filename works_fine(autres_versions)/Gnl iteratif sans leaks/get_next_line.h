/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarabe <lemarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 12:09:06 by lemarabe          #+#    #+#             */
/*   Updated: 2019/11/18 03:33:40 by lemarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

typedef struct	s_struct
{
	char    *stock;
    int     i;
}				t_struct;
int		read_next_line(int fd, char **line, char **stock);
int		get_next_line(int fd, char **line);
int		seek_nl(char *str);
int		ft_strlen(char *str);
char    *ft_strdup(char *str);
char	*ft_strcat(char *s1, char *s2);
char	*ft_substr(char *s, int start, char c);

#endif

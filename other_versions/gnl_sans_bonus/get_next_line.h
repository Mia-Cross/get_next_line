/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarabe <lemarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 12:09:06 by lemarabe          #+#    #+#             */
/*   Updated: 2019/11/13 13:03:52 by lemarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

int		get_next_line(int fd, char **line);
int		seek_nl(char *str);
int		ft_strlen(char *str);
char	*ft_strcat(char *s1, char *s2);
char	*ft_substr(char *s, int start, int len);
int		read_next_line(int fd, char **stock);
void	update_strings(char **line, char **stock, int limit);

#endif

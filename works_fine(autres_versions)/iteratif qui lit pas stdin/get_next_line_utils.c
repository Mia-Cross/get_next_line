/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarabe <lemarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 21:28:31 by lemarabe          #+#    #+#             */
/*   Updated: 2019/11/19 15:19:24 by lemarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

int		seek_nl(char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i] && str[i] != '\n')
			i++;
	}
	return (i);
}

int		ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *s1, char *s2)
{
	char	*new;
	int		i;
	int		j;
	int		k;

	if (!(new = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	k = 0;
	if (s1)
	{
		while (s1[i])
			new[k++] = s1[i++];
	}
	if (s2)
	{
		while (s2[j])
			new[k++] = s2[j++];
	}
	free(s2);
	new[k] = 0;
	return (new);
}

char	*ft_substr(char *s, int start, char c)
{
	char	*sub;
	int		i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (NULL);
	i = start;
	if (s[i])
	{
		while (s[i] && s[i] != c)
		i++;
	}
	if (!(sub = (char *)malloc(sizeof(char) * (i - start + 1))))
		return (NULL);
	i = 0;
	while (s[start] && s[start] != c)
	{
		sub[i++] = s[start++];
	}
	sub[i] = 0;
	return (sub);
}

char *ft_strdup(char *str)
{
	char *dup;
	int i;

	if (!str)
		return (NULL);
	if (!(dup = malloc(sizeof(char) * ft_strlen(str) + 1)))
		return (NULL);
	i = 0;
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = 0;
	return (dup);
}

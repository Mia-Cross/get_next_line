/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarabe <lemarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 21:28:31 by lemarabe          #+#    #+#             */
/*   Updated: 2019/11/13 13:21:03 by lemarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line_bonus.h"

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
		free(s1);
	}
	if (s2)
	{
		while (s2[j])
			new[k++] = s2[j++];
		free(s2);
	}
	new[k] = 0;
	return (new);
}

char	*ft_substr(char *s, int start, int len)
{
	char	*sub;
	int		i;

	if (!s)
		return (NULL);
	if (!(sub = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	if (start >= i)
	{
		sub[0] = '\0';
		return (sub);
	}
	i = 0;
	while (len && s[start])
	{
		sub[i++] = s[start++];
		len--;
	}
	sub[i] = 0;
	return (sub);
}

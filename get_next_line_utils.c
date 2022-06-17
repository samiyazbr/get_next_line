/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samiyazubair <samiyazubair@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 15:05:34 by samiyazubai       #+#    #+#             */
/*   Updated: 2022/06/16 15:05:38 by samiyazubai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *all, char *str)
{
	size_t	i;
	size_t	j;
	char	*join;

	if (!all)
	{
		all = (char *)malloc(1 * sizeof(char));
		all[0] = '\0';
	}
	if (!all || !str)
		return (NULL);
	join = malloc(sizeof(char) * ((ft_strlen(all) + ft_strlen(str)) + 1));
	if (join == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (all)
		while (all[++i] != '\0')
			join[i] = all[i];
	while (str[j] != '\0')
		join[i++] = str[j++];
	join[ft_strlen(all) + ft_strlen(str)] = '\0';
	free(all);
	return (join);
}

char	*ft_get_line(char *all)
{
	int		i;
	char	*line;

	i = 0;
	if (!all[i])
		return (NULL);
	while (all[i] && all[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (all[i] && all[i] != '\n')
	{
		line[i] = all[i];
		i++;
	}
	if (all[i] == '\n')
	{
		line[i] = all[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*remain(char *all)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (all[i] && all[i] != '\n')
		i++;
	if (!all[i])
	{
		free(all);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(all) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (all[i])
		str[j++] = all[i++];
	str[j] = '\0';
	free(all);
	return (str);
}

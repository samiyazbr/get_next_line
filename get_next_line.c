/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samiyazubair <samiyazubair@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 12:18:35 by samiyazubai       #+#    #+#             */
/*   Updated: 2022/06/16 13:56:33 by samiyazubai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_all(int fd, char *all)
{
	char	*str;
	int		n_readbytes;

	str = malloc(sizeof(char) * (BUFFER_SIZE + 1))
		if (str == NULL)
		return (NULL);
	n_readbytes = 1;
	while (ft_strchr(all, '\n') == 0 && n_readbytes != 0)
	{
		n_readbytes = read(fd, str, BUFFER_SIZE);
		if (n_readbytes == -1)
		{
			free(str);
			return (NULL);
		}
		str[n_readbytes] = '\0';
		all = ft_strjoin(all, str);
	}
	free(str);
	return (all);
}

char	*ft_get_line(char *all)
{
	int		all_i;
	char	*line;

	all_i = 0;
	if (!all[all_i])
		return (NULL);
	while (all[all_i] && all[all_i] != '\n')
		all_i++;
	line = (char *)malloc(sizeof(char) * (all_i + 2));
	if (line == NULL)
		return (NULL);
	all_i = 0;
	while (all[all_i] && all[all_i] != '\n')
	{
		line[all_i] = all[all_i];
		all_i++;
	}
	if (all[all_i] == '\n')
	{
		line[all_i] = all[all_i];
		all_i++;
	}
	line[all_i] = '\0';
	return (line);
}

char	*remain(char *all)
{
	int		all_i;
	int		str_i;
	char	*str;

	all_i = 0;
	while (all[all_i] && all[all_i] != '\n')
		all_i++;
	if (!all[all_i])
	{
		free(all);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(all)) - all_i + 1);
	if (str == NULL)
		return (NULL);
	all_i++;
	str_i = 0;
	while (all[all_i] != '\0')
		str[str_i++] = all[all_i++];
	str[str_i] = '\0';
	free(all);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*all;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	all = read_all(fd, all);
	if (!all)
		return (NULL);
	line = ft_get_line(all);
	all = remain(all);
	return (line);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samiyazubair <samiyazubair@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 15:04:51 by samiyazubai       #+#    #+#             */
/*   Updated: 2022/06/16 15:04:56 by samiyazubai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_all(int fd, char *all)
{
	char	*str;
	int		n_readbytes;

	str = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!str)
		return (NULL);
	n_readbytes = 1;
	while (!ft_strchr(all, '\n') && n_readbytes != 0)
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

char	*get_next_line(int fd)
{
	char		*line;
	static char	*all[4096];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	all[fd] = read_all(fd, all[fd]);
	if (!all[fd])
		return (NULL);
	line = ft_get_line(all[fd]);
	all[fd] = remain(all[fd]);
	return (line);
}

// int	main(void)
// {
// 	char	*line;
// 	int		i;
// 	int		fd1;
// 	int		fd2;
// 	int		fd3;

// 	fd1 = open("tests/test.txt", O_RDONLY);
// 	fd2 = open("tests/test2.txt", O_RDONLY);
// 	fd3 = open("tests/test3.txt", O_RDONLY);
// 	i = 1;
// 	while (i < 7)
// 	{
// 		line = get_next_line(fd1);
// 		printf("line 1: %s", line);
// 		free(line);
// 		line = get_next_line(fd2);
// 		printf("line 2: %s", line);
// 		free(line);
// 		line = get_next_line(fd3);
// 		printf("line 3 %s", line);
// 		free(line);
// 		i++;
// 	}
// 	close(fd1);
// 	close(fd2);
// 	close(fd3);
// 	return (0);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samiyazubair <samiyazubair@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 15:05:46 by samiyazubai       #+#    #+#             */
/*   Updated: 2022/06/16 15:06:47 by samiyazubai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_all(int fd, char *all)
{
	char	*str;
	int		n_readbytes;

	str = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!str)
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

char	*get_next_line(int fd)
{
	char		*line;
	static char	*left_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	left_str = read_all(fd, left_str);
	if (!left_str)
		return (NULL);
	line = ft_get_line(left_str);
	left_str = remain(left_str);
	return (line);
}

// int	main(void)
// {
// 	char	*line;

// 	int fd = open("test.txt", O_RDONLY);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);
// 	while (line != NULL)
// 	{
// 		line = get_next_line(fd);
// 		if (line == NULL)
// 			break;
// 		printf("%s", line);
// 		free(line);
// 	}
// 	close(fd);
// }

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

char *read_all(int fd, char *all)
{
    char *str;           // Declare a character buffer for reading data from the file.
    int n_readbytes;     // Declare an integer to store the number of bytes read.

    str = malloc((BUFFER_SIZE + 1) * sizeof(char));  // Allocate memory for reading a chunk of data.
    if (!str)
        return (NULL);   // If memory allocation fails, return NULL.

    n_readbytes = 1;     // Initialize the number of bytes read to 1 (to enter the loop).

    while (ft_strchr(all, '\n') == 0 && n_readbytes != 0)
    {
        n_readbytes = read(fd, str, BUFFER_SIZE);  // Read data from the file descriptor into the buffer.
        if (n_readbytes == -1)  // Check for read error.
        {
            free(str);       // Free the allocated memory in case of an error.
            return (NULL);   // Return NULL to indicate an error.
        }
        str[n_readbytes] = '\0';  // Null-terminate the read data.
        all = ft_strjoin(all, str);  // Concatenate the read data to the 'all' string.
    }

    free(str);          // Free the temporary buffer used for reading.

    return (all);       // Return the 'all' string, which contains the concatenated data.
}

char *get_next_line(int fd)
{
    char *line;                // Declare a character pointer to store the next line read.
    static char *all[4096];    // Declare an array of character pointers for file-specific storage.

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (0);            // Check for invalid file descriptor or buffer size.

    all[fd] = read_all(fd, all[fd]);  // Read data from the file and append it to 'all' array for this file descriptor.
    if (!all[fd])
        return (NULL);         // If reading fails or reaches the end, return NULL.

    line = ft_get_line(all[fd]);  // Extract a line from 'all' for this file descriptor.
    all[fd] = remain(all[fd]);    // Update 'all' to store the remaining data for this file descriptor.

    return (line);              // Return the extracted line.
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

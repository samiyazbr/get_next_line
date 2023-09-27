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
    char *line;               // Declare a character pointer to store the next line read.
    static char *left_str;    // Declare a static character pointer to store leftover data.

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (0);           // Check for invalid file descriptor or buffer size.

    left_str = read_all(fd, left_str);  // Read data from the file and append it to 'left_str'.
    if (!left_str)
        return (NULL);        // If reading fails or reaches the end, return NULL.

    line = ft_get_line(left_str);  // Extract a line from 'left_str'.
    left_str = remain(left_str);   // Update 'left_str' to store the remaining data.

    return (line);            // Return the extracted line.
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

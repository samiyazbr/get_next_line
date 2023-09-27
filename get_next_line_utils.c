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

char *ft_get_line(char *all)
{
    int i;
    char *line;

    i = 0;  // Initialize an index variable 'i' to zero.
    if (!all[i])
        return (NULL);  // Check if the input string is empty; if so, return NULL.

    // Loop to find the length of the line or until a newline character is encountered.
    while (all[i] && all[i] != '\n')
        i++;

    // Allocate memory for the 'line' variable to store the line and a newline character.
    line = (char *)malloc(sizeof(char) * (i + 2));
    if (!line)
        return (NULL);  // Check if memory allocation fails; if so, return NULL.

    i = 0;  // Reset the index 'i' to zero.

    // Loop to copy characters from 'all' to 'line' until a newline character is encountered.
    while (all[i] && all[i] != '\n')
    {
        line[i] = all[i];
        i++;
    }

    if (all[i] == '\n')
    {
        line[i] = all[i];  // Include the newline character.
        i++;
    }

    line[i] = '\0';  // Null-terminate the 'line' string.

    return (line);  // Return the extracted line including the newline character.
}

char *remain(char *all)
{
    int i;
    int j;
    char *str;

    i = 0;  // Initialize an index variable 'i' to zero.

    // Loop to find the position of the first newline character or the end of the string.
    while (all[i] && all[i] != '\n')
        i++;

    if (!all[i])  // Check if there is no newline character (end of file reached).
    {
        free(all);  // If there's no newline character, free the memory.
        return (NULL);  // Return NULL to indicate the end of the file.
    }

    // Allocate memory for 'str' to store the remaining characters after the newline.
    str = (char *)malloc(sizeof(char) * (ft_strlen(all) - i + 1));
    if (!str)
        return (NULL);  // Check if memory allocation fails; if so, return NULL.

    i++;  // Increment 'i' to skip the newline character.

    j = 0;  // Initialize an index variable 'j' to zero.

    // Loop to copy the remaining characters after the newline to 'str'.
    while (all[i])
        str[j++] = all[i++];

    str[j] = '\0';  // Null-terminate the 'str' string.

    free(all);  // Free the memory used by the original 'all' string.

    return (str);  // Return the remaining characters after the newline.
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samiyazubair <samiyazubair@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 11:26:34 by samiyazubai       #+#    #+#             */
/*   Updated: 2022/06/16 13:03:50 by samiyazubai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	if ((char)c == '\0')
	{
		return ((char *)&s[i]);
	}
	return (NULL);
}

int	total1(char *all, char const *str)
{
	int	s1_len;
	int	s2_len;
	int	total;

	s1_len = ft_strlen(all);
	s2_len = ft_strlen(str);
	total = s1_len + s2_len;
	return (total);
}

char	*ft_strjoin(char *all, char *str)
{
	int		total;
	char	*new;
	int		i;
	int		ij;

	total = total1(all, str);
	i = 0;
	new = malloc(sizeof(char) * (total + 1));
	if (new == NULL)
		return (NULL);
	while (all[i])
	{
		new[i] = all[i];
		i++;
	}
	ij = 0;
	while (str[ij])
	{
		new[i] = str[ij];
		i++;
		ij++;
	}
	new[total] = '\0';
	return (new);
}

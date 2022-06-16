/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samiyazubair <samiyazubair@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 11:28:03 by samiyazubai       #+#    #+#             */
/*   Updated: 2022/06/16 12:47:40 by samiyazubair     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*read_all(int fd, char *all);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *all, char *str);
int		total1(char *all, char const *str);
size_t	ft_strlen(char *s);
char	*ft_get_line(char *all);
char	*remain(char *all);

#endif

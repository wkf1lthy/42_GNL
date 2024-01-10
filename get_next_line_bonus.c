/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouchel <hbouchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:05:58 by hbouchel          #+#    #+#             */
/*   Updated: 2024/01/09 18:20:49 by hbouchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buff[1025][BUFFER_SIZE + 1];
	char		*dest;
	int			i;

	i = 1;
	dest = NULL;
	if (BUFFER_SIZE == 0 || fd < 0)
		return (0);
	if (ft_check(buff[fd]) == 1)
	{
		ft_buf_cut(buff[fd]);
		dest = ft_join(dest, buff[fd]);
	}
	while (i > 0 && ft_check(buff[fd]) == 0)
	{
		i = read(fd, buff[fd], BUFFER_SIZE);
		if (i < 0)
		{
			free(dest);
			return (NULL);
		}
		buff[fd][i] = '\0';
		dest = ft_join(dest, buff[fd]);
	}
	return (dest);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-brit <vde-brit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 18:00:08 by vde-brit          #+#    #+#             */
/*   Updated: 2022/08/10 20:26:13 by vde-brit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*next_line(char *buff)
{
	int		i;
	int		j;
	char	*new_line_ret;

	i = 0;
	while (buff[i] != '\0' && buff[i] != '\n')
		i++;
	if (buff[i] == '\0')
	{
		free(buff);
		return (NULL);
	}
	new_line_ret = malloc(sizeof(char) * (ft_strlen(buff) - i + 1));
	if (!new_line_ret)
	{
		free(new_line_ret);
		return (NULL);
	}
	i++;
	j = 0;
	while (buff[i] != '\0')
		new_line_ret[j++] = buff[i++];
	new_line_ret[j] = '\0';
	free(buff);
	return (new_line_ret);
}

char	*line_thrower(char *buff)
{
	char	*line_ret;
	int		i;

	i = 0;
	if (!buff[i])
		return (NULL);
	while (buff[i] != '\0' && buff[i] != '\n')
		i++;
	line_ret = ft_substr(buff, 0, i + needs_null(buff));
	if (!line_ret)
	{
		free(line_ret);
		return (NULL);
	}
	return (line_ret);
}

char	*fd_read(int fd, char *buff)
{
	char	*buff_string;
	int		read_bytes;

	buff_string = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff_string)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(buff, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buff_string, BUFFER_SIZE);
		if (read_bytes < 0)
		{
			free(buff_string);
			return (NULL);
		}
		buff_string[read_bytes] = '\0';
		buff = ft_strjoin(buff, buff_string);
	}
	free(buff_string);
	return (buff);
}

char	*get_next_line(int fd)
{
	char		*ret;
	static char	*buff;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = fd_read(fd, buff);
	if (!buff)
		return (NULL);
	ret = line_thrower(buff);
	buff = next_line(buff);
	return (ret);
}

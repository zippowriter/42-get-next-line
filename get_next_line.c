/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkono <hkono@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 21:58:41 by hkono             #+#    #+#             */
/*   Updated: 2020/12/19 09:34:47 by hkono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		join_line(int fd, char **line)
{
	char        *tmp;
	int         ret;
	char        *buf;

	if (!(buf = (char *)malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1))))
		return (-1);
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (*line)
			if (!(tmp = ft_strjoin(*line, buf)))
				return (-1);
		if (!*line)
			if (!(tmp = ft_strdup(buf)))
				return (-1);
		if (*line)
			free(*line);
		*line = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	free(buf);
	return (ret > 0 ? 1 : ret);
}

int		get_next_prep(char **line, char **save)
{
	char        *tmp;
	char        *nlptr;

	if (!(nlptr = ft_strchr(*line, '\n')))
		return (0);
	if (!(tmp = ft_substr(*line, 0, nlptr - *line)))
		return (-1);
	if (!(*save = ft_strdup(nlptr + 1)))
		return (-1);
	free(*line);
	*line = tmp;
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char *save;
	int         ret;

	if (!line || fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	*line = save;
	save = "";
	ret = 1;
	if (!*line || !ft_strchr(*line, '\n'))
		ret = join_line(fd, line);
	if (ret == -1)
		return (-1);
	else if (ret == 0 && !*line)
	{
		*line = ft_strdup("");
		return (0);
	}
	if ((get_next_prep(line, &save)) == -1)
		return (-1);
	return (ret);
}

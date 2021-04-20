/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkono <hkono@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 21:58:41 by hkono             #+#    #+#             */
/*   Updated: 2021/04/20 23:57:52 by hkono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	var_init(char **buf, int fd)
{
	int		ret;

	ret = 0;
	*buf = (char *)malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1));
	if (*buf == NULL)
		return (-1);
	ret = read(fd, *buf, BUFFER_SIZE);
	return (ret);
}

static int	join_line(int fd, char **line)
{
	char	*tmp;
	int		ret;
	char	*buf;

	ret = var_init(&buf, fd);
	while (ret > 0)
	{
		buf[ret] = '\0';
		if (*line)
			tmp = ft_strjoin(*line, buf);
		else if (!*line)
			tmp = ft_strdup(buf);
		if (tmp == NULL)
			return (-1);
		if (*line)
			free(*line);
		*line = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
		ret = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	if (ret > 0)
		return (1);
	return (ret);
}

static int	get_next_prep(char **line, char **save)
{
	char	*tmp;
	char	*nlptr;

	nlptr = ft_strchr(*line, '\n');
	if (nlptr == NULL)
		return (0);
	tmp = ft_substr(*line, 0, nlptr - *line);
	if (tmp == NULL)
		return (-1);
	*save = ft_strdup(nlptr + 1);
	if (*save == NULL)
		return (-1);
	free(*line);
	*line = tmp;
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	*save;
	int			ret;

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

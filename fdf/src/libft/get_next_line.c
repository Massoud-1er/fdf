/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmovahhe <mmovahhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 18:53:29 by mmovahhe          #+#    #+#             */
/*   Updated: 2018/12/04 20:09:40 by mmovahhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	cut_line(char **rest, char **str, char ***line)
{
	char *t;
	char *t1;

	t = ft_strdup(*rest + 1);
	free(*rest);
	*rest = ft_dupfree(t);
	if (ft_strchr((const char *)*rest, '\n') != NULL)
	{
		t = ft_strdup(ft_strchr((const char *)*rest, '\n'));
		t1 = ft_strsub((const char *)*rest, 0, ft_strlen(*rest) - ft_strlen(t));
		free(*rest);
		*rest = ft_dupfree(t);
		**line = ft_joinfree(*str, t1);
		free(t1);
		return (1);
	}
	return (0);
}

int	read_line(int ret, char *buf, char **rest, char **str)
{
	char *tmp;
	char *tmp2;

	buf[ret] = '\0';
	if (ft_strchr((const char *)buf, '\n') != NULL)
	{
		tmp = ft_strchr((const char *)buf, '\n');
		tmp2 = ft_strsub((const char *)buf, 0, ft_strlen(buf) - ft_strlen(tmp));
		*str = ft_joinfree(*str, tmp2);
		free(tmp2);
		*rest = ft_strdup(tmp);
		return (1);
	}
	tmp = ft_joinfree(*str, buf);
	*str = ft_dupfree(tmp);
	return (0);
}

int	return_value(int ret, char **str)
{
	if (ret == 0 && ft_strlen(*str))
		return (1);
	if (ret < 0)
		return (-1);
	if (ret > 0)
		return (1);
	return (0);
}

int	get_next_line(const int fd, char **line)
{
	int			ret;
	char		buf[BUFF_SIZE + 1];
	static char	*rest[FD_NB];
	char		*str;

	if (fd < 0 || !line || BUFF_SIZE <= 0)
		return (-1);
	str = ft_strnew(0);
	if (rest[fd])
	{
		if (cut_line(&rest[fd], &str, &line))
			return (1);
		str = ft_joinfree(str, rest[fd]);
		free(rest[fd]);
		rest[fd] = NULL;
	}
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		if (read_line(ret, buf, &rest[fd], &str))
			break ;
	}
	*line = ft_dupfree(str);
	return (return_value(ret, line));
}

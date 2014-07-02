/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 22:52:10 by mdarty            #+#    #+#             */
/*   Updated: 2014/01/19 22:52:38 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libwf.h"

static size_t		ft_check_line(char *str, char **end, char **line)
{
	size_t		i;

	i = 0;
	if (ft_strchr(str, '\n'))
	{
		*end = ft_strdup(ft_strchr(str, '\n') + 1);
		while (str[i] != '\n')
			i++;
		str[i] = '\0';
		*line = str;
		return (1);
	}
	return (0);
}

static int			ft_check_end(char **str, char *test, char **buf)
{
	char		*tmp;

	if (test == NULL)
	{
		tmp = *str;
		*str = ft_strjoin(tmp, *buf);
		ft_memdel((void**)buf);
		return (1);
	}
	tmp = test;
	*str = ft_strjoin(tmp, *buf);
	ft_memdel((void**)buf);
	return (0);
}

int					get_next_line(int const fd, char **line)
{
	static char		*end = NULL;
	char			*str;
	char			*buf;
	ssize_t			ret;
	char			*tmp;

	ret = 1;
	str = ft_strnew(BUFF_SIZE);
	while (ret > 0)
	{
		buf = ft_strnew(BUFF_SIZE);
		if ((ret = read(fd, buf, BUFF_SIZE)) == -1)
			exit(0);
		tmp = end;
		if (!ft_check_end(&str, tmp, &buf))
			ft_memdel((void**)&end);
		if (ft_check_line(str, &end, line) == 1)
			return (1);
	}
	*line = ft_strdup(str);
	free(str);
	if (ft_strlen(*line) || *line[0] == '\n')
		return (1);
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/04 23:50:58 by mdarty            #+#    #+#             */
/*   Updated: 2014/01/19 21:15:54 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libwf.h"

static void		ft_read_first_line(int const fd, char **line,
									t_env *e, int *tab)
{
	if (get_next_line(fd, line) > 0)
	{
		ft_nbrsplit_first_line(*line, &tab);
		e->height = tab[0];
		e->x = tab[1];
		e->y = tab[2];
		e->map = (char **)malloc(sizeof(char *) * (e->height + 1));
		e->size_map = (int *)malloc(sizeof(int) * e->height);
		e->map[e->height] = (char *)malloc(sizeof(char));
		e->map[e->height][0] = '\0';
	}
	else
		ft_error();
}

static void		ft_save_map(int const fd, char **line, t_env *e)
{
	int			i;

	i = 0;
	while ((get_next_line(fd, line)) != 0)
	{
		e->map[i] = ft_charsplit(*line);
		e->size_map[i] = (int)ft_strlen(e->map[i]);
		i++;
	}
	if (i != e->height)
		ft_error_map();
}

static void		ft_test_map(t_env *e)
{
	if (e->x < 0 || e->y < 0 || e->y > e->height
		|| e->x > e->size_map[(int)e->y])
		ft_error_map();
	if (e->map[(int)e->y][(int)e->x] == '1')
		ft_error_map();
}

void			ft_create_map(char *av, t_env *e)
{
	int		*tab;
	int		fd;
	char	*line;

	if ((fd = open(av, O_RDONLY)) == -1)
		ft_error();
	tab = NULL;
	line = NULL;
	if (e->status == '0')
	{
		e->mlx = NULL;
		e->win = NULL;
		e->status = '1';
	}
	ft_read_first_line(fd, &line, e, tab);
	ft_save_map(fd, &line, e);
	close(fd);
	ft_test_map(e);
	e->angle = 0;
}

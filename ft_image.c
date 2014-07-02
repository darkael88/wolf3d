/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/04 23:22:40 by mdarty            #+#    #+#             */
/*   Updated: 2014/01/19 09:02:26 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libwf.h"

int			put_to_img(t_env *e, int x, int y, int color)
{
	if (e->data != NULL && x >= 0 && x <= 1280 && y >= 0 && y <= 800)
		ft_memcpy(&e->data[(x * 4) + (y * 4 * 1280)], &color, 4);
	return (0);
}

void		ft_print_wall(t_env *e, float distance, int x)
{
	int		wall;
	int		y;
	int		color;

	color = ft_print_wall_color(e->typecolor1, e->typecolor2, e);
	if (distance < 1)
		wall = 800;
	else
		wall = 800 / distance;
	y = (800 / 2) - (wall / 2);
	while (y < ((800 / 2) + (wall / 2)))
	{
		put_to_img(e, x, y, color);
		y++;
	}
}

int			wall(t_env *e)
{
	int		i;
	float	angle;
	float	distance;

	i = 0;
	angle = e->angle - (M_PI / 6);
	while (i < 1280)
	{
		distance = ft_distance(e, angle);
		if (distance != 0)
			ft_print_wall(e, distance, i);
		i++;
		angle = angle + ((M_PI / 3) / 1280);
	}
	return (0);
}

int			sky(t_env *e)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y <= 400)
	{
		if (x == 1280)
		{
			x = 0;
			y++;
		}
		while (x < 1280)
		{
			put_to_img(e, x, y, e->color[0]);
			x++;
		}
	}
	return (0);
}

int			floorz(t_env *e)
{
	int		x;
	int		y;

	x = 0;
	y = 400;
	while (y <= 800)
	{
		if (x == 1280)
		{
			x = 0;
			y++;
		}
		while (x < 1280)
		{
			put_to_img(e, x, y, e->color[1]);
			x++;
		}
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_distance.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 13:31:48 by mdarty            #+#    #+#             */
/*   Updated: 2014/01/19 09:24:54 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libwf.h"

int			ft_print_wall_color(int color1, int color2, t_env *e)
{
	int		color;

	if (color1 == 0 && color2 == 0)
		color = e->color[2];
	else if (color1 == 0 && color2 == 1)
		color = e->color[3];
	else if (color1 == 1 && color2 == 0)
		color = e->color[4];
	else
		color = e->color[5];
	return (color);
}

void		ft_wall_color(t_env *e, float v_sin, float v_cos)
{
	if (e->typecolor1 == 0)
	{
		if (v_sin > 0)
			e->typecolor2 = 1;
		else
			e->typecolor2 = 0;
	}
	else if (e->typecolor1 == 1)
	{
		if (v_cos > 0)
			e->typecolor2 = 1;
		else
			e->typecolor2 = 0;
	}
}

float		ft_distance(t_env *e, float angle)
{
	float	distance;
	int		x;
	int		y;
	float	v_cos;
	float	v_sin;

	v_cos = cos(angle);
	v_sin = sin(angle);
	x = e->x;
	y = e->y;
	distance = 0.1;
	e->typecolor1 = 0;
	while (x >= 0 && y >= 0 && x < e->size_map[y]
			&& y < e->height && e->map[y][x] == '0')
	{
		x = e->x + (distance * v_cos);
		if (e->map[y][x] == '1')
			e->typecolor1 = 1;
		y = e->y + (distance * v_sin);
		distance += 0.0025;
	}
	if (x < 0 || x >= e->size_map[y] || y < 0 || y >= e->height)
		return (0);
	ft_wall_color(e, v_sin, v_cos);
	return (distance * cos(angle - e->angle));
}

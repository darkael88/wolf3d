/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wolf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/04 23:28:19 by mdarty            #+#    #+#             */
/*   Updated: 2014/01/19 21:18:22 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libwf.h"

void	ft_color(t_env *e)
{
	e->color[0] = 0x00BBFF;
	e->color[1] = 0xDDCC77;
	e->color[2] = 0x888888;
	e->color[3] = 0x666666;
	e->color[4] = 0x444444;
	e->color[5] = 0x222222;
}

void    wolf_3d(char *str, t_env *e)
{
	e->status = '0';
	ft_create_map(str, e);
	ft_color(e);
	if (e->mlx == NULL)
		e->mlx = mlx_init();
	if (e->win == NULL)
		e->win = mlx_new_window(e->mlx, 1280, 800, "Wolf3d");
	if (e->mlx != NULL)
    {
		e->img_ptr = mlx_new_image(e->mlx, 1280, 800);
		e->data = mlx_get_data_addr(e->img_ptr, &e->bitpp,
										&e->size_l, &e->endian);
		mlx_expose_hook(e->win, &expose_loop, e);
		mlx_do_key_autorepeaton(e->mlx);
		mlx_hook(e->win, 2, (1L << 0), button, e);
		mlx_loop(e->mlx);
    }
}

int		expose_loop(t_env *e)
{
	sky(e);
	floorz(e);
	wall(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img_ptr, 0, 0);
	return (0);
}

void	ft_modif_place(t_env *e, float tmpx, float tmpy)
{
	int		i;

	if (e->map[(int)tmpy][(int)tmpx] == '0'
		&& tmpx >= 0 && tmpy >= 0)
	{
		e->x = tmpx;
		e->y = tmpy;
	}
	if (e->x < 1 || (e->y + 1) > e->height || e->y < 1 ||
		(e->x + 1) > e->size_map[(int)e->y])
	{
		i = 0;
		(e->nb_map)++;
		if (e->str[e->nb_map] != NULL)
		{
			e->map = NULL;
			ft_create_map(e->str[e->nb_map], e);
		}
		else
			exit(0);
	}
}

int		button(int keycode, t_env *e)
{
	float	tmpx;
	float	tmpy;

	if (keycode == 65361)
		e->angle = e->angle - (M_PI / 30);
	else if (keycode == 65362)
	{
		tmpx = e->x + (cos(e->angle) * 0.3);
		tmpy = e->y + (sin(e->angle) * 0.3);
		ft_modif_place(e, tmpx, tmpy);
	}
	else if (keycode == 65363)
		e->angle = e->angle + (M_PI / 30);
	else if (keycode == 65364)
	{
		tmpx = e->x - (cos(e->angle) * 0.3);
		tmpy = e->y - (sin(e->angle) * 0.3);
		ft_modif_place(e, tmpx, tmpy);
	}
	else if (keycode == 65307)
		exit(1);
	expose_loop(e);
	return (0);
}

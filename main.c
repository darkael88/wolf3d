/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/04 22:34:39 by mdarty            #+#    #+#             */
/*   Updated: 2014/01/19 19:28:15 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libwf.h"

int			main(int ac, char **av)
{
	char	*tmp;
	int		i;
	char	j[2] = {'0', '\0'};
	t_env	e;

	if (ac >= 1)
	{
		i = 0;
		e.str = (char **)malloc(sizeof(char *) * 6);
		while (i < 5)
		{
			tmp = ft_strsub(av[0], 0, ft_strlen(av[0]) - 6);
			e.str[i] = ft_strjoin(ft_strjoin(tmp, "maps/map"), j);
			j[0] = j[0] + 1;
			i++;
		}
		while (i < 6)
		{
			e.str[i] = NULL;
			i++;
		}
		e.nb_map = 0;
		wolf_3d(e.str[0], &e);
	}
	return (0);
}

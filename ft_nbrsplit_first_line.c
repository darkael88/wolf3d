/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrsplit_first_line.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/04 18:09:36 by mdarty            #+#    #+#             */
/*   Updated: 2014/01/17 17:47:25 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libwf.h"

static int		*ft_memtab(char const *s, int *size)
{
	unsigned int	i;
	unsigned int	count;
	int				*tab;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			count++;
			while (s[i] >= '0' && s[i] <= '9')
				i++;
		}
		else
			i++;
	}
	*size = count;
	tab = (int *)malloc((count + 1) * sizeof(int));
	return (tab);
}

static void		ft_search_int(char const *s,
							  int *j, int *nb, int *start)
{
	while (s[*j] == '-' || s[*j] == '+')
	{
		if (s[*j] == '-')
			*nb = *nb + 1;
		*j = *j + 1;
	}
	while (s[*j] >= '0' && s[*j] <= '9')
	{
		if (*start == -1)
			*start = *j;
		*j = *j + 1;
	}
}

static void		ft_fill_tab(int *tab, char const *s, int *len)
{
	int				i;
	int				j;
	int				start;
	int				nb;
	char			*str;

	i = 0;
	j = 0;
	while (i < *len && s[j] != '\0')
	{
		nb = 0;
		start = -1;
		ft_search_int(s, &j, &nb, &start);
		if (start != -1)
		{
			if (nb % 2 == 0)
				str = ft_strsub(s + start, 0, j - start);
			else
				str = ft_strnjoin("-", s + start, (j - start + 1));
			tab[i] = ft_atoi(str);
			free(str);
			i++;
		}
		j++;
	}
}

void			ft_nbrsplit_first_line(char const *s, int **tab)
{
	int			count;

	count = 0;
	while (count < 3)
	{
		*tab = ft_memtab(s, &count);
		count++;
	}
	ft_fill_tab(*tab, s, &count);
}

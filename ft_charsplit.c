/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charsplit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/04 18:10:18 by mdarty            #+#    #+#             */
/*   Updated: 2014/01/19 18:42:49 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libwf.h"

static char		*ft_memtab(char const *s, int *size)
{
	unsigned int	i;
	unsigned int	count;
	char			*tab;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == ' ')
			i++;
		else if (s[i] >= '0' && s[i] <= '9')
		{
			count++;
			while (s[i] >= '0' && s[i] <= '9')
				i++;
		}
		else
			ft_error_map();
	}
	*size = count;
	tab = (char *)malloc((count + 1) * sizeof(char));
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

static void		ft_fill_tab(char *tab, char const *s, int *len)
{
	t_tab			var;
	char			*str;

	var.i = 0;
	var.j = 0;
	while (var.i < *len && s[var.j] != '\0')
	{
		var.nb = 0;
		var.start = -1;
		ft_search_int(s, &var.j, &var.nb, &var.start);
		if (var.start != -1)
		{
			if (var.nb % 2 == 0)
				str = ft_strsub(s + var.start, 0, var.j - var.start);
			else
				str = ft_strnjoin("-", s + var.start, (var.j - var.start + 1));
			if (ft_strlen(str) == 1 && str[0] == '0')
				tab[var.i] = '0';
			else
				tab[var.i] = '1';
			free(str);
			(var.i)++;
		}
		(var.j)++;
	}
}

char			*ft_charsplit(char const *s)
{
	char		*tab;
	int			count;

	tab = ft_memtab(s, &count);
	ft_fill_tab(tab, s, &count);
	return (tab);
}

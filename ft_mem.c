/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 18:17:16 by mdarty            #+#    #+#             */
/*   Updated: 2014/01/03 17:41:07 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libwf.h"

void		ft_memdel(void **ap)
{
	if (ap && *ap)
	{
		free(*ap);
		*ap = NULL;
	}
}

char		*ft_strnew(unsigned int size)
{
	char				*str;
	unsigned int		i;

	i = 0;
	if (!size)
		return (str = ft_memalloc(size + 1));
	if ((str = malloc(size + 1)) && size != 0)
	{
		while (i <= size)
		{
			str[i] = '\0';
			i++;
		}
		return (str);
	}
	else
		return (NULL);
}

void		*ft_memalloc(unsigned int size)
{
	void		*str;

	if ((str = malloc(size)))
	{
		ft_bzero(str, size);
		return (str);
	}
	return (NULL);
}

void		ft_bzero(void *s, unsigned int n)
{
	unsigned int		i;
	char				*str;

	str = s;
	i = 0;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	str = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

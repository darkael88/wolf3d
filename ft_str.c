/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 18:19:31 by mdarty            #+#    #+#             */
/*   Updated: 2014/01/03 17:41:16 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libwf.h"

unsigned int	ft_strlen(const char *s)
{
	int			i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char			*ft_strdup(const char *s1)
{
	char		*dest;

	dest = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	ft_strcpy(dest, s1);
	return (dest);
}

char			*ft_strcpy(char *s1, const char *s2)
{
	int			i;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	while (s1 && s2 && s2[i] != '\0')
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

char			*ft_strnjoin(char const *s1, char const *s2, int len)
{
	int			i;
	int			j;
	char		*str;

	str = (char *)malloc(len * sizeof(*str) + 1);
	i = 0;
	j = 0;
	while (s1[i] != '\0' && i < len)
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0' && i < len)
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

char			*ft_strchr(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	if (s[i] == c)
		return ((char *)(s + i));
	else
		return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 09:44:40 by mdarty            #+#    #+#             */
/*   Updated: 2014/01/17 18:21:49 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_test_sign(char c)
{
	if (c == '-')
		return (-1);
	else if (c == '+' || (c >= '0' && c <= '9'))
		return (1);
	else
		return (0);
}

int			ft_atoi(const char *str)
{
	unsigned int	i;
	int				sign;
	int				number;

	i = 0;
	while ((char)str[i] == ' ' || (char)str[i] == '\t'
			|| (char)str[i] == '\n' || (char)str[i] == '\r'
			|| (char)str[i] == '\v' || (char)str[i] == '\f')
		i++;
	sign = ft_test_sign((char)str[i]);
	if (sign == 0)
		return (0);
	if (sign == -1 || (char)str[i] == '+')
		i++;
	number = 0;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10 - '0' + (char)str[i];
		i++;
	}
	number = number * sign;
	return (number);
}

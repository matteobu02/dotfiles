/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 01:09:06 by mbucci            #+#    #+#             */
/*   Updated: 2022/08/20 13:59:05 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	ft_atoi(char *str)
{
	int				s;
	int				i;
	unsigned long	ret;

	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	s = 1;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			s = -1;
	ret = 0;
	while (str[i] && ft_isnum(str[i]))
	{
		ret = (ret * 10) + str[i] - '0';
		if (ret > MAX_INT && s == 1)
			return (-1);
		if (ret > 2147483648 && s == -1)
			return (0);
		i++;
	}
	return (s * ret);
}

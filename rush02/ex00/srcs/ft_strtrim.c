/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 01:10:27 by mbucci            #+#    #+#             */
/*   Updated: 2022/08/21 16:25:34 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

char	*ft_strtrim(char *s, int (*ft)(int))
{
	int		i;
	int		front;
	int		back;
	char	*ret;

	i = 0;
	while (s[i] && ft(s[i]))
		i++;
	front = i;
	i = ft_strlen(s) - 1;
	while (i > 0 && ft(s[i]))
		i--;
	back = i;
	if (!front && back == (ft_strlen(s) - 1))
		return (ft_strdup(s));
	ret = (char *)malloc(ft_strlen(s) + 1);
	if (!ret)
		return (NULL);
	i = 0;
	while (front <= back)
		ret[i++] = s[front++];
	ret[i] = 0;
	return (ret);
}

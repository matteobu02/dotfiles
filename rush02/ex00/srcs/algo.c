/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 16:39:03 by mbucci            #+#    #+#             */
/*   Updated: 2022/08/22 00:51:08 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	write_hundreds(void)
{
	;
}

void	write_tens(void)
{
	;
}

//int	algo_manager(t_rush *struc)
//{
//	int	len;
//	int	div;
//	int	mod;
//	int	i;
//	int	j;
//
//	len = ft_strlen(struc->num);
//	div = len / 3;
//	mod = len % 3;
//	i = -1;
//	while (i)
//	{
//		j = -1;
//		while (++j < 3)
//		{
//
//		}
//	}
//	
//	return (1);
//}

int	look_up_one(t_dict *dict, int mag, char n)
{
	int	ret;

	ret = 0;
	while (dict)
	{
		if (ft_strlen(dict->key) == 1 && dict->key[0] == n)
		{
			ft_putstr(dict->val);
			ret = 1;
		}
		dict = dict->next;
	}
	if (ret && !mag)
		ft_putstr(" hundred");
	return (ret);
}

int	look_up_two(t_dict *dict, char n1, char n2)
{
	int		ret;
	t_dict	*save;

	ret = 0;
	save = dict;
	while (dict)
	{
		if (ft_strlen(dict->key) == 2 && dict->key[0] == n1)
			ft_putstr(dict->val);
		dict = dict->next;
	}
	if (!look_up_one(save, 1, n2))
		return ()
}

int	algo(t_rush *struc)
{
	int	i;
	int	mod;
	int	div;
	int	len;

	i = 0;
	len = ft_strlen(struc->num);
	while (struc->num[i])
	{
		mod = (len - i) % 3;
		div = (len - i) / 3;
		if (mod < 2)
			if (!look_up_one(struc->dict, mod, struc->num[i++]))
				return (0);
		else
			if (look_up_two(struc->dict, struc->num[i++], struc->num[i++]))
				return (0);
		if (!((len - i) % 3))
			if (look_up_magn(struc->dict, div - mod))
				return (0);
	}
	return (1);
}

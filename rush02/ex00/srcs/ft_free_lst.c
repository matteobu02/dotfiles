/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 15:15:45 by mbucci            #+#    #+#             */
/*   Updated: 2022/08/21 15:20:22 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	ft_free_lst(t_dict *ptr)
{
	t_dict	*tmp;

	if (!ptr)
		return ;
	while (ptr)
	{
		tmp = ptr->next;
		if (ptr->key)
		{
			free(ptr->key);
			ptr->key = NULL;
		}
		if (ptr->val)
		{
			free(ptr->val);
			ptr->val = NULL;
		}
		free(ptr);
		ptr = tmp;
	}
	return ;
}

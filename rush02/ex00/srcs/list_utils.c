/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 22:04:29 by mbucci            #+#    #+#             */
/*   Updated: 2022/08/21 22:23:14 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	create_link(t_dict *ptr, char **page)
{
	ptr->key = ft_strtrim(page[0], &ft_isspace);
	ptr->val = ft_strtrim(page[1], &ft_isspace);
	if (!ptr->key || !ptr->val)
		return (0);
	return (1);
}

// if len1 < 3 && len2 < 3 ==> compare: if 1 == 2 ==> remove 2
// 		sort 1 & 2
// if (len1 > 3 || len2 > 3) && 1[0] || 2[0] != 1 ==> remove

//void	dict_remove(t_dict **dict, t_dict *target)
//{
//	t_dict	*tmp;
//
//	if (*dict == target)
//	{
//		tmp = *dict;
//		if ((*dict)->next)
//			*dict = (*dict)->next;
//		else
//			*dict = NULL;
//	}
//	else
//	{
//		while (*dict && (*dict)->next && (*dict)->next != target)
//			*dict = (*dict)->next;
//		tmp = (*dict)->next;
//		if ((*dict)->next->next)
//			(*dict)->next = (*dict)->next->next;
//		else
//			(*dict)->next = NULL;
//	}
//	if (tmp->key)
//		free(tmp->key);
//	if (tmp->val)
//		free(tmp->val);
//	free(tmp);
//}
//
//void	sort_dict(t_dict *dict)
//{
//	t_dict	*tmp;
//
//	while (dict)
//	{
//		tmp = dict->next;
//		while (tmp)
//		{
//			if ()
//		}
//	}
//}
//
//void	clean_dict(t_dict *dict)
//{
//	while (dict)
//	{
//		if 
//	}
//}

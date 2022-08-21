/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 15:32:38 by mbucci            #+#    #+#             */
/*   Updated: 2022/08/21 16:27:48 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	clean_exit(t_rush *s)
{
	if (s)
	{
		if (s->num)
			free(s->num);
		if (s->raw)
			free(s->raw);
		if (s->dict)
			ft_free_lst(s->dict);
		free(s);
		s = NULL;
	}
	return (0);
}

int	print_error(char *msg)
{
	ft_putstr(msg);
	return (0);
}

int	close_and_print(int fd, char *msg)
{
	close(fd);
	return (print_error(msg));
}

int	clean_link_setup(char **dict, char **page)
{
	dict = ft_free_tab(dict);
	if (page)
		page = ft_free_tab(page);
	return (print_error(DICT_ERROR));
}

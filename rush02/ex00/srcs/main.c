/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 22:55:34 by mbucci            #+#    #+#             */
/*   Updated: 2022/08/21 23:46:59 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

//void	print_lst(t_dict *ptr)
//{
//	while (ptr)
//	{
//		ft_putstr(ptr->key);
//		write(1, " : ", 3);
//		ft_putstr(ptr->val);
//		write(1, "\n", 1);
//		ptr = ptr->next;
//	}
//}

int	check_num(int ac, char **av, t_rush *struc)
{
	int	i;

	i = 1;
	if (ac != 2)
		i = 2;
	struc->num = ft_strtrim(av[i], &ft_isspace);
	if (!struc->num || !*struc->num)
		return (print_error(ERROR));
	i = -1;
	while (struc->num[++i])
		if (!ft_isnum(struc->num[i]))
			return (print_error(ERROR));
	return (1);
}

void	get_right_path(t_rush *struc, int ac, char **av)
{
	if (ac == 2)
		struc->path = DEFAULT_PATH;
	else
		struc->path = av[1];
	return ;
}

int	get_all_dict(t_rush *struc, int fd, int rd)
{
	char	*tmp;

	while (rd > 0)
	{
		tmp = (char *)malloc(BUFF_SIZE + 1);
		if (!tmp)
			return (0);
		rd = read(fd, tmp, BUFF_SIZE);
		if (rd > 0)
		{
			tmp[rd] = 0;
			struc->raw = ft_strjoin(struc->raw, tmp);
			if (!struc->raw)
				return (0);
			free(tmp);
		}
	}
	tmp = NULL;
	return (1);
}

int	get_dict(t_rush *struc)
{
	int	fd;
	int	rd;

	fd = open(struc->path, O_RDONLY);
	if (fd == -1)
		return (print_error(DICT_ERROR));
	if (read(fd, NULL, 0) == -1)
		return (close_and_print(fd, DICT_ERROR));
	struc->raw = (char *)malloc(BUFF_SIZE + 1);
	if (!struc->raw)
		return (close_and_print(fd, DICT_ERROR));
	rd = read(fd, struc->raw, BUFF_SIZE);
	if (rd < 0)
		return (close_and_print(fd, DICT_ERROR));
	struc->raw[rd] = 0;
	if (rd == BUFF_SIZE)
		if (!get_all_dict(struc, fd, rd))
			return (close_and_print(fd, DICT_ERROR));
	close(fd);
	return (1);
}

int	checks_for_link(char **page)
{
	if (!page)
		return (0);
	if (ft_tablen(page) != 2)
		return (0);
	return (1);
}

int	init_dict(t_dict **d)
{
	(*d) = (t_dict *)malloc(sizeof(t_dict));
	if (!*d)
		return (0);
	(*d)->val = NULL;
	(*d)->key = NULL;
	(*d)->next = NULL;
	return (1);
}

int	link_dict(t_rush *struc, t_dict *dict)
{
	char	**tab;
	char	**curr;
	int		i;

	tab = ft_split(struc->raw, '\n');
	if (!tab)
		return (print_error(DICT_ERROR));
	i = -1;
	while (tab[++i])
	{
		curr = ft_split(tab[i], ':');
		if (!checks_for_link(curr))
			return (clean_link_setup(tab, curr));
		if (!create_link(dict, curr))
			return (clean_link_setup(tab, curr));
		curr = ft_free_tab(curr);
		if (tab[i + 1])
			if (!init_dict(&dict->next))
				return (clean_link_setup(tab, NULL));
		dict = dict->next;
	}
	tab = ft_free_tab(tab);
	free(struc->raw);
	struc->raw = NULL;
	return (1);
}

t_rush	*init_main_struct(void)
{
	t_rush	*ret;

	ret = (t_rush *)malloc(sizeof(t_rush));
	if (!ret)
		return (NULL);
	ret->raw = NULL;
	ret->ret = NULL;
	ret->dict = NULL;
	return (ret);
}

int	main(int ac, char **av)
{
	t_rush	*data;

	if (ac > 3 || ac < 2)
		return (1);
	data = init_main_struct();
	if (!data)
		return (1);
	get_right_path(data, ac, av);
	if (!init_dict(&data->dict))
		return (clean_exit(data));
	if (!check_num(ac, av, data))
		return (clean_exit(data));
	if (!get_dict(data))
		return (clean_exit(data));
	if (!link_dict(data, data->dict))
		return (clean_exit(data));
	if (!algo(data))
	{
		if (data->ret)
			fee(data->ret);
		print_error(DICT_ERROR);
	}
	return (clean_exit(data));
}

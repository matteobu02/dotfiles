/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 22:53:57 by mbucci            #+#    #+#             */
/*   Updated: 2022/08/21 23:41:01 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# define DEFAULT_PATH	"./dict.txt"
# define MAX_INT		2147483647
# define BUFF_SIZE		4096

// ERRORS
# define ERROR			"Error\n"
# define DICT_ERROR		"Dict Error\n"

typedef struct s_dict
{
	char			*key;
	char			*val;
	struct s_dict	*next;
}	t_dict;

typedef struct s_rush
{
	char	*raw;
	char	*path;
	char	*num;
	char	*ret;
	t_dict	*dict;
}	t_rush;

/** EXIT_UTILS.c **/
int		clean_exit(t_rush *s);
int		print_error(char *msg);
int		close_and_print(int fd, char *msg);
int		clean_link_setup(char **dict, char **page);

/** LIST_UTILS.C **/
int		create_link(t_dict *ptr, char **page);

/** OTHER **/
int		ft_isspace(int c);
int		ft_isnum(int c);
int		ft_atoi(char *str);
int		ft_strlen(char const *s);
int		ft_strcmp(char const *s1, char const *s2);
int		ft_tablen(char **tab);

char	*ft_strtrim(char *s, int (*ft)(int));
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(char const *s);

char	**ft_split(char const *s, int c);

void	ft_putstr(char *s);
void	ft_free_lst(t_dict *ptr);

void	*ft_free_tab(char **tab);

#endif

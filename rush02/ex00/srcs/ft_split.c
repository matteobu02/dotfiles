/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 23:59:28 by mbucci            #+#    #+#             */
/*   Updated: 2022/08/21 16:14:47 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

static int	count_words(char const *s, char c)
{
	int	flag;
	int	count;
	int	i;

	flag = 0;
	count = 0;
	i = -1;
	if (c == 0)
	{
		if (!*s)
			return (0);
		return (1);
	}
	while (s[++i])
	{
		if (flag && s[i] == c)
			flag = 0;
		else if (!flag && s[i] != c)
		{
			flag = 1;
			count++;
		}
	}
	return (count);
}

static int	get_len_word(char const *s, char c, int index)
{
	int	flag;
	int	count;
	int	i;
	int	len;

	i = -1;
	flag = 0;
	count = 0;
	len = ft_strlen(s);
	while (s[++i] && index)
	{
		if (flag && s[i] == c)
		{
			flag = 0;
			index--;
		}
		else if (!flag && s[i] != c)
			flag = 1;
	}
	while (s[i] == c)
		i++;
	while (s[i++] != c && i <= len)
		count++;
	return (count);
}

static void	fill_tab(char const *s, char c, char **tab, int len)
{
	int	i;
	int	j;

	i = 0;
	while (s && i < len)
	{
		while (s && *s == c)
			s++;
		j = 0;
		while (s && *s != c)
		{
			tab[i][j++] = *s++;
			if (!*s)
				break ;
		}
		tab[i++][j] = '\0';
	}
}

char	**ft_split(char	const *s, int c)
{
	char	**tab;
	int		words;
	int		i;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	tab = (char **)malloc(sizeof(char *) * (words + 1));
	if (!tab)
		return (NULL);
	i = -1;
	while (++i < words)
	{
		tab[i] = (char *)malloc(get_len_word(s, c, i) + 1);
		if (!tab[i])
			return (ft_free_tab(tab));
	}
	tab[i] = NULL;
	fill_tab(s, c, tab, words);
	return (tab);
}

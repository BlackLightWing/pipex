/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorbell <msorbell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 14:30:15 by msorbell          #+#    #+#             */
/*   Updated: 2023/04/12 14:18:11 by msorbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_elsif(const char *s, int m, int i, int o)
{
	char	*str;

	str = malloc((i - m + 1) * sizeof(char));
	while (m < i)
		str[o++] = s[m++];
	str[o] = '\0';
	return (str);
}

static void	ft_while1(char const *str, int *tab, char c)
{
	while (*str)
	{
		if (*str != c && tab[3] == 0)
		{
			tab[3] = 1;
			tab[2]++;
		}
		else if (*str == c)
			tab[3] = 0;
		str++;
	}
}

static void	ft_while2(int *tab, char const *s, char c, char **split)
{
	while (tab[0] <= tab[5])
	{
		if (s[tab[0]] != c && tab[4] < 0)
			tab[4] = tab[0];
		else if ((s[tab[0]] == c || tab[0] == tab[5]) && tab[4] >= 0)
		{
			split[tab[1]++] = ft_elsif(s, tab[4], tab[0], tab[6]);
			tab[4] = -1;
		}
		tab[0]++;
	}
}

char	**ft_split(char const *s, char c)
{
	int			tab[7];
	char		**split;
	char const	*str;

	if (!s)
		return (NULL);
	ft_bzero(tab, sizeof(int) * 7);
	tab[5] = ft_strlen(s);
	str = s;
	ft_while1(str, tab, c);
	split = (char **)malloc((tab[2] + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	tab[4] = -1;
	ft_while2(tab, s, c, split);
	split[tab[1]] = 0;
	return (split);
}

	// i = 0	tab[0]
	// j = 0	tab[1]
	// k = 0	tab[2]
	// l = 0	tab[3]
	// m = 0	tab[4]
	// n = ft_strlen(s)	tab[5]
	// o = 0	tab[6]

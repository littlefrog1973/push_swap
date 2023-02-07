/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:06:55 by sdeeyien          #+#    #+#             */
/*   Updated: 2022/10/18 13:42:30 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_freemem(char **str, int i)
{
	while (i-- > 0)
		free(str[i]);
	free (str);
}

static char	**do_split(char const *s, size_t count, size_t *t_pos, char **split)
{
	size_t			i;

	i = 0;
	while (i < count)
	{
		split[i] = ft_substr(s, (unsigned int) t_pos[2 * i], t_pos[2 * i + 1]);
		if (!*(split + i))
		{
			ft_freemem(split, i);
			free(t_pos);
			return (NULL);
		}
		i++;
	}
	split[i] = NULL;
	free(t_pos);
	return (split);
}

static void	make_tmp_pos(char const *deli_pos, size_t *tmp_pos, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	flag;

	i = 0;
	j = 0;
	flag = 0;
	while (deli_pos[i])
	{
		if (deli_pos[i] == c)
			flag = 0;
		if (deli_pos[i] != c && !flag)
		{
			tmp_pos[2 * j] = i;
			k = 0;
			while (deli_pos[i + k] != c && deli_pos[i + k] != '\0')
				k++;
			tmp_pos[(2 * j) + 1] = k;
			flag = 1;
			j++;
		}
		i++;
	}
}

static size_t	word_count(char const *deli_pos, char c)
{
	size_t	i;
	size_t	j;
	size_t	flag;

	i = 0;
	j = 0;
	flag = 0;
	while (deli_pos[i])
	{
		if (deli_pos[i] == c)
			flag = 0;
		if (deli_pos[i] != c && !flag)
		{
			flag = 1;
			j++;
		}
		i++;
	}
	return (j);
}

char	**ft_split(char const *s, char c)
{
	size_t	count;
	char	**split;
	size_t	*tmp_pos;
	size_t	len;

	if (!s)
		return ((char **) NULL);
	len = ft_strlen(s);
	count = word_count(s, c);
	if (count == 0 || count == len || len == 0 || !s)
	{
		split = (char **) ft_calloc(1, sizeof(char *));
		return (split);
	}
	else
	{
		tmp_pos = (size_t *) malloc(count * 2 * sizeof(size_t));
		if (!tmp_pos)
			return ((char **) NULL);
		split = (char **) malloc((count + 1) * sizeof(char *));
		if (!split)
			return ((char **) NULL);
		make_tmp_pos(s, tmp_pos, c);
		return (do_split(s, count, tmp_pos, split));
	}
}
/*
#include <stdio.h>

int	main(void)
{
//	char str[] = "\0aa\0bbb";
	char str[] = "ab,cd,ef,f";
	char **split;
	int	i;
//	size_t	count;
//	size_t	ttmp_pos[1000];

	split = ft_split(str, '\0');
	if (!split)
		exit (1);
	i = 0;
	while (split[i])
	{
		printf("split[%d] = %s\n", i, *(split + i));
		i++;
	}
	return (0);
}*/

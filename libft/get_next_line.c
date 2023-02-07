/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 21:55:35 by sdeeyien          #+#    #+#             */
/*   Updated: 2022/10/04 23:47:41 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*init_line(char *line)
/* Just initiate line with only one byte allocation */
{
	if (!line)
	{
		line = (char *) malloc(sizeof(char));
		if (!line)
			return (NULL);
		line[0] = '\0';
	}
	return (line);
}

static char	*chop(char *line)
/* To chop line to each new line ended chop_line */
{
	size_t	j;
	char	*chop_line;
	size_t	i;
	size_t	s_len;

	j = 0;
	while (line[j] != '\n' && line[j])
		j++;
	chop_line = (char *) malloc((j + 2));
	if (!chop_line)
	{
		free(line);
		return (NULL);
	}
	ft_strlcpy(chop_line, line, j + 2);
	i = 0;
	s_len = ft_strlen(line);
	while (i + (j + 1) < s_len)
	{
		line[i] = line[j + 1 + i];
		i++;
	}
	line[i] = '\0';
	return (chop_line);
}

static char	*join_line_buffer(char *line, char *buffer, ssize_t j)
/* Join read buffer to static char *line */
{
	char	*temp;

	buffer[j] = '\0';
	temp = line;
	line = ft_strjoin(line, buffer);
	if (!line)
	{
		free(temp);
		return (NULL);
	}
	free(temp);
	return (line);
}

static char	*read_to_line(char *r_line, int fd, int *sig)
/* read to buffer until found new line, use sig to inform caller in case error
 sig = 1 = malloc error of local r_buffer so just return (r_line) */
{
	char	*r_buffer;
	ssize_t	j;

	r_buffer = (char *) malloc(BUFFER_SIZE + 1);
	if (!r_buffer)
	{
		*sig = 1;
		return (r_line);
	}
	while (1)
	{
		j = read(fd, r_buffer, BUFFER_SIZE);
		if (j > 0)
		{
			r_line = join_line_buffer(r_line, r_buffer, j);
			if (!r_line || check_new_line(r_line) >= 0)
				break ;
			continue ;
		}
		else
			break ;
	}
	free (r_buffer);
	return (r_line);
}

char	*get_next_line(int fd)
/* new get_next_line to reduce line number of code */
{
	static char	*line;
	int			err;

	if (BUFFER_SIZE < 0 || fd < 0)
		return (NULL);
	err = 0;
	line = init_line(line);
	if (!line)
		return (NULL);
	line = read_to_line(line, fd, &err);
	if (err || !(*line))
	{
		free(line);
		line = NULL;
		return (NULL);
	}
	else
		return (chop(line));
}

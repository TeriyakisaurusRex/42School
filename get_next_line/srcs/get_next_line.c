/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 13:05:47 by jthiele           #+#    #+#             */
/*   Updated: 2022/03/01 15:07:56 by jthiele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

static char	*free_copycat(char *s1, char *s2)
{
	char	*temp;

	temp = s1;
	s1 = ft_strjoin(s1, s2);
	free(temp);
	temp = NULL;
	return (s1);
}

static char	*read_line(int fd, char *line, char *buffer)
{
	int	i;
	int	read_value;

	i = 0;
	read_value = read(fd, buffer, BUFFER_SIZE);
	while (read_value != -1)
	{
		if (!read_value)
			return (line);
		buffer[read_value] = '\0';
		if (!line)
			line = ft_strdup("");
		line = free_copycat(line, buffer);
		while (line[i] && line[i] != '\n')
			i++;
		if (line[i] == '\n')
			return (line);
		read_value = read(fd, buffer, BUFFER_SIZE);
	}
	return (0);
}

static char	*trim_excess(char *line)
{
	int		i;
	char	*trim;

	i = 0;
	trim = NULL;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
		return (trim);
	if (line[i + 1])
		trim = ft_substr(line, i + 1, ft_strlen(line) - (i + 1));
	line[i + 1] = '\0';
	return (trim);
}

char	*get_next_line(int fd)
{
	static char	*excess;
	char		*line;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = malloc(sizeof(*buffer) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	line = read_line(fd, excess, buffer);
	free(buffer);
	if (!line)
		return (0);
	excess = trim_excess(line);
	return (line);
}

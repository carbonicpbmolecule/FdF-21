/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jirwin <jirwin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 12:36:40 by jirwin            #+#    #+#             */
/*   Updated: 2020/01/22 12:37:09 by jirwin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	appendline(char **s, char **line)
{
	int		len;
	char	*tmp;

	len = 0;
	while ((*s)[len] != '\n' && (*s)[len] != '\0')
		len++;
	if ((*s)[len] == '\n')
	{
		*line = ft_strsub(*s, 0, len);
		tmp = ft_strdup(&((*s)[len + 1]));
		free(*s);
		*s = tmp;
		if ((*s)[0] == '\0')
			ft_strdel(s);
	}
	else
	{
		*line = ft_strdup(*s);
		ft_strdel(s);
	}
	return (1);
}

static int	output(char **s, char **line, int ret)
{
	if (ret < 0)
		return (-1);
	else if (ret == 0 && *s == NULL)
		return (0);
	else
		return (appendline(s, line));
}

int			get_next_line(const int fd, char **line)
{
	char		buff[BUFF_SIZE + 1];
	int			bwr;
	static char	*remainder;
	char		*tmp;

	while ((bwr = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[bwr] = '\0';
		if (remainder == NULL)
			remainder = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin(remainder, buff);
			free(remainder);
			remainder = tmp;
		}
		if (ft_strchr(remainder, '\n'))
			break ;
	}
	return (output(&remainder, line, bwr));
}

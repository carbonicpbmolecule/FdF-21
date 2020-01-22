/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jirwin <jirwin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 12:34:02 by jirwin            #+#    #+#             */
/*   Updated: 2020/01/22 18:07:30 by jirwin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void 	error(void)
{
	ft_putstr("error\n");
	exit(1);
}

int		is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

void	free_strarray(char **strarray)
{
	int		i;
	
	i = 0;
	while (strarray[i] != NULL)
		free(strarray[i++]);
	free(strarray);
}

void	check_height(char *line)
{
	char	**words;
	char	**height;
	int		i;
	int		j;
	
	words = ft_strsplit(line, ' ');
	if (!(words[0]))
			error();
	i = 0;
	while (words[i] != NULL)
	{
		height = ft_strsplit(words[i], ',');
		if (!(height[0]))
			error();
		j = 0;
		while (height[0][j] != '\0')
		{
			if (!(is_digit(height[0][j++])))
			{
				if (height[0][0] != '-')
				{
					free_strarray(height);
					free_strarray(words);
					error();
				}
			}
		}
		free_strarray(height);
		i++;
	}
	free_strarray(words);
}

int		get_height(char *file_name)
{
	char	*line;
	int		fd;
	int		height;
	int		i;
	int		j;
	char	**words;

	fd = open(file_name, O_RDONLY, 0);
	height = 0;
	while (get_next_line(fd, &line))
	{
		height++;
		check_height(line);
		free(line);
	}
	close(fd);
	return (height);
}

int		get_width(char *file_name)
{
	char	*line;
	int		fd;
	int		width;
	int		width_prev;

	fd = open(file_name, O_RDONLY, 0);
	width_prev = -1;
	while (get_next_line(fd, &line))
	{
		width = ft_wdcounter(line, ' ');
		if (width_prev != -1 && width != width_prev)
			error();
		width_prev = width;
		free(line);
	}
	if (width_prev == -1)
		error();
	close(fd);
	return (width);
}

void	fill_matrix(int *z_line, char *line)
{
	char	**nums;
	int		i;

	nums = ft_strsplit(line, ' ');
	i = 0;
	while (nums[i])
	{
		z_line[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	free(nums);
}

void	read_file(char *file_name, fdf *data)
{
	int		fd;
	char	*line;
	int		i;

	data->is_iso = 0;
	data->angle = 0.8;
	data->height = get_height(file_name);
	data->width = get_width(file_name);
	if (data->height <= 2 && data->width <= 2)
		error();
	data->z_matrix = (int **)malloc(sizeof(int *) * (data->height + 1));
	i = 0;
	while (i <= data->height)
		data->z_matrix[i++] = (int *)malloc(sizeof(int) * (data->width + 1));
	fd = open(file_name, O_RDONLY, 0);
	i = 0;
	while (get_next_line(fd, &line))
	{
		fill_matrix(data->z_matrix[i++], line);
		free(line);
	}
	close(fd);
}

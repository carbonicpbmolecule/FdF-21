/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jirwin <jirwin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 19:25:39 by rjeraldi          #+#    #+#             */
/*   Updated: 2020/01/22 20:40:51 by jirwin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	free_matrix(t_fdf *data)
{
	int	i;

	i = 0;
	while (i <= data->height)
		free(data->z_matrix[i++]);
	free(data->z_matrix);
	free(data);
}

void	free_strarray(char **strarray)
{
	int	i;

	i = 0;
	while (strarray[i] != NULL)
		free(strarray[i++]);
	free(strarray);
}

void	free_check_height(char **strarray1, char **strarray2)
{
	free_strarray(strarray1);
	free_strarray(strarray2);
	error();
}

void	error(void)
{
	ft_putstr("error: invalid map\n");
	exit(1);
}

void	quit(t_fdf *data)
{
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	exit(1);
}

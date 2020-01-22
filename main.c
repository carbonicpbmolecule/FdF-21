/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jirwin <jirwin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 12:25:48 by jirwin            #+#    #+#             */
/*   Updated: 2020/01/22 17:19:09 by jirwin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		deal_key(int key, fdf *data)
{
	// printf("%d\n", key);
	if (key == ESCAPE)
	{
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		exit(1);
	}
	if (key == PLUS)
		data->zoom += 5;
	if ((key == MINUS) && (data->zoom > 5))
		data->zoom -= 5;
	if (key == DOWN_KEY)
		data->shift_y -= 20;
	if (key == UP_KEY)
		data->shift_y += 20;
	if (key == RIGHT_KEY)
		data->shift_x -= 20;
	if (key == LEFT_KEY)
		data->shift_x += 20;
	if (key == 21 && (data->angle = 0.8))
		data->is_iso = (data->is_iso == 0) ? 1 : 0;
	if (key == 22 && (data->is_iso = 1))
		data->angle += 0.1;
	if (key == 23 && (data->is_iso = 1))
		data->angle -= 0.1;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
	return (0); 
}

void	free_matrix(fdf *data)
{
	int i;

	i = 0;
	while (i <= data->height)
		free(data->z_matrix[i++]);
	free(data->z_matrix);
	free(data);
}

int		main(int argc, char **argv)
{
	fdf	*data;

	if (argc != 2)
	{
		ft_putstr("usage: ./fdf map.fdf\n");
		exit(1);
	}
	data = (fdf *)malloc(sizeof(fdf));
	read_file(argv[1], data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 800, 600, "fdf");
	data->zoom = 25;
	data->shift_x = 300;
	data->shift_y = 150;
	draw(data);
	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_loop(data->mlx_ptr);
	free_matrix(data);
	return (0);
}

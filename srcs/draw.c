/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jirwin <jirwin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 12:56:49 by jirwin            #+#    #+#             */
/*   Updated: 2020/01/22 20:18:10 by rjeraldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int		isometric(float *x, float *y, int z, float angle)
{
	*x = (*x - *y) * cos(angle);
	*y = (*x + *y) * sin(angle) - z;
	return (1);
}

void	zoom(t_xy *xy0, t_xy *xy1, t_fdf *data)
{
	xy0->x *= data->zoom;
	xy1->x *= data->zoom;
	xy0->y *= data->zoom;
	xy1->y *= data->zoom;
}

void	shift(t_xy *xy0, t_xy *xy1, t_fdf *data)
{
	xy0->x += data->shift_x;
	xy0->y += data->shift_y;
	xy1->x += data->shift_x;
	xy1->y += data->shift_y;
}

void	bresenham(t_xy xy0, t_xy xy1, t_fdf *data)
{
	float	x_step;
	float	y_step;
	int		max;
	int		z0;
	int		z1;

	z0 = data->z_matrix[(int)xy0.y][(int)xy0.x];
	z1 = data->z_matrix[(int)xy1.y][(int)xy1.x];
	zoom(&xy0, &xy1, data);
	data->color = (z0 || z1) ? 0xe80c0c : 0xffffff;
	if (data->is_iso && (isometric(&xy0.x, &xy0.y, z0, data->angle)))
		isometric(&xy1.x, &xy1.y, z1, data->angle);
	shift(&xy0, &xy1, data);
	x_step = xy1.x - xy0.x;
	y_step = xy1.y - xy0.y;
	max = fmax(fabs(x_step), fabs(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(xy0.x - xy1.x) || (int)(xy0.y - xy1.y))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, xy0.x, xy0.y, data->color);
		xy0.x += x_step;
		xy0.y += y_step;
	}
}

void	draw(t_fdf *data)
{
	t_xy	xy0;
	t_xy	xy1;

	xy0.y = 0;
	while (xy0.y < data->height)
	{
		xy0.x = 0;
		while (xy0.x < data->width)
		{
			if (xy0.x < data->width - 1)
			{
				xy1.x = xy0.x + 1;
				xy1.y = xy0.y;
				bresenham(xy0, xy1, data);
			}
			if (xy0.y < data->height - 1)
			{
				xy1.x = xy0.x;
				xy1.y = xy0.y + 1;
				bresenham(xy0, xy1, data);
			}
			xy0.x++;
		}
		xy0.y++;
	}
}

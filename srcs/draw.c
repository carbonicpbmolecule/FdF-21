/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jirwin <jirwin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 12:56:49 by jirwin            #+#    #+#             */
/*   Updated: 2020/01/22 17:18:23 by jirwin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void isometric(float *x, float *y, int z, float angle)
{
	*x = (*x - *y) * cos(angle);
	*y = (*x + *y) * sin(angle) - z;
}

void zoom(float *x0, float *x1, float *y0, float *y1, fdf *data)
{
	*x0 *= data->zoom;
	*x1 *= data->zoom;
	*y0 *= data->zoom;
	*y1 *= data->zoom;
}

void shift(float *x0, float *x1, float *y0, float *y1, fdf *data)
{
	*x0 += data->shift_x;
	*y0 += data->shift_y;
	*x1 += data->shift_x;
	*y1 += data->shift_y;
}

void bresenham(t_xy xy0, t_xy xy1, fdf *data)
{
	float	x_step;
	float	y_step;
	int		max;
	int		z0;
	int		z1;

	z0 = data->z_matrix[(int)xy0.y][(int)xy0.x];
	z1 = data->z_matrix[(int)xy1.y][(int)xy1.x];
	zoom(&xy0.x, &xy1.x, &xy0.y, &xy1.y, data);
	data->color = (z0 || z1) ? 0xe80c0c : 0xffffff;
	if (data->is_iso)
	{
		isometric(&xy0.x, &xy0.y, z0, data->angle);
		isometric(&xy1.x, &xy1.y, z1, data->angle);
	}
	shift(&xy0.x, &xy1.x, &xy0.y, &xy1.y, data);
	x_step = xy1.x - xy0.x;
	y_step = xy1.y - xy0.y;
	max = MAX(MOD(x_step), MOD(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(xy0.x - xy1.x) || (int)(xy0.y - xy1.y))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, xy0.x, xy0.y, data->color);
		xy0.x += x_step;
		xy0.y += y_step;
	}
}

void draw(fdf *data)
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeraldi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 18:30:39 by rjeraldi          #+#    #+#             */
/*   Updated: 2020/01/22 18:31:34 by rjeraldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <libft.h>
# include <mlx.h>
# include <math.h>
# include <fcntl.h>

# define MAX(a, b) (a > b ? a : b)
# define MOD(a) ((a < 0) ? -a : a)
# define UP_KEY 125
# define DOWN_KEY 126
# define RIGHT_KEY 123
# define LEFT_KEY 124
# define ESCAPE 53
# define PLUS 24
# define MINUS 27
# define NUM4 21
# define NUM5 23
# define NUM6 24

typedef struct
{
	int			width;
	int			height;
	int			zoom;
	int			color;
	int			**z_matrix;
	int			shift_x;
	int			shift_y;
	int			is_iso;
	float		angle;
	void		*mlx_ptr;
	void		*win_ptr;
}				fdf;

typedef struct	s_xy
{
	float		x;
	float		y;
}				t_xy;

void			read_file(char *file_name, fdf *data);
void 			bresenham(t_xy xy0, t_xy xy1, fdf *data);
void			draw(fdf *data);
void 			free_z_matrix(fdf *data);

#include <stdio.h>

#endif

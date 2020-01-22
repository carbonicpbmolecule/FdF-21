/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeraldi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 18:44:24 by rjeraldi          #+#    #+#             */
/*   Updated: 2020/01/22 20:15:10 by rjeraldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <libft.h>
# include <mlx.h>
# include <math.h>
# include <fcntl.h>

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
}				t_fdf;

typedef struct	s_xy
{
	float		x;
	float		y;
}				t_xy;

int				is_digit(char c);
void			read_file(char *file_name, t_fdf *data);
void			bresenham(t_xy xy0, t_xy xy1, t_fdf *data);
void			draw(t_fdf *data);
void			free_matrix(t_fdf *data);
void			free_z_matrix(t_fdf *data);
void			free_strarray(char **strarray);
void			free_check_height(char **strarray1, char **strarray2);
void			error(void);
void			quit(t_fdf *data);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlahrach <mlahrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 20:42:55 by mlahrach          #+#    #+#             */
/*   Updated: 2024/06/09 20:16:33 by mlahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 800
# define HEIGHT 800

# define BLACK 0x000000
# define WHITE 0xFFFFFF

typedef struct s_complex
{
	double	x;
	double	y;
}			t_complex;

typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}			t_img;

typedef struct s_fractal
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;

	double	escape_value;
	int		iterations_defintion;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
}			t_fractal;

int			ft_strncmp(char *s1, char *s2, int n);
void		putstr_fd(char *s, int fd);
double		atodbl(char *s);

void		fractal_init(t_fractal *fractal);

void		fractal_render(t_fractal *fractal);

double		map1(double unscaled_num);
double		map2(double unscaled_num, int iterations);

t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);

int			key_handler(int keysym, t_fractal *fractal);

int			close_handler(t_fractal *fractal);
int			mouse_handler(int button, int x, int y, t_fractal *fractal);

#endif

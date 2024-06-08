/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlahrach <mlahrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 20:43:44 by mlahrach          #+#    #+#             */
/*   Updated: 2024/06/07 17:38:18 by mlahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "minilibx-linux/mlx.h"

static void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

static void	mandel_vs_julia(t_complex *z, t_complex *c, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		c->x = fractal->julia_x;
		c->y = fractal->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

void	init_struct_1(MapParams *params, int x)
{
	params->unscaled_num = x;
	params->new_min = 0;
	params->new_max = WIDTH;
	params->old_min = -2;
	params->old_max = +2;
}
void	init_struct_2(MapParams *params, int y)
{
	params->unscaled_num = y;
	params->new_min = 0;
	params->new_max = HEIGHT;
	params->old_min = +2;
	params->old_max = -2;
}
void	init_struct_3(MapParams *params, int i, t_fractal *fractal)
{
	params->unscaled_num = i;
	params->new_min = 0;
	params->new_max = fractal->iterations_defintion;
	params->old_min = BLACK;
	params->old_max = WHITE;
}
static void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;
	MapParams mapParams;

	i = 0;
	init_struct_1(&mapParams, x);
	z.x = (map(mapParams) * fractal->zoom) + fractal->shift_x;
	init_struct_2(&mapParams, y);
	z.y = (map(mapParams) * fractal->zoom) + fractal->shift_y;
	mandel_vs_julia(&z, &c, fractal);
	while (i < fractal->iterations_defintion)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
		{
			init_struct_3(&mapParams, i, fractal);
			color = map(mapParams);
			my_pixel_put(x, y, &fractal->img, color);
			return ;
		}
		++i;
	}
	my_pixel_put(x, y, &fractal->img, WHITE);
}

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			handle_pixel(x, y, fractal);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window,
		fractal->img.img_ptr, 0, 0);
}

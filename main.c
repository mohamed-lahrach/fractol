/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlahrach <mlahrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 20:43:21 by mlahrach          #+#    #+#             */
/*   Updated: 2024/06/09 19:56:45 by mlahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "minilibx-linux/mlx.h"

int	main(int ac, char **av)
{
	t_fractal	fractal;
	char		*message;

	if ((2 == ac && !ft_strncmp(av[1], "mandelbrot", 10)) || (4 == ac
			&& !ft_strncmp(av[1], "julia", 5)))
	{
		fractal.name = av[1];
		if (!ft_strncmp(fractal.name, "julia", 5))
		{
			fractal.julia_x = atodbl(av[2]);
			fractal.julia_y = atodbl(av[3]);
		}
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
	{
		message = "Usage:\n"
			"\t\"./fractol mandelbrot\"\n"
			"\t\"./fractol julia <v1> <v2>\"\n";
		putstr_fd(message, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}

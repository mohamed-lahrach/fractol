/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlahrach <mlahrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 20:43:21 by mlahrach          #+#    #+#             */
/*   Updated: 2024/06/12 22:34:26 by mlahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "minilibx-linux/mlx.h"
#include <stdio.h>

int	is_double(const char *str)
{
	int			seen_digit;
	int			seen_dot;
	const char	*ptr = str;

	seen_digit = 0;
	seen_dot = 0;
	if (*ptr == '+' || *ptr == '-')
		ptr++;
	while (*ptr)
	{
		if (my_isdigit(*ptr))
			seen_digit = 1;
		else if (*ptr == '.')
		{
			if (seen_dot)
				return (0);
			seen_dot = 1;
		}
		else
			break ;
		ptr++;
	}
	return (seen_digit && *ptr == '\0');
}

void	show_error1(void)
{
	putstr_fd("There are invalid values\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	show_error2(void)
{
	char	*message;

	message = "Usage:\n"
		"\t\"./fractol mandelbrot\"\n"
		"\t\"./fractol julia <v1> <v2>\"\n";
	putstr_fd("There are invalid values\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

int	main(int ac, char **av)
{
	t_fractal	fractal;

	if ((2 == ac && !ft_strncmp(av[1], "mandelbrot", 10)) || (4 == ac
			&& !ft_strncmp(av[1], "julia", 5)))
	{
		fractal.name = av[1];
		if (!ft_strncmp(fractal.name, "julia", 5))
		{
			if (!is_double(av[2]) || !is_double(av[3]))
				show_error1();
			fractal.julia_x = atodbl(av[2]);
			fractal.julia_y = atodbl(av[3]);
		}
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
		show_error2();
}

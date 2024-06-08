/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlahrach <mlahrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 20:43:34 by mlahrach          #+#    #+#             */
/*   Updated: 2024/06/04 20:43:35 by mlahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


double map(MapParams params) {
	return ((params.new_max - params.new_min) * (params.unscaled_num - params.old_min) 
			/ (params.old_max - params.old_min) + params.new_min);
}
t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return (result);
}

t_complex	square_complex(t_complex z)
{
	t_complex	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlahrach <mlahrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 20:43:49 by mlahrach          #+#    #+#             */
/*   Updated: 2024/06/04 20:43:50 by mlahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(char *s1, char *s2, int n)
{
	if (NULL == s1 || NULL == s2 || n <= 0)
		return (0);
	while (*s1 == *s2 && n > 0 && *s1 != '\0')
	{
		++s1;
		++s2;
		--n;
	}
	return (*s1 - *s2);
}

void	putstr_fd(char *s, int fd)
{
	if (NULL == s || fd < 0)
		return ;
	if (*s != '\0')
	{
		write(fd, s, 1);
		putstr_fd(s + 1, fd);
	}
}

double	parse_fractional_part(char *s, double *pow, int *dot_count)
{
	double	fractional_part;

	fractional_part = 0;
	while (*s)
	{
		if (!(*s >= '0' && *s <= '9'))
			return (0);
		if ('.' == *s)
			(*dot_count)++;
		if (*dot_count > 1)
			return (0);
		*pow /= 10;
		fractional_part = fractional_part + (*s++ - 48) * *pow;
	}
	return (fractional_part);
}

double	parse_integer_part(char **s, int *sign)
{
	long	integer_part;

	integer_part = 0;
	if ('+' == **s || '-' == **s)
	{
		if ('-' == *(*s)++)
			*sign = -*sign;
	}
	if (!(**s >= '0' && **s <= '9'))
		return (0);
	while (**s != '.' && **s)
	{
		if (!(**s >= '0' && **s <= '9'))
			return (0);
		integer_part = (integer_part * 10) + (*(*s)++ - 48);
	}
	return (integer_part);
}

double	atodbl(const char *s)
{
	long	integer_part;
	double	fractional_part;
	double	pow;
	int		sign;

	integer_part = 0;
	fractional_part = 0;
	sign = +1;
	pow = 1;
	while (my_isspace(*s))
		++s;
	if (*s == '-')
		sign = -sign;
	if (*s == '-' || *s == '+')
		++s;
	while (*s != '.' && *s)
		integer_part = (integer_part * 10) + (*s++ - 48);
	if ('.' == *s)
		++s;
	while (*s)
	{
		pow /= 10;
		fractional_part = fractional_part + (*s++ - 48) * pow;
	}
	return ((integer_part + fractional_part) * sign);
}

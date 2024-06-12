/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlahrach <mlahrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 22:33:55 by mlahrach          #+#    #+#             */
/*   Updated: 2024/06/12 22:34:16 by mlahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	my_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r');
}

int	my_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}
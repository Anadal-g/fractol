/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadal-g <anadal-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:20:14 by anadal-g          #+#    #+#             */
/*   Updated: 2024/10/15 17:38:30 by anadal-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_strncmp(char *s1, char *s2, int n)
{
	if (s1 == NULL || s2 == NULL || n <= 0)
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
	ssize_t	result;

	if (s == NULL || fd < 0)
		return ;
	if (*s != '\0')
	{
		result = write(fd, s, 1);
		if (result == -1)
			return ;
		putstr_fd(s + 1, fd);
	}
}

static double	ft_atodbl2(char *str, double nb)
{
	double	dec;
	double	aux;

	dec = 10;
	while (*str >= '0' && *str <= '9')
	{
		nb = ((*str - '0') + (nb * 10));
		str++;
	}
	if (*str == '.')
	{
		dec = 10;
		str++;
		while (*str >= '0' && *str <= '9')
		{
			aux = ((*str - '0'));
			nb = nb + (aux / dec);
			dec *= 10;
			str++;
		}
	}
	return (nb);
}

double	ft_atodbl(char *str, t_fractal *fractal)
{
	double	nb;
	int		sing;

	nb = 0;
	sing = 0;
	while ((*str <= 13 && *str >= 9) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sing = 1;
		str++;
	}
	nb = ft_atodbl2(str, nb);
	if (*str < '0' || *str > '9')
		fractal->error = 1;
	if (sing == 1)
		nb = nb * -1;
	return (nb);
}

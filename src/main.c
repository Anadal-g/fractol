/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadal-g <anadal-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:04:23 by anadal-g          #+#    #+#             */
/*   Updated: 2024/01/23 12:23:20 by anadal-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	error_message(void)
{
	putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
	putstr_fd(ERROR_MESSAGE1, STDERR_FILENO);
	putstr_fd(ERROR_MESSAGE12, STDERR_FILENO);
	putstr_fd(ERROR_MESSAGE13, STDERR_FILENO);
	putstr_fd(ERROR_MESSAGE14, STDERR_FILENO);
	putstr_fd(ERROR_MESSAGE2, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

int	main(int ac, char **av)
{
	t_fractal	fractal;

	if ((ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10))
		|| (ac == 4 && !ft_strncmp(av[1], "julia", 5))
		|| (ac == 2 && !ft_strncmp(av[1], "ship", 4)))
	{
		fractal.name = av[1];
		if (!ft_strncmp(av[1], "julia", 5))
		{
			fractal.julia_x = ft_atodbl(av[2], &fractal);
			fractal.julia_y = ft_atodbl(av[3], &fractal);
			if (fractal.error == 1)
				error_message();
		}
		if (!ft_strncmp(av[1], "ship", 4))
		{
			fractal.name = av[1];
		}
		fractal_init(&fractal);
		fractal_render(&fractal);
		events_init(&fractal);
	}
	else
		error_message();
}

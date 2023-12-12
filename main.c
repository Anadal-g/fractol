/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadal-g <anadal-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:04:23 by anadal-g          #+#    #+#             */
/*   Updated: 2023/12/12 11:59:18 by anadal-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
			fractal.julia_x = atodbl(av[2]);
			fractal.julia_y = atodbl(av[3]);
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
	{
		putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		putstr_fd(ERROR_MESSAGE1, STDERR_FILENO);
		putstr_fd(ERROR_MESSAGE2, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadal-g <anadal-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:34:22 by anadal-g          #+#    #+#             */
/*   Updated: 2023/12/12 11:48:17 by anadal-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_window(t_fractal *fractal)
{
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	exit(EXIT_SUCCESS);
}

int	key_hooks(int keysym, t_fractal *fractal)
{
	if (keysym == 53)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		exit(0);
	}
	else if (keysym == 123)
		fractal->shift_x += (0.5 * fractal->zoom);
	else if (keysym == 124)
		fractal->shift_x -= (0.5 * fractal->zoom);
	else if (keysym == 126)
		fractal->shift_y -= (0.5 * fractal->zoom);
	else if (keysym == 125)
		fractal->shift_y += (0.5 * fractal->zoom);
	else if (keysym == 69)
		fractal->iteration += 10;
	else if (keysym == 78)
		fractal->iteration -= 10;
	else if (keysym == 13)
		fractal->color += 1000;
	fractal_render(fractal);
	return (0);
}

int	mouse_hooks(int keysym, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	if (keysym == 5)
	{
		fractal->zoom *= 0.9;
	}
	else if (keysym == 4)
	{
		fractal->zoom *= 1.1;
	}
	fractal_render(fractal);
	return (0);
}

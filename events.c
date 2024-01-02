/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadal-g <anadal-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:34:22 by anadal-g          #+#    #+#             */
/*   Updated: 2024/01/02 13:31:44 by anadal-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_window(t_fractal *fractal)
{
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	exit(EXIT_SUCCESS);
}

static void	zoom_in(t_fractal *fractal, int x, int y)
{
	int	aux_x;
	int	aux_y;

	aux_x = x;
	aux_y = y;
	fractal->zmx *= 0.9;
	fractal->zmy *= 0.9;
	if (!ft_strncmp(fractal->name, "ship", 4))
	{
		fractal->shftx += map(aux_x, -fractal->zmx, fractal->zmy, WIDTH) * 0.19;
		fractal->shfty += map(aux_y, fractal->zmx, -fractal->zmy, WIDTH) * 0.19;
	}
	else
	{
		fractal->shftx += map(aux_x, -fractal->zmx, fractal->zmy, WIDTH) * 0.19;
		fractal->shfty += map(aux_y, fractal->zmx, -fractal->zmy, WIDTH) * 0.19;
	}
}

static void	zoom_out(t_fractal *fractal, int x, int y)
{
	int	aux_x;
	int	aux_y;

	aux_x = x;
	aux_y = y;
	fractal->zmx *= 1.1;
	fractal->zmy *= 1.1;
	if (!ft_strncmp(fractal->name, "ship", 4))
	{
		fractal->shftx += map(aux_x, -fractal->zmx, fractal->zmy, WIDTH) * 0.19;
		fractal->shfty += map(aux_y, -fractal->zmx, fractal->zmy, WIDTH) * 0.19;
	}
	else
	{
		fractal->shftx += map(aux_x, -fractal->zmx, fractal->zmy, WIDTH) * 0.19;
		fractal->shfty += map(aux_y, fractal->zmx, -fractal->zmy, WIDTH) * 0.19;
	}
}

int	key_hooks(int keysym, t_fractal *fractal)
{
	if (keysym == 53)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		exit(0);
	}
	else if (keysym == 123)
		fractal->shftx += (0.5 * fractal->zmx);
	else if (keysym == 124)
		fractal->shftx -= (0.5 * fractal->zmx);
	else if (keysym == 126)
		fractal->shfty -= (0.5 * fractal->zmx);
	else if (keysym == 125)
		fractal->shfty += (0.5 * fractal->zmx);
	else if (keysym == 69)
		fractal->iter += 10;
	else if (keysym == 78)
		fractal->iter -= 10;
	else if (keysym == 13)
		fractal->color += 1000;
	fractal_render(fractal);
	return (0);
}

int	mouse_hooks(int keysym, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	if (keysym == 4)
	{
		zoom_out(fractal, x, y);
	}
	else if (keysym == 5)
	{
		zoom_in(fractal, x, y);
	}
	fractal_render(fractal);
	return (0);
}

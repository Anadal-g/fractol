/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadal-g <anadal-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:34:22 by anadal-g          #+#    #+#             */
/*   Updated: 2024/10/15 18:56:07 by anadal-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

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
	if (keysym == 65307)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		exit(0);
	}
	else if (keysym == 97 || keysym == 65361)
		fractal->shftx += (0.5 * fractal->zmx);
	else if (keysym == 100 || keysym == 65363)
		fractal->shftx -= (0.5 * fractal->zmx);
	else if (keysym == 119 || keysym == 65362)
		fractal->shfty -= (0.5 * fractal->zmx);
	else if (keysym == 115 || keysym == 65364)
		fractal->shfty += (0.5 * fractal->zmx);
	else if (keysym == 51)
		fractal->iter += 10;
	else if (keysym == 50)
		fractal->iter -= 10;
	else if (keysym == 49)
		fractal->color += 1000;
	fractal_render(fractal);
	return (0);
}

int	mouse_hooks(int keysym, int x, int y, t_fractal *fractal)
{
	if (keysym == 5)
		zoom_out(fractal, x, y);
	else if (keysym == 4)
		zoom_in(fractal, x, y);
	fractal_render(fractal);
	return (0);
}

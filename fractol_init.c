/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadal-g <anadal-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:38:50 by anadal-g          #+#    #+#             */
/*   Updated: 2024/01/02 13:31:55 by anadal-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	malloc_error(void)
{
	perror("Problems with malloc");
	exit(EXIT_FAILURE);
}

static void	data_init(t_fractal *fractal)
{
	fractal->escape = 4;
	fractal->iter = 100;
	fractal->shftx = 0.0;
	fractal->shfty = 0.0;
	fractal->zmx = 1.0;
	fractal->zmy = 1.0;
	fractal->zoom_ship = 1.0;
	fractal->error = 0;
	fractal->color = WHITE;
}

void	events_init(t_fractal *fractal)
{
	mlx_key_hook(fractal->mlx_window, key_hooks, fractal);
	mlx_mouse_hook(fractal->mlx_window, mouse_hooks, fractal);
	mlx_loop(fractal->mlx_connection);
}

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init();
	if (fractal->mlx_connection == NULL)
		malloc_error();
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection,
			WIDTH, HEIGHT, fractal->name);
	if (fractal->mlx_window == NULL)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		malloc_error();
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection,
			WIDTH, HEIGHT);
	if (fractal->img.img_ptr == NULL)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		malloc_error();
	}
	fractal->img.pixels_ptr = mlx_get_data_addr(fractal->img.img_ptr,
			&fractal->img.bpp,
			&fractal->img.line_length,
			&fractal->img.endian);
	data_init(fractal);
}

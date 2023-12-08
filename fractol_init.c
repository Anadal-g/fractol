/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadal-g <anadal-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:38:50 by anadal-g          #+#    #+#             */
/*   Updated: 2023/12/07 16:27:11 by anadal-g         ###   ########.fr       */
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
	//Si la hipotenusa de los puntos es mayor a 2 ^ 2
	fractal->escape = 4;
	fractal->iteration = 100;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;

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
		// mlx_clear_window(fractal->mlx_connection, fractal->mlx_window);
		malloc_error();
		// free(fractal->mlx_connection);
	}

	fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection,
											WIDTH, HEIGHT);
	if (fractal->img.img_ptr == NULL)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		// mlx_clear_window(fractal->mlx_connection, fractal->mlx_window);
		malloc_error();
		// free(fractal->mlx_connection);
	}
	
	fractal->img.pixels_ptr = mlx_get_data_addr(fractal->img.img_ptr,
												&fractal->img.bpp,
												&fractal->img.line_length,
												&fractal->img.endian);
	
	data_init(fractal);
}

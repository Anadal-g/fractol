/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadal-g <anadal-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:34:22 by anadal-g          #+#    #+#             */
/*   Updated: 2023/12/07 16:46:43 by anadal-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_window(t_fractal *fractal)
{
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	exit(EXIT_SUCCESS);
}

int	 key_hooks(int keysym, t_fractal *fractal)
{
	//(void)fractal;
	printf("%d\n", keysym);
	if (keysym == 53)
	{
		
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		printf("uwu\n");
		exit(0);
	}
	else if	(keysym == 123)
		fractal->shift_x += (0.5 * fractal->zoom);
	else if	(keysym == 124)
		fractal->shift_x -= (0.5 * fractal->zoom);
	else if	(keysym == 126)
		fractal->shift_y -= (0.5 * fractal->zoom);
	else if	(keysym == 125)
		fractal->shift_y += (0.5 * fractal->zoom);
	else if	(keysym == 69)
		fractal->iteration += 10;
	else if	(keysym == 78)
		fractal->iteration -= 10;
	
	//recargamos la imagen despues del movimiento
	fractal_render(fractal);
	return (0);
}
int	mouse_hooks(int keysym, int x, int y,t_fractal *fractal)
{
	// (void)fractal;
	// printf("%d\n", keysym);
	x = x + 0;
	y = y + 0;
	if	(keysym == 5)
	{
		fractal->zoom *= 0.95;
	}
	else if (keysym == 4)
	{
		fractal->zoom *= 1.05;
	}
	fractal_render(fractal);
	return (0);
}

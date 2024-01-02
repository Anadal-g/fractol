/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadal-g <anadal-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:20:35 by anadal-g          #+#    #+#             */
/*   Updated: 2024/01/02 13:10:43 by anadal-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	put_pixel(int x, int y, t_img *img, int color)
{
	int	bytes_per_pixel;
	int	offset;

	if (img == NULL || img->pixels_ptr == NULL)
		return ;
	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	bytes_per_pixel = img->bpp / 8;
	if (bytes_per_pixel <= 0 || bytes_per_pixel > 4)
		return ;
	offset = (y * img->line_length) + (x * bytes_per_pixel);
	if (offset < 0 || offset >= img->line_length * HEIGHT)
		return ;
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

static void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.x = 0.0;
	z.y = 0.0;
	c.x = (map(x, -2, 2, WIDTH) * fractal->zoom_x) + fractal->shift_x;
	c.y = (map(y, 2, -2, HEIGHT) * fractal->zoom_x) + fractal->shift_y;
	while (i < fractal->iteration)
	{
		z = suma_num(calc_square(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape)
		{
			color = map(i, fractal->color, fractal->color * 10,
					fractal->iteration);
			put_pixel(x, y, &fractal->img, color);
			return ;
		}
		i++;
	}
	put_pixel(x, y, &fractal->img, BLACK);
}

static void	handle_pixel_julia(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.x = (map(x, -2, 2, WIDTH) * fractal->zoom_x) + fractal->shift_x;
	z.y = (map(y, 2, -2, HEIGHT) * fractal->zoom_x) + fractal->shift_y;
	julia(&z, &c, fractal);
	while (i < fractal->iteration)
	{
		z = suma_num(calc_square(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape)
		{
			color = map(i, fractal->color, fractal->color * 6, fractal->iteration);
			put_pixel(x, y, &fractal->img, color);
			return ;
		}
		i++;
	}
	put_pixel(x, y, &fractal->img, BLACK);
}

static void	handle_burning_ship(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			iter;
	int			color;

	iter = 0;
	z.x = 0.0;
	z.y = 0.0;
	c.x = ((((double)x / WIDTH) * 3.5 - 2.5) * fractal->zoom_x) + fractal->shift_x;
	c.y = ((((double)y / HEIGHT) * 2.0 - 1.0) * fractal->zoom_x) - fractal->shift_y;
	while (iter < fractal->iteration)
	{
		ship(&z, &c);
		iter++;
		if ((z.x * z.x) + (z.y * z.y) > 4)
		{
			color = map(iter, fractal->color, fractal->color - 5000,
					fractal->iteration);
			put_pixel(x, y, &fractal->img, color);
			return ;
		}
	}
	put_pixel(x, y, &fractal->img, BLACK);
}

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			if (!ft_strncmp(fractal->name, "mandelbrot", 10))
			{
				handle_pixel(x, y, fractal);
			}
			else if (!ft_strncmp(fractal->name, "julia", 5))
			{
				handle_pixel_julia(x, y, fractal);
			}
			else if (!ft_strncmp(fractal->name, "ship", 5))
			{
				handle_burning_ship(x, y, fractal);
			}
		}
	}
	mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window,
		fractal->img.img_ptr, 0, 0);
}

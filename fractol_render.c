/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadal-g <anadal-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:20:35 by anadal-g          #+#    #+#             */
/*   Updated: 2023/12/07 17:22:05 by anadal-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void put_pixel(int x, int y, t_img *img, int color) 
{
    if (img == NULL || img->pixels_ptr == NULL) {
        // Verifica si la estructura de imagen o el puntero de píxeles son nulos
        return;
    }

    if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0) {
        // Verifica si las coordenadas del píxel están dentro de los límites de la imagen
        return;
    }

    int bytes_per_pixel = img->bpp / 8;
    if (bytes_per_pixel <= 0 || bytes_per_pixel > 4) 
	{
        // Verifica que el tamaño de bytes por píxel sea válido (usualmente entre 1 y 4)
        return;
    }

    int offset = (y * img->line_length) + (x * bytes_per_pixel);
    if (offset < 0 || offset >= img->line_length * HEIGHT) {
        // Verifica si el offset calculado está dentro de los límites de la imagen
        return;
    }

    // Asigna el color al píxel en la posición dada
    *(unsigned int *)(img->pixels_ptr + offset) = color;
}

// static void	put_pixel(int x, int y, t_img *img, int color)
// {
// 	int	offset;

// 	if(x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
// 		return ;
// 	if (img == NULL || img->pixels_ptr == NULL)
// 		return ;
// 	offset = (y * img->line_length) + (x  * (img->bpp / 8));
// 	*(unsigned int *)(img->pixels_ptr + offset) = color;
// }

static void julia(t_complex *z, t_complex *c, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		c->x = fractal->julia_x;
		c->y = fractal->julia_y;
	}
	else 
	{
		c->x = z->x;
		c->y = z->y;
	}
}

static void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;
	
	i = 0;
	//Primera iteracion
	//  z.x = 0.0;
	//  z.y = 0.0;
	
	z.x = (map_escale(x, -2, 2, 0, WIDTH) * fractal->zoom) + fractal->shift_x;
	z.y = (map_escale(y, 2, -2, 0, HEIGHT)* fractal->zoom) + fractal->shift_y;
	julia(&z, &c, fractal);
	//Veces que vamos a iterar la funcion 
	while (i < fractal->iteration)
	{
		z = suma_num(calc_square(z), c);
		//Si el valor se escapa
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape)
		{
			color = map_escale(i, TURQUESA_BRILLANTE, MELOCOTON, 0, fractal->iteration);
			put_pixel(x, y, &fractal->img, color);
			return ;
		}
		i++;
	}
	put_pixel(x, y, &fractal->img, LILA);
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
			handle_pixel(x, y, fractal); 
		}
	}
	mlx_put_image_to_window(fractal->mlx_connection,
							fractal->mlx_window,
							fractal->img.img_ptr,
							0, 0);
}	

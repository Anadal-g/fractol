/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadal-g <anadal-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:04:12 by anadal-g          #+#    #+#             */
/*   Updated: 2023/11/30 11:41:18 by anadal-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <mlx.h>

#define ERROR_MESSAGE "Please enter \n\t\"./fractol mandelbrot\" or \n\t\"./fractol julia <value_1> <value_2>\"\n"


#define WIDTH	800
#define HEIGHT	800

/*
 Valores del numero complejo
*/
typedef struct s_complex
{ 
	//Real
	double	x;
	//Imaginario
	double	y;
}				t_complex;


/*
 * IMAGE
 * es un buffer de pixels
 * los valores son sacados de mlx_get_data_addr()
*/
typedef	struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_length;
}				t_img;


/*
 * FRACTAL ID
*/
typedef	struct s_fractal
{
	char	*name;
	//MLX
	void	*mlx_connection; //mlx_init()
	void	*mlx_window; 	 //mlx_new_window()
	//IMAGE
	t_img	img;
	//HOOKS MENBER VARIABLES
}				t_fractal;

//fractol_utils
int		ft_strncmp(char *s1, char *s2, int n);
void	putstr_fd(char *s, int fd);

//fractal_init
void	fractal_init(t_fractal *fractal);

//Escalado del mapa
double	map_escale(double unscaled_num, double new_min, double new_max, double old_min, double old_max);

//render
//static void	handle_pixel(int x, int y, t_fractal *fractal);

#endif
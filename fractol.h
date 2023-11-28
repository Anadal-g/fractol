/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadal-g <anadal-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:04:12 by anadal-g          #+#    #+#             */
/*   Updated: 2023/11/28 12:15:41 by anadal-g         ###   ########.fr       */
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
#define EIGHT	800


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
//static void	malloc_error(void);
void	fractal_init(t_fractal *fractal);


#endif
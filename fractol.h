/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadal-g <anadal-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:04:12 by anadal-g          #+#    #+#             */
/*   Updated: 2023/12/07 17:21:44 by anadal-g         ###   ########.fr       */
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


#define WIDTH	500
#define HEIGHT	500

/*
 *COLORES
*/
#define WHITE 0xFFFFFF // Valor RGB: R=255, G=255, B=255
#define BLACK 0x000000 // Valor RGB: R=0, G=0, B=0
#define ROJO 0xFF0000 // Valor RGB: R=255, G=0, B=0
#define VERDE 0x00FF00 // Valor RGB: R=0, G=255, B=0
#define AZUL 0x0000FF // Valor RGB: R=0, G=0, B=255
#define AMARILLO 0xFFFF00 // Valor RGB: R=255, G=255, B=0
#define MAGENTA 0xFF00FF // Valor RGB: R=255, G=0, B=255
#define CIAN 0x00FFFF // Valor RGB: R=0, G=255, B=255
#define VIOLETA 0x8A2BE2 // Valor RGB: R=138, G=43, B=226
#define TURQUESA 0x40E0D0 // Valor RGB: R=64, G=224, B=208
#define CORAL 0xFF7F50 // Valor RGB: R=255, G=127, B=80
#define ESMERALDA 0x2ECC71 // Valor RGB: R=46, G=204, B=113
#define ZAFIRO 0x082567 // Valor RGB: R=8, G=37, B=103
#define INDIGO 0x4B0082 // Valor RGB: R=75, G=0, B=130
#define AGUAMARINA 0x7FFFD4 // Valor RGB: R=127, G=255, B=212
#define MELOCOTON 0xFFE5B4 // Valor RGB: R=255, G=229, B=180
#define RUBI 0xE0115F // Valor RGB: R=224, G=17, B=95
#define TOPACIO 0x1E90FF // Valor RGB: R=30, G=144, B=255
#define ROSA_PALIDO 0xFFB6C1 // Valor RGB: R=255, G=182, B=193
#define FUCSIA 0xFF00FF // Valor RGB: R=255, G=0, B=255
#define CHARTREUSE 0x7FFF00 // Valor RGB: R=127, G=255, B=0
#define TURQUESA_BRILLANTE 0x00F5FF // Valor RGB: R=0, G=245, B=255
#define AMARANTO 0xE52B50 // Valor RGB: R=229, G=43, B=80
#define LILA 0xB666D2 // Valor RGB: R=182, G=102, B=210
#define AMARILLO_NEON 0xDFFF00 // Valor RGB: R=223, G=255, B=0


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
	double	escape;
	int		iteration;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;

}				t_fractal;

//fractol_utils
int		ft_strncmp(char *s1, char *s2, int n);
void	putstr_fd(char *s, int fd);
double	atodbl(char *s);

//fractal_init
void	fractal_init(t_fractal *fractal);

//Escalado del mapa
double		map_escale(double unscaled_num, double new_min, double new_max, double old_min, double old_max);
t_complex	suma_num(t_complex z1, t_complex z2);
t_complex	calc_square(t_complex z);
//render
void	fractal_render(t_fractal *fractal);
// static void julia(t_complex *z, t_complex *c, t_fractal *fractal);

// static void	put_pixel(int x, int y, t_img *img, int color);

//HOOKS
int	 key_hooks(int keysym, t_fractal *fractal);
int	mouse_hooks(int keysym, int x, int y,t_fractal *fractal);
int	close_window(t_fractal *fractal);
void	events_init(t_fractal *fractal);

#endif
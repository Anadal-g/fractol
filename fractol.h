/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadal-g <anadal-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:04:12 by anadal-g          #+#    #+#             */
/*   Updated: 2024/01/02 13:05:14 by anadal-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <mlx.h>

# define ERROR_MESSAGE "Please enter \n\t\"./fractol mandelbrot\" or \n\t\""
# define ERROR_MESSAGE1 "./fractol julia <val1> <val2>\"\n\t"
# define ERROR_MESSAGE12 "./u can try with this values\"\n\t"
# define ERROR_MESSAGE13 "./(0.28 , 0),(-0.7, -0.3), (-0.8, 0.156) \"\n\t"
# define ERROR_MESSAGE14 "./(0.4 , 0.4),(-0.835, -0.2321), (0.35, 0.35) \"\n\t"
# define ERROR_MESSAGE2 "./fractol ship\"\n"
# define WIDTH	500
# define HEIGHT	500

# define WHITE 0xFFFFFF
# define BLACK 0x000000
# define ROJO 0xFF0000
# define VERDE 0x00FF00
# define AZUL 0x0000FF
# define AMARILLO 0xFFFF00
# define MAGENTA 0xFF00FF
# define CIAN 0x00FFFF
# define VIOLETA 0x8A2BE2
# define TURQUESA 0x40E0D0
# define CORAL 0xFF7F50
# define ESMERALDA 0x2ECC71
# define ZAFIRO 0x082567
# define LOLA_INDIGO 0x4B0082
# define AGUAMARINA 0x7FFFD4
# define MELOCOTON 0xFFE5B4
# define RUBI 0xE0115F
# define TOPACIO 0x1E90FF
# define ROSA_PALIDO 0xFFB6C1
# define FUCSIA 0xFF00FF
# define CHARTREUSE 0x7FFF00
# define TURQUESA_BRILLANTE 0x00F5FF
# define AMARANTO 0xE52B50
# define LILA 0xB666D2
# define AMARILLO_NEON 0xDFFF00

/*
 Valores del numero complejo
*/
typedef struct s_complex
{
	double	x;
	double	y;
}				t_complex;

/*
 * IMAGE
*/
typedef struct s_img
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
typedef struct s_fractal
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;
	double	escape;
	int		color;
	int		iteration;
	int		error;
	double	shift_x;
	double	shift_y;
	double	zoom_x;
	double	zoom_y;
	double	julia_x;
	double	julia_y;
	double	zoom_ship;

}				t_fractal;

int			ft_strncmp(char *s1, char *s2, int n);
void		putstr_fd(char *s, int fd);
double		ft_atodbl(char *str, t_fractal *fractal);
void		fractal_init(t_fractal *fractal);
double		map(double unscaled_num, double new_min, double new_max, double old_max);
t_complex	suma_num(t_complex z1, t_complex z2);
t_complex	calc_square(t_complex z);
void		fractal_render(t_fractal *fractal);
int			key_hooks(int keysym, t_fractal *fractal);
int			mouse_hooks(int keysym, int x, int y, t_fractal *fractal);
int			close_window(t_fractal *fractal);
void		events_init(t_fractal *fractal);
void		julia(t_complex *z, t_complex *c, t_fractal *fractal);
void		ship(t_complex *z, t_complex *c);
int			ft_isdigit(int c);
#endif
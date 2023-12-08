/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_escale.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadal-g <anadal-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:04:15 by anadal-g          #+#    #+#             */
/*   Updated: 2023/12/07 16:57:39 by anadal-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "fractol.h"
/*
 *El old_min es 0, asi que podemos quitarlo para reducir una variable.
*/
 double	map_escale(double unscaled_num, double new_min, double new_max, 
 					double old_min, double old_max)
 {
	return (new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min) + new_min;
 }
 
 /*
 *Suma de vectores
 */
t_complex	suma_num(t_complex z1, t_complex z2)
{
	t_complex	result;
	
	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return (result);
}

/*
 *Calcular cuadrado
  * z = z^2 + c
 *X = (x^2 - y^2)
 *Y = 2 * x * y
*/
t_complex	calc_square(t_complex z)
{
	t_complex	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}


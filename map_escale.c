/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_escale.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadal-g <anadal-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:04:15 by anadal-g          #+#    #+#             */
/*   Updated: 2023/11/29 12:27:31 by anadal-g         ###   ########.fr       */
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
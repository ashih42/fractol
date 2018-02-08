/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricell.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 04:06:56 by ashih             #+#    #+#             */
/*   Updated: 2018/02/08 02:12:09 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	compute_tricell(int x, int y, t_fractal *f)
{
	t_cnum	c;
	t_cnum	z;
	int		i;

	c.real = CHANGE((double)x, 0.0, (double)WIN_WIDTH,
		f->x_min * f->zoom, f->x_max * f->zoom);
	c.imag = CHANGE((double)y, 0.0, (double)WIN_HEIGHT,
		f->y_min * f->zoom, f->y_max * f->zoom);
	c_invert(&c, &c);
	ft_memcpy(&z, &(f->mandel_z), sizeof(t_cnum));
	i = 0;
	while ((z.real * z.real + z.imag * z.imag) < 4.0 && i < f->max_iter)
	{
		c_square(&z);
		c_add(&z, &c);
		c_invert(&z, &z);
		i++;
	}
	store_diter(&(f->diter[x][y]), i, &z, f);
	draw_fractal(x, y, f);
}

void	compute_tricell_julia(int x, int y, t_fractal *f)
{
	t_cnum	z;
	t_cnum	invert_c;
	int		i;

	z.real = CHANGE((double)x, 0.0, (double)WIN_WIDTH,
		f->x_min * f->zoom, f->x_max * f->zoom);
	z.imag = CHANGE((double)y, 0.0, (double)WIN_HEIGHT,
		f->y_min * f->zoom, f->y_max * f->zoom);
	c_invert(&(f->julia_c), &invert_c);
	i = 0;
	while ((z.real * z.real + z.imag * z.imag) < 4.0 && i < f->max_iter)
	{
		c_square(&z);
		c_add(&z, &invert_c);
		c_invert(&z, &z);
		i++;
	}
	store_diter(&(f->diter[x][y]), i, &z, f);
	draw_fractal(x, y, f);
}

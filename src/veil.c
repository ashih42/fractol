/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   veil.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 07:05:52 by ashih             #+#    #+#             */
/*   Updated: 2018/02/08 07:06:10 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	compute_veil(int x, int y, t_fractal *f)
{
	t_cnum	c;
	t_cnum	z;
	int		i;

	c.real = CHANGE((double)x, 0.0, (double)WIN_WIDTH,
		f->x_min * f->zoom, f->x_max * f->zoom);
	c.imag = CHANGE((double)y, 0.0, (double)WIN_HEIGHT,
		f->y_min * f->zoom, f->y_max * f->zoom);
	ft_memcpy(&z, &(f->mandel_z), sizeof(t_cnum));
	i = 0;
	while ((z.real * z.real + z.imag * z.imag) < 4.0 && i < f->max_iter)
	{
		if (z.real * z.real + z.imag * z.imag < 0.5)
			c_square(&z);
		else
		{
			c_square(&z);
			c_square(&z);
		}
		c_add(&z, &c);
		i++;
	}
	store_diter(&(f->diter[x][y]), i, &z, f);
	draw_fractal(x, y, f);
}

void	compute_veil_julia(int x, int y, t_fractal *f)
{
	t_cnum	z;
	int		i;

	z.real = CHANGE((double)x, 0.0, (double)WIN_WIDTH,
		f->x_min * f->zoom, f->x_max * f->zoom);
	z.imag = CHANGE((double)y, 0.0, (double)WIN_HEIGHT,
		f->y_min * f->zoom, f->y_max * f->zoom);
	i = 0;
	while ((z.real * z.real + z.imag * z.imag) < 4.0 && i < f->max_iter)
	{
		if (z.real * z.real + z.imag * z.imag < 0.5)
			c_square(&z);
		else
		{
			c_square(&z);
			c_square(&z);
		}
		c_add(&z, &(f->julia_c));
		i++;
	}
	store_diter(&(f->diter[x][y]), i, &z, f);
	draw_fractal(x, y, f);
}

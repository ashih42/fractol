/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 20:28:53 by ashih             #+#    #+#             */
/*   Updated: 2018/02/05 20:31:36 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		zoom_in(int x, int y, t_fractal *f)
{
	double	point_x;
	double	point_y;
	double	dx;
	double	dy;

	point_x = CHANGE((double)x, 0.0, (double)WIN_WIDTH,
		f->x_min * f->zoom, f->x_max * f->zoom);
	point_y = CHANGE((double)y, 0.0, (double)WIN_HEIGHT,
		f->y_min * f->zoom, f->y_max * f->zoom);
	dx = (double)point_x / (f->zoom / ZOOM_INC) - (double)point_x / f->zoom;
	dy = (double)point_y / (f->zoom / ZOOM_INC) - (double)point_y / f->zoom;
	f->x_min += dx;
	f->x_max += dx;
	f->y_min += dy;
	f->y_max += dy;
	f->zoom /= ZOOM_INC;
}

void		zoom_out(int x, int y, t_fractal *f)
{
	double	point_x;
	double	point_y;
	double	dx;
	double	dy;

	point_x = CHANGE((double)x, 0.0, (double)WIN_WIDTH,
		f->x_min * f->zoom, f->x_max * f->zoom);
	point_y = CHANGE((double)y, 0.0, (double)WIN_HEIGHT,
		f->y_min * f->zoom, f->y_max * f->zoom);
	dx = (double)point_x / (f->zoom * ZOOM_INC) - (double)point_x / f->zoom;
	dy = (double)point_y / (f->zoom * ZOOM_INC) - (double)point_y / f->zoom;
	f->x_min += dx;
	f->x_max += dx;
	f->y_min += dy;
	f->y_max += dy;
	f->zoom *= ZOOM_INC;
}

void		set_julia_c(int x, int y, t_fractal *f)
{
	f->julia_c.real = CHANGE((double)x, 0.0, (double)WIN_WIDTH,
		f->x_min * f->zoom, f->x_max * f->zoom);
	f->julia_c.imag = CHANGE((double)y, 0.0, (double)WIN_HEIGHT,
		f->y_min * f->zoom, f->y_max * f->zoom);
	render(f);
}

void		set_mandel_z(int x, int y, t_fractal *f)
{
	f->mandel_z.real = CHANGE((double)x, 0.0, (double)WIN_WIDTH,
		f->x_min * f->zoom, f->x_max * f->zoom);
	f->mandel_z.imag = CHANGE((double)y, 0.0, (double)WIN_HEIGHT,
		f->y_min * f->zoom, f->y_max * f->zoom);
	render(f);
}

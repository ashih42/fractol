/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 21:16:22 by ashih             #+#    #+#             */
/*   Updated: 2018/02/05 21:16:45 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			move_screen_left(t_fractal *f)
{
	double		dx;

	dx = (f->x_max - f->x_min) / WIN_WIDTH * 10.0;
	f->x_min -= dx;
	f->x_max -= dx;
}

void			move_screen_right(t_fractal *f)
{
	double		dx;

	dx = (f->x_max - f->x_min) / WIN_WIDTH * 10.0;
	f->x_min += dx;
	f->x_max += dx;
}

void			move_screen_down(t_fractal *f)
{
	double		dy;

	dy = (f->y_max - f->y_min) / WIN_HEIGHT * 10.0;
	f->y_min += dy;
	f->y_max += dy;
}

void			move_screen_up(t_fractal *f)
{
	double		dy;

	dy = (f->y_max - f->y_min) / WIN_HEIGHT * 10.0;
	f->y_min -= dy;
	f->y_max -= dy;
}

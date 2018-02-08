/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 19:41:08 by ashih             #+#    #+#             */
/*   Updated: 2018/02/05 20:31:07 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Keycode		Key					Function
** 1			LMB					Drag to move the screen
** 4			SCROLL UP			Zoom in
** 5			SCROLL DOWN			Zoom out
*/

int			mouse_button_down(int button, int x, int y, t_fractal *f)
{
	if (button == LMB)
		f->mouse.lmb_down = 1;
	else if (button == SCROLL_UP)
		zoom_in(x, y, f);
	else if (button == SCROLL_DOWN)
		zoom_out(x, y, f);
	render(f);
	return (0);
}

int			mouse_button_up(int button, int x, int y, t_fractal *f)
{
	if (button == LMB)
		f->mouse.lmb_down = 0;
	(void)x;
	(void)y;
	return (0);
}

int			mouse_move(int x, int y, t_fractal *f)
{
	double	shift_x;
	double	shift_y;

	if (f->shift_down)
		set_julia_c(x, y, f);
	if (f->ctrl_down)
		set_mandel_z(x, y, f);
	if (f->mouse.lmb_down < 2)
	{
		f->mouse.x = x;
		f->mouse.y = y;
		return (f->mouse.lmb_down *= 2);
	}
	shift_x = CHANGE(fabs((double)(x - f->mouse.x)), 0.0, (double)WIN_WIDTH,
		0.0, f->x_max - f->x_min);
	shift_y = CHANGE(fabs((double)(y - f->mouse.y)), 0.0, (double)WIN_HEIGHT,
		0.0, f->y_max - f->y_min);
	f->x_min += (x - f->mouse.x < 0) ? shift_x : shift_x * -1.0;
	f->x_max += (x - f->mouse.x < 0) ? shift_x : shift_x * -1.0;
	f->y_min += (y - f->mouse.y < 0) ? shift_y : shift_y * -1.0;
	f->y_max += (y - f->mouse.y < 0) ? shift_y : shift_y * -1.0;
	f->mouse.x = x;
	f->mouse.y = y;
	render(f);
	return (0);
}

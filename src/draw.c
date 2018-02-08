/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 22:51:50 by ashih             #+#    #+#             */
/*   Updated: 2018/02/08 02:05:44 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_dot(int x, int y, int color, t_fractal *f)
{
	if (0 <= x && x < WIN_WIDTH && 0 <= y && y < WIN_HEIGHT)
	{
		f->frame[x + y * WIN_WIDTH] = color;
	}
}

void	draw_fractal(int x, int y, t_fractal *f)
{
	draw_dot(x, y, get_color(f->diter[x][y], f), f);
}

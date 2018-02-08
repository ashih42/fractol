/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 01:50:17 by ashih             #+#    #+#             */
/*   Updated: 2018/02/08 02:02:20 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				interp_color(int color1, int color2, double k)
{
	int			r;
	int			g;
	int			b;

	r = ft_round_dbl((1.0 - k) * (double)(color1 >> 16 & 0xFF) +
		k * (double)(color2 >> 16 & 0xFF));
	g = ft_round_dbl((1.0 - k) * (double)(color1 >> 8 & 0xFF) +
		k * (double)(color2 >> 8 & 0xFF));
	b = ft_round_dbl((1.0 - k) * (double)(color1 >> 0 & 0xFF) +
		k * (double)(color2 >> 0 & 0xFF));
	return ((r << 16) | (g << 8) | (b << 0));
}

int				get_color_from_scheme(double r, t_fractal *f)
{
	double		width;
	int			color2;
	t_scheme	*schemes;

	schemes = ((t_master *)(f->m))->scheme_table;
	width = 1.0 / (schemes[f->scheme_id].num_colors - 1);
	color2 = 0;
	while (color2 * width < r)
		color2++;
	return (interp_color(
		schemes[f->scheme_id].color[color2 - 1],
		schemes[f->scheme_id].color[color2],
		CHANGE((double)r, width * (color2 - 1), width * color2, 0.0, 1.0)));
}

/*
** int get_color_by_mode(int iter, t_fractal *f);
**
** map_func == 0	// linear mapping
** map_func == 1	// square root mapping
** map_func == 2	// logarithmic mapping
*/

int				get_color_by_mode(int iter, t_fractal *f)
{
	double		r;

	if (f->map_func == 0)
		r = ((double)iter / f->max_iter) + f->color_shift;
	else if (f->map_func == 1)
		r = (sqrt((double)iter) / sqrt(f->max_iter)) + f->color_shift;
	else
		r = (log((double)iter) / log(f->max_iter)) + f->color_shift;
	if (r > 1.0)
		r -= 1.0;
	return (get_color_from_scheme(r, f));
}

int				get_color(double diter, t_fractal *f)
{
	int			color1;
	int			color2;

	color1 = get_color_by_mode((int)diter, f);
	if (f->smooth_mode == 0)
		return (color1);
	color2 = get_color_by_mode(((int)diter + 1) % f->max_iter, f);
	return (interp_color(color1, color2, diter - (double)(int)diter));
}

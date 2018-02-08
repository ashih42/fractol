/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 19:35:41 by ashih             #+#    #+#             */
/*   Updated: 2018/02/08 08:11:36 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	terminate(t_fractal *f)
{
	free_all(f->m);
	exit(0);
}

void	reset_view(t_fractal *f)
{
	f->x_min = -2.5;
	f->x_max = 2.5;
	f->y_min = -2.5;
	f->y_max = 2.5;
	f->zoom = 1.0;
	f->scheme_id = 0;
	f->psych_mode = 0;
	f->color_shift = 0.0;
	f->map_func = 0;
	f->smooth_mode = 0;
	f->max_iter = MAX_ITER;
	ft_bzero(&(f->mandel_z), sizeof(t_cnum));
}

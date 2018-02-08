/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 23:22:04 by ashih             #+#    #+#             */
/*   Updated: 2018/02/05 21:21:54 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		print_cnum(t_cnum *n)
{
	ft_printf("Real = %.3f, Imag = %.3f\n", n->real, n->imag);
}

void		print_diagnostics(t_fractal *f)
{
	ft_printf("zoom = %.3f, x_min = %.3f, xmax = %.3f, y_min = %.3f,"\
		"y_max = %.3f\n", f->zoom, f->x_min, f->x_max, f->y_min, f->y_max);
}

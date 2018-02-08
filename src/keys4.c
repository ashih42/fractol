/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 21:15:15 by ashih             #+#    #+#             */
/*   Updated: 2018/02/05 21:20:04 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	inc_max_iter(t_fractal *f)
{
	f->max_iter += MAX_ITER_INC;
	ft_printf("[%s] Max Iterations = %d\n", f->name, f->max_iter - 1);
}

void	dec_max_iter(t_fractal *f)
{
	f->max_iter -= MAX_ITER_INC;
	if (f->max_iter <= 2)
		f->max_iter = 2;
	ft_printf("[%s] Max Iterations = %d\n", f->name, f->max_iter - 1);
}

void	set_shift_down(t_fractal *f)
{
	f->shift_down = 1;
}

void	set_ctrl_down(t_fractal *f)
{
	f->ctrl_down = 1;
}

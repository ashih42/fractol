/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 21:14:30 by ashih             #+#    #+#             */
/*   Updated: 2018/02/08 02:02:33 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			select_next_scheme(t_fractal *f)
{
	t_scheme	*schemes;

	schemes = ((t_master *)(f->m))->scheme_table;
	f->scheme_id = (f->scheme_id + 1) % MAX_SCHEMES;
	ft_printf("[%s] Color Scheme: %s\n", f->name, schemes[f->scheme_id].name);
}

void			toggle_psych_mode(t_fractal *f)
{
	f->psych_mode = !(f->psych_mode);
	ft_printf("[%s] Psychedelica: %s\n", f->name,
		(f->psych_mode) ? "ON" : "OFF");
}

void			select_next_map_func(t_fractal *f)
{
	f->map_func = (f->map_func + 1) % 3;
	ft_printf("[%s] Color Mapping Function: ", f->name);
	if (f->map_func == 0)
		ft_printf("%s\n", "Linear");
	else if (f->map_func == 1)
		ft_printf("%s\n", "Square Root");
	else
		ft_printf("%s\n", "Logarithmic");
}

void			toggle_smooth_mode(t_fractal *f)
{
	f->smooth_mode = !(f->smooth_mode);
	ft_printf("[%s] Smooth Coloring: %s\n", f->name,
		(f->smooth_mode) ? "ON" : "OFF");
}

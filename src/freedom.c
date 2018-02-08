/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freedom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 02:10:40 by ashih             #+#    #+#             */
/*   Updated: 2018/02/05 20:48:20 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		free_all(t_master *m)
{
	ft_lstdel(&(m->fractal_list), (void (*)(void *, size_t))del_fractal);
	if (m->mlx)
	{
		ft_memdel((void **)&(m->mlx->font[1]));
		ft_memdel((void **)&(m->mlx->font));
		ft_memdel((void **)&(m->mlx));
	}
}

void		del_fractal(t_fractal *f)
{
	t_master	*m;

	m = f->m;
	if (f->win)
		mlx_destroy_window(m->mlx, f->win);
	if (f->img)
		mlx_destroy_image(m->mlx, f->img);
	ft_strdel(&(f->name));
}

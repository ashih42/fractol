/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 19:35:41 by ashih             #+#    #+#             */
/*   Updated: 2018/02/07 00:22:19 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Keycode		Key					Function
** 53			ESC					Terminate program
** 49			SPACE				Reset to default view
** 48			TAB					Select next color scheme
** 12			Q					Toggle psychedelica on/off
** 13			W					Select next color mapping function
** 14			E					Toggle smooth color mode on/off
** 24			PLUS				Increase MAX_ITER
** 27			MINUS				Decrease MAX_ITER
** 257			SHIFT				Hold to set c for Julia types
** 256			CONTROL				Hold to set z for Mandelbrot types
** 123			LEFT ARROW			Move screen to the left
** 124			RIGHT ARROW			Move screen to the right
** 125			DOWN ARROW			Move screen down
** 126			UP ARROW			Move screen up
*/

int				key_press_hook(int keycode, t_fractal *f)
{
	t_keyfunc	*key_table;
	int			i;

	key_table = ((t_master *)(f->m))->key_table;
	i = -1;
	while (++i < KEYS_ASSIGNED)
	{
		if (keycode == key_table[i].keycode)
		{
			key_table[i].func(f);
			break ;
		}
	}
	render(f);
	return (0);
}

int				key_release_hook(int keycode, t_fractal *f)
{
	if (keycode == SHIFT_KEY)
		f->shift_down = 0;
	if (keycode == CTRL_KEY)
		f->ctrl_down = 0;
	return (0);
}

int				loop_hook(t_list *fractal_list)
{
	t_fractal	*f;

	while (fractal_list != 0)
	{
		f = fractal_list->content;
		if (f->psych_mode)
		{
			f->color_shift += COLOR_INC;
			if (f->color_shift > 1.0)
				f->color_shift -= 1.0;
			render(f);
		}
		fractal_list = fractal_list->next;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 19:24:15 by ashih             #+#    #+#             */
/*   Updated: 2018/02/08 08:04:25 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				init_mlx_stuff(t_fractal *f, t_master *m)
{
	if (!(f->win = mlx_new_window(m->mlx, WIN_WIDTH, WIN_HEIGHT, f->name)) ||
		!(f->img = mlx_new_image(m->mlx, WIN_WIDTH, WIN_HEIGHT)) ||
		!(f->frame = (int *)mlx_get_data_addr(f->img, &(f->bpp),
			&(f->size_line), &(f->endian))))
		return (ft_puterror(ERROR_MEMORY, 0, 1));
	f->bpp /= 8;
	f->m = m;
	reset_view(f);
	render(f);
	mlx_hook(f->win, 2, 0, key_press_hook, f);
	mlx_hook(f->win, 3, 0, key_release_hook, f);
	mlx_hook(f->win, 4, 0, mouse_button_down, f);
	mlx_hook(f->win, 5, 0, mouse_button_up, f);
	mlx_hook(f->win, 6, 0, mouse_move, f);
	mlx_hook(f->win, 17, 0, (int (*)())terminate, f);
	return (0);
}

int				init_all_fractals(t_master *m)
{
	t_list		*list;

	list = m->fractal_list;
	if (ft_lst_size(list) == 0)
		exit(0);
	if (!(m->mlx = mlx_init()))
		return (ft_puterror(ERROR_MEMORY, 0, 1));
	while (list != 0)
	{
		if (init_mlx_stuff(list->content, m))
			return (1);
		list = list->next;
	}
	return (0);
}

int				main(int argc, char **argv)
{
	t_master	m;

	ft_bzero(&m, sizeof(t_master));
	FT00;
	ST00;
	KT00;
	if (argc == 1)
		return (print_usage(&m));
	if (parse_terms(argc, argv, &m))
		return (0);
	if (init_all_fractals(&m))
		return (0);
	mlx_loop_hook(m.mlx, loop_hook, m.fractal_list);
	mlx_loop(m.mlx);
	return (0);
}

int				print_usage(t_master *m)
{
	int			i;

	ft_printf("{bold}usage: fractol [-n]{reset}\n");
	i = -1;
	while (++i < FRACTAL_TYPES)
		ft_printf("  n = %2d\t\t%s\n", i + 1, m->fractal_table[i].name + 2);
	ft_printf("\n{bold}Controls{reset}\n"\
		"[Mouse Scroll Wheel]\tZoom in/out\n"\
		"[Left Mouse Button]\tDrag to move the screen position\n"\
		"[Arrow Keys]\t\tMove the screen position\n"\
		"[Spacebar]\t\tReset view\n"\
		"[Shift]\t\t\tHold/release to set C (for Julia types)\n"\
		"[Control]\t\tHold/release to set Z (for Mandelbrot types)\n"\
		"[Tab]\t\t\tSelect next color scheme\n"
		"[Q]\t\t\tToggle psychedelica on/off\n"\
		"[W]\t\t\tSelect next color mapping function\n"\
		"[E]\t\t\tToggle smooth coloring on/off\n"\
		"[+]\t\t\tIncrease max iterations\n"\
		"[-]\t\t\tDecrease max iterations\n");
	return (0);
}

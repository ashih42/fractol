/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 19:51:23 by ashih             #+#    #+#             */
/*   Updated: 2018/02/08 08:06:54 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				parse_terms(int argc, char **argv, t_master *m)
{
	int			id;
	int			i;

	id = 1;
	i = 0;
	while (++i < argc)
	{
		if (add_fractal(&id, argv[i], m))
			return (1);
	}
	return (0);
}

int				add_fractal(int *id, char *term, t_master *m)
{
	t_fractal	*f;
	int			i;
	char		*temp;

	i = -1;
	while (++i < FRACTAL_TYPES)
	{
		if (ft_strequ(m->fractal_table[i].term, term))
		{
			if (!(f = ft_memalloc(sizeof(t_fractal))))
				return (ft_puterror(ERROR_MEMORY, 0, 1));
			f->id = (*id)++;
			temp = ft_itoa(f->id);
			f->name = ft_strjoin(temp, m->fractal_table[i].name);
			ft_strdel(&temp);
			f->compute = m->fractal_table[i].compute;
			ft_lstadd(&(m->fractal_list), ft_lst_new_ref(f, sizeof(t_fractal)));
			ft_printf("Launching {bold}%s{reset}\n", f->name);
			return (0);
		}
	}
	return (ft_puterror(ERROR_PARSING, term, 0));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 02:04:12 by ashih             #+#    #+#             */
/*   Updated: 2018/02/08 00:55:53 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				render(t_fractal *f)
{
	static void		*(*compute[THREAD_MAX])(void *) = {th0_compute,
		th1_compute, th2_compute, th3_compute};
	pthread_t		threads[4];
	mach_port_t		ports[4];
	int				affinity[4];
	int				i;

	ft_bzero(f->frame, WIN_WIDTH * WIN_HEIGHT * f->bpp);
	i = -1;
	while (++i < 4)
	{
		pthread_create_suspended_np(threads + i, 0, compute[i], f);
		ports[i] = pthread_mach_thread_np(threads[i]);
		affinity[i] = i;
		thread_policy_set(ports[i], THREAD_AFFINITY_POLICY, &affinity[i], 1);
		thread_resume(ports[i]);
	}
	i = -1;
	while (++i < 4)
		pthread_join(threads[i], 0);
	mlx_put_image_to_window(((t_master *)(f->m))->mlx,
		f->win, f->img, 0, 0);
}

/*
** void				render(t_fractal *f)
** {
** 	static void		*(*compute[THREAD_MAX])(void *) = {th0_compute,
** 		th1_compute, th2_compute, th3_compute};
** 	pthread_t		thread[THREAD_MAX];
** 	int				i;
**
** 	ft_bzero(f->frame, WIN_WIDTH * WIN_HEIGHT * f->bpp);
** 	i = -1;
** 	while (++i < THREAD_MAX - 1)
** 		pthread_create(thread + i, 0, compute[i], f);
** 	compute[THREAD_MAX - 1](f);
** 	i = -1;
** 	while (++i < THREAD_MAX - 1)
** 		pthread_join(thread[i], 0);
** 	mlx_put_image_to_window(((t_master *)(f->m))->mlx,
** 		f->win, f->img, 0, 0);
** }
*/

void				*th0_compute(void *f)
{
	int				i;

	i = 0;
	while (i < WIN_WIDTH * WIN_HEIGHT)
	{
		((t_fractal *)f)->compute(i % WIN_WIDTH, i / WIN_WIDTH, f);
		i += 4;
	}
	return (0);
}

void				*th1_compute(void *f)
{
	int				i;

	i = 1;
	while (i < WIN_WIDTH * WIN_HEIGHT)
	{
		((t_fractal *)f)->compute(i % WIN_WIDTH, i / WIN_WIDTH, f);
		i += 4;
	}
	return (0);
}

void				*th2_compute(void *f)
{
	int				i;

	i = 2;
	while (i < WIN_WIDTH * WIN_HEIGHT)
	{
		((t_fractal *)f)->compute(i % WIN_WIDTH, i / WIN_WIDTH, f);
		i += 4;
	}
	return (0);
}

void				*th3_compute(void *f)
{
	int				i;

	i = 3;
	while (i < WIN_WIDTH * WIN_HEIGHT)
	{
		((t_fractal *)f)->compute(i % WIN_WIDTH, i / WIN_WIDTH, f);
		i += 4;
	}
	return (0);
}

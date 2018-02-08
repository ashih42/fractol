/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_ops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 17:34:34 by ashih             #+#    #+#             */
/*   Updated: 2018/02/08 07:39:58 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** void		c_sin(t_cnum *n, t_cnum *result)
** {
** 	t_cnum	temp;
**
** 	temp.real = sin(n->real) * cosh(n->imag);
** 	temp.imag = cosh(n->real) * sin(n->imag);
** 	ft_memcpy(result, &temp, sizeof(t_cnum));
** }
**
** void		c_mult(t_cnum *n1, t_cnum *n2, t_cnum *result)
** {
** 	// wow slow
** 	t_cnum	temp;
**
** 	temp.real = n1->real * n2->real - n1->imag * n2->imag;
** 	temp.imag = n1->real * n2->imag + n1->imag * n2->real;
** 	ft_memcpy(result, &temp, sizeof(t_cnum));
** }
**
** void		c_swap(t_cnum *n)
** {
** 	double	temp;
**
** 	temp = n->real;
** 	n->real = n->imag;
** 	n->imag = temp;
** }
**
** double		c_magnitude(t_cnum *n)
** {
** 	// unused
** 	return (sqrt(n->real * n->real + n->imag * n->imag));
** }
*/

/*
** void c_square(t_num *n);
**
** Multiply n x n x n, and store the result in n.
*/

void		c_cube(t_cnum *n)
{
	t_cnum	temp;
	double	real_sq;
	double	imag_sq;

	real_sq = n->real * n->real;
	imag_sq = n->imag * n->imag;
	temp.real = real_sq * n->real - 3.0 * n->real * imag_sq;
	temp.imag = 3.0 * real_sq * n->imag - imag_sq * n->imag;
	ft_memcpy(n, &temp, sizeof(t_cnum));
}

/*
** void c_square(t_num *n);
**
** Multiply n x n, and store the result in n.
*/

void		c_square(t_cnum *n)
{
	double	temp;

	temp = (n->real * n->real) - (n->imag * n->imag);
	n->imag = 2.0 * n->real * n->imag;
	n->real = temp;
}

/*
** void c_add(t_num *n1, t_num *n2);
**
** Add n1 + n2, and store the result in n1.
*/

void		c_add(t_cnum *n1, t_cnum *n2)
{
	n1->real = n1->real + n2->real;
	n1->imag = n1->imag + n2->imag;
}

/*
** void c_invert(t_num *n)
**
** Find the multiplicative inverse of n, and store in result.
** e.g. Inverse of (a, bi) is (a/(a^2 + b2^), -bi/(a^2 + b^2))
*/

void		c_invert(t_cnum *n, t_cnum *result)
{
	double	a;
	double	b;
	double	denum;

	if (n->real == 0.0 && n->imag == 0.0)
		return ;
	a = n->real;
	b = n->imag;
	denum = a * a + b * b;
	result->real = a / denum;
	result->imag = -1.0 * b / denum;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 19:22:29 by ashih             #+#    #+#             */
/*   Updated: 2018/02/08 08:06:52 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <pthread.h>
# include <mach/thread_act.h>

# define ERROR_MEMORY	"Out of memory"
# define ERROR_PARSING	"Invalid term"

# define THREAD_MAX		4

# define WIN_WIDTH		500
# define WIN_HEIGHT		500
# define WIN_NAME		"fractol"

# define LMB			1
# define SCROLL_UP		4
# define SCROLL_DOWN	5

# define ESC_KEY		53
# define SPACEBAR		49
# define TAB_KEY		48
# define Q_KEY			12
# define W_KEY			13
# define E_KEY			14
# define PLUS_KEY		24
# define MINUS_KEY		27
# define SHIFT_KEY		257
# define CTRL_KEY		256
# define LEFT_ARROW		123
# define RIGHT_ARROW	124
# define DOWN_ARROW		125
# define UP_ARROW		126

# define ZOOM_INC		1.2
# define ARROW_INC		0.2
# define PHASE_INC		(M_PI / 90.0)
# define COLOR_INC		(4.0 / f->max_iter)

# define MAX_ITER		128
# define MAX_ITER_INC	1

/*
** transform x in [min, max] to new value in [a, b]
*/
# define CHANGE(x, min, max, a, b) (((b)-(a))*((x)-(min))/((max)-(min)))+(a)

# define FRACTAL_TYPES	24

# define FT00 t_dict fractal_table[FRACTAL_TYPES] = {					FT01
# define FT01 {"-1", ". Mandelbrot Set", compute_mandelbrot},			FT02
# define FT02 {"-2", ". Julia Set", compute_julia},						FT03
# define FT03 {"-3", ". Burning Ship", compute_burning_ship},			FT04
# define FT04 {"-4", ". Burning Ship - Julia", compute_burning_ship_julia}, FT05
# define FT05 {"-5", ". Tricorn", compute_tricorn},						FT06
# define FT06 {"-6", ". Tricorn - Julia", compute_tricorn_julia},		FT07
# define FT07 {"-7", ". Mandelbrot ^3", compute_brot_3},				FT08
# define FT08 {"-8", ". Julia ^3", compute_julia_3},					FT09
# define FT09 {"-9", ". Mandelbrot ^4", compute_brot_4},				FT10
# define FT10 {"-10", ". Julia ^4", compute_julia_4},					FT11
# define FT11 {"-11", ". Mandelbrot ^8", compute_brot_8},				FT12
# define FT12 {"-12", ". Julia ^8", compute_julia_8},					FT13
# define FT13 {"-13", ". Mandel Drop", compute_mandeldrop},				FT14
# define FT14 {"-14", ". Mandel Drop - Julia", compute_mandeldrop_julia}, FT15
# define FT15 {"-15", ". Triplet Mitosis", compute_tricell},			FT16
# define FT16 {"-16", ". Triplet Mitosis - Julia", compute_tricell_julia}, FT17
# define FT17 {"-17", ". Hyperbolic Triangulum", compute_triangulum},	FT18
# define FT18 {"-18", ". Hyperbolic Triangulum - Julia", 				FT18_2
# define FT18_2 compute_triangulum_julia}, 								FT19
# define FT19 {"-19", ". Spiral Rose", compute_spiral},					FT20
# define FT20 {"-20", ". Spiral Rose - Julia", compute_spiral_julia},	FT21
# define FT21 {"-21", ". Elysian Veil", compute_veil},					FT22
# define FT22 {"-22", ". Elysian - Julia", compute_veil_julia},			FT23
# define FT23 {"-23", ". Void Star", compute_voidstar},					FT24
# define FT24 {"-24", ". Void Star - Julia", compute_voidstar_julia}};	FT_END
# define FT_END m.fractal_table = fractal_table;

# define MAX_SCHEMES	6
# define MAX_NUM_COLORS	10

# define ST00 t_scheme scheme_table[MAX_SCHEMES] = {						ST01
# define ST01 {"RGB Classic", 5, {0x0, 0xFF0000, 0x00FF00, 0x0000FF, 0x0}}, ST02
# define ST02 {"CMY Revival", 5, {0x0, 0x00FFFF, 0xFF00FF, 0xFFFF00, 0x0}}, ST03
# define ST03 {"Patriotica 704", 4, {0xFFFFFF, 0xFF0000, 0x0000FF, ST03_2
# define ST03_2 0xFFFFFF}},												ST04
# define ST04 {"Oreo Infinity", 3, {0x0, 0xFFFFFF, 0x0}},				ST05
# define ST05 {"Abyssal Conflagration", 3, {0x0, 0xFF0000, 0x0}},		ST06
# define ST06 {"Rainbow Dash", 9, {0x0, 0xFF0000, 0xFF7F00, 0xFFFF00,	ST06_2
# define ST06_2 0x00FF00, 0x0000FF, 0x4B0082, 0x9400D3, 0x0}}};			ST_END
# define ST_END m.scheme_table = scheme_table;

# define KEYS_ASSIGNED	14

# define KT00 t_keyfunc key_table[KEYS_ASSIGNED] = {					KT01
# define KT01 {ESC_KEY, terminate},										KT02
# define KT02 {SPACEBAR, reset_view},									KT03
# define KT03 {TAB_KEY, select_next_scheme},							KT04
# define KT04 {Q_KEY, toggle_psych_mode},								KT05
# define KT05 {W_KEY, select_next_map_func},							KT06
# define KT06 {E_KEY, toggle_smooth_mode},								KT07
# define KT07 {PLUS_KEY, inc_max_iter},									KT08
# define KT08 {MINUS_KEY, dec_max_iter},								KT09
# define KT09 {SHIFT_KEY, set_shift_down},								KT10
# define KT10 {CTRL_KEY, set_ctrl_down},								KT11
# define KT11 {LEFT_ARROW, move_screen_left},							KT12
# define KT12 {RIGHT_ARROW, move_screen_right},							KT13
# define KT13 {DOWN_ARROW, move_screen_down},							KT14
# define KT14 {UP_ARROW, move_screen_up}};								KT_END
# define KT_END m.key_table = key_table;

typedef struct			s_cnum
{
	double				real;
	double				imag;
}						t_cnum;

typedef struct			s_mouse
{
	int					x;
	int					y;
	int					lmb_down;
}						t_mouse;

typedef struct			s_dict
{
	char				*term;
	char				*name;
	void				(*compute)();
}						t_dict;

typedef struct			s_scheme
{
	char				*name;
	int					num_colors;
	int					color[MAX_NUM_COLORS];
}						t_scheme;

typedef struct			s_keyfunc
{
	int					keycode;
	void				(*func)();
}						t_keyfunc;

typedef struct			s_mlx
{
	void				*appid;
	void				*win_list;
	void				*img_list;
	void				(*loop_hook)(void *);
	void				*loop_hook_data;
	void				*loop_timer;
	void				**font;
	int					main_loop_active;
}						t_mlx;

typedef struct			s_master
{
	t_mlx				*mlx;
	t_list				*fractal_list;

	t_dict				*fractal_table;
	t_scheme			*scheme_table;
	t_keyfunc			*key_table;
}						t_master;

typedef struct			s_fractal
{
	int					id;
	char				*name;
	void				(*compute)();
	void				*m;

	void				*win;
	void				*img;
	int					*frame;
	int					bpp;
	int					size_line;
	int					endian;

	t_mouse				mouse;
	int					shift_down;
	int					ctrl_down;

	int					max_iter;
	int					escape_limit;
	double				x_min;
	double				x_max;
	double				y_min;
	double				y_max;
	double				zoom;

	int					scheme_id;
	int					psych_mode;
	double				color_shift;
	int					map_func;
	int					smooth_mode;

	double				diter[WIN_WIDTH][WIN_HEIGHT];
	t_cnum				julia_c;
	t_cnum				mandel_z;
}						t_fractal;

/*
** mouse.c
*/
int						mouse_button_down(int button, int x, int y,
							t_fractal *f);
int						mouse_button_up(int button, int x, int y, t_fractal *f);
int						mouse_move(int x, int y, t_fractal *f);

/*
** mouse2.c
*/
void					zoom_in(int x, int y, t_fractal *f);
void					zoom_out(int x, int y, t_fractal *f);
void					set_julia_c(int x, int y, t_fractal *f);
void					set_mandel_z(int x, int y, t_fractal *f);

/*
** keys.c
*/
int						key_press_hook(int keycode, t_fractal *f);
int						key_release_hook(int keycode, t_fractal *f);
int						loop_hook(t_list *fractal_list);

/*
** keys2.c
*/
void					terminate(t_fractal *f);
void					reset_view(t_fractal *f);

/*
** keys3.c
*/
void					select_next_scheme(t_fractal *f);
void					toggle_psych_mode(t_fractal *f);
void					select_next_map_func(t_fractal *f);
void					toggle_smooth_mode(t_fractal *f);

/*
** keys4.c
*/
void					inc_max_iter(t_fractal *f);
void					dec_max_iter(t_fractal *f);
void					set_shift_down(t_fractal *f);
void					set_ctrl_down(t_fractal *f);

/*
** keys5.c
*/
void					move_screen_left(t_fractal *f);
void					move_screen_right(t_fractal *f);
void					move_screen_down(t_fractal *f);
void					move_screen_up(t_fractal *f);

/*
** draw.c
*/
void					draw_dot(int x, int y, int color, t_fractal *f);
void					draw_fractal(int x, int y, t_fractal *f);

/*
** color.c
*/
int						interp_color(int color1, int color2, double k);
int						get_color_from_scheme(double r, t_fractal *f);
int						get_color_by_mode(int iter, t_fractal *f);
int						get_color(double diter, t_fractal *f);

/*
** c_ops.c
*/
void					c_cube(t_cnum *n);
void					c_square(t_cnum *n);
void					c_add(t_cnum *n1, t_cnum *n2);
void					c_invert(t_cnum *n, t_cnum *result);

/*
** mandelbrot.c
*/
void					compute_mandelbrot(int x, int y, t_fractal *f);
void					compute_julia(int x, int y, t_fractal *f);
void					store_diter(double *diter, int i, t_cnum *z,
							t_fractal *f);

/*
** burning_ship.c
*/
void					compute_burning_ship(int x, int y, t_fractal *f);
void					compute_burning_ship_julia(int x, int y, t_fractal *f);

/*
** tricorn.c
*/
void					compute_tricorn(int x, int y, t_fractal *f);
void					compute_tricorn_julia(int x, int y, t_fractal *f);

/*
** brot_3.c
*/
void					compute_brot_3(int x, int y, t_fractal *f);
void					compute_julia_3(int x, int y, t_fractal *f);

/*
** brot_4.c
*/
void					compute_brot_4(int x, int y, t_fractal *f);
void					compute_julia_4(int x, int y, t_fractal *f);

/*
** brot_8.c
*/
void					compute_brot_8(int x, int y, t_fractal *f);
void					compute_julia_8(int x, int y, t_fractal *f);

/*
** mandeldrop.c
*/
void					compute_mandeldrop(int x, int y, t_fractal *f);
void					compute_mandeldrop_julia(int x, int y, t_fractal *f);

/*
** tricell.c
*/
void					compute_tricell(int x, int y, t_fractal *f);
void					compute_tricell_julia(int x, int y, t_fractal *f);

/*
** triangulum.c
*/
void					compute_triangulum(int x, int y, t_fractal *f);
void					compute_triangulum_julia(int x, int y, t_fractal *f);

/*
** spiral.c
*/
void					compute_spiral(int x, int y, t_fractal *f);
void					compute_spiral_julia(int x, int y, t_fractal *f);

/*
** veil.c
*/
void					compute_veil(int x, int y, t_fractal *f);
void					compute_veil_julia(int x, int y, t_fractal *f);

/*
** voidstar.c
*/
void					compute_voidstar(int x, int y, t_fractal *f);
void					compute_voidstar_julia(int x, int y, t_fractal *f);

/*
** parse.c
*/
int						parse_terms(int argc, char **argv, t_master *m);
int						add_fractal(int *id, char *term, t_master *m);

/*
** render.c
*/
void					render(t_fractal *f);
void					*th0_compute(void *f);
void					*th1_compute(void *f);
void					*th2_compute(void *f);
void					*th3_compute(void *f);

/*
** main.c
*/
int						init_mlx_stuff(t_fractal *f, t_master *m);
int						init_all_fractals(t_master *m);
int						main(int argc, char **argv);
int						print_usage(t_master *m);

/*
** freedom.c
*/
void					free_all(t_master *m);
void					del_fractal(t_fractal *f);

/*
** debug.c
*/
void					print_cnum(t_cnum *n);
void					print_diagnostics(t_fractal *f);

#endif

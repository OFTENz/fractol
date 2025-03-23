/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mir <sel-mir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 01:31:10 by sel-mir           #+#    #+#             */
/*   Updated: 2025/03/23 20:05:07 by sel-mir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <limits.h>
# include <unistd.h>
# include <mlx.h>
# include <stdlib.h>

# ifndef WIDTH
#  define WIDTH 600
# endif

# ifndef DBL_MAX
#  define DBL_MAX 1.7976931348623157e+308
# endif

# ifndef HEIGHT
#  define HEIGHT 600
# endif

# ifndef N_MAX
#  define N_MAX 2.0
# endif

# ifndef N_MIN
#  define N_MIN -2.0
# endif

# ifndef MAX_ITER
#  define MAX_ITER 100
# endif

typedef struct s_xnbr
{
	double	real;
	double	imag;
}	t_xnbr;

typedef struct s_unit
{
	unsigned int	color;
	t_xnbr			julia;
	int				choice;
	void			*mlx;
	void			*mlx_window;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	t_xnbr			offset;
	double			zoom;
}	t_unit;

unsigned int	colorization(int i);

void			initiating(t_unit *core);
void			sanitize(char *str);
void			usage(void);
void			parsing(int ac, char **av, t_unit *data);
void			mandelbrot_work(t_unit *data);
void			flush(void);
void			cplx_convert(int x, int y, t_unit *data, t_xnbr *nbr);
void			*get_pxl_add(t_unit *data, int x, int y);
void			julia_work(t_unit *data);
void			engine(t_unit *data);
void			error_float(void);
void			is_digit(char *str);

int				mandelbrot(t_xnbr c);
int				compare(char *str, char *original);
int				mouse_zoom(int button, int x, int y, t_unit *data);
int				key_events(int key, t_unit *data);
int				close_window(t_unit *data);
int				julia(t_xnbr z, t_xnbr c);

double			ft_atoi(char *str);
double			fraction_part(char *str);

#endif

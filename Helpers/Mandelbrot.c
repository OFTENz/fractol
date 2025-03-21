/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mir <sel-mir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:45:56 by sel-mir           #+#    #+#             */
/*   Updated: 2025/03/20 14:15:13 by sel-mir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

//	This Should be the main Function for mandelbrot !

void	mandelbrot_work(t_unit *data)
{
	unsigned int	*pixel;
	int				x;
	int				y;
	t_xnbr			*nbr;
	int				i;

	x = -1;
	nbr = malloc(sizeof(t_xnbr));
	while (++x < 650)
	{
		y = -1;
		while (++y < 650)
		{
			cplx_convert(x, y, data, nbr);
			i = mandelbrot(*nbr);
			(*data).color = colorization(i);
			pixel = get_pxl_add(data, x, y);
			(*pixel) = ((*data).color);
		}
	}
	mlx_put_image_to_window((*data).mlx, (*data).mlx_window, (*data).img, 0, 0);
}

//	This is the function that tranform a pixel to a Complex Number  !

void	cplx_convert(int x, int y, t_unit *data, t_xnbr *nbr)
{
	(*nbr).real = ((x / (double)WIDTH) * 4.0 - 2.0)
		* data->zoom + data->offset.real;
	(*nbr).imag = ((y / (double)HEIGHT) * 4.0 - 2.0)
		* data->zoom + data->offset.imag;
}

//	This function is the one that checks  if output of the function 
//	Escaped to Infinity Or NOT !
//	Wich Decides if it's a Mandelbro Point Or NOT !

int	mandelbrot(t_xnbr c)
{
	t_xnbr	z;
	int		i;
	double	tmp;

	z.real = 0;
	z.imag = 0;
	i = 0;
	while (z.real * z.real + z.imag * z.imag <= 4 && i < MAX_ITER)
	{
		tmp = z.real * z.real - z.imag * z.imag + c.real;
		z.imag = 2.0 * z.real * z.imag + c.imag;
		z.real = tmp;
		i++;
	}
	return (i);
}

//This Function gets the addr of the pixel using the address of the image !

void	*get_pxl_add(t_unit *data, int x, int y)
{
	return (data->addr + (y * data->line_length)
		+ (x * (data->bits_per_pixel / 8)));
}

unsigned int	colorization(int i)
{
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;

	if (i == MAX_ITER)
		return (0x000000);
	red = (i * 5) % 256;
	green = (i * 10) % 256;
	blue = (i * 20) % 256;
	return ((red << 16) | (green << 8) | blue);
}

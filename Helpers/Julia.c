/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mir <sel-mir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 23:49:56 by sel-mir           #+#    #+#             */
/*   Updated: 2025/03/20 14:14:48 by sel-mir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	julia_work(t_unit *data)
{
	unsigned int	*pixel;
	int				x;
	int				y;
	t_xnbr			*z;
	int				i;

	x = -1;
	z = malloc(sizeof(t_xnbr));
	while (++x < 650)
	{
		y = -1;
		while (++y < 650)
		{
			cplx_convert(x, y, data, z);
			i = julia(*z, (*data).julia);
			(*data).color = colorization(i);
			pixel = get_pxl_add(data, x, y);
			(*pixel) = ((*data).color);
		}
	}
	mlx_put_image_to_window((*data).mlx, (*data).mlx_window, (*data).img, 0, 0);
}

// Do the same but this time the z is derived from Coordinates 
// And C is Constant !

int	julia( t_xnbr z, t_xnbr c)
{
	int		i;
	double	tmp;

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

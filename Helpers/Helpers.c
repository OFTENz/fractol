/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 07:59:10 by            #+#    #+#             */
/*   Updated: 2025/04/06 09:37:20 by           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

//This function is getting stuff ready !

void	initiating(t_unit *core)
{
	(*core).mlx = mlx_init();
	if (!(*core).mlx)
		flush();
	(*core).mlx_window = mlx_new_window((*core).mlx, 650, 650, "Alpha");
	if (!(*core).mlx_window)
		flush();
	(*core).img = mlx_new_image((*core).mlx, 650, 650);
	if (!(*core).img)
	{
		mlx_destroy_window((*core).mlx, (*core).mlx_window);
		flush();
	}
	(*core).addr = mlx_get_data_addr((*core).img,
			&(*core).bits_per_pixel, &(*core).line_length, &(*core).endian);
	if (!(*core).addr)
	{
		mlx_destroy_window((*core).mlx, (*core).mlx_window);
		mlx_destroy_image((*core).mlx, (*core).img);
		flush();
	}
}

//

void	my_mlx_pixel_put(t_unit *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*dst = color;
}

void	flush(void)
{
	write (1, "\nError !\n", 9);
	exit(1);
}

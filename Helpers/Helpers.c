/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mir <sel-mir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 07:59:10 by sel-mir           #+#    #+#             */
/*   Updated: 2025/03/20 14:14:04 by sel-mir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

//This function is getting stuff ready !

void	initiating(t_unit *core)
{
	(*core).mlx = mlx_init();
	(*core).mlx_window = mlx_new_window((*core).mlx, 650, 650, "Alpha");
	(*core).img = mlx_new_image((*core).mlx, 650, 650);
	(*core).addr = mlx_get_data_addr((*core).img,
			&(*core).bits_per_pixel, &(*core).line_length, &(*core).endian);
	if (!(*core).mlx || !(*core).mlx_window || !(*core).img || !(*core).addr)
		flush();
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

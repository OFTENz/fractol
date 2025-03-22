/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mir <sel-mir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 01:30:51 by sel-mir           #+#    #+#             */
/*   Updated: 2025/03/22 06:06:45 by sel-mir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	engine(t_unit *data)
{
	if (!(*data).choice)
		mandelbrot_work(data);
	else
		julia_work(data);
}

void	leak(void)
{
	system("leaks fractol");
}

int	main(int ac, char **av)
{
	// atexit(leak);
	t_unit	data;
	t_unit	*hold;

	hold = &data;
	parsing(ac, av, hold);
	initiating(hold);
	engine(hold);
	mlx_key_hook(data.mlx_window, key_events, &data);
	mlx_hook(data.mlx_window, 17, 0, close_window, &data);
	mlx_mouse_hook(data.mlx_window, mouse_zoom, &data);
	// mlx_loop(data.mlx);
	
}

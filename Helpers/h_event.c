/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_event.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mir <sel-mir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:09:32 by sel-mir           #+#    #+#             */
/*   Updated: 2025/03/22 05:51:51 by sel-mir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	close_window(t_unit *data)
{
	(void)data;
	exit(0);
}

int	key_events(int key, t_unit *data)
{
	if (key == 53)
		close_window(data);
	return (0);
}

int	mouse_zoom(int button, int x, int y, t_unit *data)
{
	(void)x;
	(void)y;
	if (button == 4)
		data->zoom *= 1.1;
	else if (button == 5)
		data->zoom /= 1.1;
	engine(data);
	return (0);
}

void	error_float()
{
	write (1, "\nError : Enter a float : 0<float<2 To get Good Fractals !\n", 58);
	exit(1);
}
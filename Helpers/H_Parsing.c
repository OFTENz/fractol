/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   H_Parsing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mir <sel-mir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 07:01:00 by sel-mir           #+#    #+#             */
/*   Updated: 2025/03/24 13:44:01 by sel-mir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

//  Print Usage and Quit !

void	usage(void)
{
	write (1, "\nError : Usage ==> ./fractol \"Mandelbrot\" OR", 44);
	write (1, "\" Julia\" 0 < num1 < 2 AND -2 < num1 < 0", 49);
	exit(1);
}

//  This Function Take Care Of the Parsing !

void	parsing(int ac, char **av, t_unit *data)
{
	if ((!compare(av[1], "Mandelbrot") && ac != 2)
		|| (!compare(av[1], "Julia") && ac != 4))
		usage();
	if ((compare(av[1], "Mandelbrot") && compare(av[1], "Julia")))
		usage();
	if (!compare(av[1], "Mandelbrot"))
	{
		data->zoom = 1.0;
		data->offset.real = 0.0;
		data->offset.imag = 0.0;
		(*data).choice = 0;
	}
	else if (!compare(av[1], "Julia"))
	{
		sanitize(av[2]);
		sanitize(av[3]);
		(*data).julia.real = ft_atoi(av[2]);
		(*data).julia.imag = ft_atoi(av[3]);
		(*data).choice = 1;
		data->zoom = 0.9;
		data->offset.real = 0.0;
		data->offset.imag = 0.0;
		(*data).choice = 1;
	}
}

// Comapres the Original With the Mutant !

int	compare(char *str, char *original)
{
	int	a;

	a = 0;
	if (!str || !original)
		return (-1);
	while (str[a] && original[a])
	{
		if (str[a] != original[a])
			return (-1);
		a++;
	}
	if (str[a] != original[a])
		return (-1);
	return (0);
}

//	This function checks if String is a Valid Float !

void	sanitize(char *str)
{
	int	a;
	int	i;

	a = 0;
	i = 0;
	if (!str[0])
		flush();
	is_digit(str);
	while (str[a])
	{
		if (str[a] == '.' && !i)
		{
			i++;
			a++;
		}
		if ((str[a] == '.' && i) || ((!(str[a] <= '9' && str[a] >= '0')
					&&str[a] != '.' && str[a] != '-'))
			|| str[0] == '.' )
			flush();
		a++;
	}
}

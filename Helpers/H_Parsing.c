/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   H_Parsing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mir <sel-mir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 07:01:00 by sel-mir           #+#    #+#             */
/*   Updated: 2025/03/21 23:09:22 by sel-mir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

//  Print Usage and Quit !

void	usage(void)
{
	write (1, "\nError : Usage ==> ./fractol \"Mandelbrot\" OR \" Julia\" 0 < num1 < 2 AND -2 < num1 < 0", 53);
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
		(*data).julia.real = atof(av[2]);
		(*data).julia.imag = atof(av[3]);
		(*data).choice = 1;
		data->zoom = 0.9;
		data->offset.real = 0.0;
		data->offset.imag = 0.0;
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
	while (str[a])
	{
		if (str[a] == '.' && !i)
		{
			i++;
			a++;
		}
		if ((!(str[a] <= '9' && str[a] >= '0') && i) || (str[a] == '.'
				&& !i && !(str[a] <= '9' && str[a] >= '0')) || str[0] == '.')
			flush();
		a++;
	}
}


static int	ft_cmplt(int sign)
{
	if (sign == -1)
		return (0);
	return (-1);
}

int	ft_atoi(const char *str)
{
	int			a;
	long long	res;
	int			sign;
	long long	d;

	sign = 1;
	res = 0;
	a = 0;
	while (str[a] == ' ' || (str[a] >= 9 && str[a] <= 13))
		a++;
	if (str[a] == '-' || str[a] == '+')
	{
		if (str[a] == '-')
			sign *= -1;
		a++;
	}
	while (str[a] <= '9' && str[a] >= '0')
	{
		d = res;
		res = res * 10 + str[a++] - 48;
		if ((res / 10 - (str[a] - 48)) != d)
			return (ft_cmplt(sign));
	}
	return (res * sign);
}


// double ft_atof(const char *str)
// {
// 	double result = 0.0;
// 	double fraction = 0.0;
// 	double divisor = 10.0;
// 	int sign = 1;
    
//     // Handle negative numbers
//     if (*str == '-')
//     {
//         sign = -1;
//         str++;
//     }
    
//     // Convert integer part
//     while (*str >= '0' && *str <= '9')
//     {
//         result = result * 10 + (*str - '0');
//         str++;
//     }

//     // Convert fractional part if present
//     if (*str == '.')
//     {
//         str++; // Skip the decimal point
//         while (*str >= '0' && *str <= '9')
//         {
//             fraction += (*str - '0') / divisor;
//             divisor *= 10;
//             str++;
//         }
//     }

//     return sign * (result + fraction);
// }

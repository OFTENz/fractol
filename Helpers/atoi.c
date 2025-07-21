/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 00:18:36 by            #+#    #+#             */
/*   Updated: 2025/04/06 11:11:16 by           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static int	ft_cmplt(void)
{
	write(1, "\nOverFlow  !\n", 13);
	exit(1);
}

double	ft_atoi(char *str)
{
	int			a;
	double		res;
	int			sign;

	sign = 1;
	res = 0;
	a = 0;
	if (str[a] == '-' || str[a] == '+')
	{
		if (str[a] == '-')
			sign *= -1;
		a++;
	}
	while (str[a] <= '9' && str[a] >= '0')
	{
		if ((sign == 1 && res > (INT_MAX - (str[a] - '0')) / 10)
			|| (res > (INT_MIN + (str[a] - '0')) / -10 && sign == -1))
			return (ft_cmplt());
		res = res * 10 + str[a++] - 48;
		if (res > 2 || res < -2)
			error_float();
	}
	return (sign * (res + fraction_part(&str[a])));
}

//	This function handles the fraction Part !

double	fraction_part(char *str)
{
	double	fraction;
	double	divisor;
	int		a;

	divisor = 10;
	fraction = 0.0;
	a = 0;
	if (str[a++] != '.')
		return (0);
	while (str[a] >= '0' && str[a] <= '9')
	{
		if (fraction > (DBL_MAX - (str[a] - '0')) / divisor)
			error_float();
		fraction += (str[a] - '0') / divisor;
		divisor *= 10;
		a++;
	}
	return (fraction);
}

void	is_digit(char *str)
{
	int	a;
	int	o;
	int	p;

	a = 0;
	o = 0;
	p = 0;
	while (str[a])
	{
		if (str[a] == '.' && !a)
			usage();
		if (str[a] == '.' && !p)
		{
			p++;
			a++;
		}
		if ((str[a] == '.' && p))
			usage();
		if ((str[a] == '+' || str[a] == '-') && a)
			usage();
		a++;
	}
}

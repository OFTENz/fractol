/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mir <sel-mir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 00:18:36 by sel-mir           #+#    #+#             */
/*   Updated: 2025/03/22 05:05:47 by sel-mir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static int	ft_cmplt(void)
{
	printf("\nOverFlow  !\n");
	exit(1);
}

double	ft_atoi(char *str)
{
	int			a;
	int			res;
	int			sign;

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
		if ((sign == 1 && res > (INT_MAX - (str[a] - '0')) / 10)
			|| (res > (INT_MIN + (str[a] - '0')) / -10 && sign == -1))
			return (ft_cmplt());
		res = res * 10 + str[a++] - 48;
	}
	return (res * sign);
}


double	fraction_part(char *str)
{
	double	fraction;
	int		divisor;
	int			a;
	
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

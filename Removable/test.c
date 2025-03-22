/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mir <sel-mir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:49:58 by sel-mir           #+#    #+#             */
/*   Updated: 2025/03/22 05:16:04 by sel-mir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <limits.h>
# include <unistd.h>
# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <float.h>


void	error_float()
{
	write (1, "\nError : Enter a float : 0<float<2 To get Good Fractals !\n", 58);
	exit(1);
}

double	fraction_part(char *str)
{
	double	fraction;
	double		divisor;
	int			a;
	
	divisor = 10;
	fraction = 0.0;
	a = 0;
	if (str[a++] != '.')
		return (0);
	printf("\nThe integers being treated is : %c\n", str[a]);
	while (str[a] >= '0' && str[a] <= '9')
	{
		if (fraction > (DBL_MAX - (str[a] - '0')) / divisor)
			error_float();
		printf("\nThe integers being treated is : %c\n", str[a]);
		fraction += (str[a] - '0') / divisor;
		divisor *= 10;
		a++;
	}
	printf("\nThe Returned Double is : %f\n", fraction);
	return (fraction);
}


void	flush(void)
{
	write (1, "\nError !\n", 9);
	exit(1);
}


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
	return (sign * (res + fraction_part(&str[a])));
}


int	main()
{
	char *str;
	
	str = "12.89";
	sanitize(str);
	printf("\nThe Float is : %f\n", ft_atoi(str));
	
}
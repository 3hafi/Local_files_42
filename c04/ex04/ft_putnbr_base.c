/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucao <lucao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 19:49:21 by lucao             #+#    #+#             */
/*   Updated: 2025/09/12 22:22:24 by lucao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
// #include <stdio.h>

int	get_base(char *base)
{
	int	i;
	int	j;

	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = 0;
		while (j < i)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		b;
	long	n;
	int		div;
	char	digit;

	b = get_base(base);
	if (b == 0)
		return ;
	n = nbr;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	div = 1;
	while (n / div >= b)
		div *= b;
	while (div > 0)
	{
		digit = base[n / div];
		write(1, &digit, 1);
		n %= div;
		div /= b;
	}
}

// int	main(void)
// {
// 	ft_putnbr_base(0, "0123456789-+");
// 	return (1);
// }

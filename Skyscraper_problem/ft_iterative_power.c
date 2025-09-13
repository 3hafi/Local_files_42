/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarval <tcarval@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:20:12 by tcarval           #+#    #+#             */
/*   Updated: 2025/09/08 15:20:13 by tcarval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	result;

	result = 1;
	if (power < 0)
		return (0);
	while (power-- > 0)
		result *= nb;
	return (result);
}

/*
#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_iterative_power(-1, -1));
	printf("%d\n", ft_iterative_power(-1, 3));
	printf("%d\n", ft_iterative_power(-1, 2));
	printf("%d\n", ft_iterative_power(-1, 0));
	printf("%d\n", ft_iterative_power(0, 0));
	printf("%d\n", ft_iterative_power(1, 0));
	printf("%d\n", ft_iterative_power(2, 4));
	printf("%d\n", ft_iterative_power(3, 2));
	printf("%d\n", ft_iterative_power(4, 3));
	printf("%d\n", ft_iterative_power(5, 2));
	printf("%d\n", ft_iterative_power(10, 5));
}
//*/

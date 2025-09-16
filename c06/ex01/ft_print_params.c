/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuekok <xuekok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 12:33:22 by xuekok            #+#    #+#             */
/*   Updated: 2025/09/15 12:41:59 by xuekok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_args(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] != '\0')
	{
		write(1, &arg[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	int		i;
	char	*arg_name;

	i = 1;
	while (i < argc)
	{
		arg_name = argv[i];
		print_args(arg_name);
		i++;
	}
	return (0);
}

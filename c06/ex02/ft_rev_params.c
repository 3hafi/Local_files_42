/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuekok <xuekok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 12:33:24 by xuekok            #+#    #+#             */
/*   Updated: 2025/09/15 13:38:50 by xuekok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	char	*input_str;

	while (--argc > 0)
	{
		input_str = argv[argc];
		while (*input_str)
		{
			write(1, &*input_str, 1);
			input_str++;
		}
		write(1, "\n", 1);
	}
	return (0);
}

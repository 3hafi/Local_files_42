/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuekok <xuekok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 12:33:15 by xuekok            #+#    #+#             */
/*   Updated: 2025/09/15 12:38:02 by xuekok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_program_name(char *name)
{
	while (*name != '\0')
	{
		write(1, name, 1);
		name++;
	}
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	char	*fn_name;

	fn_name = argv[argc % argc];
	print_program_name(fn_name);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuekok <xuekok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 12:33:25 by xuekok            #+#    #+#             */
/*   Updated: 2025/09/15 13:47:00 by xuekok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != 0 && s2[i] != 0 && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

char	**sort_args(char **argv)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_strcmp(argv[i], argv[j]) > 0)
			{
				temp = argv[i];
				argv[i] = argv[j];
				argv[j] = temp;
			}
			j++;
		}
		i++;
	}
	return (argv);
}

int	main(int argc, char **argv)
{
	char	*s;

	(void) argc;
	argv = sort_args(++argv);
	while (*argv)
	{
		s = *argv++;
		while (*s)
			write(1, &*s++, 1);
		write(1, "\n", 1);
	}
	return (0);
}

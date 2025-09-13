/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarval <tcarval@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 13:57:24 by tcarval           #+#    #+#             */
/*   Updated: 2025/09/13 13:57:24 by tcarval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_put_char(char c)
{
	write(1, &c, 1);
}

void	ft_put_str(char *str)
{
	while (*str != '\0')
		write(1, str++, 1);
}

void	ft_put_err(char *str)
{
	while (*str != '\0')
		write(2, str++, 1);
}

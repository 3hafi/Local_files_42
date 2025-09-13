/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarval <tcarval@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 14:46:20 by tcarval           #+#    #+#             */
/*   Updated: 2025/09/13 13:57:37 by tcarval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

int	char_in_str(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_str_dup_til_next_sep(char *src, char *charset)
{
	unsigned int	i;
	unsigned int	l_target;
	char			*output;

	l_target = 0;
	while (!char_in_str(src[l_target], charset) && src[l_target] != '\0')
		l_target++;
	output = malloc(sizeof(char) * (l_target + 1));
	i = 0;
	while (i < l_target)
	{
		output[i] = src[i];
		i++;
	}
	output[l_target] = '\0';
	return (output);
}

int	get_word_count(char *str, char *charset)
{
	int	i;
	int	in_word;
	int	word_count;

	i = 0;
	in_word = 0;
	word_count = 0;
	while (str[i] != '\0')
	{
		if (char_in_str(str[i], charset))
			in_word = 0;
		else
		{
			if (in_word == 0)
				word_count++;
			in_word = 1;
		}
		i++;
	}
	return (word_count);
}

char	**ft_split(char *str, char *charset)
{
	int		word_count;
	int		i;
	int		j;
	char	**result;

	word_count = get_word_count(str, charset);
	result = malloc(sizeof(void *) * (word_count + 1));
	result[word_count] = NULL;
	i = 0;
	j = 0;
	if (!(str[0] == '\0' || char_in_str(str[0], charset)))
		result[j++] = ft_str_dup_til_next_sep(str, charset);
	while (str[i] != '\0')
	{
		if (char_in_str(str[i], charset))
		{
			if (!(char_in_str(str[i + 1], charset) || str[i + 1] == '\0'))
			{
				result[j++] = ft_str_dup_til_next_sep(str + i + 1, charset);
			}
		}
		i++;
	}
	return (result);
}

/*
#include <stdio.h>

int	main(void)
{
	char	**r;

	r = ft_split(".", ".");
	while (*r != NULL)
		printf("|%s|\n",*r++);
}
//*/

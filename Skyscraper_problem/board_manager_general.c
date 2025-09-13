/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_manager_general.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarval <tcarval@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 14:38:37 by tcarval           #+#    #+#             */
/*   Updated: 2025/09/13 20:14:07 by tcarval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

extern void	ft_put_char(char c);
extern void	ft_put_str(char *str);
extern void	ft_put_err(char *str);
extern void	ft_swap(int *arr, int i, int j);

int	coord_to_index(int column_x, int row_y, int grid_size)
{
	return (row_y * grid_size + column_x);
}

void	init_board(int	*board, int grid_size)
{
	int	i;

	i = 0;
	while (i < grid_size * grid_size)
		board[i++] = 0;
}

int	*new_board(int grid_size)
{
	int	*board;

	board = malloc(sizeof(int) * grid_size * grid_size);
	init_board(board, grid_size);
	return (board);
}

void	print_bounding_line(int views[], int view_offset)
{
	int	i;

	i = 0;
	ft_put_str("  ");
	while (i < 4)
	{
		ft_put_char('0' + views[view_offset + i++]);
		ft_put_str(" ");
	}
	ft_put_str(" \n");
}

void	print_middle_line(int *board, int views[], int line, int view_offset)
{
	int	i;

	ft_put_char('0' + views[8 + view_offset]);
	ft_put_char('|');
	i = 0;
	while (i < 4)
	{
		ft_put_char('0' + board[coord_to_index(i, line, 4)]);
		if (i++ < 3)
			ft_put_str(" ");
	}
	ft_put_char('|');
	ft_put_char('0' + views[12 + view_offset]);
	ft_put_str(" \n");
	i++;
}

void	print_board(int *board, int views[])
{
	int	i;

	print_bounding_line(views, 0);
	i = 0;
	while (i < 4)
	{
		print_middle_line(board, views, i, i);
		i++;
	}
	print_bounding_line(views, 4);
}

/*

"col1top col2top col3top col4top
col1bottom col2bottom col3bottom col4bottom 
row1left row2left row3left row4left 
row1right row2right row3right row4right"

*/

// "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"
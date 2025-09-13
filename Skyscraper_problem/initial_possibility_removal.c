/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_possibility_removal.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarval <tcarval@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 18:47:33 by tcarval           #+#    #+#             */
/*   Updated: 2025/09/13 20:07:16 by tcarval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
// #include <stdio.h>

extern int	coord_to_index(int column_x, int row_y, int grid_size);

void	init_lr_possibilities(int lr_merge,
	int value_count, int ***row_possibilities)
{
	int	left;
	int	right;

	left = (lr_merge / 10) - 1;
	right = (lr_merge % 10) - 1;
	if (row_possibilities[left] == NULL)
		row_possibilities[left] = malloc(sizeof(void *) * 4);
	row_possibilities[left][right] = malloc(sizeof(void *) * (4 + 1));
	row_possibilities[left][right][value_count] = 0;
}

void	setup_lr_possibility(int lr_merge,
	int ***row_possibilities, int possible_value, int index)
{
	int	left;
	int	right;

	left = (lr_merge / 10) - 1;
	right = (lr_merge % 10) - 1;
	row_possibilities[left][right][index] = possible_value;
}

void	setup_left_1(int	***row_possibilities)
{
	init_lr_possibilities(12, 2, row_possibilities);
	setup_lr_possibility(12, row_possibilities, 4123, 0);
	setup_lr_possibility(12, row_possibilities, 4213, 1);
	init_lr_possibilities(13, 2, row_possibilities);
	setup_lr_possibility(13, row_possibilities, 4312, 0);
	setup_lr_possibility(13, row_possibilities, 4132, 1);
	setup_lr_possibility(13, row_possibilities, 4231, 2);
	init_lr_possibilities(14, 1, row_possibilities);
	setup_lr_possibility(14, row_possibilities, 4321, 0);
}

void	setup_left_2(int	***row_possibilities)
{
	init_lr_possibilities(21, 2, row_possibilities);
	setup_lr_possibility(21, row_possibilities, 3124, 0);
	setup_lr_possibility(21, row_possibilities, 3214, 0);
	init_lr_possibilities(22, 6, row_possibilities);
	setup_lr_possibility(22, row_possibilities, 2143, 0);
	setup_lr_possibility(22, row_possibilities, 3142, 1);
	setup_lr_possibility(22, row_possibilities, 3241, 2);
	setup_lr_possibility(22, row_possibilities, 1423, 3);
	setup_lr_possibility(22, row_possibilities, 2413, 4);
	setup_lr_possibility(22, row_possibilities, 3412, 5);
	init_lr_possibilities(23, 3, row_possibilities);
	setup_lr_possibility(23, row_possibilities, 1432, 0);
	setup_lr_possibility(23, row_possibilities, 2431, 1);
	setup_lr_possibility(23, row_possibilities, 3421, 2);
}

void	setup_left_3(int	***row_possibilities)
{
	init_lr_possibilities(31, 3, row_possibilities);
	setup_lr_possibility(31, row_possibilities, 2134, 0);
	setup_lr_possibility(31, row_possibilities, 1324, 1);
	setup_lr_possibility(31, row_possibilities, 3214, 2);
	init_lr_possibilities(32, 3, row_possibilities);
	setup_lr_possibility(32, row_possibilities, 2341, 0);
	setup_lr_possibility(32, row_possibilities, 1342, 1);
	setup_lr_possibility(32, row_possibilities, 1243, 2);
}

void	setup_left_4(int	***row_possibilities)
{
	init_lr_possibilities(41, 1, row_possibilities);
	setup_lr_possibility(41, row_possibilities, 1234, 0);
}

int	***create_row_possibilities(void)
{
	int	***row_possibilities;

	row_possibilities = malloc(sizeof(void *) * 4);
	setup_left_1(row_possibilities);
	setup_left_2(row_possibilities);
	setup_left_3(row_possibilities);
	setup_left_4(row_possibilities);
	return (row_possibilities);
}

int	**get_view_possibilities(int ***r_pos, int views[])
{
	int	**view_possibilities;

	view_possibilities = malloc(sizeof(void *) * 4 * 2);
	view_possibilities[0] = r_pos[views[0 + 0] - 1][views[4 + 0] - 1];
	view_possibilities[1] = r_pos[views[0 + 1] - 1][views[4 + 1] - 1];
	view_possibilities[2] = r_pos[views[0 + 2] - 1][views[4 + 2] - 1];
	view_possibilities[3] = r_pos[views[0 + 3] - 1][views[4 + 3] - 1];
	view_possibilities[4] = r_pos[views[8 + 0] - 1][views[12 + 0] - 1];
	view_possibilities[5] = r_pos[views[8 + 1] - 1][views[12 + 1] - 1];
	view_possibilities[6] = r_pos[views[8 + 2] - 1][views[12 + 2] - 1];
	view_possibilities[7] = r_pos[views[8 + 3] - 1][views[12 + 3] - 1];
	return (view_possibilities);
}

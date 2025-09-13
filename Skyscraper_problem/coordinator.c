// #include <stdio.h>

extern int	*new_board(int grid_size);
extern int	***create_row_possibilities(void);
extern int	ft_len_to_null(int *ptr);
extern int	coord_to_index(int column_x, int row_y, int grid_size);
extern int	ft_iterative_power(int nb, int power);
extern int	**get_view_possibilities(int ***row_possibilities, int views[]);
extern void	ft_put_err(char *str);
extern void	ft_put_str(char *str);
extern void	print_board(int *board, int views[]);

int	sum_digits_to_number(int d1, int d2, int d3, int d4)
{
	// RENAME FUNCTION
	return (d1 * 1000 + d2 * 100 + d3 * 10 + d4);
}

int	create_start(int *board, int x, int possible_row, int row_y)
{
	int	values[4];
	int	i;
	int	start_value;

	// RENAME FUNCTION
	i = 0;
	while (i < 4)
		values[i++] = 0;
	i = 0;
	while (i < row_y)
	{
		values[i] = board[coord_to_index(x, i, 4)];
		i++;
	}
	possible_row /= ft_iterative_power(10, 4 - x - 1);
	values[i] = possible_row % 10;
	start_value = sum_digits_to_number(values[0], values[1],
			values[2], values[3]);
	return (start_value);
}

int	is_col_valid(int start, int possible_column, int digits_to_check)
{
	int	i;
	int	pow;

	i = 0;
	while (i < digits_to_check)
	{
		pow = ft_iterative_power(10, 4 - i - 1);
		if ((start / pow) % 10 != (possible_column / pow) % 10)
			return (0);
		i++;
	}
	return (1);
}

int	is_row_possible(int *board, int row_y,
	int possible_row, int **view_possibilities)
{
	int	*possible_cols;
	int	x;
	int	j;
	int	possible_column;

	x = 0;
	while (x < 4)
	{
		possible_cols = view_possibilities[0 + x];
		j = 0;
		possible_column = 0;
		while (possible_cols[j])
		{
			if (is_col_valid(create_start(board, x, possible_row, row_y),
					possible_cols[j], row_y + 1))
				possible_column = 1;
			j++;
		}
		if (possible_column == 0)
			return (0);
		x++;
	}
	return (1);
}

int	recurse_row(int *board, int row_y, int **view_possibilities, int views[])
{
	int	*possible_rows;
	int	i;

	if (row_y == 4)
	{
		print_board(board, views);
		return (1);
	}
	possible_rows = view_possibilities[4 + row_y];
	i = 0;
	while (possible_rows[i])
	{
		if (is_row_possible(board, row_y, possible_rows[i], view_possibilities))
		{
			board[4 * row_y + 0] = (possible_rows[i] / 1000) % 10;
			board[4 * row_y + 1] = (possible_rows[i] / 100) % 10;
			board[4 * row_y + 2] = (possible_rows[i] / 10) % 10;
			board[4 * row_y + 3] = (possible_rows[i] / 1) % 10;
			if (recurse_row(board, row_y + 1, view_possibilities, views) == 1)
				return (1);
		}
		i++;
	}
	return (0);
}

void	place_boxes(int views[])
{
	int	*board;
	int	***row_possibilities;
	int	**view_possibilities;

	board = new_board(4);
	row_possibilities = create_row_possibilities();
	view_possibilities = get_view_possibilities(row_possibilities, views);
	recurse_row(board, 0, view_possibilities, views);
}

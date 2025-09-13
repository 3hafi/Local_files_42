extern char	**ft_split(char *str, char *charset);
extern int	ft_strlen(char *str);
extern void	ft_put_char(char c);
extern void	ft_put_str(char *str);
extern void	ft_put_err(char *str);
extern void	place_boxes(int views[], int grid_size);

int	check_arguments(int argc, char **argv)
{
	int		view_str_length;

	if (argc != 2)
	{
		ft_put_err("Incorrect number of arguments");
		return (1);
	}
	view_str_length = ft_strlen(argv[1]);
	if (view_str_length != 2 * (4 * 4) - 1)
	{
		ft_put_err("Incorrect layout for ...");
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	char	**split_views;
	int		views[16];
	int		i;

	if (check_arguments == 1)
		return (1);
	split_views = ft_split(argv[1], " ");
	i = 0;
	while (i < 4 * 4)
	{
		if (ft_strlen(split_views[i]) != 1
			|| !('0' <= split_views[i][0] && split_views[i][0] <= '9'))
		{
			ft_put_err(split_views[i]);
			ft_put_err(" is not a digit\n");
			return (1);
		}
		else
			views[i] = split_views[i][0] - '0';
		i++;
	}
	place_boxes(views, 4);
}

/*

"col1top col2top col3top col4top
col1bottom col2bottom col3bottom col4bottom 
row1left row2left row3left row4left 
row1right row2right row3right row4right"

*/

// "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"
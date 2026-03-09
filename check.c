/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejanga <alejanga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 13:13:17 by alejanga          #+#    #+#             */
/*   Updated: 2026/03/09 14:52:11 by alejanga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_invalid(int count, int size, int hint, int visible);

int	check_duplicate(int *board, int row, int col, int size)
{
	int		index;
	int		to_find;

	index = 0;
	to_find = board[row * size + col];
	while (index < size)
	{
		if (index != col && board[row * size + index] == to_find)
			return (1);
		if (index != row && board[index * size + col] == to_find)
			return (1);
		index++;
	}
	return (0);
}

int	check_top_hint(int *board, int *combination, int size, int col)
{
	int		index;
	int		max_height;
	int		visible;
	int		cell_count;

	index = 0;
	max_height = 0;
	visible = 0;
	cell_count = 0;
	while (index < size)
	{
		if (board[index * size + col] != -1)
		{
			cell_count++;
			if (board[index * size + col] > max_height)
			{
				max_height = board[index * size + col];
				visible++;
			}
		}
		index++;
	}
	return (is_invalid(cell_count, size, combination[col], visible));
}

int	check_bottom_hint(int *board, int *combination, int size, int col)
{
	int		index;
	int		max_height;
	int		visible;
	int		filled_count;

	index = size - 1;
	max_height = 0;
	visible = 0;
	filled_count = 0;
	while (index >= 0)
	{
		if (board[index * size + col] != -1)
		{
			filled_count++;
			if (board[index * size + col] > max_height)
			{
				max_height = board[index * size + col];
				visible++;
			}
		}
		index--;
	}
	if (filled_count == size && visible != combination[size + col])
		return (1);
	return (0);
}

int	check_left(int *board, int *combination, int size, int row)
{
	int		index;
	int		max_height;
	int		visible;
	int		cell_count;

	index = 0;
	max_height = 0;
	visible = 0;
	cell_count = 0;
	while (index < size)
	{
		if (board[row * size + index] != -1)
		{
			cell_count++;
			if (board[row * size + index] > max_height)
			{
				max_height = board[row * size + index];
				visible++;
			}
		}
		index++;
	}
	return (is_invalid(cell_count, size, combination[size * 2 + row], visible));
}

int	check_right(int *board, int *combination, int size, int row)
{
	int		index;
	int		max_height;
	int		visible;
	int		filled_count;

	index = size - 1;
	max_height = 0;
	visible = 0;
	filled_count = 0;
	while (index >= 0)
	{
		if (board[row * size + index] != -1)
		{
			filled_count++;
			if (board[row * size + index] > max_height)
			{
				max_height = board[row * size + index];
				visible++;
			}
		}
		index--;
	}
	if (filled_count == size && visible != combination[size * 3 + row])
		return (1);
	return (0);
}

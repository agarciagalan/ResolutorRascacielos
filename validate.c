/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejanga <alejanga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 13:30:37 by alejanga          #+#    #+#             */
/*   Updated: 2026/03/09 14:40:01 by alejanga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_duplicate(int *board, int row, int col, int size);
int		check_top_hint(int *board, int *comb, int size, int col);
int		check_bottom_hint(int *board, int *comb, int size, int col);
int		check_left(int *board, int *comb, int size, int row);
int		check_right(int *board, int *comb, int size, int row);

int	is_invalid(int count, int size, int hint, int visible)
{
	if (visible > hint)
		return (1);
	if (count == size && visible != hint)
		return (1);
	return (0);
}

int	validate_position(int *board, int size, int *combination, int position)
{
	int		col;
	int		row;

	row = position / size;
	col = position % size;
	if (check_duplicate(board, row, col, size))
		return (1);
	if (check_top_hint(board, combination, size, col))
		return (1);
	if (check_left(board, combination, size, row))
		return (1);
	if (check_right(board, combination, size, row))
		return (1);
	if (check_bottom_hint(board, combination, size, col))
		return (1);
	return (0);
}

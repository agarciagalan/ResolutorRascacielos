/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejanga <alejanga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 13:13:21 by alejanga          #+#    #+#             */
/*   Updated: 2026/03/09 16:51:02 by alejanga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		validate_position(int *board, int size, int *combination, int position);
void	print_board(int *board, int size);

int	solve(int *board, int size, int position, int *combination)
{
	int		option;

	if (position == size * size)
	{
		print_board(board, size);
		return (0);
	}
	if (board[position] != -1)
		return(solve(board, size, position + 1, combination));
	option = 1;
	while (option <= size)
	{
		board[position] = option;
		if (validate_position(board, size, combination, position) == 0)
		{
			if (solve(board, size, position + 1, combination) == 0)
				return (0);
		}
		(board)[position] = -1;
		option++;
	}
	return (1);
}

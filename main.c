/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejanga <alejanga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 13:13:23 by alejanga          #+#    #+#             */
/*   Updated: 2026/03/09 13:13:23 by alejanga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int		*create_board(int *board, int size);
int		get_combination(char *arg, int *combination, int size);
void	set_initial_values(int *board, int *combination, int size);
int		solve(int *board, int size, int position, int *combination);

int	main(int argc, char **argv)
{
	int		size;
	int		*board;
	int		*combination;

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	size = 7;
	combination = (int *)malloc(size * 4 * sizeof(int));
	get_combination(argv[1], combination, size);
	board = (int *)malloc(size * size * sizeof(int));
	create_board(board, size);
	set_initial_values(board, combination, size);
	if (solve(board, size, 0, combination))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	free(board);
	free(combination);
	return (0);
}

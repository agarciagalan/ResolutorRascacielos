/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combination.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejanga <alejanga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 13:13:42 by alejanga          #+#    #+#             */
/*   Updated: 2026/03/09 14:37:27 by alejanga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_combination(char *arg, int *combination, int size)
{
	int		arg_index;
	int		comb_index;

	arg_index = 0;
	comb_index = 0;
	while (arg[arg_index] != '\0')
	{
		if (arg[arg_index] >= '1' && arg[arg_index] <= '9')
		{
			(combination)[comb_index] = arg[arg_index] - '0';
			comb_index++;
		}
		arg_index++;
	}
	if (comb_index != size * 4)
		return (1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoporan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 14:19:03 by dsoporan          #+#    #+#             */
/*   Updated: 2016/07/17 18:30:56 by dsoporan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	point_to_zero(char mat[9][9])
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			if (mat[i][j] == '.')
				mat[i][j] = '0';
			j++;
		}
		i++;
	}
}

void	transformare(char mat[9][9])
{
	int i;
	int	j;

	i = 0;
	j = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			mat[i][j] = (int)(mat[i][j] - '0');
			j++;
		}
		i++;
	}
}

void	afisare(char mat[9][9])
{
	int i;
	int j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			mat[i][j] += '0';
			write(1, &mat[i][j], 1);
			if (j != 8)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int		col_row(char mat[9][9], int row, int col, int num)
{
	int j;

	j = 0;
	while (j < 9)
	{
		if ((mat[row][j] == num) || (mat[j][col] == num))
			return (0);
		j++;
	}
	return (1);
}

int		patrat(char mat[9][9], int row_start, int col_start, int num)
{
	int i;
	int j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			if (mat[row_start + i][col_start + j] == num)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

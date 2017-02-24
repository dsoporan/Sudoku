/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoporan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 14:07:00 by dsoporan          #+#    #+#             */
/*   Updated: 2016/07/17 18:29:22 by dsoporan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	point_to_zero(char mat[9][9]);
void	transformare(char mat[9][9]);
void	afisare(char mat[9][9]);
int		col_row(char mat[9][9], int row, int col, int num);
int		patrat(char mat[9][9], int row_start, int col_start, int num);
void	lines(char mat[9][9]);
int		verif(int argc, char **argv);

int		modulo(char mat[9][9], int row, int col, int num)
{
	return (col_row(mat, row, col, num) && (patrat(mat, row - (row % 3),
				col - (col % 3), num)));
}

int		liber(char mat[9][9], int *row, int *col)
{
	*row = 0;
	while (*row < 9)
	{
		*col = 0;
		while (*col < 9)
		{
			if (mat[*row][*col] == 0)
				return (0);
			(*col)++;
		}
		(*row)++;
	}
	return (1);
}

int		solve(char mat[9][9])
{
	int *row;
	int *col;
	int num;

	row = (int *)malloc(sizeof(int));
	col = (int *)malloc(sizeof(int));
	num = 1;
	if (liber(mat, row, col))
	{
		return (1);
	}
	while (num <= 9)
	{
		mat[*row][*col] = num;
		mat[*row][*col] = 0;
		if (modulo(mat, *row, *col, num) == 1)
		{
			mat[*row][*col] = num;
			if (solve(mat) == 1)
				return (1);
			mat[*row][*col] = 0;
		}
		num++;
	}
	return (0);
}

int		atribuire(int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (j < 9)
		{
			if (argv[i][j] != '.' && !(argv[i][j] >= '1' && argv[i][j] <= '9'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		main(int argc, char **argv)
{
	int		i;
	int		j;
	char	mat[9][9];

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (j < 9)
		{
			mat[i - 1][j] = argv[i][j];
			j++;
		}
		i++;
	}
	lines(mat);
	if ((argc != 10) || (atribuire(argc, argv) == 0) || verif(argc, argv) == 0)
	{
		write(1, "Erreur\n", 7);
		return (0);
	}
	afisare(mat);
	return (0);
}

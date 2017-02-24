/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku_extensie.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoporan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 16:24:01 by dsoporan          #+#    #+#             */
/*   Updated: 2016/07/17 18:28:38 by dsoporan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	point_to_zero(char mat[9][9]);
void	transformare(char mat[9][9]);
void	afisare(char mat[9][9]);
int		col_row(char mat[9][9], int row, int col, int num);
int		patrat(char mat[9][9], int row_start, int col_start, int num);
int		solve(char mat[9][9]);

int		verif(int argc, char **argv)
{
	int i;
	int j;
	int k;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (j < 9)
		{
			k = j + 1;
			while (k < 10)
			{
				if (argv[i][j] >= '1' && argv[i][j] <= '9' &&
						argv[i][k] >= '1' && argv[i][k] <= '9' &&
						argv[i][j] == argv[i][k])
					return (0);
				k++;
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	lines(char mat[9][9])
{
	point_to_zero(mat);
	transformare(mat);
	solve(mat);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_contutil_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabbar <asabbar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 15:53:16 by imittous          #+#    #+#             */
/*   Updated: 2022/02/20 18:19:04 by asabbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	checkpe(char **s)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	j = 0;
	n = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			if (s[i][j] == 'C')
				n++;
			j++;
		}
		i++;
	}
	return (n);
}

int	checkpx(char **s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			if (s[i][j] == 'P')
				break ;
			j++;
		}
		if (s[i][j] == 'P')
			break ;
		i++;
	}
	return (j);
}

int	checkpy(char **s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			if (s[i][j] == 'P')
				break ;
			j++;
		}
		if (s[i][j] == 'P')
			break ;
		i++;
	}
	return (i);
}

void	put_image_utils(t_var *move, int i, int j)
{
	if (move->map[i][j] == 'E')
	{
		if (!checkpe(move->map))
		{
			mlx_put_image_to_window(move->mlx, move->win,
				move->mlx_black, j * move->img_h, i * move->img_w);
			mlx_put_image_to_window(move->mlx, move->win,
				move->mlx_exit2, j * move->img_h, i * move->img_w);
		}
		else
			mlx_put_image_to_window(move->mlx, move->win,
				move->mlx_exit, j * move->img_h, i * move->img_w);
	}
	if (move->map[i][j] == '0')
		mlx_put_image_to_window(move->mlx, move->win,
			move->mlx_black, j * move->img_h, i * move->img_w);
}

void	put_image(t_var *move, int i, int j)
{
	i = -1;
	while (move->map[++i])
	{
		j = -1;
		while (move->map[i][++j])
		{
			if (move->map[i][j] == 'C')
				mlx_put_image_to_window(move->mlx, move->win, move->mlx_coin,
					j * move->img_h, i * move->img_w);
			else if (move->map[i][j] == '1')
				mlx_put_image_to_window(move->mlx, move->win, move->mlx_wall,
					j * move->img_h, i * move->img_w);
			else if (move->map[i][j] == 'P')
				mlx_put_image_to_window(move->mlx, move->win, move->mlx_player,
					j * move->img_h, i * move->img_w);
			put_image_utils(move, i, j);
		}
	}
}

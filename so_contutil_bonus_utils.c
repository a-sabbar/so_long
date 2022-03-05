/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_contutil_bonus_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabbar <asabbar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 15:53:16 by imittous          #+#    #+#             */
/*   Updated: 2022/02/22 10:29:02 by asabbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	move_db(t_vars *move, int i, int j)
{
	i = checkpy(move->map);
	j = checkpx(move->map);
	if (move->map[i][j + 1] == 'E' && !checkpe(move->map))
		ft_win();
	if (move->map[i][j + 1] == 'A')
		ft_exit();
	if (move->map[i][j + 1] == '1' || move->map[i][j + 1] == 'E')
		return (0);
	if (move->map[i][j + 1] == 'C')
	{
		move->map[i][j] = '0';
		move->map[i][j + 1] = 'P';
		mlx_put_image_to_window(move->mlx, move->win,
			move->mlx_black, (j + 1) * move->img_h, i * move->img_w);
		ft_count(move);
	}
	else
	{
		move->map[i][j] = '0';
		move->map[i][j + 1] = 'P';
		ft_count(move);
	}
	put_image_bounus(move, i, j);
	return (1);
}

int	move_ab(t_vars *move, int i, int j)
{
	i = checkpy(move->map);
	j = checkpx(move->map);
	if (move->map[i][j - 1] == 'E' && !checkpe(move->map))
		ft_win();
	if (move->map[i][j - 1] == 'A')
		ft_exit();
	if (move->map[i][j - 1] == '1' || move->map[i][j - 1] == 'E')
		return (0);
	if (move->map[i][j - 1] == 'C')
	{
		move->map[i][j] = '0';
		move->map[i][j - 1] = 'P';
		mlx_put_image_to_window(move->mlx, move->win,
			move->mlx_black, (j - 1) * move->img_h, i * move->img_w);
		ft_count(move);
	}
	else
	{
		move->map[i][j] = '0';
		move->map[i][j - 1] = 'P';
		ft_count(move);
	}
	put_image_bounus(move, i, j);
	return (1);
}

int	move_sb(t_vars *move, int i, int j)
{
	i = checkpy(move->map);
	j = checkpx(move->map);
	if (move->map[i + 1][j] == 'E' && !checkpe(move->map))
		ft_win();
	if (move->map[i + 1][j] == 'A')
		ft_exit();
	if (move->map[i + 1][j] == '1' || move->map[i + 1][j] == 'E')
		return (0);
	if (move->map[i + 1][j] == 'C')
	{
		move->map[i][j] = '0';
		move->map[i + 1][j] = 'P';
		mlx_put_image_to_window(move->mlx, move->win,
			move->mlx_black, j * move->img_h, (i + 1) * move->img_w);
		ft_count(move);
	}
	else
	{
		move->map[i][j] = '0';
		move->map[i + 1][j] = 'P';
		ft_count(move);
	}
	i = 0;
	put_image_bounus(move, i, j);
	return (1);
}

int	move_wb(t_vars *move, int i, int j)
{
	i = checkpy(move->map);
	j = checkpx(move->map);
	if (move->map[i - 1][j] == 'E' && !checkpe(move->map))
		ft_win();
	if (move->map[i - 1][j] == 'A')
		ft_exit();
	if (move->map[i - 1][j] == '1' || move->map[i - 1][j] == 'E')
		return (0);
	if (move->map[i - 1][j] == 'C')
	{
		move->map[i][j] = '0';
		move->map[i - 1][j] = 'P';
		mlx_put_image_to_window(move->mlx, move->win,
			move->mlx_black, j * move->img_h, (i -1) * move->img_w);
		ft_count(move);
	}
	else
	{
		move->map[i][j] = '0';
		move->map[i - 1][j] = 'P';
		ft_count(move);
	}
	put_image_bounus(move, i, j);
	return (1);
}

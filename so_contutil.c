/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_contutil.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabbar <asabbar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 15:53:16 by imittous          #+#    #+#             */
/*   Updated: 2022/02/22 10:23:21 by asabbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_d(t_var *move, int i, int j)
{
	i = checkpy(move->map);
	j = checkpx(move->map);
	if (move->map[i][j + 1] == 'E' && !checkpe(move->map))
		ft_win();
	if (move->map[i][j + 1] == '1' || move->map[i][j + 1] == 'E')
		return (0);
	if (move->map[i][j + 1] == 'C')
	{
		move->map[i][j] = '0';
		move->map[i][j + 1] = 'P';
		mlx_put_image_to_window(move->mlx, move->win,
			move->mlx_black, (j + 1) * move->img_h, i * move->img_w);
		ft_count_m(move);
	}
	else
	{
		move->map[i][j] = '0';
		move->map[i][j + 1] = 'P';
		ft_count_m(move);
	}
	put_image(move, i, j);
	return (1);
}

int	move_a(t_var *move, int i, int j)
{
	i = checkpy(move->map);
	j = checkpx(move->map);
	if (move->map[i][j - 1] == 'E' && !checkpe(move->map))
		ft_win();
	if (move->map[i][j - 1] == '1' || move->map[i][j - 1] == 'E')
		return (0);
	if (move->map[i][j - 1] == 'C')
	{
		move->map[i][j] = '0';
		move->map[i][j - 1] = 'P';
		mlx_put_image_to_window(move->mlx, move->win,
			move->mlx_black, (j - 1) * move->img_h, i * move->img_w);
		ft_count_m(move);
	}
	else
	{
		move->map[i][j] = '0';
		move->map[i][j - 1] = 'P';
		ft_count_m(move);
	}
	put_image(move, i, j);
	return (1);
}

int	move_s(t_var *move, int i, int j)
{
	i = checkpy(move->map);
	j = checkpx(move->map);
	if (move->map[i + 1][j] == 'E' && !checkpe(move->map))
		ft_win();
	if (move->map[i + 1][j] == '1' || move->map[i + 1][j] == 'E')
		return (0);
	if (move->map[i + 1][j] == 'C')
	{
		move->map[i][j] = '0';
		move->map[i + 1][j] = 'P';
		mlx_put_image_to_window(move->mlx, move->win,
			move->mlx_black, j * move->img_h, (i + 1) * move->img_w);
		ft_count_m(move);
	}
	else
	{
		move->map[i][j] = '0';
		move->map[i + 1][j] = 'P';
		ft_count_m(move);
	}
	i = 0;
	put_image(move, i, j);
	return (1);
}

int	move_w(t_var *move, int i, int j)
{
	i = checkpy(move->map);
	j = checkpx(move->map);
	if (move->map[i - 1][j] == 'E' && !checkpe(move->map))
		ft_win();
	if (move->map[i - 1][j] == '1' || move->map[i - 1][j] == 'E')
		return (0);
	if (move->map[i - 1][j] == 'C')
	{
		move->map[i][j] = '0';
		move->map[i - 1][j] = 'P';
		mlx_put_image_to_window(move->mlx, move->win,
			move->mlx_black, j * move->img_h, (i -1) * move->img_w);
		ft_count_m(move);
	}
	else
	{
		move->map[i][j] = '0';
		move->map[i - 1][j] = 'P';
		ft_count_m(move);
	}
	put_image(move, i, j);
	return (1);
}

int	ft_mouvment(int key, void *parm)
{
	int		i;
	int		j;
	t_var	*move;

	move = (t_var *)parm;
	i = checkpy(move->map);
	j = checkpx(move->map);
	if (key == KEY_W)
		move_w(move, i, j);
	else if (key == KEY_S)
		move_s(move, i, j);
	else if (key == KEY_D)
		move_d(move, i, j);
	else if (key == KEY_A)
		move_a(move, i, j);
	else if (key == KEY_ESC)
		exit(0);
	return (1);
}

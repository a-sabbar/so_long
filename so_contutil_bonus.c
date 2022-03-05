/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_contutil_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabbar <asabbar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 15:53:16 by imittous          #+#    #+#             */
/*   Updated: 2022/02/22 10:29:09 by asabbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_image_bounus_utils(t_vars *move, int i, int j)
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

void	put_image_bounus(t_vars *move, int i, int j)
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
			put_image_bounus_utils(move, i, j);
		}
	}
}

int	ft_mouvment_bonus(int key, void *parm)
{
	int		i;
	int		j;
	t_vars	*move;

	move = (t_vars *)parm;
	i = checkpy(move->map);
	j = checkpx(move->map);
	if (key == KEY_W)
		move_wb(move, i, j);
	else if (key == KEY_S)
		move_sb(move, i, j);
	else if (key == KEY_D)
		move_db(move, i, j);
	else if (key == KEY_A)
		move_ab(move, i, j);
	else if (key == KEY_ESC)
		exit(0);
	return (1);
}

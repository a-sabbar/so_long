/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabbar <asabbar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 11:48:33 by asabbar           #+#    #+#             */
/*   Updated: 2022/02/22 10:30:49 by asabbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_anima_utils(t_vars *move)
{
	if ((move->map[move->i_img][move->j_img + 1] == '0'
		|| move->map[move->i_img][move->j_img + 1] == 'P') && move->n2 == 1)
	{
		if (move->map[move->i_img][move->j_img + 1] == 'P')
			ft_exit();
		move->map[move->i_img][move->j_img] = '0';
		move->map[move->i_img][move->j_img + 1] = 'A';
		move->j_img++;
	}
	else if ((move->map[move->i_img][move->j_img - 1] == '0'
		|| move->map[move->i_img][move->j_img - 1] == 'P') && move->n2 == 0)
	{
		if (move->map[move->i_img][move->j_img - 1] == 'P')
			ft_exit();
		move->map[move->i_img][move->j_img] = '0';
		move->map[move->i_img][move->j_img - 1] = 'A';
		move->j_img--;
	}
}

void	move_anima(t_vars *move)
{
	if ((move->map[move->i_img + 1][move->j_img] == '0'
		|| move->map[move->i_img + 1][move->j_img] == 'P') && move->n2 == 0)
	{
		if (move->map[move->i_img + 1][move->j_img] == 'P')
			ft_exit();
		move->map[move->i_img][move->j_img] = '0';
		move->map[move->i_img + 1][move->j_img] = 'A';
		move->i_img++;
	}
	else if ((move->map[move->i_img - 1][move->j_img] == '0'
		|| move->map[move->i_img - 1][move->j_img] == 'P') && move->n2 == 1)
	{
		if (move->map[move->i_img - 1][move->j_img] == 'P')
			ft_exit();
		move->map[move->i_img][move->j_img] = '0';
		move->map[move->i_img - 1][move->j_img] = 'A';
		move->i_img--;
	}
	else
		move_anima_utils(move);
}

void	ft_animation(t_vars *move)
{
	if (move->n <= 10)
		mlx_put_image_to_window(move->mlx, move->win,
			move->mlx_anima1, move->j_img * move->img_h,
			move->i_img * move->img_w);
	else if (move->n >= 10 && move->n <= 20)
		mlx_put_image_to_window(move->mlx, move->win,
			move->mlx_anima, move->j_img * move->img_h,
			move->i_img * move->img_w);
	else if (move->n >= 20 && move->n <= 30)
		mlx_put_image_to_window(move->mlx, move->win,
			move->mlx_anima1, move->j_img * move->img_h,
			move->i_img * move->img_w);
	else if (move->n >= 30 && move->n < 40)
		mlx_put_image_to_window(move->mlx, move->win,
			move->mlx_anima, move->j_img * move->img_h,
			move->i_img * move->img_w);
	else if (move->n == 40)
		move->n = 0;
	move->n++;
}

void	put_img_bonus_util(t_vars *move)
{
	if (move->map[move->i_img][move->j_img] == 'E')
	{
		if (!checkpe(move->map))
		{
			mlx_put_image_to_window(move->mlx, move->win,
				move->mlx_black, move->j_img * move->img_h,
				move->i_img * move->img_w);
			mlx_put_image_to_window(move->mlx, move->win,
				move->mlx_exit2, move->j_img * move->img_h,
				move->i_img * move->img_w);
		}
		else
			mlx_put_image_to_window(move->mlx, move->win,
				move->mlx_exit, move->j_img * move->img_h,
				move->i_img * move->img_w);
	}
	if (move->map[move->i_img][move->j_img] == 'A')
		move_anima(move);
	if (move->map[move->i_img][move->j_img] == 'A')
		ft_animation(move);
	if (move->map[move->i_img][move->j_img] == '0')
		mlx_put_image_to_window(move->mlx, move->win,
			move->mlx_black, move->j_img * move->img_h,
			move->i_img * move->img_w);
}

void	put_img_bonus(t_vars *move)
{
	move->i_img = -1;
	while (move->map[++move->i_img])
	{
		move->j_img = -1;
		while (move->map[move->i_img][++move->j_img])
		{
			if (move->map[move->i_img][move->j_img] == 'C')
				mlx_put_image_to_window(move->mlx, move->win, move->mlx_coin,
					move->j_img * move->img_h, move->i_img * move->img_w);
			else if (move->map[move->i_img][move->j_img] == '1')
				mlx_put_image_to_window(move->mlx, move->win, move->mlx_wall,
					move->j_img * move->img_h, move->i_img * move->img_w);
			else if (move->map[move->i_img][move->j_img] == 'P')
				mlx_put_image_to_window(move->mlx, move->win, move->mlx_player,
					move->j_img * move->img_h, move->i_img * move->img_w);
			put_img_bonus_util(move);
		}
	}	
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xpm_to_image.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabbar <asabbar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 15:41:57 by asabbar           #+#    #+#             */
/*   Updated: 2022/02/22 10:28:40 by asabbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	close1(int key, void *parm)
{
	(void)key;
	(void)parm;
	exit(0);
}

int	ft_mouvment_bonus1(t_vars *move)
{
	char	*count;

	move->n2 = arc4random() % 20;
	put_img_bonus(move);
	count = ft_itoa(move->i);
	mlx_string_put(move->mlx, move->win, 99, 1, 0, "counter : ");
	mlx_string_put(move->mlx, move->win, 99, 2, 0, "counter : ");
	mlx_string_put(move->mlx, move->win, 250, 1, 0, count);
	mlx_string_put(move->mlx, move->win, 250, 2, 0, count);
	free(count);
	return (1);
}

void	ft_fre(char **cmd)
{
	int	i;

	i = -1;
	while (cmd[++i])
		free(cmd[i]);
	free(cmd);
}

void	ft_xpm_utils(t_vars *mouve)
{
	mouve->mlx_black = mlx_xpm_file_to_image(mouve->mlx, "img/black.xpm",
			&mouve->img_w, &mouve->img_h);
	mouve->mlx_coin = mlx_xpm_file_to_image(mouve->mlx, "img/coin1.xpm",
			&mouve->img_w, &mouve->img_h);
	mouve->mlx_player = mlx_xpm_file_to_image(mouve->mlx, "img/player.xpm",
			&mouve->img_w, &mouve->img_h);
	mouve->mlx_exit = mlx_xpm_file_to_image(mouve->mlx, "img/exit2.xpm",
			&mouve->img_w, &mouve->img_h);
	mouve->mlx_exit2 = mlx_xpm_file_to_image(mouve->mlx, "img/exit3.xpm",
			&mouve->img_w, &mouve->img_h);
	mouve->mlx_wall = mlx_xpm_file_to_image(mouve->mlx, "img/wall2.xpm",
			&mouve->img_w, &mouve->img_h);
	mouve->mlx_anima = mlx_xpm_file_to_image(mouve->mlx, "img/N5.xpm",
			&mouve->img_w, &mouve->img_h);
	mouve->mlx_anima1 = mlx_xpm_file_to_image(mouve->mlx, "img/N6.xpm",
			&mouve->img_w, &mouve->img_h);
	mouve->mlx_anima2 = mlx_xpm_file_to_image(mouve->mlx, "img/N7.xpm",
			&mouve->img_w, &mouve->img_h);
	mouve->mlx_anima3 = mlx_xpm_file_to_image(mouve->mlx, "img/N8.xpm",
			&mouve->img_w, &mouve->img_h);
}

void	ft_xpm_to_image(t_vars mouve)
{
	mouve.mlx = mlx_init();
	ft_xpm_utils(&mouve);
	mouve.win = mlx_new_window(mouve.mlx,
			(mouve.j) * 60, (mouve.i) * 60, "./so_long");
	mouve.i = 0;
	put_image_bounus(&mouve, mouve.i, mouve.j);
	mlx_hook(mouve.win, 2, 1L << 2, ft_mouvment_bonus, &mouve);
	mlx_hook(mouve.win, EVENT_CLOSE, 0L, close1, &mouve);
	mlx_loop_hook(mouve.mlx, ft_mouvment_bonus1, &mouve);
	mlx_loop(mouve.mlx);
	ft_fre (mouve.map);
}

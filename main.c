/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabbar <asabbar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 17:38:15 by asabbar           #+#    #+#             */
/*   Updated: 2022/02/24 17:40:31 by asabbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close1(int key, void *parm)
{
	(void)key;
	(void)parm;
	exit(0);
}

void	ft_fre(char **cmd)
{
	int	i;

	i = -1;
	while (cmd[++i])
		free(cmd[i]);
	free(cmd);
}

void	ft_checkmain(char **av, t_var *mouve)
{
	char	*str;
	int		fd;

	fd = open(av[1], O_RDONLY, 0777);
	printf("%d", fd);
	if (fd == -1)
	{
		ft_putstr("error!!!!!!!!\n");
		exit (1);
	}
	str = ft_strchar(av[1], '.');
	if (!str || ft_strcmp(".ber", str))
	{
		ft_putstr("error name file!!\n");
		exit (1);
	}
	mouve->map = check_map(fd);
}

void	mlx_xpm_utils(t_var *mouve)
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
	mouve->mlx_anima = mlx_xpm_file_to_image(mouve->mlx, "img/animation.xpm",
			&mouve->img_w, &mouve->img_h);
	mouve->i = 0;
	ft_putstr("counter : ");
	ft_putnbr(mouve->i);
	ft_putstr("\n");
	mouve->i++;
}

int	main(int ac, char **av)
{
	t_var	mouve;

	if (ac != 2)
		return (ft_putstr("error!!\n"), 1);
	ft_checkmain(av, &mouve);
	mouve.mlx = mlx_init();
	mouve.i = 0;
	mouve.j = 0;
	while (mouve.map[mouve.i])
	{
		mouve.j = 0;
		while (mouve.map[mouve.i][mouve.j])
			mouve.j++;
		mouve.i++;
	}
	mouve.win = mlx_new_window(mouve.mlx,
			(mouve.j) * 
			60, (mouve.i) * 60, "txt");
	mlx_xpm_utils(&mouve);
	put_image(&mouve, mouve.i, mouve.j);
	mlx_hook(mouve.win, 2, 1L << 2, ft_mouvment, &mouve);
	mlx_hook(mouve.win, EVENT_CLOSE, 0L, close1, &mouve);
	mlx_loop(mouve.mlx);
	ft_fre (mouve.map);
}

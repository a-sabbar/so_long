/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabbar <asabbar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 17:38:15 by asabbar           #+#    #+#             */
/*   Updated: 2022/02/22 10:30:06 by asabbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_checkmain(char **av, t_vars *mouve)
{
	char	*str;
	int		fd;

	fd = open(av[1], O_RDONLY, 0777);
	if (fd == -1)
	{
		ft_putstr("error!!\n");
		exit (1);
	}
	str = ft_strchar(av[1], '.');
	if (!str)
	{
		ft_putstr("error name file!!\n");
		exit (1);
	}
	if (ft_strcmp(".ber", str))
	{
		ft_putstr("error name file!!\n");
		exit (1);
	}
	mouve->map = check_map_bonus(fd);
}

int	main(int ac, char **av)
{
	t_vars	mouve;

	if (ac != 2)
		return (ft_putstr("error in arguments!!\n"), 1);
	ft_checkmain(av, &mouve);
	mouve.i = 0;
	mouve.j = 0;
	while (mouve.map[mouve.i])
	{
		mouve.j = 0;
		while (mouve.map[mouve.i][mouve.j])
			mouve.j++;
		mouve.i++;
	}
	mouve.n = 0;
	ft_xpm_to_image(mouve);
}

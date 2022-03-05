/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_utils1_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabbar <asabbar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 12:46:15 by asabbar           #+#    #+#             */
/*   Updated: 2022/02/22 10:28:54 by asabbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_freexit(char *str)
{
	free(str);
	exit (1);
}

void	ft_freexit2(char **s, char *str)
{
	ft_fre(s);
	if (str)
	{
		ft_putstr(str);
		ft_putstr("\n");
	}
	exit (1);
}

void	ft_win(void)
{
	ft_putstr ("----YOU WIN----\n\n");
	exit(1);
}

void	ft_count(t_vars *move)
{
	move->i++;
}

void	ft_exit(void)
{
	ft_putstr ("----Game Over----\n\n");
	exit(0);
}

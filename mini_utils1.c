/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabbar <asabbar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 12:46:15 by asabbar           #+#    #+#             */
/*   Updated: 2022/02/22 10:22:28 by asabbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	ft_count_m(t_var *move)
{
	move->i++;
	ft_putstr("counter : ");
	ft_putnbr(move->i);
	ft_putstr("\n");
}

void	ft_exit(void)
{
	ft_putstr ("----Game Over----\n\n");
	exit(0);
}

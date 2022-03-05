/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabbar <asabbar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:36:19 by asabbar           #+#    #+#             */
/*   Updated: 2022/02/22 10:16:46 by asabbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	numberof_p(char **str)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'P')
				len++;
			j++;
		}
		i++;
	}
	if (len != 1)
		return (ft_putstr("error in number of  P\n"), 0);
	return (1);
}

int	numberof_e(char **str)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'E')
				len++;
			j++;
		}
		i++;
	}
	if (len == 0)
		return (ft_putstr("error in number of  E\n"), 0);
	return (1);
}

int	numberof_c(char **str)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'C')
				len++;
			j++;
		}
		i++;
	}
	if (len == 0)
		return (ft_putstr("error in number of  C\n"), 0);
	return (1);
}

int	checklen(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (ft_strlen(s[0]) == ft_strlen(s[i]))
			i++;
		else
			return (0);
	}
	return (ft_strlen(s[0]));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabbar <asabbar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 09:51:38 by asabbar           #+#    #+#             */
/*   Updated: 2022/02/22 10:25:06 by asabbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*ft_strchar(char *str, char c)
{
	int	i;

	i = 0;
	while (i <= ft_strlen(str))
	{
		if (str[i] == c)
			return (&str[i]);
		i++;
	}
	return (0);
}

int	numberof_a(char **str)
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
			if (str[i][j] == 'A')
				len++;
			j++;
		}
		i++;
	}
	if (len == 0)
		return (ft_putstr("error in number of  A"), 0);
	return (1);
}

int	ifcheck(char **s, int j)
{
	int	i;

	i = 1;
	if (!check1(s[--j], '1'))
		return (ft_putstr("you need 1 in last line\n"), 0);
	while (--j)
	{
		if (!check2(s[i]))
			return (0);
		i++;
	}
	if (!numberof_p(s))
		return (0);
	if (!numberof_c(s))
		return (0);
	if (!numberof_e(s))
		return (0);
	if (!numberof_a(s))
		return (0);
	return (1);
}

void	checkerror(char **s, int j, int len)
{
	if (!len)
	{
		ft_putstr("error checklen");
		free(s);
		exit (0);
	}
	if (!check1(s[0], '1'))
	{
		ft_putstr("you need 1 in first line");
		free(s);
		exit (0);
	}
	if (!ifcheck(s, j))
	{
		free(s);
		exit (0);
	}
}

char	**check_map_bonus(int fd)
{
	int		j;
	int		len;
	char	*str;
	char	**s;

	str = (char *)malloc(1 * sizeof(char));
	str[0] = '\0';
	str = ft_read_bonus(str, fd);
	if (!str)
		ft_freexit(str);
	s = ft_split(str, '\n');
	free(str);
	j = 0;
	while (s[j])
		j++;
	len = checklen(s);
	if (!len)
		ft_freexit2(s, "error in len of lines");
	if (!check1(s[0], '1'))
		ft_freexit2(s, "you need 1 in first line");
	if (!ifcheck(s, j))
		ft_freexit2(s, "");
	return (s);
}

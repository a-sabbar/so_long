/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabbar <asabbar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:42:36 by asabbar           #+#    #+#             */
/*   Updated: 2022/02/22 10:25:35 by asabbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check1(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			i++;
		else
			return (0);
	}
	return (1);
}

int	check2(char *str)
{
	int	i;
	int	len;

	i = 1;
	len = ft_strlen(str);
	if (str[0] != '1')
		return (ft_putstr("error first it's not 1\n"), 0);
	if (str[--len] != '1')
		return (ft_putstr("error last it's not 1\n"), 0);
	return (1);
}

void	ft_min_check2(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '0' || s[i] == 'P' || s[i] == '1'
			|| s[i] == 'C' || s[i] == 'E' || s[i] == '\n')
			i++;
		else
		{
			ft_putstr("error { ");
			ft_putchar(s[i]);
			ft_putstr(" }\n");
			exit(1);
		}
	}
}

int	ft_min_check(char *rest, int j)
{
	if (rest[0] == '\n')
		return (ft_putstr("error new line in the first\n"), 0);
	if (rest[j] == '\n' && (rest[j + 1] == '\n' || rest[j + 1] == '\0'))
		return (ft_putstr("error in line or NULL\n"), 0);
	return (1);
}

char	*ft_read(char *rest, int fd)
{
	int		i;
	int		j;
	char	*s;

	s = malloc(2);
	if (!s)
		return (NULL);
	i = 1;
	j = -1;
	while (i)
	{
		i = read(fd, s, 1);
		if (i == -1 || !s)
			return (free(s), NULL);
		s[i] = '\0';
		rest = ft_strjoin(rest, s);
		if (!ft_min_check(rest, j))
			return (0);
		ft_min_check2(rest);
		j++;
	}
	free(s);
	if (!ft_strchr(rest, '\n'))
		return (ft_putstr("The map is not complete\n"), NULL);
	return (rest);
}

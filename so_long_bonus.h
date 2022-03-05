/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabbar <asabbar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 09:15:41 by asabbar           #+#    #+#             */
/*   Updated: 2022/02/22 10:29:28 by asabbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <time.h>
# include <fcntl.h>
# include <mlx.h>
# define KEY_W 13
# define KEY_D 2
# define KEY_A 0
# define KEY_S 1
# define KEY_ESC 53
# define EVENT_CLOSE 17

typedef struct s_vars {
	void	*mlx;
	void	*win;
	char	**map;
	int		img_w;
	int		img_h;
	void	*mlx_coin;
	void	*mlx_wall;
	void	*mlx_player;
	void	*mlx_anima;
	void	*mlx_anima1;
	void	*mlx_anima2;
	void	*mlx_anima3;
	void	*mlx_exit;
	void	*mlx_black;
	void	*mlx_exit2;
	int		i;
	int		j;
	int		n;
	int		n2;
	int		i_img;
	int		j_img;
}	t_vars;

void	ft_fre(char **cmd);
int		checki0(char **s);
int		checkj0(char **s);
int		checkpe(char **s);
int		numberof_p(char **str);
int		numberof_e(char **str);
int		numberof_c(char **str);
int		numberof0(char **str);
int		checklen(char **s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *s);
int		check1(char *str, char c);
int		check2(char *str);
char	*ft_read(char *rest, int fd);
char	**ft_split(char *s, char c);
char	**check_map(int fd);
char	*ft_strchar(char *str, char c);
int		ft_strcmp(char *str1, char *str2);
int		ft_mouvment(int key, void *parm);
void	put_image(t_vars *move, int i, int j);
void	put_image_bounus(t_vars *move, int i, int j);
int		ft_mouvment_bonus(int key, void *parm);
int		randomn(int *i);
char	**check_map_bonus(int fd);
void	ft_min_check2_bonus(char *s);
char	*ft_read_bonus(char *rest, int fd);
void	ft_fre(char **cmd);
char	*ft_itoa(int n);
char	*move(char *s1, char *s2, char *s);
void	ft_xpm_to_image(t_vars mouve);
int		numberof_a(char **str);
void	put_img_bonus(t_vars *move);
void	ft_exit(void);
void	ft_count(t_vars *move);
void	ft_win(void);
int		checkpy(char **s);
int		checkpx(char **s);
int		checkpe(char **s);
void	move_anima(t_vars *move);
void	ft_freexit2(char **s, char *str);
void	ft_freexit(char *str);
void	ft_freexit(char *str);
void	ft_freexit2(char **s, char *str);
int		a_check(char **s);
int		move_wb(t_vars *move, int i, int j);
int		move_sb(t_vars *move, int i, int j);
int		move_db(t_vars *move, int i, int j);
int		move_ab(t_vars *move, int i, int j);
void	ft_putstr(char	*c);
void	ft_putnbr(int nb);
void	ft_putchar(char c);

#endif
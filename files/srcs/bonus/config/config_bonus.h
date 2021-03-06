/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 12:36:17 by mmateo-t          #+#    #+#             */
/*   Updated: 2020/07/18 12:47:17 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_BONUS_H
# define CONFIG_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../../../lib/libft/libft.h"
# include "../../../lib/get_next_line/get_next_line.h"

# define MAX_WIDTH   1920
# define MAX_HEIGHT  1080
# define MIN_WIDTH   320
# define MIN_HEIGHT  200
# define NUM_CONFIG  10

typedef struct		s_resolution
{
	int				x;
	int				y;
}					t_resolution;

typedef struct		s_color
{
	int				rgb[3];
	char			*rgb_hex;
	int				rgb_int;
}					t_color;

typedef struct		s_map
{
	int				n_row;
	int				n_col;
	char			*buff;
	char			**world_map;
}					t_map;

typedef struct		s_config
{
	t_resolution	r;
	t_color			f;
	t_color			c;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*s1;
	char			*ct;
	char			*ft;
	char			*tx1;
	char			*tx2;
	char			*s2;
	t_map			map;
	int				counter;
	int				pos_x;
	int				pos_y;
	char			dir;
	int				save;
	int				is_tex;
}					t_config;

t_config			g_config;

int					create_window();
void				read_map(int fd);
int					read_config(char *argv);
t_resolution		save_resolution(char *line);
void				throw_error(const char *str);
int					is_digit(char *str);
int					check_len(char **aux, int num);
t_color				save_color(char *line, char *position);
void				free_str(char **str);
char				*save_texture(char *line);
int					check_arg(int argc, char **argv);
char				*pad_right(char c, int len);
char				**parse_map();
int					check_map(char **map, int row, int col);
char				**copy_matrix(int m, char **array);

#endif

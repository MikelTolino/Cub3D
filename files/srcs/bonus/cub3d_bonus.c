/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 12:16:45 by mmateo-t          #+#    #+#             */
/*   Updated: 2020/07/18 12:16:56 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	hooks(t_engine en)
{
	mlx_hook(en.mlx.win, 2, 1, key_press, &en);
	mlx_hook(en.mlx.win, 3, 2, key_release, &en);
	mlx_hook(en.mlx.win, 17, 1L << 17, exit_game, &en);
	mlx_loop_hook(en.mlx.ptr, gameloop, &en);
	mlx_loop(en.mlx.ptr);
}

int		main(int argc, char **argv)
{
	t_engine en;

	check_arg(argc, argv);
	read_config(argv[1]);
	create_window(&en);
	init(&en);
	gameloop(&en);
	hooks(en);
	return (0);
}

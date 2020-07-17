/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameloop_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 14:01:42 by mmateo-t          #+#    #+#             */
/*   Updated: 2020/07/17 23:12:56 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

static void		destroy_create_image(t_engine *en)
{
	mlx_destroy_image(en->mlx.ptr, en->mlx.img.ptr);
	en->mlx.img.ptr = mlx_new_image(en->mlx.ptr, g_config.R.x, g_config.R.y);
	en->mlx.img.data = (int*)mlx_get_data_addr(en->mlx.img.ptr,
	&en->mlx.img.bpp, &en->mlx.img.endian, &en->mlx.img.size_line);
}

int				gameloop(t_engine *en)
{
	char *fps;

	movement(en);
	floor_casting(en);
	raycasting(en);
	sprite_casting(en);
	fps = get_time(en);
	mlx_put_image_to_window(en->mlx.ptr, en->mlx.win, en->mlx.img.ptr, 0, 0);
	mlx_string_put(en->mlx.ptr, en->mlx.win, 20, 20, rgb_int(255, 255, 255), fps);
	if (g_config.save)
	{
		save_bmp(en);
		exit_game(en);
	}
	usleep(10000);
	destroy_create_image(en);
	free(fps);
	return (0);
}

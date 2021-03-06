/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 18:25:58 by miguel            #+#    #+#             */
/*   Updated: 2020/07/18 13:11:05 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	create_window(t_engine *en)
{
	if (!((en->mlx.ptr = mlx_init())))
		throw_error("Failed minilibx connection");
	if (!(en->mlx.win = mlx_new_window(en->mlx.ptr, g_config.r.x,
	g_config.r.y, "cub3D")))
		throw_error("There was a problem with window creation");
	if (!(en->mlx.img.ptr = mlx_new_image(en->mlx.ptr,
	g_config.r.x, g_config.r.y)))
		throw_error("Image cannot be created");
	en->mlx.img.data = (int *)mlx_get_data_addr(en->mlx.img.ptr,
	&en->mlx.img.bpp, &en->mlx.img.size_line, &en->mlx.img.endian);
	return (0);
}

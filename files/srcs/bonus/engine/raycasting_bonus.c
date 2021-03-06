/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 13:57:17 by mmateo-t          #+#    #+#             */
/*   Updated: 2020/07/18 13:27:44 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

static void	dda(t_engine *en)
{
	while (en->hit == 0)
	{
		if (en->side_dist.x < en->side_dist.y)
		{
			en->side_dist.x += en->delta_dist.x;
			en->map_x += en->step_x;
			en->side = 0;
		}
		else
		{
			en->side_dist.y += en->delta_dist.y;
			en->map_y += en->step_y;
			en->side = 1;
		}
		if (g_config.map.world_map[en->map_x][en->map_y] == '1' ||
		g_config.map.world_map[en->map_x][en->map_y] == '3' ||
		g_config.map.world_map[en->map_x][en->map_y] == '4')
			en->hit = 1;
	}
	if (en->side == 0)
		en->perp_wall_dist = (en->map_x - en->pos.x + (1 - en->step_x) / 2)
		/ en->ray_dir.x;
	else
		en->perp_wall_dist = (en->map_y - en->pos.y + (1 - en->step_y) / 2)
		/ en->ray_dir.y;
}

static void	calc_pixel(t_engine *en)
{
	en->line_height = (int)(g_config.r.y / en->perp_wall_dist);
	en->draw_start = -(en->line_height) / 2 + g_config.r.y / 2;
	if (en->draw_start < 0)
		en->draw_start = 0;
	en->draw_end = en->line_height / 2 + g_config.r.y / 2;
	if (en->draw_end >= g_config.r.y)
		en->draw_end = g_config.r.y - 1;
}

static void	steps_initial_dist(t_engine *en)
{
	if (en->ray_dir.x < 0)
	{
		en->step_x = -1;
		en->side_dist.x = (en->pos.x - en->map_x) * en->delta_dist.x;
	}
	else
	{
		en->step_x = 1;
		en->side_dist.x = (en->map_x + 1.0 - en->pos.x) * en->delta_dist.x;
	}
	if (en->ray_dir.y < 0)
	{
		en->step_y = -1;
		en->side_dist.y = (en->pos.y - en->map_y) * en->delta_dist.y;
	}
	else
	{
		en->step_y = 1;
		en->side_dist.y = (en->map_y + 1.0 - en->pos.y) * en->delta_dist.y;
	}
}

static void	init_calc(t_engine *en, int x)
{
	en->camera.x = 2 * x / (double)g_config.r.x - 1;
	en->ray_dir.x = en->dir.x + en->plane.x * en->camera.x;
	en->ray_dir.y = en->dir.y + en->plane.y * en->camera.x;
	en->map_x = (int)en->pos.x;
	en->map_y = (int)en->pos.y;
	en->delta_dist.x = fabs(1 / en->ray_dir.x);
	en->delta_dist.y = fabs(1 / en->ray_dir.y);
	en->hit = 0;
}

int			raycasting(t_engine *en)
{
	int x;

	x = 0;
	while (x < g_config.r.x)
	{
		init_calc(en, x);
		steps_initial_dist(en);
		dda(en);
		calc_pixel(en);
		get_texture(en);
		en->z_buff[x] = en->perp_wall_dist;
		draw(en, x);
		x++;
	}
	return (0);
}

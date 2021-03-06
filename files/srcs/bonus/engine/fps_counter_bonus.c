/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps_counter_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 13:22:32 by mmateo-t          #+#    #+#             */
/*   Updated: 2020/07/18 13:22:34 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

char		*get_time(t_engine *en)
{
	double	frame_time;
	char	*buff;

	buff = malloc(sizeof(char) * 6);
	en->fps.old_time = en->fps.time;
	en->fps.time = clock();
	frame_time = (double)(en->fps.time - en->fps.old_time) / CLOCKS_PER_SEC;
	en->fps.counter = (1.0 / frame_time);
	en->fps.average += en->fps.counter;
	en->fps.num++;
	if (en->fps.counter > en->fps.max)
		en->fps.max = en->fps.counter;
	if (en->fps.counter < en->fps.min)
		en->fps.min = en->fps.counter;
	gcvt(en->fps.counter, 6, buff);
	en->move_speed = frame_time * 5;
	en->rot_speed = frame_time * 3;
	return (buff);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_texture_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 00:27:38 by miguel            #+#    #+#             */
/*   Updated: 2020/07/18 02:40:40 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config_bonus.h"

char		*save_texture(char *line)
{
	char	**num_str;
	char	*filename;

	num_str = ft_split(line, ' ');
	check_len(num_str, 2);
	filename = ft_strdup(num_str[1]);
	free_str(num_str);
	g_config.counter++;
	return (filename);
}

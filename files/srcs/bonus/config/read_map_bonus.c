/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 12:34:47 by mmateo-t          #+#    #+#             */
/*   Updated: 2020/07/22 13:22:04 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config_bonus.h"

int			is_map(char *line)
{
	unsigned int i;

	i = 0;
	if (!*line)
		return (0);
	while (line[i] == ' ' || line[i] == '1' || line[i] == '2' || line[i] == '0'
	|| line[i] == 'N' || line[i] == 'S' || line[i] == 'E' || line[i] == 'W' ||
	line[i] == '3' || line[i] == '4' || line[i] == '5')
		i++;
	if (i == ft_strlen(line))
		return (1);
	else
		return (0);
}

static void	calculate_map(char *line, int end, char *aux, int c_len)
{
	if (is_map(line))
	{
		aux = ft_strjoin(g_config.map.buff, line);
		free(g_config.map.buff);
		g_config.map.buff = aux;
		if (end)
		{
			aux = ft_strjoin(g_config.map.buff, "\n");
			free(g_config.map.buff);
			g_config.map.buff = aux;
		}
		g_config.map.n_row++;
		c_len = ft_strlen(line);
		if (c_len > g_config.map.n_col)
			g_config.map.n_col = c_len;
	}
}

void		read_map(int fd)
{
	char	*line;
	int		c_len;
	int		end;
	char	*aux;

	g_config.map.n_col = 0;
	g_config.map.n_row = 0;
	g_config.map.buff = ft_strdup("");
	c_len = 0;
	aux = NULL;
	while ((end = get_next_line(fd, &line)) >= 0)
	{
		calculate_map(line, end, aux, c_len);
		free(line);
		if (!end)
			break ;
	}
	g_config.map.world_map = parse_map();
	free(g_config.map.buff);
}

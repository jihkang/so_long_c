/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihkang <jihkang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 06:54:05 by jihkang           #+#    #+#             */
/*   Updated: 2022/08/16 07:44:02 by jihkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "so_long.h"
#include <stdlib.h>
#include <stdio.h>

int	arr[5][10] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 4, 0, 0, 1},
	{1, 0, 0, 2, 3, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
};

void	print_map(t_screen s)
{
	int	i;
	int	j;

	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 10)
		{
			if (arr[i][j] == 1)
				mlx_put_image_to_window(s.mlx, s.win, s.w.img, j * 100, i * 100);
			else if (arr[i][j] == 2)
				mlx_put_image_to_window(s.mlx, s.win, s.f.img, j * 100, i * 100);
			else if (arr[i][j] == 3)
				mlx_put_image_to_window(s.mlx, s.win, s.p.img, j * 100, i * 100);
			else if (arr[i][j] == 0)
				mlx_put_image_to_window(s.mlx, s.win, s.b.img, j * 100, i * 100);
			else if (arr[i][j] == 4)
				mlx_put_image_to_window(s.mlx, s.win, s.e.img, j * 100, i * 100);
			j++;
		}
	 	i++;
	}
}

int	keypress(int key, t_screen *s)
{
	if (key == ESC)
	{
		mlx_destroy_window(s->mlx, s->win);
		exit(1);
	}
	if (key == W && arr[s->p_pos[0] - 1][s->p_pos[1]] != 1)
	{
		arr[s->p_pos[0]][s->p_pos[1]] = 0;
		s->p_pos[0]--;
		s->p_count++;
		arr[s->p_pos[0]][s->p_pos[1]] = 3;
	}
	else if (key == A && arr[s->p_pos[0]][s->p_pos[1] - 1] != 1)
	{
		arr[s->p_pos[0]][s->p_pos[1]] = 0;
		s->p_pos[1]--;
		s->p_count++;
		arr[s->p_pos[0]][s->p_pos[1]] = 3;
	}
	else if (key == S && arr[s->p_pos[0] + 1][s->p_pos[1]] != 1)
	{
		arr[s->p_pos[0]][s->p_pos[1]] = 0;
		s->p_pos[0]++;
		s->p_count++;
		arr[s->p_pos[0]][s->p_pos[1]] = 3;
	}
	else if (key == D && arr[s->p_pos[0]][s->p_pos[1] + 1] != 1)
	{
		arr[s->p_pos[0]][s->p_pos[1]] = 0;
		s->p_pos[1]++;
		s->p_count++;
		arr[s->p_pos[0]][s->p_pos[1]] = 3;
	}
	print_map(*s);
	return (0);
}

void	find_player_pos(t_screen *s)
{
	int i;
	int j;
	int	cnt;

	i = 0;
	cnt = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 10)
		{
			if (arr[i][j] == 3) 
			{
				s->p_pos[0] = i;
				s->p_pos[1] = j;
				cnt++;
			}
			j++;
		}
		i++;
	}
	if (cnt == 2)
		printf("error");
}

int main()
{
	t_screen s;

	ft_memset(&s, sizeof(t_screen));
	s.mlx = mlx_init();
	s.win = mlx_new_window(s.mlx, 1500, 1000, "so_long");
	find_player_pos(&s);
	s.p.img = mlx_xpm_file_to_image(s.mlx, "./texture/scv.xpm", &s.p.w, &s.p.h);
	s.b.img = mlx_xpm_file_to_image(s.mlx, "./texture/map.xpm", &s.b.w, &s.b.h);
	s.f.img = mlx_xpm_file_to_image(s.mlx, "./texture/mineral.xpm", &s.f.w, &s.f.h);
	s.w.img = mlx_xpm_file_to_image(s.mlx, "./texture/gas.xpm", &s.w.w, &s.w.h);
	s.e.img = mlx_xpm_file_to_image(s.mlx, "./texture/exit.xpm", &s.e.w, &s.e.h);
	mlx_key_hook(s.win, keypress, &s);
	print_map(s);
	mlx_loop(s.mlx);
	return (0);
}

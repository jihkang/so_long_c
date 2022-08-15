/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihkang <jihkang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 07:35:08 by jihkang           #+#    #+#             */
/*   Updated: 2022/08/16 07:44:17 by jihkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define W 13
# define S 1
# define D 2
# define A 0
# define ESC 53

typedef	struct s_item
{
	void	*img;
	int		w;
	int		h;
}t_item;

typedef struct s_screen
{
	void	*mlx;
	void	*win;
	t_item	w;
	t_item	p;
	t_item	f;
	t_item	b;
	t_item	e;
	int		f_count;
	int		p_count;
	int		move_count;
	int		p_pos[2];
	char	map[500][500];
}t_screen;

int		is_correct_key(int key);
void	ft_memset(void *dst, int size);
#endif
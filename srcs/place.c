/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <lmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 18:48:08 by lmarques          #+#    #+#             */
/*   Updated: 2018/02/08 17:51:15 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	get_enemy_last_pos(t_filler *f)
{
	char	enemy_sign;
	t_point	p;

	enemy_sign = f->p_sign == 'O' ? 'X' : 'O';
	p.y = -1;
	while (++p.y < f->map.y)
	{
		p.x = -1;
		while (++p.x < f->map.x)
		{
			if (f->past_map[p.y][p.x] == '.' &&
				f->curr_map[p.y][p.x] == enemy_sign)
			{
				f->enemy_pos = p;
				return ;
			}
		}
	}
}

int		is_valid_pos(t_filler *f)
{
	char	enemy_sign;
	char	is_valid;
	t_point	p;

	enemy_sign = f->p_sign == 'O' ? 'X' : 'O';
	is_valid = 0;
	p.y = -1;
	while (++p.y < f->p_size.y)
	{
		p.x = -1;
		while (++p.x < f->p_size.x)
		{
			if (f->piece[p.y][p.x] == '*' &&
				(p.y + f->pos.y < 0 || p.x + f->pos.x < 0 ||
				p.y + f->pos.y >= f->map.y || p.x + f->pos.x >= f->map.x))
				return (0);
			if (f->piece[p.y][p.x] == '*' &&
				f->curr_map[p.y + f->pos.y][p.x + f->pos.x] == enemy_sign)
				return (0);
			if (f->piece[p.y][p.x] == '*' &&
				f->curr_map[p.y + f->pos.y][p.x + f->pos.x] == f->p_sign)
				is_valid++;
		}
	}
	return (is_valid == 1 ? 1 : 0);
}

int		get_dist(t_filler *f)
{
	t_point	p;

	p.x = f->pos.x - f->enemy_pos.x;
	p.y = f->pos.y - f->enemy_pos.y;
	if (ft_sqrt(p.x * p.x + p.y * p.y) < f->dist)
	{
		f->dist = ft_sqrt(p.x * p.x + p.y * p.y);
		return (1);
	}
	return (0);
}

int		place_piece(t_filler *f)
{
	char	placed;

	placed = 0;
	f->dist = 1000;
	f->final_pos.x = 1000;
	f->final_pos.y = 1000;
	f->pos.y = -f->p_size.y - 1;
	while (++f->pos.y < f->map.y)
	{
		f->pos.x = -f->p_size.x - 1;
		while (++f->pos.x < f->map.x)
		{
			if (is_valid_pos(f) && get_dist(f))
			{
				f->final_pos = f->pos;
				placed = 1;
			}
		}
	}
	return (placed);
}

int		do_job(t_filler *f)
{
	if (!read_data(f))
	{
		ft_putendl("0 0");
		return (0);
	}
	get_enemy_last_pos(f);
	if (!place_piece(f))
	{
		ft_putendl("0 0");
		return (0);
	}
	ft_putnbr(f->final_pos.y);
	ft_putchar(' ');
	ft_putnbr(f->final_pos.x);
	ft_putchar('\n');
	return (1);
}

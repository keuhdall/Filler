/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <lmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 19:33:55 by lmarques          #+#    #+#             */
/*   Updated: 2018/01/07 03:53:49 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		init_piece(t_filler *f, char *l)
{
	int	count;

	count = -1;
	if (!(f->piece = (char **)malloc(sizeof(char *) * f->p_size.y + 1)))
		return (0);
	f->piece[f->p_size.y] = 0;
	while (++count < f->p_size.y)
	{
		if (!(f->piece[count] = (char *)malloc(sizeof(char) * f->p_size.x)))
			return (0);
		free(l);
		get_next_line(0, &l);
		ft_strcpy(f->piece[count], l);
	}
	free(l);
	return (1);
}

int		get_piece(t_filler *f)
{
	int		count;
	char	*l;

	if (f->piece)
		free_array(f->piece);
	count = 6;
	get_next_line(0, &l);
	f->p_size.y = ft_atoi(l + count);
	while (l[count++] != ' ')
		continue;
	f->p_size.x = ft_atoi(l + count + 1);
	if (!init_piece(f, l))
		return (0);
	return (1);
}

int		read_data(t_filler *f)
{
	if (!f->curr_map)
		if (!init_map(f))
			return (0);
	if (!init_map(f) || !get_piece(f))
		return (0);
	return (1);
}

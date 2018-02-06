/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <lmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 03:25:24 by lmarques          #+#    #+#             */
/*   Updated: 2018/02/06 15:36:39 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		get_array_length(char **a)
{
	int	count;

	count = -1;
	while (a[++count])
		continue;
	return (count);
}

void	free_array(char **a)
{
	int	count;

	count = -1;
	while (a[++count])
		free(a[count]);
	free(a);
}

int		init_map(t_filler *f)
{
	int	count;

	count = -1;
	if (!(f->past_map = (char **)malloc(sizeof(char *) * f->map.y)) ||
		(!(f->curr_map = (char **)malloc(sizeof(char *) * f->map.y))))
		return (0);
	while (++count < f->map.y)
	{
		if (!(f->past_map[count] = (char *)malloc(sizeof(char) * f->map.x)) ||
			(!(f->curr_map[count] = (char *)malloc(sizeof(char) * f->map.x))))
			return (0);
	}
	return (1);
}

int		refresh_map(t_filler *f)
{
	char	*l;
	int		count;

	l = NULL;
	count = f->start ? -2 : -3;
	while (++count < f->map.y)
	{
		get_next_line(0, &l);
		if (!l)
			return (0);
		if (count >= 0)
		{
			ft_strcpy(f->past_map[count], f->curr_map[count]);
			ft_strcpy(f->curr_map[count], l + 4);
		}
		free(l);
	}
	f->start = 0;
	return (1);
}

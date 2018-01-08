/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <lmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 01:15:58 by lmarques          #+#    #+#             */
/*   Updated: 2018/01/08 00:25:06 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	get_infos(t_filler *f, int	*e)
{
	char	*l;
	char	**split;

	get_next_line(0, &l);
	f->p = ft_atoi(l + 10);
	f->p_sign = f->p == 1 ? 'O' : 'X';
	free(l);
	get_next_line(0, &l);
	if (get_array_length(split = ft_strsplit(l, ' ')) >= 3)
	{
		f->map.x = ft_atoi(split[2]);
		f->map.y = ft_atoi(split[1]);
	}
	else
		*e = 1;
	free_array(split);
	free(l);
	f->past_map = NULL;
	f->curr_map = NULL;
	f->piece = NULL;
	f->start = 1;
}

int	main(void)
{
	t_filler	f;
	int			e;

	ft_bzero(&f, sizeof(f));
	e = 0;
	get_infos(&f, &e);
	if (e)
	{
		ft_putendl("An error occured, exiting.");
		return (-1);
	}
	while (1)
	{
		if (!do_job(&f))
			break ;
	}
	return (0);
}

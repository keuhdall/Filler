/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <lmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 01:13:20 by lmarques          #+#    #+#             */
/*   Updated: 2018/01/07 03:57:32 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

#include "../libft/libft.h"

typedef struct	s_point
{
	int	x;
	int	y;
}				t_point;

typedef struct	s_filler
{
	int		p;
	char	p_sign;
	char	start;
	char	**past_map;
	char	**curr_map;
	char	**piece;
	t_point	p_size;
	t_point	map;
}				t_filler;

int		init_map(t_filler *f);
int		read_data(t_filler *f);
int		get_array_length(char **a);
void	free_array(char **a);

#endif
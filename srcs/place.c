/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <lmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 18:48:08 by lmarques          #+#    #+#             */
/*   Updated: 2018/01/07 03:58:03 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int	do_job(t_filler *f)
{
	if (!read_data(f))
	{
		ft_putendl("0 0");
		return (0);
	}
	return (1);
}

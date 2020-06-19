/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   micro_paint.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-hou <rvan-hou@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/19 13:50:51 by rvan-hou      #+#    #+#                 */
/*   Updated: 2020/06/19 14:01:13 by rvan-hou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MICRO_PAINT_H
# define MICRO_PAINT_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

typedef struct	s_data
{
	int			width;
	int			height;
	char		background;
	char		type;
	float		x;
	float		y;
	float		w;
	float		h;
	char		color;
}				t_data;

#endif
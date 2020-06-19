/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mini_paint.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-hou <rvan-hou@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/19 11:29:20 by rvan-hou      #+#    #+#                 */
/*   Updated: 2020/06/19 11:45:37 by rvan-hou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_PAINT_H
# define MINI_PAINT_H
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
	float		radius;
	char		color;
}				t_data;

#endif

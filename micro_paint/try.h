/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   try.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-hou <rvan-hou@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/22 12:22:18 by rvan-hou      #+#    #+#                 */
/*   Updated: 2020/06/22 12:39:43 by rvan-hou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRY_H
# define TRY_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

typedef struct	s_data
{
	int			width;
	int			height;
	char		back;
	float		x;
	float		y;
	float		w;
	float		h;
	char		fill;
	char		type;
}				t_data;

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_mat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 14:18:11 by erli              #+#    #+#             */
/*   Updated: 2018/12/13 17:11:31 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_free_mat_int(int **mat, int row)
{
	int i;

	i = 0;
	if (mat == NULL)
		return ;
	while (i < row)
	{
		free(mat[i]);
		i++;
	}
	free(mat);
}
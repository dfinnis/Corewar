/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_others.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinnis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 13:09:57 by dfinnis           #+#    #+#             */
/*   Updated: 2019/02/13 13:09:58 by dfinnis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	op_live(t_game *game, t_process *process)
{
	int		id;

	id = ft_reverse_bytes(&game->arena[(process->index + 1) % MEM_SIZE], DIR_SIZE);
	process->alive = 1;
	if (id > 0 && id <= game->champ_count)
	{
		game->alive_count++;
		game->champ[id].alive_count++;
		ft_printf("Player %i (%s) is alive!\n", game->champ[id].nbr, game->champ[id].header.prog_name); //if visu flag is off
	}
	process->index += DIR_SIZE;
}

void	op_zjmp(t_game *game, t_process *process)
{
	short	index;

	ft_get_index(&game->arena[++process->index % MEM_SIZE], IND_SIZE, &index);
	if (process->carry)
		process->index += (index % MEM_SIZE) - 2; //why -2 and not -1??
}

void	op_aff(t_game *game, t_process *process)
{
	t_op			op_tab;
	t_arg_type		args[4];

	op_tab = ft_get_op(15);
	process->seek_index = process->index;
	find_args(&game->arena[++process->seek_index % MEM_SIZE], args);
	if (args[0] == REG_CODE
	&& game->arena[(process->seek_index + 1) % MEM_SIZE] >= 1
	&& game->arena[(process->seek_index + 1) % MEM_SIZE] <= REG_NUMBER)
	{
		ft_printf("%c", process->reg[game->arena[++process->seek_index % MEM_SIZE]]);
		process->index = process->seek_index;
	}
}
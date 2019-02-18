/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinnis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 14:35:44 by dfinnis           #+#    #+#             */
/*   Updated: 2019/02/04 14:35:45 by dfinnis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	init_game(t_game *game)
{
	ft_bzero(game, sizeof(*game));
	ft_bzero(game->arena_champs, sizeof(MEM_SIZE));
	game->cycle_to_die = CYCLE_TO_DIE;
	game->cycle = CYCLE_TO_DIE;
}

int			find_champ_total(int argc, char **argv)
{
	int	champ_total;

	champ_total = 0;
	while (argc--)
	{
		if (ft_strstr(argv[argc], ".cor"))
			champ_total++;
	}
	if (champ_total > 4)
		error_exit("too many champions", NULL);
	return (champ_total);
}

void		ft_free_game(t_game *game)
{
	t_process *tmp;

	while (game && game->process)
	{
		tmp = game->process;
		game->process = game->process->next;
		free(tmp);
		tmp = NULL;
	}
}

int			main(int argc, char **argv)
{
	t_game	game;

	init_game(&game);
	read_args(argc, argv, &game);
	if (game.flag_i)
		print_intro(&game);
	if (game.flag_v)
		ft_printf("%s%s", CLEAR, MOVE_CURSOR);
	if (game.dump_set && !game.flag_dump)
		print_dump(game.arena, &game);
	ft_game(&game);
	ft_free_game(&game);
	return (0);
}

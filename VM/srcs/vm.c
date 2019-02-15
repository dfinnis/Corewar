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

void	error_exit(char *err_message)
{
	ft_putstr("ERROR ");
	ft_putstr(err_message);
	ft_putstr("\n");
	//free everything
	exit (1);
}

void	init_game(t_game *game)
{
	ft_bzero(game, sizeof(*game));
	ft_bzero(game->arena_champs, sizeof(MEM_SIZE));
	game->cycle_to_die = CYCLE_TO_DIE;
	game->cycle = CYCLE_TO_DIE;
	game->frame_rate = 25;//define in .h
}

int 	main(int argc, char **argv)
{
	t_game	game;

	init_game(&game);
	read_args(argc, argv, &game);
	ft_printf("\033[2J");//if just dump?
	ft_game(&game);
	// if (game.cycle_to_dump)//change to deal with cycles
	//	print_arena(game.arena);
	return (0);
}
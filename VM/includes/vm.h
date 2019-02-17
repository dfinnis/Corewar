#ifndef VM_H
# define VM_H

# include "../../op.h"
# include "../libft/ft_printf/ft_printf.h"
# include <fcntl.h>

# define FILE_SIZE 		(PROG_NAME_LENGTH + COMMENT_LENGTH + CHAMP_MAX_SIZE)

# define CLEAR			"\x1B[2J"
# define MOVE_CURSOR	"\x1B[H"
# define HIDE_CURSOR	"\x1B[?25l"
# define RESET_CURSOR	"\x1B[?12;25h"

# define LIGHT			"\x1B[47;1;31m"
# define GREY			"\x1B[1;30m"
# define RED			"\x1B[31m"
# define GREEN			"\x1B[32m"
# define YELLOW			"\x1b[33m"
# define BLUE			"\x1b[34m"
# define BRED			"\x1B[41m"
# define BGREEN			"\x1B[42m"
# define BYELLOW		"\x1b[43m"
# define BBLUE			"\x1b[44m"
# define BRIGHT			"\x1b[1m"
# define RESET			"\x1B[0m"

// typedef void 			t_op_type;

typedef struct			s_process
{
	int					index;
	int					seek;
	int					reg[17];
	int					duration;
	int					duration_set;
	int					carry;
	int					alive;
	short				champ;
	struct s_process	*next;
}						t_process;

typedef struct			s_champ
{
	struct header_s		header;
	int					start_index;
	unsigned int		nbr;
	short				nbr_set;
	int					weight;
	int			    	alive_count;
	long long			last_alive;
}						t_champ;

typedef struct			s_game
{
	unsigned char		arena[MEM_SIZE];
	unsigned char		arena_champs[MEM_SIZE];
	int					cycle_to_die;
	int					cycle;
	int					alive_count;
	long long			cycle_count;
	struct s_champ		champ[5];
	// int					champ_count;
	int					champ_total;//
	struct s_process	*process;
	int					flag_dump;
	short				dump_set;
	int					flag_v;
	int					speed;
	int					flag_i;
	int					flag_w;
	int					flag_cp;
	int					flag_a;
	int					flag_op;
	int					flag_arg;
	int					flag_e;
	// int					flag_p;
}						t_game;

/*
**		vm.c
*/
void					ft_free_game(t_game *game);
void					error_exit(char *err_message, t_game *game);
void					init_game(t_game *game);
int 					main(int argc, char **argv);

/*
**		read_args.c
*/
void					read_args(int argc, char **argv, t_game *game);

/*
**		read_champs.c
*/
void					read_champion(char *cor, t_game *game, unsigned char champ_count, int champ_total);
int						find_champ_total(int argc, char **argv);

/*
**		game.c
*/
int						ft_reverse_bytes(void *ptr, unsigned int size);
unsigned int			ft_get_bytes(void *ptr, int size);
int						ft_add_duration(t_game *game, t_process *process);
void					ft_game(t_game *game);
void					ft_fork_process(t_game *game, t_process *parent, short index);

t_op					ft_get_op(int index);

/*
**		process.c
*/
void					ft_add_process(t_game *game, int champ);
void					ft_check_process(t_game *game);
int						ft_count_process(t_game *game);

/*
**		op_and_or.c
*/

void					op_and(t_game *game, t_process *process);
void					op_or(t_game *game, t_process *process);
void					op_xor(t_game *game, t_process *process);

/*
**		op_arg_value.c
*/
void					get_first_value(t_game *game, t_process *process, t_arg_type *args, int *value1);
void					get_second_value(t_game *game, t_process *process, t_arg_type *args, int *value2);
void					get_first_value_ind(t_game *game, t_process *process, t_arg_type args, int *value1);
void					get_second_value_ind(t_game *game, t_process *process, t_arg_type args, int *value2);

/*
**		op_args.c
*/
void					find_args(unsigned char *ptr, t_arg_type arg[], int flag_arg);
void					ft_get_size(unsigned int *size, t_arg_type args, int i);

/*
**		op_fork.c
*/
void					op_fork(t_game *game, t_process *process);
void					op_lfork(t_game *game, t_process *process);

/*
**		op_load.c
*/
void					op_ld(t_game *game, t_process *process);
void					op_ldi(t_game *game, t_process *process);
void					op_lld(t_game *game, t_process *process);
void					op_lldi(t_game *game, t_process *process);

/*
**		op_math.c
*/
void					op_add(t_game *game, t_process *process);
void					op_sub(t_game *game, t_process *process);

/*
**		op_store.c
*/
void					op_st(t_game *game, t_process *process);
void					op_sti(t_game *game, t_process *process);

/*
**		op_others.c
*/
void					op_live(t_game *game, t_process *process);
void					op_zjmp(t_game *game, t_process *process);
void					op_aff(t_game *game, t_process *process);

/*
**		print.c
*/
void    				print_dump(unsigned char *arena, t_game *game);
void					print_visualizer(t_game *game, int i);
void					print_usage(t_game *game);
void					print_intro(t_game *game);

/*
**		print_colors.c
*/
void        			print_arena_color(t_game *game);

/*
**		idx.c
*/
void					ft_get_index(unsigned char	*process, int size, short *index);
void					ft_index_sum(short index1, short index2, short *total);
int						ft_index_mod(int index);
int						ft_move_index(int index, t_arg_type *args, int op_id);
int						ft_check_args(t_game *game, int index, t_arg_type *args, int op_id);

#endif
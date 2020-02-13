/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pseudo_ralph.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 02:53:42 by kmira             #+#    #+#             */
/*   Updated: 2020/02/13 12:08:13 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PSEUDO_RALPH_H
# define PSEUDO_RALPH_H

#define _GNU_SOURCE

# include <stdio.h>
# include <stdint.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <time.h>

# define OPTION 0
# define WRONG -1
# define RIGHT  1

#define MAX_LIVES 6

# define ANSI_RESET "\033[0m"
# define ANSI_CLEAR "\33[2K"

#define CURSOR_CONTROL_INIT() int cursor_pos = 0;
#define cur_for(x) printf("\033[%dC", (x))
#define cur_back(x) printf("\033[%dD", (x))
#define cur_up(x) printf("\033[%dA", (x)); cursor_pos++;
#define cur_down(x) printf("\033[%dB", (x)); cursor_pos++;

char	*color_code(uint8_t red, uint8_t green, uint8_t blue);
char	*intesity_code(uint8_t intensity);

void	print_char_set(int *char_state);
void	print_lives(int wrong_guesses);
void	print_game_over(void);
void	print_phrase_state(char *phrase_state);
void	print_game_win(void);

void	update_phrase_state(char *phrase, char *phrase_state, char guess);
int		phase_guessed(char *phrase_state);

#endif

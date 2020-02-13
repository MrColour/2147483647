/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 06:00:22 by xinu              #+#    #+#             */
/*   Updated: 2020/02/13 12:11:58 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pseudo_ralph.h"

void	print_char_set(int *char_state)
{
	int		i;
	char	*wrong;
	char	*green;

	wrong = intesity_code(120);
	green = color_code(30, 200, 50);
	i = 'a';
	while (i <= 'z')
	{
		if (char_state[i] == OPTION)
			printf("%c "ANSI_RESET, i);
		else if (char_state[i] == WRONG)
			printf("%s%c "ANSI_RESET, wrong, i);
		else if (char_state[i] == RIGHT)
			printf("%s%c "ANSI_RESET, green, i);
		else
			printf("ERROR!\n");
		i++;
	}
}

void	print_lives(int wrong_guesses)
{
	int		i;
	char	*red;
	char	*faded_gray;

	i = 0;
	red = color_code(200, 30, 30);
	printf("%s", red);
	while (i < wrong_guesses)
	{
		printf("X");
		i++;
	}
	faded_gray = intesity_code(120);
	printf("%s", faded_gray);
	while (i < MAX_LIVES)
	{
		printf("X");
		i++;
	}
	printf(ANSI_RESET);
}

void		print_phrase_state(char *phrase_state)
{
	char	*white;

	white = intesity_code(180);
	printf("%s%s"ANSI_RESET, white, phrase_state);
}

void		print_game_over(void)
{
	char	*red;

	red = color_code(200, 30, 30);
	printf(ANSI_CLEAR"\r");
	printf("%sGAME OVER"ANSI_RESET, red);
}

void		print_game_win(void)
{
	char	*bright_green;

	bright_green = color_code(70, 230, 100);
	printf(ANSI_CLEAR"\r");
	printf("%sYou WIN!"ANSI_RESET, bright_green);
}

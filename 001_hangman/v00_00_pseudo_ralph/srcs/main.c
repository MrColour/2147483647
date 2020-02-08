/**************************************************************
 * FILENAME:    main.c	REF: ASM_pseudo-ralph_srcs
 *
 * DESCRIPTION:
 *      Entry point for <ATTEMPT>: pseudo_ralph
 *
 * ENVIRONMENT:
 *      macOS High Sierra Version 10.13.4
 *      Visual Studio Code 1.Version: 1.38.1
 *
 * VERSION:
 *      0.0.0.4
 *
 * AUTHOR(s):
 *      Kevin Colour
 *
 * DATES:
 *      Created:			Sat Jan 11 21:04:30 PST 2020
 *		Verified Execute:	Sat Feb  8 08:58:44 PST 2020
 *
****************************************************************/

#include "pseudo_ralph.h"

#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>

char	*strlwr(const char *str)
{
	size_t	i;
	size_t	length;
	char	*result;

	i = 0;
	length = strlen(str);
	result = malloc(sizeof(*result) * (length + 1));
	while (i < length)
	{
		result[i] = tolower(str[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}

void	update_phrase_state(char *phrase, char *phrase_state, char guess)
{
	int		i;

	i = 0;
	while (phrase[i] != '\0')
	{
		if (phrase[i] == guess)
			phrase_state[i] = guess;
		i++;
	}
}

int		phase_guessed(char *phrase_state)
{
	int		i;
	int		result;

	i = 0;
	result = 1;
	while (phrase_state[i] != '\0')
	{
		if (phrase_state[i] == '_')
		{
			result = 0;
			break;
		}
		i++;
	}
	return (result);
}

int		main(void)
{
	int		char_state[128];

	char	phrase[] = "Hangman game";
	char	phrase_state[sizeof(phrase)];
	char	*str;

	bzero(char_state, sizeof(char_state));
	bzero(phrase_state, sizeof(phrase_state));
	memset(phrase_state, '_', sizeof(phrase_state) - 1);

	int	i;
	int	guess;
	int	wrong_guesses;

	CURSOR_CONTROL_INIT()

	i = 0;
	while (phrase[i] != '\0')
	{
		if (phrase[i] == ' ')
			phrase_state[i] = ' ';
		i++;
	}
	i = 0;
	wrong_guesses = 0;
	str = strlwr(phrase);
	printf("\n");
	while (i < 100)
	{
		guess = (rand() % ('z' - 'a')) + 'a';
		printf(ANSI_CLEAR"\r");

		if (char_state[(int)guess] == 0)
			printf("[GUESS: %c]", guess);
		else
			printf("[Already guessed: %c]", guess);

		if (strchr(str, guess) != NULL)
		{
			char_state[(int)guess] = RIGHT;
			update_phrase_state(str, phrase_state, guess);
		}
		else if (char_state[(int)guess] == 0)
		{
			char_state[(int)guess] = WRONG;
			wrong_guesses++;
		}
		printf("\n");
		print_char_set(char_state);
		printf("\n");
		print_lives(wrong_guesses);
		printf("\n");
		print_phrase_state(phrase_state);
		printf("\n");
		cur_up(4);
		if (wrong_guesses >= MAX_LIVES)
		{
			print_game_over();
			break ;
		}
		if (phase_guessed(phrase_state) == 1)
		{
			print_game_win();
			break ;
		}
		usleep(300000);
		i++;
	}
	cur_up(2);
	printf(ANSI_CLEAR"\r");
	return (0);
}

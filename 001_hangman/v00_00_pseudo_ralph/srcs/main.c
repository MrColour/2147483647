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
 *      0.0.0.3
 *
 * AUTHOR(s):
 *      Kevin Colour
 *
 * DATES:
 *      Created:			Sat Jan 11 21:04:30 PST 2020
 *		Verified Execute:	NULL
 *
****************************************************************/

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

#define cur_for(x) printf("\033[%dC", (x))
#define cur_back(x) printf("\033[%dD", (x))
#define cur_up(x) printf("\033[%dA", (x))
#define cur_down(x) printf("\033[%dB", (x))

int		main(void)
{
	int		char_state[128];

	char	phrase[] = "Hangman game";
	char	*str;

	bzero(char_state, sizeof(char_state));

	int	i;
	int	guess;
	struct timespec delta;
	delta.tv_sec = 0;
	delta.tv_nsec = 100;

	i = 0;
	str = strlwr(phrase);
	printf("String is: %s\n", str);
	while (i < 20)
	{
		guess = (rand() % ('z' - 'a')) + 'a';
		if (strchr(str, guess) != NULL)
			char_state[(int)guess] = RIGHT;
		else
			char_state[(int)guess] = WRONG;
		printf("[GUESS: %c]", guess);
		cur_down(1);
		printf("\r");
		print_char_set(char_state);
		printf("\n");
		cur_up(2);
		cur_down(2);
		fflush(stdout);
		usleep(300000);
		i++;
	}
	return (0);
}

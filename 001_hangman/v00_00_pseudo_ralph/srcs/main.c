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
#include <time.h>

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

#define BUFF_SIZE 30

char	*get_phrase(void)
{
	int		i;
	int		dict_fd;
	int		phrase_id;
	int		bytes_read;
	int		newline_count;
	char	buffer[BUFF_SIZE + 1];

	bytes_read = 1;
	newline_count = 0;
	dict_fd = open("resources/dictonary", O_RDONLY);
	while (bytes_read > 0)
	{
		bzero(buffer, sizeof(buffer));
		bytes_read = read(dict_fd, buffer, BUFF_SIZE);
		i = 0;
		while (buffer[i] != '\0')
		{
			if (buffer[i] == '\n')
				newline_count++;
			i++;
		}
	}
	newline_count--;
	phrase_id = -1;
	if (RAND_MAX <= newline_count)
		printf("Not all phrases will be picked\n");
	else if (newline_count != 0)
		phrase_id = (rand() % (newline_count)) + 1;

	bytes_read = 1;
	newline_count = 0;
	lseek(dict_fd, 0, SEEK_SET);
	while (bytes_read > 0)
	{
		bzero(buffer, sizeof(buffer));
		bytes_read = read(dict_fd, buffer, BUFF_SIZE);
		i = 0;
		while (buffer[i] != '\0')
		{
			if (buffer[i] == '\n')
				newline_count++;
			if (newline_count + 1 == phrase_id)
				break ;
			i++;
		}
		if (newline_count + 1 == phrase_id)
			break ;
	}
	int	phrase_start;
	int	phrase_end;

	lseek(dict_fd, -bytes_read, SEEK_CUR);
	lseek(dict_fd, i + 1, SEEK_CUR);
	phrase_start = lseek(dict_fd, 0, SEEK_CUR);
	printf("NEWLINES %d and choosen: %d\n", newline_count, phrase_id);
	printf("Starts %d\n", phrase_start);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bzero(buffer, sizeof(buffer));
		bytes_read = read(dict_fd, buffer, BUFF_SIZE);
		i = 0;
		while (buffer[i] != '\0' && buffer[i] != '\n')
			i++;
		if (buffer[i] == '\n')
			break ;
	}
	phrase_end = lseek(dict_fd, 0, SEEK_CUR) - bytes_read + i;

	char	*result;

	if (phrase_id == 1)
		phrase_start--;
	result = malloc(sizeof(*result) * (phrase_end - phrase_start + 1));
	lseek(dict_fd, phrase_start, SEEK_SET);
	read(dict_fd, result, phrase_end - phrase_start);
	result[phrase_end - phrase_start] = '\0';
	printf("Phrase: %s, start: %d ends: %d\n", result, phrase_start, phrase_end);

	return (result);
}

int		main(void)
{
	int		char_state[128];

	char	*phrase;
	char	*phrase_state;
	char	*str;

	srand(time(NULL));
	phrase = get_phrase();
	phrase_state = malloc(sizeof(*phrase_state) * (strlen(phrase) + 1));

	bzero(char_state, sizeof(char_state));
	bzero(phrase_state, sizeof(*phrase_state) * (strlen(phrase) + 1));
	memset(phrase_state, '_', sizeof(*phrase_state) * (strlen(phrase)));

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
	srand(time(0));
	while (i < 200)
	{
		guess = (rand() % ('z' - 'a' + 1)) + 'a';
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
		if (wrong_guesses >= MAX_LIVES)
		{
			usleep(1000000);
			cur_up(4);
			print_game_over();
			break ;
		}
		if (phase_guessed(phrase_state) == 1)
		{
			print_game_win();
			break ;
		}
		cur_up(4);
		usleep(500000);
		i++;
	}
	// cur_up(2);
	// printf("\r");
	return (0);
}

/**************************************************************
 * FILENAME:    main.c	REF: ASM_pseudo-ralph_srcs
 *
 * DESCRIPTION:
 *      Entry point for <ATTEMPT>: pseudo_ralph
 *
 * ENVIRONMENT:
 *      Windows 10 Home v1803 x64
 *      Visual Studio Code 1.41.1
 *           Extensions: ms-vscode-remote.remote-wsl
 *
 * VERSION:
 *      0.0.0.1
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

int		main(void)
{
	int		char_state[128];

	bzero(char_state, sizeof(char_state));
	char_state['a'] = WRONG;
	char_state['p'] = WRONG;
	char_state['w'] = RIGHT;
	print_char_set(char_state);
	return (0);
}

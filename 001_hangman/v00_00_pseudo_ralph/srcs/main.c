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

#define OPTION 0
#define WRONG -1
#define RIGHT  1

int		main(void)
{
	printf("%s", intesity_code(120));
	printf("Working or does it re?\n");
	printf("%s", color_code(0, 255, 255));
	printf("Working or does it re?\n");
	return (0);
}

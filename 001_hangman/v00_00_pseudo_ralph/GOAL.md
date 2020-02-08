/**************************************************************
 * FILENAME:    main.c	REF: AG_pseudo-ralph_srcs
 *
 * DESCRIPTION:
 *      GOAL.md for <ATTEMPT>: pseudo_ralph
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
 *      Created:			Sat Jan 11 21:20:32 PST 2020
 *		Verified Execute:	NULL
 *
****************************************************************/

The <ATTEMPT> pseudo_ralph shall accomplish the following points:

1. Allow an agent to play to game of hangman.
2. Display all the lowercase alphabetical ascii characters. From
	these choices, correct guesses are to be marked green when guessed,
	and wrong choices are to be marked red.
3. A configuration file that shall have each possible hangman phrase.
	Each phrase shall be seperated by a newline, phrases shall be only
	alpabetical characters or the space character.
4. Must randomly choose one phrase from the config file.
5. Matching is case insensative.
6. Display the current progress on the phrase and where each correct letter
	is in such phrase.
7. The agent has 6 allowed wrong guesses.
8. A screen displaying lost state if agent has 7 wrong guesses.
9. A screen displaying won state if agent correctly guesses the phrase.

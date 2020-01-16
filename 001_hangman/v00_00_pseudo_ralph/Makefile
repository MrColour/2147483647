# *************************************************************
 # FILENAME:    Makefile	REF: MK_pseudo-ralph_V00_00_pseudo_ralph
 #
 # DESCRIPTION:
 #      Makefile for <ATTEMPT>: pseudo_ralph
 #
 # ENVIRONMENT:
 #      Windows 10 Home v1803 x64
 #      Visual Studio Code 1.41.1
 #           Extensions: ms-vscode-remote.remote-wsl
 #
 # VERSION:
 #      0.0.0.1
 #
 # AUTHOR(s):
 #      Kevin Colour
 #
 # DATES:
 #      Created:			Sat Jan 11 21:10:10 PST 2020
 #		Verified Execute:	NULL
 #
# ***************************************************************/

NAME = run_pseudo_ralph

FLAGS = -Wall -Wextra -Werror

INCLUDES = -I includes

BINARY_DIR = bin/

SRCS_FILES = \
	main

SOURCE_FILES = $(addsuffix .c, $(addprefix srcs/, $(SRCS_FILES)))
OBJS = $(addsuffix .o, $(SRCS_FILES))

all: $(NAME)

$(NAME): $(OBJS)
	gcc -o $(NAME) $(FLAGS) $(INCLUDES) $(BINARY_DIR)$(OBJS)

$(OBJS): $(SOURCE_FILES)
	gcc -c $(FLAGS) $(INCLUDES) $(SOURCE_FILES)
	mv $(OBJS) $(BINARY_DIR)

clean:
	rm -f $(BINARY_DIR)$(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re

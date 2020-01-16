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
	main \
	output_styling

SOURCE_FILES = $(addsuffix .c, $(addprefix srcs/, $(SRCS_FILES)))
OBJS_FILES = $(addsuffix .o, $(SRCS_FILES))
OBJS = $(addsuffix .o, $(addprefix $(BINARY_DIR), $(SRCS_FILES)))

all: $(NAME)

$(NAME): $(OBJS_FILES)
	gcc -o $(NAME) $(FLAGS) $(INCLUDES) $(OBJS)

$(OBJS_FILES): $(BINARY_DIR)
	gcc -c $(FLAGS) $(INCLUDES) $(SOURCE_FILES)
	mv $(OBJS_FILES) $(BINARY_DIR)

$(BINARY_DIR):
	mkdir $(BINARY_DIR)

clean:
	rm -f $(BINARY_DIR)$(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

save:
	git add .
	git commit -m "GIT: $(COUNT) 001:pseudo_ralph: $(MSG)"
	git push

.PHONY: clean fclean all re

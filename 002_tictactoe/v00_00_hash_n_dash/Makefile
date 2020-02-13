# *************************************************************
 # FILENAME:    Makefile	REF: MK_hash-n-dash_V00_00_hash_n_dash
 #
 # DESCRIPTION:
 #      Makefile for <ATTEMPT>: hash_n_dash
 #
 # ENVIRONMENT:
 #      Windows 10 Home v1803 x64
 #      Visual Studio Code 1.41.1
 #           Extensions: ms-vscode-remote.remote-wsl
 #
 # VERSION:
 #      0.0.0.2
 #
 # AUTHOR(s):
 #      Kevin Colour
 #
 # DATES:
 #      Created:			Sat Jan 11 21:10:10 PST 2020
 #		Verified Execute:	Thu Feb 13 12:12:20 PST 2020
 #
# ***************************************************************/

NAME = run_hash_n_dash

FLAGS = -Wall -Wextra -Werror

INCLUDES = -I includes

BINARY_DIR = bin/

SRCS_FILES = \
	main \

SOURCE_FILES = $(addsuffix .c, $(addprefix srcs/, $(SRCS_FILES)))
OBJS_FILES = $(addsuffix .o, $(SRCS_FILES))
OBJS = $(addsuffix .o, $(addprefix $(BINARY_DIR), $(SRCS_FILES)))

all: $(NAME)

$(NAME): $(OBJS)
	gcc -o $(NAME) $(FLAGS) $(INCLUDES) $(OBJS)

$(OBJS): $(BINARY_DIR)
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
	git commit -m "GIT: $(COUNT) 002:hash_n_dash: $(MSG)"
	git push

.PHONY: clean fclean all re

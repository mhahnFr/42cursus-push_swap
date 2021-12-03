# All source files.
SRC = ./main.c ./input/input_check.c ./input/input_parse.c ./sort/sort.c

# The object files.
OBJ = $(patsubst %.c,%.o,$(SRC))

# The flags to compile with.
CFLAGS = -Wall -Werror -Wextra -g #-Ofast

# The name of the executable.
NAME = push_swap


# Makes everything.
all: $(NAME)

# Makes everything that is needed for the executable.
$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $(NAME)

# Runs the norm checker on all registered files.
nor:
	norminette $(SRC) $(patsubst %.c,%.h,$(SRC)) | grep :

# Convenience rule for a bonus work which should already be included.
bonus: all

# Compiles each file individually.
%.o: %.c
	$(CC) $(CFLAGS) -I. -c -o $@ $<

# Removes all temporary files.
clean:
	- $(RM) $(OBJ)
	- $(RM) *~
	- find . -name \*~ -print -delete

# Removes all files created by this makefile.
fclean: clean
	- $(RM) $(NAME)

# Recompiles everything.
re: fclean all

# A list with rules that are always dirty.
.PHONY: all bonus clean fclean nor re

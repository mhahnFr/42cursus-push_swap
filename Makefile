# All source files.
SRC = ./main.c ./input/input_check.c ./input/input_parse.c ./sort/sort.c	  \
	  ./stack/stack.c ./utils/utils.c ./stack/stack_print.c					  \
	  ./stack/stack_contains.c ./stack/stack_size.c ./stack/stack_rotate.c	  \
	  ./stack/stack_push.c ./sort/sort_ops.c ./sort/sort_next_op.c			  \
	  ./arraylist/arraylist.c ./arraylist/arraylist_array.c 				  \
	  ./arraylist/arraylist_array_unsafe.c ./arraylist/arraylist_get.c		  \
	  ./arraylist/arraylist_insert.c ./arraylist/arraylist_remove.c			  \
	  ./arraylist/arraylist_reset_indices.c ./arraylist/arraylist_size.c

# The object files.
OBJ = $(patsubst %.c,%.o,$(SRC))

# The flags to compile with.
CFLAGS = -Wall -Werror -Wextra -g #-Ofast

# The name of the executable.
NAME = push_swap

# The path to the libft.
LFT_D = ./libft/src

# The name of the libft.
LFT_A = libft.a

# The full path to the libft.
LFT_P = $(LFT_D)/$(LFT_A)

# The includes.
INCL = -I. -I$(LFT_D) -I./arraylist

# The flags for the linker.
LDFLAGS = -L$(LFT_D) -lft

# Makes everything.
all: $(NAME)

# Makes everything that is needed for the executable.
$(NAME): $(OBJ) $(LFT_P)
	$(CC) $(OBJ) $(LDFLAGS) -o $(NAME)

# Runs the norm checker on all registered files.
nor:
	norminette $(SRC) $(patsubst %.c,%.h,$(SRC)) | grep :

# Convenience rule for a bonus work which should already be included.
bonus: all

# Calls the makefile of the libft.
$(LFT_P):
	make -C $(LFT_D) $(LFT_A)

# Compiles each file individually.
%.o: %.c
	$(CC) $(CFLAGS) $(INCL) -c -o $@ $<

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

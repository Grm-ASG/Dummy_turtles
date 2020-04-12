NAME = dummy_turtles

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCDIR = ./src/
_SRC = $(wildcard $(SRCDIR)*.c)

OBJDIR = ./obj/
OBJ = $(_SRC:$(SRCDIR)%.c=$(OBJDIR)%.o)

HEADER = ./includes/
OPTIONS = -c -I $(HEADER)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c $(HEADER)header.h
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(OPTIONS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)
	
re : fclean all

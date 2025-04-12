CC = cc
CFLAGS = -Wall -Wextra -g #-Werror
BIN_DIR=bin
SRCS := $(wildcard *.c)
OBJS := $(patsubst %.c, $(BIN_DIR)/%.o, $(SRCS))

NAME = push_swap

DEP = push_swap.h

all : $(NAME)

debug:CFLAGS+=-g
debug: re

$(BIN_DIR)/%.o: %.c $(DEP) | $(BIN_DIR)
	$(CC) -c $(CFLAGS) $< -o $@
	
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

clean: 
	rm -rf $(BIN_DIR)

fclean: clean
	rm -rf $(NAME)

re:
	rm -rf $(BIN_DIR)
	rm -rf $(NAME)
	make all

.PHONY:
	all clean fclean re
.SECONDARY:

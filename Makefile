NAME	:= a.out
CFLAGS	:= -g -Wextra -Wall -Werror -Wunreachable-code -Ofast 
LIBFT 	:= ./libft

HEADERS	:= -I./include -I$(LIBFT)
LIBS	:= $(LIBFT)/libft.a
SRCS	:= push_swap.c push_swap_utils.c push_swap_operations.c push_swap_operations2.c push_swap_delete.c
OBJS	:= ${SRCS:.c=.o}

all: libft $(NAME)

libft:
	@make -C $(LIBFT)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C $(LIBFT)

# run:

re: clean all

.PHONY: all, clean, fclean, re, libft
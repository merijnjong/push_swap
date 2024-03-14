sourcefiles = 	push_swap.c

objects =		$(sourcefiles:.c=.o)

NAME =			libft.a

all:			$(NAME)

$(NAME):		$(objects)
	@ar rcs libft.a $(objects)

%.o: %.c
	cc -Wall -Wextra -Werror -c $< -o $@

clean:
	@rm -f $(objects)

fclean:
	@rm -f $(objects) $(NAME)

re: 			fclean all
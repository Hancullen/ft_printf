NAME	=	libftprintf.a

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
LIBFT	=	libft
HEADER	=	ft_printf.h
SRCS	= 	char_handle.c		num_handle.c		num_padding_handle.c	\
			padding_handle.c	percent_handle.c	pointer_handle.c		\
			print_str.c			str_handle.c		str_padding_handle.c	\
			struct_handle.c		ft_printf.c			conversion_handle.c

OBJS 	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT)
	cp libft/libft.a ./$(NAME)
	ar rcs $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT)

fclean:
	rm -f $(NAME)
	make fclean -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean re

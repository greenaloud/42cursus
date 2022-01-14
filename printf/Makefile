CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRCS = ft_flag.c ft_print_int.c ft_printf.c ft_util.c ft_print_char.c ft_print_str.c ft_print_percent.c ft_print_u_int.c ft_print_hex.c ft_print_addr.c
BONUS_SRCS = ft_flag.c ft_print_int.c ft_printf.c ft_util.c ft_print_char.c ft_print_str.c ft_print_percent.c ft_print_u_int.c ft_print_hex.c ft_print_addr.c
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar -cr $@ $^

bonus :
	make "OBJS = $(OBJS) $(BONUS_OBJS)" all

clean :
	rm -f $(OBJS) $(BONUS_OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all bonus clean fclean re

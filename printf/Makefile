CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRCS = ft_printf.c ft_flag.c ft_print_int.c ft_print_u_int.c ft_print_hex.c ft_print_addr.c ft_print_char.c ft_print_str.c ft_util.c
SRCS_BONUS = ft_printf_bonus.c ft_flag_bonus.c ft_print_int_bonus.c ft_print_u_int_bonus.c ft_print_hex_bonus.c ft_print_addr_bonus.c ft_print_char_bonus.c ft_print_str_bonus.c ft_util_bonus.c
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

ifdef CHECK
	OB = $(OBJS_BONUS)
else
	OB = $(OBJS)
endif

all: $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< 

$(NAME) : $(OB)
	ar -cr $@ $^

bonus :
	make CHECK=1 all 

clean :
	rm -f $(OBJS) $(OBJS_BONUS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all bonus clean fclean re

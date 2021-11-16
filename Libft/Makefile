CC = gcc
CFLAGS = -Wall -Wextra -Werror
TARGETS = libft.a
OBJS = $(patsubst %.c,%.o,$(wildcard *.c))

$(TARGETS) : $(OBJS)
	ar -cr $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $<

all : $(TARGETS)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f libft.a

re : fclean all

SOURCESSRV = server.c
OBJECTSSRV = $(SOURCESSRV:.c=.o)

SOURCESCLI = client.c
OBJECTSCLI = $(SOURCESCLI:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: server client

bonus: server client

server: $(OBJECTSSRV) libft
	$(CC) $(CFLAGS) -o $@ $< -Llibft -lft

client: $(OBJECTSCLI) libft
	$(CC) $(CFLAGS) -o $@ $< -Llibft -lft

%.o: %.c
	$(CC) -c $(CFLAGS) $?

libft:
	cd libft && make

clean:
	rm -f $(OBJECTSCLI) $(OBJECTSSRV)
	make -C libft clean
	
fclean: clean
	rm -f server client libft/libft.a
	

re: fclean all

.PHONY: all bonus libft clean fclean re
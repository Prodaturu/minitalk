SERVER = server
CLIENT = client
NAME = minitalk
PRINTFLIBFT = printf/libftprintf.a
PRINTF = printf

SRCSC = client.c
SRCSS = server.c
OBJSC = $(SRCSC:.c=.o)
OBJSS = $(SRCSS:.c=.o)

CC = cc
FLAGS = -Wall -Werror -Wextra

all: $(PRINTFLIBFT) $(SERVER) $(CLIENT)

$(PRINTFLIBFT):
	make -C $(PRINTF)

$(SERVER): $(OBJSS)
	$(CC) $(FLAGS) $(PRINTFLIBFT) -o $@ $(OBJSS)

$(CLIENT): $(OBJSC)
	$(CC) $(FLAGS) $(PRINTFLIBFT) -o $@ $(OBJSC)

bonus: all

%.o: %.c
	$(CC) $(FLAGS) $(SRCSC) -c
	$(CC) $(FLAGS) $(SRCSS) -c

clean:
	make clean -C $(PRINTF)
	rm -f $(OBJSC) $(OBJSS)

fclean: clean
	make fclean -C $(PRINTF)
	rm -f $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all fclean clean re bonus
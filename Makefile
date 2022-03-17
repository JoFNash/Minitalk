HEADER = includes/minitalk.h

LIBFT_DIR		= ./libft/
LIBFT			= libft.a

CLIENT			= client
SERVER			= server

SERVER_SRCS		= server.c
SERVER_OBJS		= $(SERVER_SRCS:.c=.o)

CLIENT_SRCS		= client.c
CLIENT_OBJS		= $(CLIENT_SRCS:.c=.o)

FLAGS			= -g -Wall -Wextra -Werror 

%.o:					%.c $(HEADER)
						gcc $(FLAGS) -I$(LIBFT_DIR) -c $< -o $(<:.c=.o)
						
all:					$(SERVER) $(CLIENT)

$(SERVER):				$(LIBFT_DIR)$(LIBFT) $(SERVER_OBJS) $(HEADER)
						gcc $(SERVER_OBJS) -I$(LIBFT_DIR) -L$(LIBFT_DIR) -lft $(FLAGS) -o $(SERVER)

$(CLIENT):				$(LIBFT_DIR)$(LIBFT) $(CLIENT_OBJS) $(HEADER)
						gcc $(CLIENT_OBJS) -I$(LIBFT_DIR) -L$(LIBFT_DIR) -lft $(FLAGS) -o $(CLIENT)

$(LIBFT_DIR)$(LIBFT):	$(LIBFT_DIR)
						make -C $(LIBFT_DIR) all

clean:
						rm -rf $(CLIENT_OBJS) $(SERVER_OBJS)
						make -C $(LIBFT_DIR) clean

fclean:					clean 
						rm -rf $(SERVER) $(CLIENT)
						make -C $(LIBFT_DIR) fclean

re:						fclean all

.PHONY:					all clean fclean re

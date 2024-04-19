NAME := so_long
CC := cc 
CFLAGS := -Wall -Wextra -Werror
AR := ar rc
RM := rm -rf
# CFILES := ft_read_map.c get_next_line_utils.c get_next_line.c so_long.c ft_check_map.c utils.c 
CFILES = ./includes/get_next_line/get_next_line.c ./includes/get_next_line/get_next_line_utils.c so_long.c utils.c ft_read_map.c ft_check_map.c flood_fill.c

LINK = -lmlx -framework AppKit -framework OpenGL
OBJS := ${CFILES:.c=.o}

all : $(NAME)

${NAME} : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LINK) -o  $(NAME)

.o:.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.SECONDARY : $(OBJS)
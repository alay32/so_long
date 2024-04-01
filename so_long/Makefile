NAME := so_long.a
CC := cc 
CFLAGS := -Wall -Wextra -Werror
AR := ar rc
RM := rm -rf
# CFILES := ft_read_map.c get_next_line_utils.c get_next_line.c so_long.c ft_check_map.c utils.c 
CFILES = ./includes/get_next_line/get_next_line.c ./includes/get_next_line/get_next_line_utils.c so_long.c utils.c ft_read_map.c ft_check_map.c

OBJS := ${CFILES:.c=.o}

all : $(NAME)

${NAME} : $(OBJS)
	
%.o:%.c
	$(CC) $(CFLAGS) $(CFILES) -o so_long

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
TARGET	= bsq
SRCS	= main.c ft_file_io.c ft_putstr.c ft_split.c ft_substr.c ft_free.c ft_check_format.c ft_strlen.c ft_atoi.c ft_str_is_printable.c ft_create_map.c ft_display_map.c ft_strcpy.c ft_calc_max_square.c ft_min_max.c ft_putnbr.c ft_putchar.c
OBJS	= $(SRCS:.c=.o)

all:$(TARGET)

$(TARGET):$(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

.o.c:
	$(CC)  -c $< -o $@

clean:
	rm -f $(OBJS)

fclean:clean
	rm -f $(TARGET)

re:fclean all

NAME    = serialize

CC      = c++
CFLAGS  = -Wall -Wextra -Werror -std=c++98

SRCS    = main.cpp\
			Serializer.cpp\

OBJS    = $(SRCS:.cpp=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

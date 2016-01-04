CXX			= g++

NAME		= 01_hello_SDL

SRCS		= 01_hello_SDL.cpp

OBJS		= $(SRCS:.cpp=.o)

CXXFLAGS	= -W -Wall -Werror

LDFLAGS		= -lSDL2

RM			= rm -f

all:	$(NAME)

$(NAME): $(OBJS)
	$(CXX) $(OBJS) $(LDFLAGS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

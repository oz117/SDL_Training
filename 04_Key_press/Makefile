CXX			= g++

NAME		= 04_Key_press

SRCS		= 04_Key_press.cpp	\
				src/Graphics.cpp	\
				src/Surfaces.cpp

OBJS		= $(SRCS:.cpp=.o)

CXXFLAGS	= -W -Wall -Werror

CXXFLAGS	+=  -I./include -g3

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

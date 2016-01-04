CXX			= g++

NAME		= 03_Event_driven

SRCS		= 03_Event_driven.cpp	\
				Graphics.cpp

OBJS		= $(SRCS:.cpp=.o)

CXXFLAGS	= -W -Wall -Werror

CXXFLAGS	+=  -I./ -g3

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

CXX			= g++

NAME		= 02_Img_on_screen

SRCS		= 02_Img_on_screen.cpp	\
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

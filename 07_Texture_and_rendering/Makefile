CXX			= g++

NAME		= 07_Texture_and_rendering

SRCS		= 07_Texture_and_rendering.cpp	\
				src/Graphics.cpp	\
				src/Surfaces.cpp

OBJS		= $(SRCS:.cpp=.o)

CXXFLAGS	= -W -Wall -Werror

CXXFLAGS	+=  -I./include -g3

LDFLAGS		= -lSDL2 -lSDL2_image

RM			= rm -f

all:	$(NAME)

$(NAME): $(OBJS)
	$(CXX) $(OBJS) $(LDFLAGS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

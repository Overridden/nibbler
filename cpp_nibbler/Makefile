##
## Makefile for  in /home/lastru_g/rendu/cpp_nibbler
##
## Made by lastrucci
## Login   <lastru_g@epitech.net>
##
## Started on  Fri Mar 28 08:49:56 2014 lastrucci
## Last update Sun Apr  6 21:21:31 2014 Alexandre NGUYEN
##

NAME		= nibbler

SRCS		= snake/nibbler.cpp		\
		map/encaps.cpp			\
		map/map.cpp			\
		open_lib.cpp			\
		main.cpp

OBJS		= $(SRCS:.cpp=.o)

NC_NAME		= lib_nibbler_ncurses.so

NC_SRCS		= nc/nc.cpp			\
		nc/nc_lib.cpp

NC_OBJS		= $(NC_SRCS:.cpp=.o)

NC_LIBS		= -lncurses

OPENGL_NAME		= lib_nibbler_opengl.so

OPENGL_SRCS		= opengl/libopengl.cpp			\
			opengl/objects.cpp

OPENGL_OBJS		= $(OPENGL_SRCS:.cpp=.o)

OPENGL_LIBS		= -lGL -lGLU -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

SDL_NAME		= lib_nibbler_sdl.so

SDL_SRCS		= lib_sdl/sdl.cpp			\
			lib_sdl/libsdl.cpp

SDL_OBJS		= $(SDL_SRCS:.cpp=.o)

SDL_LIBS		= -lSDL

SHARED		= -shared -fPIC

CPP		= g++

FLAG		= -ldl

RM		= rm -f

CXXFLAGS	= -W -Wall -Werror -Wextra -I../ -fPIC

all:		$(NC_NAME) $(OPENGL_NAME) $(SDL_NAME) $(NAME)

$(NAME):	$(OBJS)
		$(CPP) $(OBJS) -o $(NAME) $(FLAG)

$(NC_NAME):	$(NC_OBJS)
		$(CPP) $(SHARED) $(NC_OBJS) -o $(NC_NAME) $(NC_LIBS)

$(OPENGL_NAME):	$(OPENGL_OBJS)
		$(CPP) $(SHARED) $(OPENGL_OBJS) -o $(OPENGL_NAME) $(OPENGL_LIBS)

$(SDL_NAME):	$(SDL_OBJS)
		$(CPP) $(SHARED) $(SDL_OBJS) -o $(SDL_NAME) $(SDL_LIBS)

clean:
		$(RM) $(OBJS) $(NC_OBJS) $(OPENGL_OBJS) $(SDL_OBJS)

fclean:		clean
		$(RM) $(NAME) $(NC_NAME) $(OPENGL_NAME) $(SDL_NAME)

re:		fclean all

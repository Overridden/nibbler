##
## Makefile for 203 in /home/nguye_1/rendu/203hotline
## 
## Made by Alexandre NGUYEN
## Login   <nguye_1@epitech.net>
## 
## Started on  Fri Mar 28 17:35:41 2014 Alexandre NGUYEN
## Last update Sat Apr  5 12:12:03 2014 Alexandre NGUYEN
##

SOURCES =	opengl.cpp	\
		objects.cpp

OBJECTS	=	$(SOURCES:.cpp=.o)

TARGET	=	a.out

LIBS	=	-lGL -lGLU -lsfml-graphics -lsfml-window -lsfml-system

CXXFLAGS	=	-Wall -Werror -Wextra

all: $(OBJECTS)
	g++ $(LIBS) -o $(TARGET) $(OBJECTS)

%o: %cpp
	g++ -o $@ -c $<

x: all
	./$(TARGET)

clean:
	rm -rf $(OBJECTS)

fclean:	clean
	rm -rf $(TARGET)

re:	fclean all


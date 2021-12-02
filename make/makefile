NAME:=main_exe
GCC:=g++
GTKMM:=`pkg-config gtkmm-3.0 --cflags --libs`
OBJFILE:=compile/
FLAGS:=-Wall -Wextra -Werror

all: $(NAME)

$(NAME): mainWindow.o main.o modelimage.h controllerimage.h
	$(GCC) -o $(NAME) $(OBJFILE)main.o $(OBJFILE)mainWindow.o $(GTKMM)

main.o: main.cpp
	$(GCC) -o $(OBJFILE)main.o main.cpp -c $(FLAGS) $(GTKMM)

mainWindow.o: controllerimage.o
	$(GCC) -o $(OBJFILE)mainWindow.o mainWindow.cpp -c $(FLAGS) $(GTKMM)

controllerimage.o:controllerimage.cpp
	$(GCC) -o $(OBJFILE)controllerimage.o controllerimage.cpp -c $(FLAGS) $(GTKMM)

modelimage.o: modelimage.cpp
	$(GCC) -o $(OBJFILE)modelimage.o modelimage.cpp -c $(FLAGS) $(GTKMM)
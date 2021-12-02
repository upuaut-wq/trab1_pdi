SRCS = main.cpp \
    mainWindow.cpp \
	controllerimage.cpp \
	modelimage.cpp

OBJS = compile/

all:application

application:$(SRCS)
    g++ $(SRCS)
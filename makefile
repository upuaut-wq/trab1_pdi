GTKMM=`pkg-config gtkmm-3.0 --cflags --libs`
OCTAVE=`pkg-config octave --cflags --libs`
CF=compile/
REQ_OBJ=main.o mainWindow.o controllerimage.o modelimage.o controlleralgoritmos.o
OBJ = compile/main.o compile/mainWindow.o compile/controllerimage.o compile/modelimage.o compile/controlleralgoritmos.o

all: file

file: $(REQ_OBJ)
	mkoctfile --link-stand-alone -o file $(OBJ) $(GTKMM)

main.o: main.cpp	
	g++ -o $(CF)main.o -c main.cpp $(GTKMM)

mainWindow.o: view/mainWindow.cpp	
	g++ -o $(CF)mainWindow.o -c view/mainWindow.cpp $(GTKMM)

controllerimage.o: controller/controllerimage.cpp	
	g++ -o $(CF)controllerimage.o -c controller/controllerimage.cpp $(GTKMM)

modelimage.o: model/modelimage.cpp	
	g++ -o $(CF)modelimage.o -c model/modelimage.cpp $(GTKMM)

controlleralgoritmos.o: controller/controlleralgoritmos.cpp
	g++ -o $(CF)/controlleralgoritmos.o -c controller/controlleralgoritmos.cpp $(OCTAVE) $(GTKMM)

CC=g++
CFLAGS=-c -std=c++11 -I/usr/include/libdrm -I -L/usr/local/lib
LINKLIBS=-lglfw3 -lX11 -lXi -lXmu -lXrandr -lXxf86vm -lpthread -lm -lGLEW -lGLU -lGL -lXinerama -lXcursor -lfbxsdk

all: fbxDemo

fbxDemo: application.o fbxDemoApp.o
	$(CC) application.o fbxDemoApp.o $(LINKLIBS) -o fbxDemo

application.o: application.cpp
	$(CC) $(CFLAGS) application.cpp

fbxDemo.o: fbxDemo.cpp
	$(CC) $(CFLAGS) fbxDemo.cpp

clean:
	rm *.o
	rm fbxDemo

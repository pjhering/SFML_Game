LIBS=-lsfml-graphics -lsfml-window -lsfml-system
OBJS=obj/App.o \
     obj/EndScreen.o \
     obj/GameScreen.o \
     obj/Main.o \
     obj/Screen.o \
     obj/ScreenManager.o \
     obj/SplashScreen.o


all: Game
	############################################################


obj/App.o: src/App.cpp
	############################################################
	g++ -c src/App.cpp -o obj/App.o 


obj/EndScreen.o: src/EndScreen.cpp
	############################################################
	g++ -c src/EndScreen.cpp -o obj/EndScreen.o 


obj/GameScreen.o: src/GameScreen.cpp
	############################################################
	g++ -c src/GameScreen.cpp -o obj/GameScreen.o 


obj/Main.o: src/Main.cpp
	############################################################
	g++ -c src/Main.cpp -o obj/Main.o 


obj/Screen.o: src/Screen.cpp
	############################################################
	g++ -c src/Screen.cpp -o obj/Screen.o 


obj/ScreenManager.o: src/ScreenManager.cpp
	############################################################
	g++ -c src/ScreenManager.cpp -o obj/ScreenManager.o 


obj/SplashScreen.o: src/SplashScreen.cpp
	############################################################
	g++ -c src/SplashScreen.cpp -o obj/SplashScreen.o 


Game: $(OBJS)
	############################################################
	g++ -o Game $(OBJS) $(LIBS)


clean:
	############################################################
	astyle --style=allman -s4 -N -p -xg -k3 src/*.hpp
	astyle --style=allman -s4 -N -p -xg -k3 src/*.cpp
	rm -Rf Game
	rm -Rf obj/*
	rm -Rf src/*.orig


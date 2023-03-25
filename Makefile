LIBS=-lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system
OBJS=obj/App.o \
     obj/Assets.o \
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
	g++ -Wall -std=c++11 -c src/App.cpp -o obj/App.o 


obj/Assets.o: src/Assets.cpp
	############################################################
	g++ -Wall -std=c++11 -c src/Assets.cpp -o obj/Assets.o 


obj/EndScreen.o: src/EndScreen.cpp
	############################################################
	g++ -Wall -std=c++11 -c src/EndScreen.cpp -o obj/EndScreen.o 


obj/GameScreen.o: src/GameScreen.cpp
	############################################################
	g++ -Wall -std=c++11 -c src/GameScreen.cpp -o obj/GameScreen.o 


obj/Main.o: src/Main.cpp
	############################################################
	g++ -Wall -std=c++11 -c src/Main.cpp -o obj/Main.o 


obj/Screen.o: src/Screen.cpp
	############################################################
	g++ -Wall -std=c++11 -c src/Screen.cpp -o obj/Screen.o 


obj/ScreenManager.o: src/ScreenManager.cpp
	############################################################
	g++ -Wall -std=c++11 -c src/ScreenManager.cpp -o obj/ScreenManager.o 


obj/SplashScreen.o: src/SplashScreen.cpp
	############################################################
	g++ -Wall -std=c++11 -c src/SplashScreen.cpp -o obj/SplashScreen.o 


Game: $(OBJS)
	############################################################
	g++ -Wall -std=c++11 -o Game $(OBJS) $(LIBS)


clean:
	############################################################
	astyle --style=allman -s4 -N -p -xg -k3 src/*.hpp
	astyle --style=allman -s4 -N -p -xg -k3 src/*.cpp
	rm -Rf Game
	rm -Rf obj/*
	rm -Rf src/*.orig


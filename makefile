CC=g++
CFLAGS=-lSDL2 -lGL -lGLEW -lm -lSDL2_image -lSDL2_mixer
PFLAGS=-Wall


all: main.o worldgen.o type.o game.o
	${CC} ${PFLAGS} -o run main.o worldgen.o type.o game.o ${CFLAGS}

main.o: main.cpp
	${CC} -c main.cpp


worldgen.o: headers/worldgen.h src/worldgen.cpp
	${CC} -c src/worldgen.cpp


type.o: headers/type.h src/type.cpp
	${CC} -c src/type.cpp

game.o: headers/game.h src/game.cpp
	${CC} -c src/game.cpp

clean:
	rm *.o
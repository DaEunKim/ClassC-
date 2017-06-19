CC = g++
CFLAGS = -lncurses
TARGET = tetris
OBJECTS = block.o game.o name.o score.o main.o

all : $(TARGET)

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

	clean :
		rm *.o main.out


CC=g++
CFLAGS=-I.
DEPS = Enemy.h Goblin.h Orc.h Troll.h GameBoard.h
OBJ = Enemy.cpp Goblin.cpp Orc.cpp Troll.cpp GameBoard.cpp main.cpp

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

game: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o game

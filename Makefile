CC = gcc
WIN_CC = x86_64-w64-mingw32-gcc

CFLAGS = -Wall -Wextra -Iinclude -g

SRC = $(wildcard *.c)

OBJ = $(patsubst %.c,obj/%.o,$(SRC))
WIN_OBJ = $(patsubst %.c,obj-win/%.o,$(SRC))

TARGET = build/tictactoe
WIN_TARGET = build/tictactoe.exe


.PHONY: all linux windows clean


all: linux windows


linux: $(TARGET)

$(TARGET): $(OBJ)
	@mkdir -p build
	$(CC) $(OBJ) -o $(TARGET)


obj/%.o: %.c
	@mkdir -p obj
	$(CC) $(CFLAGS) -c $< -o $@


windows: $(WIN_TARGET)

$(WIN_TARGET): $(WIN_OBJ)
	@mkdir -p build
	$(WIN_CC) $(WIN_OBJ) -o $(WIN_TARGET)


obj-win/%.o: %.c
	@mkdir -p obj-win
	$(WIN_CC) $(CFLAGS) -c $< -o $@


clean:
	rm -rf obj obj-win build
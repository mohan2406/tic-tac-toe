CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -g

SRC = $(wildcard *.c)
OBJ = $(patsubst *%.c,obj/%.o,$(SRC))

TARGET = build/tictactoe

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

obj/%.o: %.c
	@mkdir -p obj
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf obj/*.o bin/tictactoe

.PHONY: all clean

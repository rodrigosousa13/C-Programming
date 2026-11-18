
CFLAGS = -ansi -pedantic

SRC = $(wildcard src/*.c)

OBJ = $(patsubst src/%.c, build/%.o, $(SRC))

TARGET = bin/main.exe

$(TARGET): $(OBJ)
	gcc $(CFLAGS) $(OBJ) -o $(TARGET)

all: $(TARGET)

build/%.o: src/%.c
	mkdir -p build
	gcc -Iinclude -MMD -MP -c $< -o $@

-include $(OBJ:.o=.d)

run: all
	$(TARGET)

clean:
	rm -rf build bin

.PHONY: all run clean

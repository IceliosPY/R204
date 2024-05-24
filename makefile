CC = gcc
CFLAGS = -Wall -Wextra -Ilibs/SDL2-2.0.14/include -Ilibs/SDL2_ttf-2.0.15/include -Ilibs/SDL2_image-2.0.5/include -Isrc
LDFLAGS = -Llibs/SDL2-2.0.14/lib -Llibs/SDL2_ttf-2.0.15/lib -Llibs/SDL2_image-2.0.5/lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf -lSDL2_image

SRC = src/main.c src/menu.c src/fonctionTraitement.c src/GPGGA.c
OBJ = $(SRC:.c=.o)
TARGET = programme

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f $(OBJ) $(TARGET)
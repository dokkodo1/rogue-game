CC      = gcc
CFLAGS  = -Wall -Wextra -g $(shell pkg-config --cflags ncurses)
LDFLAGS = $(shell pkg-config --libs ncurses)
TARGET  = rogue
SRC     = main.c

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)

clean:
	rm -f $(TARGET)

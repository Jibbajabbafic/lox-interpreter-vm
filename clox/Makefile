CC = gcc
# Debug flags
CFLAGS = -Wall -Wextra -g
# Optimized flags
# CFLAGS = -Wall -Wextra -O3
TARGET = bin/clox
SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

run: $(TARGET)
	./$(TARGET) $(filter-out $@,$(MAKECMDGOALS))

%:
	@:

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all run clean

CC = gcc
# Debug flags
CFLAGS = -Wall -Wextra -g
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

# Optimized flags
bench: CFLAGS = -Wall -Wextra -O3 -march=native -flto
# Run the benchmark file with optimized flags
bench: clean $(TARGET)
	./$(TARGET) bench.lox

%:
	@:

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all run bench clean

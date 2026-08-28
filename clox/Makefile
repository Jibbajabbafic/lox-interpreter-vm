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
bench-time: CFLAGS = -Wall -Wextra -O3 -march=native -flto
# Run the time benchmark file with optimized flags
bench-time: clean $(TARGET)
	./$(TARGET) benchmarks/time.lox
# Optimized flags
bench-work: CFLAGS = -Wall -Wextra -O3 -march=native -flto
# Run the work benchmark file with optimized flags
bench-work: clean $(TARGET)
	./$(TARGET) benchmarks/work.lox

%:
	@:

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all run bench-time bench-work clean

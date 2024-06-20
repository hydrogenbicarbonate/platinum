all: ptvm

CC = clang
override CFLAGS += -g -Wno-everything -pthread -lm

SRCS = $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.c' -print)
HEADERS = $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.h' -print)

build:
	mkdir -p build

ptvm: build
	$(CC) $(CFLAGS) $(SRCS) -o build/ptvm

ptvm-debug: build
	$(CC) $(CFLAGS) -O0 $(SRCS) -o build/ptvm-debug

clean:
	rm -rf build
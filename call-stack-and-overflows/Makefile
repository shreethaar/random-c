CC=gcc
CFLAGS=-g -Wall
EXE=thestack

all: $(EXE)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(EXE): $(patsubst %.c,%.o,$(wildcard *.c))
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f *.o $(EXE)

.PHONY: all clean

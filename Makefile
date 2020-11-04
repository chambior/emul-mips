CC = gcc
CFLAGS = -Wall -ansi -pedantic
OBJECTSO = main.o string.o word32.o

main: $(OBJECTSO)
	$(CC) $(CFLAGS) $^ -o exe

%.o: %.c
	$(CC) $(CFLAGS) $< -c
clean:
	rm -f $(OBJECTSO) exe

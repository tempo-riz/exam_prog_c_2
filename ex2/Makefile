cc=gcc
CFLAGS=-Wextra -Wall -g -fsanitize=address -fsanitize=leak
LFLAGS=-fsanitize=address -fsanitize=leak -lm



main: tree.o main.o 
	$(cc) -o $@ $^ $(CFLAGS) $(LFLAGS)

clean:
	rm -f *.o *.x

main: main.o
	gcc -o $@ $< -fsanitize=address -fsanitize=leak

main.o: main.c 
	gcc -c -Wall -Wextra -pedantic -fsanitize=address -fsanitize=leak $<

clean:
	rm -f *.o main

rebuild: clean main
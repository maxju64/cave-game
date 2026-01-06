build/cave: build/cave.o build/timer.o
	gcc build/cave.o build/timer.o -o build/cave 

build/cave.o: src/main.c
	gcc -O0 -g -c src/main.c -o build/cave.o

build/timer.o: src/timer.c
	gcc -O0 -g -c src/timer.c -o build/timer.o

clean:
	rm *.o

run:
	build/./cave

print: $(wildcard *.c)
	ls -la $?

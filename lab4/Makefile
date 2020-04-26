c: obj/main.o obj/queue.o obj/stack.o obj/list.o
	gcc -Wall obj/queue.o obj/stack.o obj/main.o obj/list.o -o main
	./main

obj/list.o: list.c
	gcc -c -g list.c -o obj/list.o

obj/main.o: main.c
	gcc -c -g main.c -o obj/main.o

obj/queue.o: queue.c
	gcc -c -g queue.c -o obj/queue.o

obj/stack.o: stack.c
	gcc -c -g stack.c -o obj/stack.o

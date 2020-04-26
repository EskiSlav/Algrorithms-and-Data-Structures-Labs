c: obj/list.o obj/main.o obj/arr.o
	g++ -Wall obj/main.o obj/arr.o obj/list.o -o ./obj/main
	./obj/main

g: obj/list.o obj/main.o obj/arr.o
	g++ -g -Wall obj/main.o obj/arr.o obj/list.o -o ./obj/main
	gdb ./obj/main

obj/list.o: list.cpp
	g++ -g -c list.cpp -o obj/list.o

obj/main.o: main.cpp
	g++ -g -c main.cpp -o obj/main.o

obj/arr.o: arr.cpp
	g++ -g -c arr.cpp -o obj/arr.o

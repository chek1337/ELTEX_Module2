lib:
	gcc -fPIC min.c -c
	gcc -fPIC add.c -c
	gcc -fPIC mult.c -c
	gcc -fPIC div.c -c
	gcc -shared min.o -o libmin.so
	gcc -shared add.o -o libadd.so
	gcc -shared div.o -o libdiv.so
	gcc -shared mult.o -o libmult.so
	
prog:
	gcc -rdynamic main.c -o prog.exe -ldl

run:
	LD_LIBRARY_PATH=".:$LD_LIBRARY_PATH" ./prog.exe


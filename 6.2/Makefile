lib:
	gcc -fPIC list.c -c
	gcc -fPIC work.c -c
	gcc -fPIC anthroponym.c -c
	gcc -fPIC persinfo.c -c
	gcc -shared list.o work.o anthroponym.o persinfo.o -o libmyname.so
prog:
	gcc main.c -o prog.exe -L. -lmyname
run:
	LD_LIBRARY_PATH=".:$LD_LIBRARY_PATH" ./prog.exe

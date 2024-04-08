lib:
	gcc -fPIC list.c -c
	gcc -fPIC work.c -c
	gcc -fPIC anthroponym.c -c
	gcc -fPIC persinfo.c -c
	gcc -shared list.o work.o anthroponym.o persinfo.o -o libmyname.so
prog:
	export LD_LIBRARY_PATH=$PWD:$LD_LIBRARY_PATH
	gcc main.c -o prog.exe -L. -lmyname

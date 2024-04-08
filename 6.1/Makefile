lib:
	gcc list.c -c
	gcc work.c -c
	gcc anthroponym.c -c
	gcc persinfo.c -c
	ar rc libmyname.a list.o work.o anthroponym.o persinfo.o
prog:
	gcc main.c -o prog.exe -L. -lmyname

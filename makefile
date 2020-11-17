all: waitinglist

waitinglist: waiting_list.o request.o readline.o

   gcc waiting_list.o request.o readline.o -o waitinglist -I

waiting_list.o: waiting.c

   gcc -c writing_list.c -I

request.o: request.c

   gcc -c request.c -I

readline.o: readline.c

   gcc -c readline.c -I
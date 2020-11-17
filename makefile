rec_classes: rec_classes.o request.o readline.o

   gcc rec_classes.o request.o readline.o -o rec_classes -I

rec_classes.o: rec_classes.c

   gcc -c rec_classes.c -I

request.o: request.c request.h

   gcc -c request.c -I

readline.o: readline.c readline.h

   gcc -c readline.c -I

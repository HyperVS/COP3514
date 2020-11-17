rec_classes: rec_classes.o request.o readline.o
<<<<<<< Updated upstream
<<<<<<< Updated upstream
	gcc -o rec_classes rec_classes.o request.o readline.o 
=======
	gcc -o rec_classes rec_classes.o request.o readline.o
>>>>>>> Stashed changes
=======
	gcc -o rec_classes rec_classes.o request.o readline.o
>>>>>>> Stashed changes
rec_classes.o: rec_classes.c
	gcc -c rec_classes.c
request.o: request.c request.h
	gcc -c request.c
readline.o: readline.c readline.h
	gcc -c readline.c

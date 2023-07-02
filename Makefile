
main: obj/main.o obj/menu.o obj/jeu.o obj/fonctions.o obj/hash.o
	gcc obj/main.o obj/menu.o obj/jeu.o obj/fonctions.o obj/hash.o -o jeu -lSDL2 -lSDL2_image -lSDL2_ttf
	
obj/main.o: src/main.c src/header/constante.h src/header/structure.h src/header/hash.h src/header/menu.h
	gcc -c src/main.c -o obj/main.o

obj/menu.o: src/menu.c src/header/constante.h src/header/structure.h src/header/fonctions.h src/header/jeu.h
	gcc -c src/menu.c -o obj/menu.o

obj/jeu.o: src/jeu.c src/header/constante.h src/header/structure.h src/header/hash.h src/header/fonctions.h
	gcc -c src/jeu.c -o obj/jeu.o
	
obj/fonctions.o: src/fonctions.c src/header/constante.h
	gcc -c src/fonctions.c -o obj/fonctions.o
	
obj/hash.o: src/hash.c src/header/constante.h src/header/structure.h
	gcc -c src/hash.c -o obj/hash.o


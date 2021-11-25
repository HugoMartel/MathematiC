all:
	rm -f calculette.exe calculette.lex.cpp calculette.bison.cpp calculette.bison.h
	bison -d calculette.y -o calculette.bison.cpp
	flex -o calculette.lex.cpp calculette.l
	g++ -w calculette.lex.cpp calculette.bison.cpp -o calculette
	./calculette test.txt
all:test calistir

test:
	g++ -I ./include/ -o ./lib/Agac.o -c ./src/Agac.cpp
	g++ -I ./include/ -o ./lib/Dugum.o -c ./src/Dugum.cpp
	g++ -I ./include/ -o ./bin/test	./lib/Agac.o ./lib/Dugum.o ./src/test.cpp
	

calistir:
	./bin/test
	
clean:
	del	lib\*.o
	del	bin\*.exe

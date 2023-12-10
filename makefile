Hash: hashTable.o 
	g++ hashTable.o main.o -o Hash
main.o: main.cpp hashTable.h
	g++ -c main.cpp
hashTable.o: hashTable.h hashTable.cpp
	g++ -c hashTable.cpp

clean: 
	rm -f Hash *.o

run: Hash
	./Hash


SingleLinkedList: main.o Executive.o Hash.o Linkedlist.o Node.o
	g++ -g -std=c++11 main.o Executive.o Hash.o Linkedlist.o Node.o -o SingleLinkedList

main.o: main.cpp Executive.h
	g++ -std=c++11 -g -c main.cpp

Executive.o: Executive.h Executive.cpp Hash.h Linkedlist.h Node.h
	g++ -std=c++11 -g -c Executive.cpp

Hash.o: Hash.h Hash.cpp 
	g++ -std=c++11 -g -c Hash.cpp

Linkedlist.o: Linkedlist.h Linkedlist.cpp Node.h
	g++ -std=c++11 -g -c Linkedlist.cpp

Node.o: Node.h Node.cpp
	g++ -std=c++11 -g -c Node.cpp

clean:
	rm *.o SingleLinkedList

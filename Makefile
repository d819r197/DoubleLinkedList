QuadDoubleHash: main.o Executive.o DoubleHash.o QuadraticHash.o RestaurantNode.o
	g++ -g -std=c++11 main.o Executive.o DoubleHash.o QuadraticHash.o RestaurantNode.o -o QuadDoubleHash

main.o: main.cpp Executive.h
	g++ -std=c++11 -g -c main.cpp

Executive.o: Executive.h Executive.cpp DoubleHash.h QuadraticHash.h 
	g++ -std=c++11 -g -c Executive.cpp

DoubleHash.o: DoubleHash.h DoubleHash.cpp RestaurantNode.h
	g++ -std=c++11 -g -c DoubleHash.cpp

QuadraticHash.o: QuadraticHash.h QuadraticHash.cpp RestaurantNode.h
	g++ -std=c++11 -g -c QuadraticHash.cpp

RestaurantNode.o: RestaurantNode.h RestaurantNode.cpp
	g++ -std=c++11 -g -c RestaurantNode.cpp

clean:
	rm *.o QuadDoubleHash

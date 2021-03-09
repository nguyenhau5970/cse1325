CXXFLAGS = --std=c++17

all: Deck Card

Deck: main.o Deck.o
	$(CXX) $(CXXFLAGS) main.o Deck.o -o Deck

Card: Card.o Deck.o *.h
	$(CXX) $(CXXFLAGS) Card.o Deck.o -o test

main.o:main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

flashCard.o: flashCard.cpp
	$(CXX) $(CXXFLAGS) -c flashCard.cpp -o flashCard.o

clean:
	rm -f *.o *.gch *~ a.out flashCard


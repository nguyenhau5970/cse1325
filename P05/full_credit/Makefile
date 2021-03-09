CXXFLAGS += --std=c++17

all: smart

debug: CXXFLAGS += -g
debug: smart

smart: main.o person.o student.o parent.o *.h
	$(CXX) $(CXXFLAGS) main.o person.o student.o parent.o -o smart


main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

person.o: person.cpp *.h
	$(CXX) $(CXXFLAGS) -c person.cpp -o persson.o

student.o: student.cpp *.h
	$(CXX) $(CXXFLAGS) -c student.cpp -o student.o

parent.o: parent.cpp *.h
	$(CXX) $(CXXFLAGS) -c parent.cpp -o parent.o

test.o: test.cpp *.h
	$(CXX) $(CXXFLAGS) -c test.cpp -o test.o

clean:
	rm -f *.o *.gch *~ a.out smart


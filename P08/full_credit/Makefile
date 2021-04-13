CXXFLAGS += --std=c++17
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

all: smart

debug: CXXFLAGS += -g
debug: smart

smart: main.o mainwin.o subject.o semester.o course.o section.o entrydialog.o person.o student.o parent.o *.h
	$(CXX) $(CXXFLAGS) main.o mainwin.o subject.o semester.o course.o section.o entrydialog.o person.o student.o parent.o $(GTKFLAGS) -o smart

main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp $(GTKFLAGS) -o main.o

mainwin.o: mainwin.cpp *.h
	$(CXX) $(CXXFLAGS) -c mainwin.cpp $(GTKFLAGS) -o mainwin.o

subject.o: subject.cpp *.h
	$(CXX) $(CXXFLAGS) -c subject.cpp $(GTKFLAGS) -o subject.o

semester.o: semester.cpp *.h
	$(CXX) $(CXXFLAGS) -c smester.cpp $(GTKFLAGS) -o semester.o

course.o: course.cpp *.h
	$(CXX) $(CXXFLAGS) -c course.cpp $(GTKFLAGS) -o course.o

section.o: section.cpp *.h
	$(CXX) $(CXXFLAGS) -c section.cpp $(GTKFLAGS) -o section.cpp

entrydialog.o: entrydialog.cpp *.h
	$(CXX) $(CXXFLAGS) -c entrydialog.cpp $(GTKFLAGS) -o entrydialog.o

person.o: person.cpp *.h
	-$(CXX) $(CXXFLAGS) -c person.cpp -o person.o

student.o: student.cpp *.h
	-$(CXX) $(CXXFLAGS) -c student.cpp -o student.o

parent.o: parent.cpp *.h
	$(CXX) $(CXXFLAGS) -c parent.cpp -o parent.o

clean:
	rm -f *.o *.gch *~ a.out smart 


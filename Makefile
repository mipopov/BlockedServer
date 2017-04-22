all: write

write: main.o student.o 
	g++ main.o student.o -o write

main.o: main.cpp student.cpp
	g++ -c main.cpp

student.o: student.cpp student.h
	g++ -c student.cpp

clean:
	rm -f *.o write

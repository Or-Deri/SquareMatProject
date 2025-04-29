#orderi429@gmail.com
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic -g
SRC = SquareMat.cpp 
HEADERS = SquareMat.h

all: main tests

main: $(SRC) main.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SRC) main.cpp -o main 

tests: $(SRC) tests.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SRC) tests.cpp -o tests

valgrind: $(SRC) tests.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SRC) tests.cpp -o tests
	valgrind --leak-check=full --track-origins=yes ./tests

clean:
	rm -f main tests


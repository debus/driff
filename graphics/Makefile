CXX := g++
LIBS := -lGLEW -lglfw

test: test.o
	$(CXX) -o test test.o $(LIBS)
test.o: test.cpp graphics.hpp
	$(CXX) -c test.cpp -o test.o

clean:
	-@rm -f test.o
	-@rm -f test

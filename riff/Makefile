
CXX := g++

INCLUDE_PATHS := -I../../debus

test: main.o
	$(CXX) -o $@ $^

main.o:
	$(CXX) -o $(@) -c $(INCLUDE_PATHS) main.cpp

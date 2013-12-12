
CXX := g++


main: smart_chunk_base.hpp
	$(CXX) -o $@ main.cpp

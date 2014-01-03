CXX := g++
LIBS := -lglfw3 -lGLU -lX11 -lpthread -lXrandr -lXi -lXxf86vm -lrt -lm -lGL
CPPFILES := test.cpp
OBJECTS := $(CPPFILES:.cpp=.o)
DEPENDS := ${OBJECTS:.o=.d}
EXEC := test


${EXEC}: ${OBJECTS}
	$(CXX) -o $(EXEC) $(OBJECTS) $(LIBS)

%.d: %.cpp
	$(CXX) -MM -MF $@ $^

clean: clean_objs clean_d_files
	-@rm -f $(EXEC)

clean_objs:
	-@rm -f $(wildcard *.o)

clean_d_files:
	-@rm -f $(wildcard *.d)

-include ${DEPENDS}

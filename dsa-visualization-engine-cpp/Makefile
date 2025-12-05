CXX=g++
CXXFLAGS=-std=c++17 -O2 -I./src

OBJ=src/logger.o src/graph.o src/sort.o src/main.o

all: dsa_visualize

src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

dsa_visualize: $(OBJ)
	$(CXX) $(CXXFLAGS) -o dsa_visualize $(OBJ)

clean:
	rm -f src/*.o dsa_visualize

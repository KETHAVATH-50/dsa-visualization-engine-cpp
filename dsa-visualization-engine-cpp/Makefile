CXX = g++
CXXFLAGS = -std=c++17 -O2 -I./src

OBJS = src/logger.o src/graph.o src/sort.o src/main.o

dsa_visualize: $(OBJS)
	$(CXX) $(CXXFLAGS) -o dsa_visualize $(OBJS)

src/%.o: src/%.cpp src/%.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

src/main.o: src/main.cpp
	$(CXX) $(CXXFLAGS) -c src/main.cpp -o src/main.o

clean:
	rm -f src/*.o dsa_visualize

CXX=clang++
CXX_FLAGS=-std=c++20 -Iincludes -gdwarf-4 -fstandalone-debug -O0 -Wall -Wextra -Werror

exec: bin/exec
tests: bin/tests

bin/exec: graph.cpp main.cpp latlong.cpp
	$(CXX) $(CXX_FLAGS) $^ -o $@

bin/tests: graph.cpp main.cpp latlong.cpp
	$(CXX) $(CXX_FLAGS) $^ -o $@

.DEFAULT_GOAL := exec
.PHONY: exec tests clean

clean:
	rm -f bin/*
CXX=clang++
CXX_FLAGS=-std=c++20 -Iincludes -gdwarf-4 -fstandalone-debug -O0 -Wall -Wextra -Werror

exec: bin/exec
tests: bin/tests

bin/exec: parse.cpp graph.cpp main.cpp latlong.cpp floyd.cpp
	$(CXX) $(CXX_FLAGS) $^ -o $@

bin/tests: parse.cpp graph.cpp latlong.cpp tests/test.cpp floyd.cpp
	$(CXX) $(CXX_FLAGS) $^ -o $@

.DEFAULT_GOAL := exec
.PHONY: exec tests clean

clean:
	rm -f bin/*

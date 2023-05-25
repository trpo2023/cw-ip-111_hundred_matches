cflags = -Wall -I include -MP -MMD
objects_temp = $(shell find src/ -name '*.cpp')
objects = $(objects_temp:%.cpp=obj/%.o)
libs_temp = $(shell find src/lib/ -name '*.cpp')
libs = $(libs_temp:src/lib/%.cpp=obj/src/lib/lib%.a)

.PHONY: all
all: bin/main

bin/main:
	g++ $(cflags) -o bin/main

.PHONY: clean
clean:
	rm -f create_dirs
	rm -rf obj
	rm -rf bin
lib0 = matches
lib1 = player
lib2 = computer
lib3 = game
lib4 = menu

cflags = -Wall -I include -MP -MMD
objects_temp = $(shell find src/ -name '*.cpp')
objects = $(objects_temp:%.cpp=obj/%.o)
libs_temp = $(shell find src/lib/ -name '*.cpp')
libs = $(libs_temp:src/lib/%.cpp=obj/src/lib/lib%.a)

.PHONY: all
all: create_dirs $(objects) $(libs) bin/main

-include obj/src/lib/*.d
-include obj/src/main/*.d

create_dirs:
	mkdir -p bin/
	mkdir -p obj/src/main/
	mkdir -p obj/src/lib/
	touch create_dirs

obj/src/lib/lib%.a: obj/src/lib/%.o
	ar rcs $@ $^

obj/%.o: %.cpp
	g++ -c $(cflags) $< -o $@

bin/main:
	g++ $(cflags) -Lobj/src/lib/ obj/src/main/main.o -l$(lib4) -l$(lib3) -l$(lib2) -l$(lib1) -l$(lib0) -o bin/main

.PHONY: clean
clean:
	rm -f create_dirs
	rm -rf obj
	rm -rf bin

.PHONY: test
test: bin/test

bin/test: $(objects) $(libs)
	g++ $(cflags) -I thirdparty $^ -o $@
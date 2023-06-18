APP_NAME = main
LIB_NAME = lib

PP = g++
CFLAGS =  -Wall -Wextra -Werror
CPPFLAGS = -I include -MP -MMD

BIN_DIR = bin
OBJ_DIR = obj
SRC_DIR = src

APP_PATH = $(BIN_DIR)/$(APP_NAME)
LIB_PATH = $(OBJ_DIR)/$(SRC_DIR)/$(LIB_NAME)/$(LIB_NAME).a
SRC_EXT = cpp

APP_SOURCES = $(shell find $(SRC_DIR)/$(APP_NAME) -name '*.$(SRC_EXT)')
APP_OBJECTS = $(APP_SOURCES:$(SRC_DIR)/%.$(SRC_EXT)=$(OBJ_DIR)/$(SRC_DIR)/%.o)
LIB_SOURCES = $(shell find $(SRC_DIR)/$(LIB_NAME) -name '*.$(SRC_EXT)')
LIB_OBJECTS = $(LIB_SOURCES:$(SRC_DIR)/%.$(SRC_EXT)=$(OBJ_DIR)/$(SRC_DIR)/%.o)
DEPS = $(APP_OBJECTS:.o=.d) $(LIB_OBJECTS:.o=.d)

test_name = test
test_path = bin/$(test_name)

test_sources = $(shell find test/ -name '*.cpp')
test_objects = $(test_sources:test/%.cpp=obj/test/%.o)

.PHONY: all
all: create_dirs $(APP_PATH) 

-include $(DEPS)

$(APP_PATH): $(APP_OBJECTS) $(LIB_PATH)
	$(PP) $(CPPFLAGS) $^ -o $@

$(LIB_PATH): $(LIB_OBJECTS)
	ar rcs $@ $^

$(OBJ_DIR)/%.o: %.cpp
	$(PP) -c $(CPPFLAGS) $< -o $@

create_dirs:
	mkdir -p bin/
	mkdir -p obj/src/main/
	mkdir -p obj/src/lib/
	touch create_dirs

.PHONY: clean
clean:
	rm -f create_dirs
	rm -rf obj/
	rm -rf bin/

.PHONY: test
test: create_test_dir $(test_path)

create_test_dir:
	mkdir -p obj/test/
	touch create_dirs

$(test_path): $(test_objects) $(LIB_PATH)
	$(PP) $(CFLAGS) $(CPPFLAGS) $^ -o $@
# Attempt at a somewhat automatic Makefile
# make init to create directories

CC := gcc
CFLAGS := -std=c99 -g -Wall -Wextra -fsanitize=address
LDFLAGS := -lm

FLAGS := $(CFLAGS)
LINKFLAGS := $(LDFLAGS)
DEBUGFLAGS := $(FLAGS) -g -O0 -DDEBUG
TESTFLAGS := $(FLAGS) -lcriterion

EXEC := main
TEST := test
SOURCEDIR := src
HEADERDIR := headers
OBJECTSDIR := obj
TESTDIR := tests

SOURCES := $(shell find $(SOURCEDIR) -name '*.c' 2>&1)
#SOURCES := $(shell find $(SOURCEDIR) -name '*.c' ! -name "$(TEST).c" ! -name "$(EXEC).c" 2>&1)
OBJECTS := $(patsubst $(SOURCEDIR)/%.c, $(OBJECTSDIR)/%.o, $(SOURCES))
TESTS := $(shell find $(TESTDIR) -name '*.c' 2>&1)
TESTOBJECTS := $(filter-out $(OBJECTSDIR)/$(EXEC).o, $(OBJECTS)) # exclude exec


.PHONY: all clean remake init
.DELETE_ON_ERROR:

all: $(EXEC)

$(EXEC): $(OBJECTSDIR)/$(OBJECTS)
	$(CC) $(FLAGS) -I$(HEADERDIR) -I$(SOURCEDIR) $(OBJECTS) $(LINKFLAGS) -o $(EXEC)

$(OBJECTSDIR)/%.o: $(SOURCEDIR)/%.c
	$(CC) $(FLAGS) -I$(HEADERDIR) -I$(SOURCEDIR) -c $< -o $@


test : $(TESTS)

$(TESTS): $(TESTOBJECTS)
	$(CC) $(TESTFLAGS) -I$(HEADERDIR) -I$(TESTDIR) $(TESTOBJECTS) $(TESTS) $(LINKFLAGS) -o $(TEST)


list:
	@echo $(SOURCES)
	@echo $(OBJECTS)
	@echo $(TESTS)
	@echo $(TESTOBJECTS)

clean:
	$(RM) -r $(OBJECTSDIR)/* $(EXEC) $(TEST)

remake: clean all

init:
	@mkdir -p $(SOURCEDIR) $(HEADERDIR) $(OBJECTSDIR) $(TESTSDIR)
